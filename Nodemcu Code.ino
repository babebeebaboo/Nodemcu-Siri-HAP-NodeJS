#include <ESP8266WiFi.h>
const char* ssid = "WongsawaWifi's Wireless"; 
const char* password = "Pass"; 
const int port = 12345;
WiFiServer server(port); 

int pin = D1;
String line;

void Connect_WIFI()
{
  delay(10);
  Serial.println("");
  Serial.print("Connecting to :"); 
  Serial.println(ssid); 
 
  WiFi.begin(ssid, password); 
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print("*");
  }

 IPAddress local_ip = {192, 168, 1, 40}; //ฟิกค่า IP
  IPAddress gateway = {192, 168, 1, 1}; //ตั้งค่า IP Gateway
  IPAddress subnet = {255, 255, 255, 0}; //ตั้งค่า Subnet
  WiFi.config(local_ip, gateway, subnet); //setค่าไปยังโมดูล
 
  Serial.println("");
  Serial.println("WiFi connected"); 
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); 
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
  Serial.print("Port: ");
  Serial.println(port);


}
void setup() {
  pinMode(pin, OUTPUT);
  
  Serial.begin(9600); 
 
  Connect_WIFI();
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) 
  {
    return; 
  }

  Serial.println("New client"); 
  
  while (client.connected()) 
  { 
    if (client.available()) 
    {
      char c = client.read();
      if(c == '1')
      {
        digitalWrite(pin, HIGH);
        Serial.println("OPEN");
      }
      else 
      {
         digitalWrite(pin, LOW);
          Serial.println("CLOSE");
      }
      break;
    }
  }
  delay(1);
  client.stop(); // ปิดการเชื่อมต่อกับ Client
  Serial.println("Client disconnect"); // ส่งข้อความว่า Client disconnect ไปที่ Serial Monitor
}
