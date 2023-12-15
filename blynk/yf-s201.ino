  
#define BLYNK_TEMPLATE_ID "TMPL6PQcpvDZd"
#define BLYNK_TEMPLATE_NAME "nhom12DLDK"
#define BLYNK_AUTH_TOKEN "YaHiiXTyDJxFUcIVLG8QVVZZsqsqXR-o"
#include <BlynkSimpleEsp32.h>//blynk
BlynkTimer timer;

char auth[] = BLYNK_AUTH_TOKEN;
bool fetch_blynk_state = true;  //true or false
#define VPIN_Bom          V0
#define VPIN_targetVol    V1
#define VPIN_Speed        V2
#define VPIN_Stop         V3
#define VPIN_Vol          V4

#include <WiFi.h>//Wifi
#include <WiFiClient.h>
char ssid[] = "Nhankisu";
char pass[] = "12345678";
#define wifiLed   2   //D2
int wifiFlag = 0;


#include <LiquidCrystal_I2C.h>//i2c LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C địa chỉ 0x27, 16 cột và 2 hàng
bool checktaget = false;
bool checkspeed = false;
bool checkbom = false;
bool checkstop = false;
#define BUTTON_INCREASE_PIN 5 // chân cho nút tăng
#define BUTTON_DECREASE_PIN 19 // chân cho nút giảm
#define BUTTON_PIN          18  // nút nhấn bơm


#define IN1	15 //IN L298N
#define IN2	4
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0
int speed = 255;

volatile bool pumpState = false; // trạng thái của động cơ bơm
volatile float targetVol = 2.0; // mục tiêu lượng nước cần bơm
volatile int flow_frequency; // Đo xung cảm biến lưu lượng
float vol = 0.0,l_minute;// Tính toán lít/giờ
unsigned char flowsensor = 34; // cảm biến lưu lượng
unsigned long currentTime;
unsigned long cloopTime;
float totalVol = 0.0; // Tổng lượng nước đã bơm

/////////////////////////////////////Modbus/////////////////////////////////////



/////////////////////////////////Khối lệnh Blynk///////////////////////////////

BLYNK_WRITE(VPIN_Bom) // V0
{
  if(param.asInt() == 1){
    pumpState = true;
  } // Đặt trạng thái bơm
  checkbom = true;
}

BLYNK_WRITE(VPIN_targetVol) // V1
{
  targetVol = param.asFloat(); // Đặt lưu lượng cần bơm
  checktaget = true;
}

BLYNK_WRITE(VPIN_Speed) // V2
{
  speed = param.asInt(); // Đặt tốc độ bơm
  checkspeed = true;
}

BLYNK_WRITE(VPIN_Stop) // V3
{
  if(param.asInt() == 1){
    pumpState = false;
  } // Đặt trạng thái bơm
  checkstop = true;
} 

void checkBlynkStatus()
{ // called every 3 seconds by SimpleTimer
  bool isconnected = Blynk.connected();
  if (isconnected == false)
  {
    wifiFlag = 1;
    digitalWrite(wifiLed, LOW);
  }
  if (isconnected == true)
  {
    wifiFlag = 0;
    if (!fetch_blynk_state)
    {
      //Blynk.virtualWrite(VPIN_Stop, !pumpState);
      Blynk.virtualWrite(VPIN_Speed, speed);
      Blynk.virtualWrite(VPIN_Bom, pumpState);
      Blynk.virtualWrite(VPIN_targetVol, targetVol);
    }
    digitalWrite(wifiLed, HIGH);
  }
}
 
BLYNK_CONNECTED()
{
  // Request the latest state from the server
  if (fetch_blynk_state)
  {
    Blynk.syncVirtual(VPIN_Stop);
    Blynk.syncVirtual(VPIN_Speed);
    Blynk.syncVirtual(VPIN_Bom);
    Blynk.syncVirtual(VPIN_targetVol);
  }
}

/////////////////////////////Khối lệnh mortor///////////////////////////////////////


void motorDung() {
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
}

void motorBom(int speed) { //speed: từ 0 - MAX_SPEED
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED
	digitalWrite(IN1, HIGH);// chân này không có PWM
	analogWrite(IN2, 255-speed);
}

///////////////////////////////////Khối lệnh Ngắt//////////////////////////////////////////

void buttonInterrupt() {// hàm ngắt nút nhấn
  pumpState = true; // đảo trạng thái của động cơ bơm
}

void increaseInterrupt() { // hàm ngắt cho nút tăng
  targetVol += 0.1; // tăng mục tiêu lượng nước lên 0.1 lít
  checktaget = true;
}

void decreaseInterrupt() { // hàm ngắt cho nút giảm
  if (targetVol > 0.1) {
    targetVol -= 0.1; // giảm mục tiêu lượng nước xuống 0.1 lít nếu nó lớn hơn 0.1
    checktaget = true;
  }
}

void flow () // hàm ngắt cảm biến
{
   flow_frequency++;
}

//////////////////////////////////////////////////////////////////////////////
void setup()
{
   Serial2.begin(115200);

   pinMode(IN1, OUTPUT);
	 pinMode(IN2, OUTPUT);
   motorDung();
   pinMode(flowsensor, INPUT);
   digitalWrite(flowsensor, HIGH);
   
   pinMode(BUTTON_PIN, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonInterrupt, FALLING); // ngắt khi nút bơm nhấn
   
   pinMode(BUTTON_INCREASE_PIN, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(BUTTON_INCREASE_PIN), increaseInterrupt, FALLING); // ngắt khi nút tăng được nhấn
 
   pinMode(BUTTON_DECREASE_PIN, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(BUTTON_DECREASE_PIN), decreaseInterrupt, FALLING); // ngắt khi nút giảm được nhấn
   
   attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); // Setup Ngắt

   lcd.init(); // khởi tạo màn hình LCD
   lcd.backlight();
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Connecting WiFi");
   lcd.setCursor(0,1);
   WiFi.begin(ssid, pass);
   while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   lcd.print(".");
   Serial.print(".");}
   Serial.println("WiFi connected"); 

   Blynk.begin( auth, ssid, pass);
   timer.setInterval(2000L, checkBlynkStatus);
   pumpState = false;
   currentTime = millis();
   cloopTime = currentTime;

}

///////////////////////////////////////////////////////////////////////////////

void loop ()
{
   Blynk.run();
   timer.run(); // Initiates SimpleTimer
   Blynk.virtualWrite(VPIN_Vol, totalVol);

  if(checktaget == true){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Taget: ");
    lcd.print(targetVol);
    Serial2.println("");
    Serial2.print(" Update Taget: ");
    Serial2.println(targetVol);
    Serial2.println("");
    delay(1000);
    checktaget = false;
  }

  if(checkbom == true){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("START");
    Serial2.println("");
    Serial2.println("START");
    Serial2.println("");

    delay(1000);
    checkbom = false;
  }

  if(checkstop == true){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("STOP");
    Serial2.println("");
    Serial2.println("STOP");
    Serial2.println("");
    delay(1000);
    checkstop = false;
  }

  if(checkspeed == true){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("speed: ");
    lcd.print(speed);
    Serial2.println("");
    Serial2.print(" Update speed: ");
    Serial2.println(speed);
    Serial2.println("");
    delay(1000);
    checkspeed = false;
  }

   currentTime = millis();
   // Mỗi giây, tính toán và in ra lít/giờ
   if(currentTime >= (cloopTime + 1000))
   {
    cloopTime = currentTime; // Updates cloopTime
    if(flow_frequency != 0){
      // Tần số xung (Hz) = 7,5Q ,Q là tốc độ dòng chảy tính bằng L/phút
      l_minute = (flow_frequency / 7.5); // (Tần số xung x 60 phút) / 7.5Q = lưu lượng L/giờ

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Rate: ");
      lcd.print(l_minute);
      lcd.print(" L/M");
      l_minute = l_minute/60;
      lcd.setCursor(0,1);
      vol = vol +l_minute;
      totalVol = totalVol + l_minute;
      lcd.print("Vol:");
      lcd.print(vol);
      lcd.print(" L");
      flow_frequency = 0; // Reset Counter
    }
    else {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Rate: ");
      lcd.print( flow_frequency );
      lcd.print(" L/M");
      lcd.setCursor(0,1);
      lcd.print("Vol:");
      lcd.print(vol);
      lcd.print(" L");
    }
  }
  if (pumpState && vol < targetVol) {
    motorBom(speed); // bật động cơ bơm với tốc độ speed
  } else {
    pumpState = false;
    motorDung(); // dừng động cơ bơm
    if (vol >= targetVol) {
      vol = 0.0; // đặt lại vol = 0 khi vol đạt đến mục tiêu
    }}
      Serial2.print("Rate: ");
      Serial2.print(l_minute); 
      Serial2.print("L/M ");
      Serial2.print(" | Vol:");
      Serial2.print(vol); 
      Serial2.println(" L");
 delay(200);
}
 
