#include <Adafruit_NeoPixel.h>

extern "C" {
  #include <neighbor_counter.h>
  #include <grid.h>
  #include <rules.h>
  #include <neopixel_adapter.h>
  #include <render.h>
  #include <gameOfLife.h>
}

//#define IS_PIL -1
#define LED_PIN 6

uint32_t liveColor = Adafruit_NeoPixel::Color(0,0,255);
uint32_t deadColor = Adafruit_NeoPixel::Color(128,0,0);
const int numCols = 23;
const int numRows = 10;
char gridData[numRows][numCols];
struct Grid grid = (struct Grid){(char*)gridData, numRows, numCols};
Adafruit_NeoPixel strip;

void preDisplay();
void postDisplay();
void displayCell(struct Point point, char mark);
void endRow();

void xpreDisplay();
void xpostDisplay();
void xdisplayCell(struct Point point, char mark);
void xendRow();

void setup() {
  Serial.begin(9600);
  delay(analogRead(0));
  
  randomizeGrid(grid, analogRead(0));
  strip = Adafruit_NeoPixel(numRows * numCols, LED_PIN, NEO_GRB + NEO_KHZ800);
  strip.setBrightness(20);
  strip.begin();

  overridePreDisplay(xpreDisplay);
  overridePostDisplay(xpostDisplay);
  overrideDisplayCell(xdisplayCell);
  overrideEndRow(xendRow);
}

void loop() {
  display(grid);
  tick(grid);
  delay(1000);
}

//#ifdef IS_PIL
void preDisplay() {
  Serial.println("\n\n\n\n");  
  xpreDisplay();
}

void postDisplay() {
  xpostDisplay();
}

void displayCell(struct Point point, char mark) {
  if(mark == ' ') mark = '.';
  Serial.print(mark); 
  xdisplayCell(point, mark);
}

void endRow() {
  Serial.println("");  
  xendRow();
}

//#else

void xpreDisplay() {
}

void xpostDisplay() {
    strip.show();
}

void xdisplayCell(struct Point point, char mark) {
  int pixel = strandOffsetForPoint(grid, point);
  strip.setPixelColor(pixel, mark=='X' ? liveColor : deadColor);
}

void xendRow() {
}

//#endif
