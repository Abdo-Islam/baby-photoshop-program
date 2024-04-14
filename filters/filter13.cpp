#include <iostream>
#include "Image_Class.h"
using namespace std; 

Image sunlight(Image photo);

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
      if (photo(i,j,0) + 50 > 255) photo(i,j,0) = 255;
      else photo(i,j,0) += 50;
      if (photo(i,j,1) + 50 > 255) photo(i,j,1) = 255;
      else photo(i,j,1) += 50;
    }
  }
  cout << "please enter a name of the new photo with it's extention : ";
  cin >> name; 
  while (true)
  {
    try 
    {
      photo.saveImage(name);
      break;
    } catch (invalid_argument) {
        cout << "please enter a name with a valid extention : ";
        cin >> name;
    }
  }
  return 0; 
}

Image sunlight(Image photo)
{
  for (int i = 0; i < photo.width; i++)
  {
    for (int j = 0; j < photo.height; j++)
    {
      if (photo(i,j,0) + 50 > 255) photo(i,j,0) = 255;
      else photo(i,j,0) += 50;
      if (photo(i,j,1) + 50 > 255) photo(i,j,1) = 255;
      else photo(i,j,1) += 50;
    }
  }
  return photo; 
}