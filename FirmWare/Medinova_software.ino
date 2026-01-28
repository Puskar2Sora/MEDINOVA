#include <ESP8266WiFi.h>

const char* ssid = "YourWiFiName";
const char* password = "YourWiFiPassword";

#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Connect to WiFi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("Car IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = client.readStringUntil('\r');
  client.flush();

  if (request.indexOf("/F") != -1) forward();
  else if (request.indexOf("/B") != -1) backward();
  else if (request.indexOf("/L") != -1) left();
  else if (request.indexOf("/R") != -1) right();
  else if (request.indexOf("/S") != -1) stop();

  // Web remote interface
  String html = R"rawliteral(
<html>
<head>
<title>WiFi Car Remote</title>
<style>
button {width:80px;height:80px;font-size:20px;margin:5px;}
.container {text-align:center;margin-top:50px;}
</style>
</head>
<body>
<div class="container">
<h2>WiFi Car Remote</h2><br>
<a href="/F"><button>↑ Forward</button></a><br>
<a href="/L"><button>← Left</button></a>
<a href="/S"><button>■ Stop</button></a>
<a href="/R"><button>→ Right</button></a><br>
<a href="/B"><button>↓ Backward</button></a>
</div>
</body>
</html>
)rawliteral";

  client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
  client.print(html);
}

// Motor control functions
void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}
void backward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}
void left() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);  // Left wheel backward
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);  // Right wheel forward
}
void right() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);  // Left wheel forward
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);  // Right wheel backward
}
void stop() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}