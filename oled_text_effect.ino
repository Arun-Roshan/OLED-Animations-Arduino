#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // Initialize the display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Infinite loop if OLED not detected
  }

  display.clearDisplay();
  display.display();
  delay(1000);
}

void loop() {
  // 1. Static Text
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Static Text");
  display.display();
  delay(2000);

  // 2. Large Text
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.println("Hello!");
  display.display();
  delay(2000);

  // 3. Inverted Text
  display.clearDisplay();
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Inverted
  display.setCursor(0, 30);
  display.setTextSize(1);
  display.println("Inverted Text");
  display.display();
  delay(2000);

  // 4. Scrolling Right
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("Scrolling Right -->");
  display.display();
  delay(500);
  display.startscrollright(0x00, 0x0F);
  delay(3000);
  display.stopscroll();

  // 5. Scrolling Left
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("<-- Scrolling Left");
  display.display();
  delay(500);
  display.startscrollleft(0x00, 0x0F);
  delay(3000);
  display.stopscroll();

  // 6. Diagonal Scroll
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("Diagonal Scroll");
  display.display();
  delay(500);
  display.startscrolldiagright(0x00, 0x07);
  delay(3000);
  display.stopscroll();

  // 7. Simulated Fade In & Out (by clearing and re-writing)
  display.clearDisplay();
  for (int size = 1; size <= 3; size++) {
    display.clearDisplay();
    display.setTextSize(size);
    display.setCursor(10, 25);
    display.setTextColor(SSD1306_WHITE);
    display.println("Fade In");
    display.display();
    delay(300);
  }
  for (int size = 3; size >= 1; size--) {
    display.clearDisplay();
    display.setTextSize(size);
    display.setCursor(10, 25);
    display.setTextColor(SSD1306_WHITE);
    display.println("Fade Out");
    display.display();
    delay(300);
  }

  // 8. Draw shapes and text together
  display.clearDisplay();
  display.drawRect(0, 0, 128, 64, SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(10, 25);
  display.setTextColor(SSD1306_WHITE);
  display.println("Boxed Text");
  display.display();
  delay(2000);
}
