#include <iostream>
#include "Image_Class.h"
using namespace std; 

Image crop(Image photo);

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
  int x, y; 
  cout << "please enter the starting coordinates to crop the photo from as (x,y) \n";
  cout << "enter the x coordinate : "; 
  cin >> x; 
  while (x < 0 || x >= photo.width)
  {
    cout << "please enter a valid x coordinate : ";
    cin >> x; 
  }
  cout << "enter the y coordinate : "; 
  cin >> y; 
  while (y < 0 || y >= photo.height)
  {
    cout << "please enter a valid y coordinate : ";
    cin >> y; 
  }
  int len_x,len_y; 
  cout << "please enter the dimensions of the wanted area \n";
  cout << "enter the length on the x axis : ";
  cin >> len_x; 
  cout << "enter the length on the y axis : ";
  cin >> len_y; 
  int wid = x + len_x, high = y + len_y ;
  Image photo1(len_x,len_y);
  int tempx = 0;
  for (int i = x; i < wid; i++)
  {
    int tempy = 0; 
    for (int j = y; j < high; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        photo1(tempx,tempy,k) = photo(i,j,k);
      }
      tempy++;
    }
    tempx++;
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

Image crop(Image photo)
{
  int x, y; 
  cout << "please enter the starting coordinates to crop the photo from as (x,y) \n";
  cout << "enter the x coordinate : "; 
  cin >> x; 
  while (x < 0 || x >= photo.width)
  {
    cout << "please enter a valid x coordinate : ";
    cin >> x; 
  }
  cout << "enter the y coordinate : "; 
  cin >> y; 
  while (y < 0 || y >= photo.height)
  {
    cout << "please enter a valid y coordinate : ";
    cin >> y; 
  }
  int len_x,len_y; 
  cout << "please enter the dimensions of the wanted area \n";
  cout << "enter the length on the x axis : ";
  cin >> len_x; 
  cout << "enter the length on the y axis : ";
  cin >> len_y; 
  int wid = x + len_x, high = y + len_y ;
  Image photo1(len_x,len_y);
  int tempx = 0;
  for (int i = x; i < wid; i++)
  {
    int tempy = 0; 
    for (int j = y; j < high; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        photo1(tempx,tempy,k) = photo(i,j,k);
      }
      tempy++;
    }
    tempx++;
  }
  return photo1; 
}