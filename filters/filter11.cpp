#include <iostream>
#include <cmath>
#include "image_class.h"
using namespace std; 

Image resize(Image photo ,Image photo1);

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
  int wid,high;
  cout << "please enter the new image width : "; 
  cin >> wid ;
  while (wid <= 0)
  {
    cout << "invalid width, please enter a valid width : ";
    cin >> wid; 
  } 
  cout << "please enter the new image height : "; 
  cin >> high ;
  while (high <= 0)
  {
    cout << "invalid height, please enter a valid height : ";
    cin >> high; 
  } 
  Image photo1(wid,high); 
  for (int i = 0; i < photo1.width; i++)
  {
    for (int j = 0; j < photo1.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        photo1(i,j,k) = photo(round(i * photo.width / photo1.width),round(j * photo.height / photo1.height),k);
      }
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

Image resize(Image photo)
{
  int wid,high;
  cout << "please enter the new image width : "; 
  cin >> wid ;
  while (wid <= 0)
  {
    cout << "invalid width, please enter a valid width : ";
    cin >> wid; 
  } 
  cout << "please enter the new image height : "; 
  cin >> high ;
  while (high <= 0)
  {
    cout << "invalid height, please enter a valid height : ";
    cin >> high; 
  } 
  Image photo1(wid,high); 
  for (int i = 0; i < photo1.width; i++)
  {
    for (int j = 0; j < photo1.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        photo1(i,j,k) = photo(round(i * photo.width / photo1.width),round(j * photo.height / photo1.height),k);
      }
    }
  }
  return photo1; 
}