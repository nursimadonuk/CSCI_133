#include "funcs.h"
#include <iostream>
// Provided functions

using namespace std;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width) {
  char c;
  int x;
  ifstream instr;
  instr.open(filename);
  // read the header P2
  instr >> c;
  assert(c == 'P');
  instr >> c;
  assert(c == '2');
  // skip the comments (if any)
  while ((instr>>ws).peek() == '#') {
    instr.ignore(4096, '\n');
  }
  instr >> width;
  instr >> height;
  assert(width <= MAX_W);
  assert(height <= MAX_H);
  int max;
  instr >> max;
  assert(max == 255);
  for (int row = 0; row < height; row++)
    for (int col = 0; col < width; col++)
      instr >> image[row][col];
  instr.close();
  return;
}
// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(std::string filename,int image[MAX_H][MAX_W], int height, int width) {
  ofstream ostr;
  ostr.open(filename);
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };
  // print the header
  ostr << "P2" << endl;
  // width, height
  ostr << width << ' ';
  ostr << height << endl;
  ostr << 255 << endl;
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      assert(image[row][col] < 256);
      assert(image[row][col] >= 0);
      ostr << image[row][col] << ' ';
      ostr << endl;
    }
  }
  ostr.close();
  return;
}
// Write all your functions in here

void invert(int image[MAX_H][MAX_W], int height, int width) {
  for(int row = 0; row < height; row++) {
    for(int column = 0; column < width; column++) {
      image[row][column] = 255 - image[row][column];
    }
  }
}



void invert_half(int image[MAX_H][MAX_W], int height, int width) {
  int half = width/2;
  for(int row = 0; row < height; row++) {
    for(int column = half; column < width; column++) {
      image[row][column] = 255 - image[row][column];
    }
  }
}

void box(int image[MAX_H][MAX_W], int height, int width) {
  int halfw = width/2;
  int halfh = height/2;
  for(int row = 0; row < height; row++) {
    for(int column = 0; column < width; column++) {
      if(row > halfh/2 && row < 3*halfh/2) {
        if(column > halfw/2 && column < 3*halfw/2) {
          image[row][column] = 255;
        }
      }else {
        image[row][column] = image[row][column];
      }
    }
  }
}

void frame(int image[MAX_H][MAX_W], int height, int width) {
  int quarw = width/4;
  int quarh = height/4;
  for(int row = 0; row < height; row++) {
    for(int column = 0; column < width; column++) {
      if(row == quarh && column > quarw && column < 3*quarw) {
        image[row][column] = 255;
      }else if(row == 3*quarh && column > quarw && column < 3*quarw) {
        image[row][column] = 255;
      }else if(column == quarw && row > quarh && row < 3*quarh) {
        image[row][column] = 255;
      }else if(column == 3*quarw && row > quarh && row < 3*quarh) {
        image[row][column] = 255;
      }
    }
  }
}

void scale(int image[MAX_H][MAX_W], int height, int width) {
  int copy[MAX_H][MAX_W];
  for(int row = 0; row < height; row++) {
    for(int col = 0; col < width; col++) {
      copy[row][col] = image[row][col];
    }
  }
  int r = 0, c = 0;
  for(int row = 0; row < height*2; row+=2) {
    for(int column = 0; column < width*2; column+=2) {
      int num = copy[r][c];
      image[row][column] = num;
      image[row+1][column] = num;
      image[row][column+1] = num;
      image[row+1][column+1] = num;
      c++;
    }
    r++;
    c = 0;
  }
}

void pixelate(int image[MAX_H][MAX_W], int height, int width) {
  for(int row = 0; row < height; row = row + 2) {
    for(int column = 0; column < width; column = column + 2) {
      int sum = image[row][column] + image[row+1][column] + image[row][column+1] + image[row+1][column+1];
      int aver = sum / 4;
      for(int i = row; i < row+2; i++) {
        for(int j = column; j < column+2; j++) {
          image[i][j] = aver;
        }
      }
    }
  }

}

void kernel(){

}
