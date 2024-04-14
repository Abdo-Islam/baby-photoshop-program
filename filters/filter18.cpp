#include <iostream>
#include <cmath>
#include "Image_Class.h"
#define PI 3.141592654
using namespace std; 

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
  float ang; 
  cout << "please enter the degree you want to skew the photo by (from 0 to 90) : "; 
  cin >> ang; 
  float slope = tan((ang / 180.0) * PI);
  Image photo1(photo.width + photo.height * cos(ang / 180.0 * PI),photo.height * sin(ang / 180.0 * PI)); 
  for (int i = 0; i < photo1.width; i++)
  {
    for (int j = 0; j < photo1.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        if (j < slope * i && j > slope * (i - photo.width))
        {
          photo1(i,j,k) = photo(i - (j / slope),j * photo.height / photo1.height,k) ;
        }
        else 
        {
          photo1(i,j,k) = 255;
        }
      }
    }
  }
  Image photo2(photo1.width,photo1.height);
  for (int i = 0; i < photo1.width; i++)
  {
    for (int j = 0; j < photo1.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        photo2(photo1.width-i-1,j,k) = photo1(i,j,k); 
      }
    } 
  }
  cout << "please enter a name of the new photo with it's extention : ";
  cin >> name; 
  while (true)
  {
    try 
    {
      photo2.saveImage(name);
      break;
    } catch (invalid_argument) {
      cout << "please enter a name with a valid extention : ";
      cin >> name;
    }
  }
  return 0;
}