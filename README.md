
# NodeMCUPinger1306

A simple project for the ESP8266 (NodeMCU) that pings a target IP address and displays the result on a 128x64 OLED screen (SSD1306). Useful for network diagnostics or monitoring the availability of a specific host.

 

✨ Features
	•	Pings a configurable IP address (default: 8.8.8.8)
	•	Displays ping status and latency on an SSD1306 OLED screen
	•	Built with Arduino framework and the ESP8266WiFi library
	•	Lightweight and easy to customize

🛠 Hardware Required
	•	NodeMCU (ESP8266-based board)
	•	128x64 I2C OLED display (SSD1306)
	•	USB cable and power source
	•	WiFi network access

🔧 Setup & Installation
	1.	Clone the repository

git clone https://github.com/bar5um/NodeMCUPinger1306.git


	2.	Open the .ino file in the Arduino IDE.
	3.	Install required libraries via the Arduino Library Manager:
	•	ESP8266WiFi
	•	Adafruit GFX Library
	•	Adafruit SSD1306
	•	Ping
	4.	Configure your WiFi credentials in the sketch:

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";


	5.	Set the IP to ping (optional):

IPAddress targetIp(8, 8, 8, 8); // Change to your desired IP


	6.	Upload to your NodeMCU board and open the Serial Monitor for debug info.

📺 Display Output

The OLED screen shows:
	•	Current target IP
	•	Ping result: Success or Timeout
	•	Latency in milliseconds

🔄 Customization

You can modify:
	•	The target IP address
	•	The refresh rate
	•	Display text and format

📄 License

MIT License. Feel free to modify and use it in your own projects.