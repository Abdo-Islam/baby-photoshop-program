#include <iostream>
#include "image_class.h"
using namespace std; 

Image gray(Image photo);

int main()
{
  string name; 
  cout << "please enter the photo name and extention : ";
  cin >> name; 
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