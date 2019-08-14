/** @module wifi-test
 *  @since 2019.08.14, 21:42
 *  @changed 2019.08.14, 21:42
 */

#include <M5Stack.h>
#include <WiFi.h>

#define DARK_GRAY_COLOR 0x7bef

// #include "Module.h"
// Module module;

extern unsigned char timer_logo[];
extern unsigned char insertsd_logo[];
extern unsigned char error_logo[];
// extern unsigned char wifi_logo[];
extern unsigned char wifi60w[];
extern unsigned char views_logo[];

WiFiServer server(80);

// bool useAutoNetworkConfig = true;
// IPAddress networkIp(192, 168, 0, 19);
// IPAddress networkGateway(192, 168, 0, 1);
// IPAddress networkSubnet(255, 255, 255, 0);

// cppcheck-suppress unusedFunction
void setup() {

  M5.begin();

  Serial.begin(9600);
  Serial.println("Start");

  // int testResult = module.test();
  // Serial.println("DEBUG: " + String(testResult));

  M5.Lcd.setBrightness(10);

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  // M5.Lcd.drawBitmap(30, 75, 59, 59, reinterpret_cast<uint16_t *>(timer_logo));
  M5.Lcd.drawBitmap(30, 75, 59, 59, (uint16_t *)timer_logo);
  M5.Lcd.setCursor(110, 90);
  Serial.println("Staring...");
  M5.Lcd.setCursor(110, 110);
  M5.Lcd.print("Wait a moment");

  if (!SD.begin()) {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawBitmap(50, 70, 62, 115, (uint16_t *)insertsd_logo);
    // M5.Lcd.drawBitmap(50, 70, 62, 115, reinterpret_cast<uint16_t *>(insertsd_logo));
    M5.Lcd.setCursor(130, 70);
    M5.Lcd.print("INSERT");
    M5.Lcd.setCursor(130, 90);
    M5.Lcd.print("THE TF-CARD");
    M5.Lcd.setCursor(130, 110);
    M5.Lcd.print("AND TAP");
    M5.Lcd.setCursor(130, 130);
    M5.Lcd.setTextColor(0xe8e4);
    M5.Lcd.print("POWER");
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.print(" BUTTON");
    while (true) {}
  }
  else if (!configWifi()) {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawBitmap(30, 75, 59, 59, (uint16_t *)error_logo);
    M5.Lcd.setCursor(110, 70);
    M5.Lcd.print("CHECK YOUR");
    M5.Lcd.setCursor(110, 90);
    M5.Lcd.print("WI-FI SETTINGS");
    M5.Lcd.setCursor(110, 110);
    M5.Lcd.print("AND TAP");
    M5.Lcd.setCursor(110, 130);
    M5.Lcd.setTextColor(0xe8e4);
    M5.Lcd.print("POWER");
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.print(" BUTTON");
    while (true) {}
  }
  else {
    String localIP = WiFi.localIP().toString();
    Serial.println("WiFi local ip: " + localIP);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawBitmap(40, 80, 60, 60, (uint16_t *)wifi60w);
    M5.Lcd.setCursor(130, 70);
    M5.Lcd.print("MARKDOWN");
    M5.Lcd.setCursor(130, 90);
    M5.Lcd.print("WEB SERVER");
    M5.Lcd.setCursor(130, 110);
    M5.Lcd.print("ON M5STACK");
    M5.Lcd.setCursor(130, 130);
    M5.Lcd.print(localIP);
    M5.Lcd.setCursor(130, 150);
    // Reset & draw views count
    saveViews(0, true);
    // drawViews();
    server.begin();
  }
}

String TFReadFile(String path) {
  File file = SD.open(strToChar(path));
  String buf = "";
  if (file) {
    while (file.available()) {
      buf += (char)file.read();
    }
    file.close();
  }
  return buf;
}

bool TFWriteFile(String path, String str) {
  File file = SD.open(strToChar(path), FILE_WRITE);
  if (file) {
    bool res = false;
    if (file.print(str)) res = true;
    return res;
  }
  file.close();
  return false;
}

char* strToChar(String str) {
  int len = str.length() + 1;
  char* buf = new char[len];
  strcpy(buf, str.c_str());
  return buf;
}

/** like a split JS
 * @param {int} idSeparator
 * @param {char} separator
 * @param {String} str
 * @return {String}
 */
String parseString(int idSeparator, char separator, String str) {
  String output = "";
  int separatorCout = 0;
  for (int i = 0; i < str.length(); i++) {
    if ((char)str[i] == separator) {
      separatorCout++;
    }
    else {
      if (separatorCout == idSeparator) {
        output += (char)str[i];
      }
      else if (separatorCout > idSeparator) {
        break;
      }
    }
  }
  return output;
}

int cntChrs(String str, char chr) {
  int cnt = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == chr) cnt++;
  }
  return cnt;
}

bool configWifi() {
  /* Get WiFi SSID & password from wifi.ini from TF-card */
  String file = TFReadFile("/system/wifi.ini");
  if (file != "") {
    for (int i = 0; i < cntChrs(file, '\n'); i++) {
      String wifi = parseString(i, '\n', file);
      Serial.println("Found wifi: " + wifi);
      // wifi = wifi.substring(0, (wifi.length() - 1)); // remove last char '\r'
      String ssid = parseString(0, '\t', wifi);
      String pswd = parseString(1, '\t', wifi);
      Serial.println("Found ssid: " + ssid);
      Serial.println("Found pswd: " + pswd);
      char* ssid_ = strToChar(ssid);
      char* pswd_ = strToChar(pswd);
      // bool useAutoNetworkConfig = true;
      // IPAddress networkIp(192, 168, 0, 14);
      // IPAddress networkGateway(192, 168, 0, 1);
      // IPAddress networkSubnet(255, 255, 255, 0);
      // WiFi.mode(WIFI_AP);
      // WiFi.softAP(ssid_, pswd_);
      // Serial.println("Network settings:\n\tnetworkIp: " + networkIp.toString() + "\n\tnetworkGateway: " + networkGateway.toString() + "\n\tnetworkSubnet: " + networkSubnet.toString());
      // WiFi.softAPConfig(networkIp, networkGateway, networkSubnet);
      if (WiFi.begin(ssid_, pswd_)) {
      // if (WiFi.begin()) {
        Serial.println("WiFi.begin: Ok");
        delay(10);
        unsigned long timeoutMs = 10000;
        unsigned long prevMs = millis();
        while (true) {
          unsigned long currMs = millis();
          unsigned long diffMs = currMs - prevMs;
          if (diffMs > timeoutMs) {
            Serial.println("WiFi.begin: wait " + String(diffMs));
            break;
          }
          if (WiFi.status() == WL_CONNECTED) {
            Serial.println("WiFi: Connected");
            return true;
          }
          delay(100);
        }
      }
    }
  }
  Serial.println("WiFi: Failed");
  return false;
}

String parseGET(String str) {
  String tmp = "";
  for (int i = 0, j = 0; i < str.length(); i++) {
    if (str[i] == ' ') j++;
    if (j == 1) {
      if (str[i] != ' ') {
        tmp += str[i];
      }
    }
    if (j == 2) {
      break;
    }
  }
  return tmp;  // tmp.substring(1)
}

/* // UNUSED openPage
 * String openPage(String page) {
 *   page += ".md";
 *   String content = TFReadFile(page);
 *   if (content != "") {
 *     // Increment & show views count
 *     increaseViews(true);
 *     // drawViews();
 *     return content;
 *   }
 *   return "# 404 NOT FOUND #\n### MARKDOWN WEB SERVER ON M5STACK  ###";  // if not found 404
 * }
 */

int getViews() {
  String file = TFReadFile("/system/views");
  if (file != "") {
    return file.toInt();
  }
  return 0;
}

bool saveViews(int views, bool draw) {
  if (draw) {
    drawViews(views);
  }
  Serial.println("Views: " + String(views));
  if (TFWriteFile("/system/views", (String)(views))) {
    return true;
  }
  return false;
}

bool increaseViews(bool draw) {
  int views = getViews() + 1;
  saveViews(views, draw);
}

void drawViews(int views) {
  // int views = getViews();
  if (views != -1) {
    M5.Lcd.fillRect(5, 185, 315, 60, BLACK);
    M5.Lcd.drawBitmap(5, 185, 59, 59, (uint16_t *)views_logo);
    M5.Lcd.setCursor(75, 205);
    M5.Lcd.print(views);
  }
}

// cppcheck-suppress unusedFunction
void loop() {
  String currentString = "";
  bool readyResponse = false;
  WiFiClient client = server.available();
  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      if ((c != '\r') && (c != '\n')) {
        currentString += c;
      }
      else {
        readyResponse = true;
      }

      if (readyResponse) {
        Serial.println("Request: " + currentString);
        String GET = parseGET(currentString);
        Serial.println("GET: " + GET);
        // String mdContent = openPage(GET);
        // Serial.println("mdContent: " + mdContent);
        client.println("HTTP/1.1 200 OK");
        client.println("Content-type: text/plain");
        client.println();
        client.println("OK GET " + GET);
        // client.println("HTTP/1.1 200 OK");
        // client.println("Content-type:text/html");
        // client.println();
        // client.println("<html>");
        // client.println("<head>");
        // client.println("<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\"/>");
        // client.println("<title>Markdown page | M5STACK</title>");
        // // client.println("<link rel=\"icon\" type=\"image/x-icon\" href=\"http://m5stack.com/favicon.ico\">");
        // // client.println("<script type=\"text/javascript\">" + TFReadFile("/system/markdown.js") + "</script>");
        // // client.println("<style type=\"text/css\">" + TFReadFile("/system/style.css") + "</style>");
        // client.println("</head>");
        // client.println("<body>");
        // client.println("<h1>OK</h1>");
        // // client.println("<article></article>");
        // // client.println("<script type=\"text/javascript\">");
        // // client.println("const message = `" + mdContent + "`;");
        // // client.println("const article = document.querySelector('article');");
        // // client.println("article.innerHTML = markdown.toHTML(message);");
        // // client.println("</script>");
        // client.println("</body>");
        // client.print("</html>");
        // client.println();
        client.println();
        readyResponse = false;
        currentString = "";
        client.flush();
        client.stop();
        // Increment & show views count
        increaseViews(true);
      }
    }
  }
}
