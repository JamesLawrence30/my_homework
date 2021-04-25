/*
  Author: James Lawrence
  Cite: N/A
*/

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <cstdint> // uint32_t
// #include <iostream>

using namespace std;

/*
Dynamic memory bitmap homework

hex: base 16
0   0000
1   0001
2   0010
3   0011
4   0100
5   0101
6   0110
7   0111
8   1000
9   1001
A   1010
B   1011
C   1100
D   1101
E   1110
F   1111

row-major order
    0 1 2 3
    4 5 6 7
    8 9 ...
    
    https://github.com/nothings/stb/blob/master/stb_image_write.h
    our color format is RRGGBBAA  (red, green, blue, alpha = transparency)
*/

class Bitmap {
private:
  uint32_t w,h;
  uint32_t* pixel; // allocate an array of w*h elements
public:

	Bitmap(uint32_t _w, uint32_t _h, uint32_t color) : w(_w), h(_h) {
		pixel = new uint32_t[w*h];
		
		// Set entire bitmap to white
		for (int i = 0; i < w*h; i++)
			pixel[i] = color;
	}

	~Bitmap() {
		delete [] pixel;
		// cout << "deleted" << endl;
	}

  void set(uint32_t x, uint32_t y, uint32_t color) { // set color at x,y
    pixel[y * w + x] = color;
  }

  uint32_t& operator ()(uint32_t x, uint32_t y) { // return bitmap at x,y to be set in main
    return pixel[y * w + x];
  }

  uint32_t operator ()(uint32_t x, uint32_t y) const { // view only. not used.
    return pixel[y * w + x];
  }

  void horizLine(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
    // set(x, y, color); // more elegant inside class
    // (*this) (x,y  ) = color; // this object of x,y = color. less elegant inside class

  	for (int i = x1; i < x2; i++)
  		set(i, y, color);
  }

  void vertLine(uint32_t y1, uint32_t y2, uint32_t x, uint32_t color) {
  	for (int i = y1; i < y2; i++) {
  		set(x, i, color);
  	}
  }

  void rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color) {
    horizLine(x, x+w, y, color); // top
    horizLine(x, x+w, y-h, color); // bottom
    vertLine(y-h, y, x, color); // left
    vertLine(y-h, y, x+w, color); // right
  }

  void write(const char filename[]) {
     stbi_write_png(filename, w, h, 4, pixel, 4*w);
  }
};



int main() {
  Bitmap bm(640, 480,   0xFFFFFFFF); // set every pixel to be color 0
  bm.set(0,0, 0x80808000);
  bm(3,4) = 0x80808000;
  bm.horizLine(0, 500, 0, 0xFFFF0000); // x1= 0 x2= 500, y = 0 BLUE
  bm.vertLine(0, 100, 10, 0xFF0000FF); // y1 = 0 y2 = 100, x = 10 RED
  bm.rect(300,100, 50, 50, 0xFF00FF00); //x=300,y=100, w=50,h=50 GREEN
  bm.write("small.png");

  Bitmap bm2(1024, 1024, 0xFFFFFFFF); // set every pixel to be color 0
  bm2.horizLine(0, 500, 0, 0xFFFF0000); // x1= 0 x2= 500, y = 0 BLUE
  bm2.vertLine(0, 100, 10, 0xFF0000FF); // y1 = 0 y2 = 100, x = 10 RED
  bm2.rect(300,100, 50, 50, 0xFF00FF00);; //left=300,top=100, w=50,h=50 GREEN
  bm2.write("big.png");
}


// set colors for looping over x's for horiz and y's for vert
// constructor
// destructor