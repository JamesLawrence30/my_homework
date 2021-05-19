/*
	Author: James Lawrence
*/

#include <utility>

using namespace std;


class Grid3D {
private:
  bool* grid;
  int XSIZE, YSIZE, ZSIZE; 
public:
	Grid3D(int x, int y, int z) : XSIZE(x), YSIZE(y), ZSIZE(z) {
		grid = new bool[XSIZE*YSIZE*ZSIZE];

		for (int i = 0; i < XSIZE*YSIZE*ZSIZE; i++)
			grid[i] = false;
	}

	~Grid3D() {
		delete [] grid;
	}

	void set(int x, int y, int z) { grid[z * (XSIZE*YSIZE) + y * (XSIZE) + z] = true; }

	Grid3D(const Grid3D& orig) : XSIZE(orig.XSIZE), YSIZE(orig.YSIZE), ZSIZE(orig.ZSIZE) {
		for (int i = 0; i < XSIZE*YSIZE*ZSIZE; i++)
			grid[i] = orig.grid[i];
	}

	Grid3D& operator =(Grid3D copy) {
		XSIZE = copy.XSIZE;
		YSIZE = copy.YSIZE;
		ZSIZE = copy.ZSIZE;
		swap(grid, copy.grid);
		return *this;
	}

	Grid3D(Grid3D&& orig) : XSIZE(orig.XSIZE), YSIZE(orig.YSIZE), ZSIZE(orig.ZSIZE), grid(orig.grid) {
		orig.grid = nullptr;
	}
};
	
Grid3D f() {
	return Grid3D(2,3,4);
}

int main() {
  Grid3D g(100, 100, 200); // Create a grid size 100 x 200 x 300 voxels.

  for (int x = 0; x < 10; x++)
    for (int y = 0; y < 10; y++)
      g.set(x,y,0); // create a flat plate (10x10)

  Grid3D g2(g); // make a copy
  Grid3D g3 = g; // make a copy

  g2.set(1,2,3);

  g3 = g2;
  Grid3D g4 = f(); //
}