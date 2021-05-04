#include <iostream>
#include "libbmp.h"
#include <string.h>

using namespace std;

void generate_checkboard(int w=512, int h=512, string filename="checkboard.bmp")
{
	BmpImg img (w, h);
	
	// Draw a checkerboard pattern:
	// Use negative loops to improve performance
	for (int y = w-1, x; y >= 0; y--)
	{
		for (x = h-1; x >= 0; x--)
		{
			if ((y % 128 < 64 && x % 128 < 64) ||
			    (y % 128 >= 64 && x % 128 >= 64))
			{
				img.set_pixel (x, y, 0, 0, 255);
			}
		}
	}
	
	img.write (filename.c_str());
}

int main(){
    generate_checkboard(512,512,"checkboard.bmp");
    return 0;
}