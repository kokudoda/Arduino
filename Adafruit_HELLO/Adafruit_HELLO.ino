#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    for(;;); // 初期化失敗なら停止
  }
  display.clearDisplay();

  // 文字スタイル設定
  display.setTextSize(3);               // 文字サイズ（1が標準、3なら3倍）
  display.setTextColor(SSD1306_WHITE);  // 白で描画
  display.setCursor(10, 20);            // 表示位置 (x=30, y=20)
  display.println(F("HELLO"));             // Hiを表示

  display.display(); // 画面更新
}

void loop() {
  
}







