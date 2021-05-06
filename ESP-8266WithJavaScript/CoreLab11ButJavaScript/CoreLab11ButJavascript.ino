  /*  Rick Ramirez
 * 
 * The following code was adapted from https://github.com/acrobotic/Ai_Demos_ESP8266
 * Looked around and found examples of what I needed
 * WebSocket seemed the be the easiest to implement and has room to add more features
 * 
 * Links to download LittleFS:
 * https://github.com/esp8266/Arduino/blob/master/doc/filesystem.rst
 * https://github.com/earlephilhower/arduino-esp8266littlefs-plugin/releases
 * 
 * Link to Charts.js min
 * https://cdn.jsdelivr.net/npm/chart.js@2.9.4/dist/Chart.min.js
 */
// Using Wifi, Webserver, WebSocket, LittleFS (to upload a javascript libray), Ticker (a timer)
// An easier method would be connecting to wifi to download the library but the point of this lab was not to do that :^)
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include <LittleFS.h>
#include <Ticker.h>

// instantiate server object and Web Socket
ESP8266WebServer server;
WebSocketsServer webSocket = WebSocketsServer(81);

// define the network you are going to connect to
char* ssid = "BlueberryEyes";
char* password = "longpasswordsaregreat";


// declare a timer variable
Ticker timer;

// bool for data flag
bool read_data = false;
#include "html.h";

void setup(){
  LittleFS.begin(); // this is serving up Chart.js
  
  WiFi.softAP(ssid, password);
  Serial.begin(115200);
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // define the routes the server will use
  server.on("/",[](){server.send_P(200, "text/html", webpage);});
  server.on("/Chart.js", serveChartFile); // The route below assumes you have Chart.js downloaded into the NodeMCU's flash mem

  // Begin our processes 
  server.begin();
  webSocket.begin();
  
  // initialize timer function
  timer.attach(/*rate in secs*/ 0.1, /*function*/ readData);
  
  // not planning on receiving any data from the client but if we were:
  // webSocket.onEvent(webSocketEvent);
}

void readData() {
  // should only be used to set/unset flags
  read_data = true;
}

void serveChartFile(){
  // So using LittleFS we are going to stream the Charts.js file we prev uploaded to our NodeMCU
  // For in depth instructions....idk I mixed and matched a few different resources to get it to work
  // it's not hard tho
  File file = LittleFS.open("/Charts.js", "r");
  server.streamFile(file, "text/javascript");
  file.close();
}


void loop(){
  webSocket.loop();
  server.handleClient();
  if(read_data){
 // build the JSON-formatted string for sending over the websocket
 // in this case just read the pot value from A0
    String json = "{\"value\":";
    json += analogRead(A0);      
    json += "}";
    webSocket.broadcastTXT(json.c_str(), json.length());
    
//   reset the flag
    read_data = false;
  }
}
