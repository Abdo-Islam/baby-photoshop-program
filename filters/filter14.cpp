#include <iostream>
#include "Image_Class.h"
using namespace std;

Image oil_painting(Image photo);

int main()
{
  string name; 
  cout << "please enter the photo name and extention : ";
  getline(cin,name); 
  Image photo;  
  while (true)
  {
    try 
    {
      photo.loadNewImage(name); 
      break;
    } catch (invalid_argument) {
      cout << "please enter a valid name or path : ";
      cin >> name; 
    }
  }
  Image photo1(photo.width, photo.height);
  for (int i = 2; i < photo.width - 3; i++)
  {
    for (int j = 2; j < photo.height - 3; j++)
    {
      int colorr[256] = {0};
      int colorg[256] = {0};
      int colorb[256] = {0};
      for (int l = i - 2; l <= i + 2; l++)
      {
        for (int m = j - 2; m <= j + 2; m++)
        {
          colorr[photo(l, m, 0)]++;
          colorg[photo(l, m, 1)]++;
          colorb[photo(l, m, 2)]++;
        }
      }
      int maxCountR = 0, maxCountG = 0, maxCountB = 0;
      int maxIndexR = 0, maxIndexG = 0, maxIndexB = 0;
      for (int c = 0; c < 256; c++)
      {
        if (colorr[c] > maxCountR)
        {
          maxCountR = colorr[c];
          maxIndexR = c;
        }
        if (colorg[c] > maxCountG)
        {
          maxCountG = colorg[c];
          maxIndexG = c;
        }
        if (colorb[c] > maxCountB)
        {
          maxCountB = colorb[c];
          maxIndexB = c;
        }
      }
      photo1(i, j, 0) = maxIndexR;
      photo1(i, j, 1) = maxIndexG;
      photo1(i, j, 2) = maxIndexB;
    }
  }
  cout << "please enter a name of the new photo with it's extention : ";
  cin >> name; 
  while (true)
  {
    try 
    {
      photo1.saveImage(name);
      break;
    } catch (invalid_argument) {
      cout << "please enter a name with a valid extention : ";
      cin >> name;
    }
  }
    return 0;
}

Image oil_painting(Image photo)
{
  Image photo1(photo.width, photo.height);
  for (int i = 2; i < photo.width - 3; i++)
  {
    for (int j = 2; j < photo.height - 3; j++)
    {
      int colorr[256] = {0};
      int colorg[256] = {0};
      int colorb[256] = {0};
      for (int l = i - 2; l <= i + 2; l++)
      {
        for (int m = j - 2; m <= j + 2; m++)
        {
          colorr[photo(l, m, 0)]++;
          colorg[photo(l, m, 1)]++;
          colorb[photo(l, m, 2)]++;
        }
      }
      int maxCountR = 0, maxCountG = 0, maxCountB = 0;
      int maxIndexR = 0, maxIndexG = 0, maxIndexB = 0;
      for (int c = 0; c < 256; c++)
      {
        if (colorr[c] > maxCountR)
        {
          maxCountR = colorr[c];
          maxIndexR = c;
        }
        if (colorg[c] > maxCountG)
        {
          maxCountG = colorg[c];
          maxIndexG = c;
        }
        if (colorb[c] > maxCountB)
        {
          maxCountB = colorb[c];
          maxIndexB = c;
        }
      }
      photo1(i, j, 0) = maxIndexR;
      photo1(i, j, 1) = maxIndexG;
      photo1(i, j, 2) = maxIndexB;
    }
  }
  return photo1; 
}