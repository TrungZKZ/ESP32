<div align="center">
<a href="https://www.espressif.com/en/products/socs/esp32" align="center"><img height="50" src="https://www.espressif.com/sites/all/themes/espressif/logo-black.svg"  /></a>
</div>
<div align="center">
<details>
<summary><H3>ESP-WROOM-32 38 PIN Development Board PINOUT</H3></summary>
  <img src="https://raw.githubusercontent.com/AchimPieters/esp32-homekit-camera/master/Images/ESP32-38%20PIN-DEVBOARD.png"  />
</details>
</div>
<div align="center">
<details>
<summary><H3>ESP-WROOM-32 30 PIN Develeopment Board PINOUT</H3></summary>
  <img src="https://raw.githubusercontent.com/AchimPieters/esp32-homekit-camera/master/Images/ESP32-30PIN-DEVBOARD.png"  />
</details>
</div>
<div align="center">
<details>
<summary><H3>ESP-WROOM-32 CHIP PINOUT</H3></summary>
  <img src="https://raw.githubusercontent.com/AchimPieters/esp32-homekit-camera/master/Images/ESP32-VROOM-32D-PINOUT.png"  />
</details>
</div>
<div align="center">
<details>
<summary><H3>WT32-ETH01 Board PINOUT</H3></summary>
<table>
  <tr> <td></td>
    <td align="right">EN ⏻</td>
    <td rowspan=13 align="center">WT32-ETH01<br>(ESP32)</td>
    <td>⭕ IO1 (reserved)</td> <td>💬 TXD</td>
  </tr>
  <tr> <td></td> <td align="right">GND ⏚</td> <td>⭕ IO3 (reserved)</td> <td>🗨️ RXD</td> </tr>
  <tr> <td></td> <td align="right">3.3V ⚡</td> <td>⭕ IO0 (reserved)</td> <td>⏱️ REFCLK and 💻 BOOT</td> </tr>
  <tr> <td align="right">pull low to reset</td> <td align="right">EN ⏻</td> <td>⏚ GND</td> <td></td> </tr>
  <tr> <td align="right">ADC1 CH4 📈</td> <td align="right">IO32 ↔️</td> <td>⬅️ IO39 (in only)</td> <td>📈 ADC1 CH3</td> </tr>
  <tr> <td align="right">ADC1 CH5 📈</td> <td align="right">IO33 ↔️</td> <td>⬅️ IO36 (in only)</td> <td>📈 ADC1 CH0</td> </tr>
  <tr> <td></td> <td align="right">IO5 ↔️</td> <td>↔️ IO15</td> <td>📉 ADC2 CH3</td> </tr>
  <tr> <td></td> <td align="right">IO17 ↔️</td> <td>↔️ IO14</td> <td>📉 ADC2 CH6</td> </tr>
  <tr> <td></td> <td align="right">GND ⏚</td> <td>▶️ IO12</td> <td>⚠️ must float at boot</td> </tr>
  <tr> <td></td> <td align="right">3.3V ⚡</td> <td>⬅️ IO35 (in only)</td> <td>📈 ADC1 CH7</td> </tr>
  <tr> <td></td> <td align="right">GND ⏚</td> <td>↔️ IO4</td> <td>📉 ADC2 CH0</td> </tr>
  <tr> <td></td> <td align="right">5V ⚡</td> <td>▶️ IO2</td> <td>⚠️ must float to program</td> </tr>
  <tr> <td align="right">ethernet link light</td> <td align="right">LINK 🖧</td> <td>⏚ GND</td> <td></td> </tr>
</table>
<br>
⭕ - Not recommended for application use<br>
▶️ - Recommended output only (avoid driving externally)<br>
⬅️ - Input only<br>
↔️ - General purpose I/O<br>
📈 - Analog input on ADC1<br> 
📉 - Analog input on ADC2 (conflicts with wi-fi)<br>
</details>
</div>
<div align="center">
<details>
<summary><H3>PINs</H3></summary>
<p>Các chân được đánh dấu màu xanh lá 🟢 đều có thể sử dụng được. Những chân được đánh dấu màu vàng 🟡 có thể sử dụng được nhưng cần chú ý vì chúng có thể có những hành vi không mong muốn, chủ yếu là khi khởi động. Các chân được đánh dấu màu đỏ 🔴 không được khuyến nghị sử dụng làm đầu vào hoặc đầu ra.</p>
<div align="center">
  
| GPIO | Input | Output | Notes |
|------|-------|--------|-------|
| 0    | 🟡pulled up | 🟡OK | outputs PWM signal at boot |
| 1    | 🔴TX Pin | 🟡OK | debug output at boot |
| 2    | 🟢OK | 🟢OK | connected to on-board LED |
| 3    | 🟡OK | 🔴RX Pin | HIGH at boot |
| 4    | 🟢OK | 🟢OK | |
| 5    | 🟢OK | 🟢OK | outputs PWM signal at boot |
| 6    | 🔴X | 🔴X | connected to the integrated SPI flash |
| 7    | 🔴X | 🔴X | connected to the integrated SPI flash |
| 8    | 🔴X | 🔴X | connected to the integrated SPI flash |
| 9    | 🔴X | 🔴X | connected to the integrated SPI flash |
| 10   | 🔴X | 🔴X | connected to the integrated SPI flash |
| 11   | 🔴X | 🔴X | connected to the integrated SPI flash |
| 12   | 🟡OK | 🟢OK | |
| 13   | 🟢OK | 🟢OK | outputs PWM signal at boot |
| 14   | 🟢OK | 🟢OK | outputs PWM signal at boot |
| 15   | 🟢OK | 🟢OK | |
| 16   | 🟢OK | 🟢OK | |
| 17   | 🟢OK | 🟢OK | |
| 18   | 🟢OK | 🟢OK | |
| 19   | 🟢OK | 🟢OK | |
| 20   | 🟢OK | 🟢OK | |
| 21   | 🟢OK | 🟢OK | |
| 22   | 🟢OK | 🟢OK | |
| 23   | 🟢OK | 🟢OK | |
| 24   | 🟢OK | 🟢OK | |
| 25   | 🟢OK | 🟢OK | |
| 26   | 🟢OK | 🟢OK | |
| 27   | 🟢OK | 🟢OK | |
| 28   | 🟢OK | 🟢OK | |
| 29   | 🟢OK | 🟢OK | |
| 30   | 🟢OK | 🟢OK | |
| 31   | 🟢OK | 🟢OK | |
| 32   | 🟢OK | 🟢OK | |
| 33   | 🟢OK | 🟢OK | |
| 34   | 🟢OK | | input only |
| 35   | 🟢OK | | input only |
| 36   | 🟢OK | | input only |
| 37   | 🟢OK | | input only |
| 38   | 🟢OK | | input only |
| 39   | 🟢OK | | input only |
</div>
</details>
</div>

<div>
<details>
<summary align="center"><H2>Cấu hình của ESP32</H2></summary>

<div align="center"><img src="https://lh3.googleusercontent.com/d/13yoyKC0Cftfv0dBHas6GjydJU8FkmERA=w1920?authuser=1"  /></div>

###

<H2>CPU:</H2>
<p>  -CPU: Xtensa Dual-Core LX6 microprocessor.<br>
  -Chạy hệ 32 bit<br>
  -Tốc độ xử lý từ 160 MHz đến 240 MHz<br>
  -ROM: 448 Kb<br>
  -Tốc độ xung nhịp từ 40 Mhz ÷ 80 Mhz (có thể tùy chỉnh khi lập trình)<br>
  -RAM: 520 Kb SRAM liền chip. Trong đó 8 Kb RAM RTC tốc độ cao – 8 Kb RAM RTC tốc độ thấp (dùng ở chế độ DeepSleep).</p>

###

<H2>Hỗ trợ 2 giao tiếp không dây</H2>
<p>  -Wi-Fi: 802.11 b/g/n/e/i<br>
  -Bluetooth: v4.2 BR/EDR và BLE</p>

###

<H2>Hỗ trợ tất cả các loại giao tiếp</H2>
<p>-2 bộ chuyển đổi số sang tương tự (DAC) 8 bit<br>
-18 kênh bộ chuyển đổi tương tự sang số (ADC) 12 bit.<br>
-2 cổng giao tiếp I²C<br>
-3 cổng giao tiếp UART<br>
-3 cổng giao tiếp SPI (1 cổng cho chip FLASH )<br>
-2 cổng giao tiếp I²S<br>
-10 kênh ngõ ra điều chế độ rộng xung (PWM)<br>
-SD card/SDIO/MMC host<br>
-Ethernet MAC hỗ trợ chuẩn: DMA và IEEE 1588<br>
-CAN bus 2.0<br>
-IR (TX/RX)</p>

###

<H2>Bảo mật</H2>
<p>-Hỗ trợ tất cả các tính năng bảo mật chuẩn IEEE 802.11, bao gồm WFA, WPA/WPA2 và WAPI<br>
-Khởi động an toàn (Secure boot)<br>
-Mã hóa flash (Flash encryption)<br>
-1024-bit OTP, lên đến 768-bit cho khách hàng<br>
-Tăng tốc phần cứng mật mã: AES, SHA-2, RSA, mật mã đường cong elliptic (ECC – elliptic curve cryptography), bộ tạo số ngẫu nhiên (RNG – random number generator)</p>

###

<H2>Nguồn điện hoạt động</H2>
<p>-Điện áp hoạt động: 2,2V => 3,6V<br>
-Nhiệt độ hoạt động: -40°C => + 85°C<br>
-Số cổng GPIO: 36
</p>

</details>
</div>

<div>
<details>
<summary align="center"><H2>Một số điều thú vị</H2></summary>
  
###
  
<H2>Cảm ứng điện dung GPIO (Capacitive touch)</H2>
<p>ESP32 có 10 cảm biến cảm ứng điện dung bên trong. Chúng có thể cảm nhận được sự biến đổi của bất cứ thứ gì mang điện tích, như da người. Vì vậy, họ có thể phát hiện các biến thể gây ra khi chạm vào GPIO bằng ngón tay. Những chân này có thể dễ dàng tích hợp vào các miếng đệm điện dung và thay thế các nút cơ. Các chân cảm ứng điện dung cũng có thể được sử dụng để đánh thức ESP32 khỏi trạng thái ngủ sâu.</p>

<p>Các cảm ứng điện dung được kết nối với các GPIO này:<br>
  - T0 (GPIO 4) <br>
  - T1 (GPIO 0)<br>
  - T2 (GPIO 2)<br>
  - T3 (GPIO 15)<br>
  - T4 (GPIO 13)<br>
  - T5 (GPIO 12)<br>
  - T6 (GPIO 14)<br>
  - T7 (GPIO 27)<br>
  - T8 (GPIO 33)<br>
  - T9 (GPIO 32)</p>

###

<H2>Cảm biến hiệu ứng Hall (Hall Effect Sensor)</H2>
<p>ESP32 cũng có cảm biến hiệu ứng Hall tích hợp để phát hiện những thay đổi của từ trường xung quanh nó.</p>

###

<H2>Ngắt (Interrupts)</H2>
<p>Tất cả GPIO có thể được cấu hình dưới dạng ngắt.</p>

###



</details>
</div>

<a href="https://docs.espressif.com/projects/esp-idf/en/stable/esp32/index.html">Tài liệu tham khảo</a>






