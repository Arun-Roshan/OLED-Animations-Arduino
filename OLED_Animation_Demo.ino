#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  barAnimation();
  graphAnimation();
  eyeBlinkAnimation();
  progressCircle();
  bouncingBall();
}

// 1. Bar Animation (Growing Bars)
void barAnimation() {
  display.clearDisplay();
  for (int i = 0; i < SCREEN_WIDTH; i += 10) {
    int height = random(10, SCREEN_HEIGHT);
    display.fillRect(i, SCREEN_HEIGHT - height, 8, height, SSD1306_WHITE);
    display.display();
    delay(150);
  }
  delay(1000);
}

// 2. Line Graph Animation
void graphAnimation() {
  display.clearDisplay();
  int oldX = 0, oldY = random(10, 54);
  for (int x = 1; x < SCREEN_WIDTH; x++) {
    int y = random(10, 54);
    display.drawLine(oldX, oldY, x, y, SSD1306_WHITE);
    oldX = x;
    oldY = y;
    display.display();
    delay(20);
  }
  delay(1000);
}

// 3. Eye Blink Animation
void eyeBlinkAnimation() {
  for (int i = 0; i < 3; i++) {
    display.clearDisplay();
    // Open Eye
    display.drawCircle(64, 32, 20, SSD1306_WHITE);
    display.fillCircle(64, 32, 7, SSD1306_WHITE); // Pupil
    display.display();
    delay(500);
    // Blink
    display.clearDisplay();
    display.drawLine(44, 32, 84, 32, SSD1306_WHITE); // Line as closed eye
    display.display();
    delay(300);
  }
  delay(1000);
}

// 4. Circular Progress Animation
void progressCircle() {
  display.clearDisplay();
  int radius = 25;
  int cx = 64, cy = 32;
  for (int angle = 0; angle <= 360; angle += 10) {
    float rad = angle * 3.14 / 180;
    int x = cx + radius * cos(rad);
    int y = cy + radius * sin(rad);
    display.drawPixel(x, y, SSD1306_WHITE);
    display.display();
    delay(50);
  }
  delay(1000);
}

// 5. Bouncing Ball Animation
void bouncingBall() {
  int x = 10, y = 10;
  int dx = 2, dy = 2;
  for (int i = 0; i < 100; i++) {
    display.clearDisplay();
    display.fillCircle(x, y, 4, SSD1306_WHITE);
    display.display();
    x += dx;
    y += dy;
    if (x <= 0 || x >= SCREEN_WIDTH - 4) dx = -dx;
    if (y <= 0 || y >= SCREEN_HEIGHT - 4) dy = -dy;
    delay(30);
  }
}
