#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define GRID_SIZE 8       // 8x8 の盤面
int grid[GRID_SIZE][GRID_SIZE];
int nextGrid[GRID_SIZE][GRID_SIZE];

// 初期配置（ブリンカー：3セル横並び）
void initGrid() {
  for (int y = 0; y < GRID_SIZE; y++) {
    for (int x = 0; x < GRID_SIZE; x++) {
      grid[y][x] = 0;
    }
  }
  grid[3][2] = 1;
  grid[3][3] = 1;
  grid[3][4] = 1; 
}



// 隣接セルを数える
int countNeighbors(int x, int y) {
  int count = 0;
  for (int dy = -1; dy <= 1; dy++) { //xの相対座標
    for (int dx = -1; dx <= 1; dx++) { //yの相対座標
      if (dx == 0 && dy == 0) continue;
      int nx = x + dx;
      int ny = y + dy;
      if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE) {
        count += grid[ny][nx];
      }
    }
  }
  return count;
}

// 次の世代を計算
void updateGrid() {
  for (int y = 0; y < GRID_SIZE; y++) {
    for (int x = 0; x < GRID_SIZE; x++) {
      int neighbors = countNeighbors(x, y);
      if (grid[y][x] == 1) {
        nextGrid[y][x] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
      } else {
        nextGrid[y][x] = (neighbors == 3) ? 1 : 0;
      }
    }
  }
  // コピー
  for (int y = 0; y < GRID_SIZE; y++) {
    for (int x = 0; x < GRID_SIZE; x++) {
      grid[y][x] = nextGrid[y][x];
    }
  }
}

// 盤面をOLEDに描画
void drawGrid() {
  display.clearDisplay();
  int cellSize = 6; // セルを拡大表示
  for (int y = 0; y < GRID_SIZE; y++) {
    for (int x = 0; x < GRID_SIZE; x++) {
      if (grid[y][x] == 1) {
        display.fillRect(x * cellSize, y * cellSize, cellSize, cellSize, SSD1306_WHITE);
      }
    }
  }
  display.display();
}

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for (;;); // 初期化失敗時は停止
  }
  initGrid();
}

void loop() {
  drawGrid();
  delay(500);   // 世代の切り替え速度（調整可能）
  updateGrid();
}