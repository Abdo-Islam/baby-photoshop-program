#include <iostream>
#include <cmath>
#include "Image_Class.h"
using namespace std; 

Image detect_edges(Image photo);

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
      cout << "please enter a valid name ot path : ";
      cin >> name; 
    }
  }
  for (int i = 0; i < photo.width; i++)
  {
    for (int j = 0; j < photo.height; j++)
    {
      unsigned int avg = 0;
      for (int k = 0; k < photo.channels; k++)
      {
        avg += photo(i,j,k);
      }
      avg /= 3;
      for (int k = 0; k < 3; k++)
      {
        photo(i,j,k) = avg; 
      }
    }
  }
  Image photo1(photo.width,photo.height); 
  for (int i = 1; i < photo.width-1; i += 1)
  {
    for (int j = 1; j < photo.height-1; j += 1)
    {
      if (abs(photo(i-1,j,0) - photo(i+1,j,0)) > 50) photo1(i,j,0) = photo1(i,j,1) = photo1(i,j,2) = 0;
      else if (abs(photo(i,j-1,0) - photo(i,j+1,0)) > 50) photo1(i,j,0) = photo1(i,j,1) = photo1(i,j,2) = 0;
      else photo1(i,j,0) = photo1(i,j,1) = photo1(i,j,2) = 255;
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

Image detect_edges(Image photo)
{
  for (int i = 0; i < photo.width; i++)
  {
    for (int j = 0; j < photo.height; j++)
    {
      unsigned int avg = 0;
      for (int k = 0; k < photo.channels; k++)
      {
        avg += photo(i,j,k);
      }
      avg /= 3;
      for (int k = 0; k < 3; k++)
      {
        photo(i,j,k) = avg; 
      }
    }
  }
  Image photo1(photo.width,photo.height); 
  for (int i = 1; i < photo.width-1; i += 1)
  {
    for (int j = 1; j < photo.height-1; j += 1)
    {
      if (abs(photo(i-1,j,0) - photo(i+1,j,0)) > 50) photo1(i,j,0) = photo1(i,j,1) = photo1(i,j,2) = 0;
      else if (abs(photo(i,j-1,0) - photo(i,j+1,0)) > 50) photo1(i,j,0) = photo1(i,j,1) = photo1(i,j,2) = 0;
      else photo1(i,j,0) = photo1(i,j,1) = photo1(i,j,2) = 255;
    }
  }
  return photo1; 
}