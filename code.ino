#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <DHT.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int ledPin = 2;
AsyncWebServer server(80);

const char controlPanelHTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>ESP32 Control Panel</title>
  <script>
    function toggleLED(state) {
      var xhr = new XMLHttpRequest();
      xhr.open("GET", "/led?state=" + state, true);
      xhr.send();
    }

    function updateData() {
      setInterval(function() {
        fetch('/temperature')
          .then(response => response.text())
          .then(data => {
            document.getElementById('temp').innerHTML = data + ' °C';
          });

        fetch('/humidity')
          .then(response => response.text())
          .then(data => {
            document.getElementById('humidity').innerHTML = data + ' %';
          });
      }, 2000);
    }
  </script>
</head>
<body onload="updateData()">
  <h1>ESP32 Control Panel</h1>
  <button onclick="toggleLED('on')">Turn LED On</button>
  <button onclick="toggleLED('off')">Turn LED Off</button>
  <h2>Temperature: <span id="temp">--</span></h2>
  <h2>Humidity: <span id="humidity">--</span></h2>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  dht.begin();
  pinMode(ledPin, OUTPUT);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send_P(200, "text/html", controlPanelHTML);
  });

  server.on("/led", HTTP_GET, [](AsyncWebServerRequest* request) {
    String state = request->getParam("state")->value();
    if (state == "on") {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
    request->send(200, "text/plain", "OK");
  });

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest* request) {
    float temp = dht.readTemperature();
    request->send(200, "text/plain", String(temp));
  });

  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest* request) {
    float humidity = dht.readHumidity();
    request->send(200, "text/plain", String(humidity));
  });

  server.begin();
}

void loop() {}
