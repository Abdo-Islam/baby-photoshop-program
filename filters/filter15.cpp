#include <iostream>
#include "Image_Class.h"
using namespace std; 

Image TV_effect(Image photo);

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
  for (int i = 0; i < photo.width; i++)
  {
    for (int j = 0; j < photo.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        if (j % 2 == 0) 
        {
          unsigned int temp = photo(i,j,k);
          temp = (photo(i,j,k)) * 1.5; 
          if (temp > 255) temp = 255; 
          photo(i,j,k) = temp;
        } 
        else 
        {
          unsigned int temp = photo(i,j,k);
          temp = (photo(i,j,k)) / 1.5; 
          if (temp < 0) temp = 0; 
          photo(i,j,k) = temp;
        }
      }
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

Image TV_effect(Image photo)
{
  for (int i = 0; i < photo.width; i++)
  {
    for (int j = 0; j < photo.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        if (j % 2 == 0) 
        {
          unsigned int temp = photo(i,j,k);
          temp = (photo(i,j,k)) * 1.5; 
          if (temp > 255) temp = 255; 
          photo(i,j,k) = temp;
        } 
        else 
        {
          unsigned int temp = photo(i,j,k);
          temp = (photo(i,j,k)) / 1.5; 
          if (temp < 0) temp = 0; 
          photo(i,j,k) = temp;
        }
      }
    }
  }
  return photo; 
}