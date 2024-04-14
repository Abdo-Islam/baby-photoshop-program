#include <iostream>
#include "image_class.h"
using namespace std; 

int main()
{
  string name; 
  cout << "please enter the photo name and extention : ";
  cin >> name; 
  Image photo(name); 
  char choice; 
  cout << "1-darking the photo \n2-lighting the photo \nplease make a dicition : ";
  cin >> choice; 
  while (choice != '1' && choice != '2')
  {
    cout << "please select a valid choice (1 to darking or 2 to lighting) : ";
    cin >> choice; 
  }
  int per; 
  cout << "please enter the percentage of lighting or darking you want (from 0 to 100) : "; 
  cin >> per; 
  while (per < 0 or per > 100)
  {
    cout << "please enter a valid percentage value : "; 
    cin >> per; 
  }
  float val;
  for (int i = 0; i < photo.width; i++)
  {
    for (int j = 0; j < photo.height; j++)
    {
      for (int k = 0; k < photo.channels; k++)
      {
        val = (per / 100.0) * photo(i,j,k); 
        if (choice == '1')
        {
          unsigned int temp = photo(i,j,k);
          temp = (photo(i,j,k) - val); 
          if (temp < 0) temp = 0; 
          photo(i,j,k) = temp;

        }
        if (choice == '2') 
        {
          unsigned int temp = photo(i,j,k);
          temp = (photo(i,j,k) + val); 
          if (per > 50 && per <= 65) temp *= 2; 
          if (per > 65 && per <= 80) temp *= 4; 
          if (per > 80 && per <= 95) temp *= 6; 
          if (per > 95 && per <= 100) 
          {
            photo(i,j,k) = 255; 
            continue;
          }
          if (temp > 255) temp = 255; 
          photo(i,j,k) = temp;
        }
      }
    }
  }
  cout << "please enter a name of the new photo (with it's extention) : ";
  cin >> name; 
  photo.saveImage(name);
  return 0; 
}