#include <iostream>
#include "Image_Class.h"
using namespace std; 

Image flip_image(Image photo);

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
  Image photo1(photo.width,photo.height);
  string choice; 
  cout << "how do you wnat to flip the photo ?\n1-Vertical Flip\n2-Horizontal Flip\n";
  cin >> choice; 
  if (choice == "1")
  {
    for (int i = 0; i < photo.width; i++)
    {
      for (int j = 0; j < photo.height; j++)
      {
        for (int k = 0; k < 3; k++)
        {
          photo1(i,photo.height-j-1,k) = photo(i,j,k); 
        }
      } 
    }
  }  
  else if (choice == "2")
  {
    for (int i = 0; i < photo.width; i++)
    {
      for (int j = 0; j < photo.height; j++)
      {
        for (int k = 0; k < 3; k++)
        {
          photo1(photo.width-i-1,j,k) = photo(i,j,k); 
        }
      } 
    }
  }
  else 
  {
    cout << "invalid choice!"; 
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

Image flip_image(Image photo)
{
  Image photo1(photo.width,photo.height);
  string choice; 
  cout << "how do you wnat to flip the photo ?\n1-Vertical Flip\n2-Horizontal Flip\n";
  cin >> choice; 
  while (choice != "1" || choice != "2")
  {
    cout << "please enter a valid choice ";
    cin >> choice; 
  }
  if (choice == "1")
  {
    for (int i = 0; i < photo.width; i++)
    {
      for (int j = 0; j < photo.height; j++)
      {
        for (int k = 0; k < 3; k++)
        {
          photo1(i,photo.height-j-1,k) = photo(i,j,k); 
        }
      } 
    }
  }  
  else if (choice == "2")
  {
    for (int i = 0; i < photo.width; i++)
    {
      for (int j = 0; j < photo.height; j++)
      {
        for (int k = 0; k < 3; k++)
        {
          photo1(photo.width-i-1,j,k) = photo(i,j,k); 
        }
      } 
    }
  }
  return photo1; 
}