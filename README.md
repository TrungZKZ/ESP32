<H1 align="center">ESP32</H1>

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
