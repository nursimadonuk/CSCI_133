#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"

int main(){
  int img[MAX_H][MAX_W];
  int h, w;
  readImage("test_image.pgm",img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data

  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array

  int out[MAX_H][MAX_W];


  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  invert(out, h, w);
  // and save this new image to file "outImage.pgm"
  writeImage("taska.pgm", out, h, w);

  int out2[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out2[row][col] = img[row][col];
    }
  }

  invert_half(out2, h, w);
  writeImage("taskb.pgm", out2, h, w);

  int out3[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out3[row][col] = img[row][col];
    }
  }
  box(out3, h, w);
  writeImage("taskc.pgm", out3, h, w);

  int out4[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out4[row][col] = img[row][col];
    }
  }
  frame(out4, h, w);
  writeImage("taskd.pgm", out4, h, w);

  int out5[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out5[row][col] = img[row][col];
    }
  }
  scale(out5, h, w);
  writeImage("taske.pgm", out5, h*2, w*2);

  int out6[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out6[row][col] = img[row][col];
    }
  }
  pixelate(out6, h, w);
  writeImage("taskf.pgm", out6, h, w);

return 0;
}
