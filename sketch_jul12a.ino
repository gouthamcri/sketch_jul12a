//WE NEED TO INCLUDE 3 HEADER FILE
#include<ESP8266WiFi.h>//it is used for all wifi related functionalities like connection.
#include<WiFiClient.h>//this file is required to send request to web browser
#include<ESP8266WebServer.h>//handles http protocol
const char* ssid="Airtel-MW40-9568";
const char* password="73760680";
ESP8266WebServer server(80);//web server is on port 80 ** u may change ** not capital S .
const char MAIN_page[] PROGMEM = R"=====(
<html>
<head>
<title>
LED ON OFF
</title>
</head>
<body>
<center>
<h1>LED ON OFF DEMO</h1>
Click to turn <a href="ledon" target="myIframe">LED ON</a><br>
Click to turn <a href="ledoff" target="myIframe">LED OFF</a><br>
LED_State:<iframe name="myIframe" width="100" height="25">
</body>
</html>
)=====";
//write ur html code inside u can even add styling and image if u want.
void handleRoot(){
  String s=MAIN_page;
  server.send(200,"text/html",s);//this will be displayed when user enters the IP address assigned by ESP8266
  }
  void handleledon(){  //u may give any name
    digitalWrite(2,HIGH);
    server.send(200,"text/html","LED ON");
    }
    void handleledoff(){
    digitalWrite(2,LOW);
    server.send(200,"text/html","LED OFF");
    
      }
 
void setup() {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  WiFi.begin(ssid,password);//start connection
  while(WiFi.status()!=WL_CONNECTED){ // again here small s
    delay(500);
    Serial.print(".");//it will print ... until successful connection is established
    }
    Serial.print("successfully connected to");
    Serial.println(WiFi.localIP());//it will print ip address assigned by ESP8266
    server.on("/",handleRoot);//when client request a webpage by entering ip address provided by ESP8266 which data to sent is handled by a subrotine and that is defined as **server.on(path,subroutine_name)**
    //ok now lets go back to handleRoot method
    server.on("/ledon",handleledon);
     server.on("/ledoff",handleledoff);
server.begin();
}

void loop() {
 
server.handleClient();//handle client request.
//now lets open our browser.
//before that compile ur code....
//here we are having an error ..,its saying server not defined ..lets fix that 
}
