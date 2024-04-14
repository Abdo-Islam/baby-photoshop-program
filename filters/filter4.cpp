#include <iostream>
#include <cmath>
#include "Image_Class.h"
using namespace std; 

Image merge(Image photo1, Image photo2);


int main()
{
  string name1,name2,name3; 
  cout << "please enter the first photo name and extention : ";
  getline(cin,name1); 
  cout << "please enter the second photo name and extention : ";
  getline(cin,name2); 
  Image photo1(name1), photo2(name2);
  Image photo3 = merge(photo1,photo2); 
  cout << "please enter a name of the new photo with it's extention : ";
  cin >> name3; 
  photo3.saveImage(name3);

  return 0; 
}

Image merge(Image photo1, Image photo2)
{
  char choice; 
  cout << "do you want to...\n"; 
  cout << "1-resize the smaller image to the bigger one then merge \n"; 
  cout << "2-merge the common area between the two images \n";
  cout << "please choose an option : ";
  cin >> choice;
  while (choice != '1' && choice != '2')
  {
    cout << "invalid choice... please make a valid one : "; 
    cin >> choice; 
  }  
  Image photo3; 
  if ( choice == '1' && photo1.width * photo1.height >= photo2.width * photo2.height)
  {
    photo3 = Image(photo1.width,photo1.height);
    for (int i = 0; i < photo3.width; i++)
    {
      for (int j = 0; j < photo3.height; j++)
      {
        for (int k = 0; k < 3; k++)
        {
          photo3(i,j,k) = (photo2(round(i * photo2.width / photo1.width),round(j * photo2.height / photo1.height),k) + photo1(i,j,k))/2; 
        }
      }
    } 
  }
  if ( choice == '1' && photo1.width * photo1.height < photo2.width * photo2.height)
  {
    photo3 = Image(photo2.width,photo2.height);
    for (int i = 0; i < photo3.width; i++)
    {
      for (int j = 0; j < photo3.height; j++)
      {
        for (int k = 0; k < 3; k++)
        {
        photo3(i,j,k) = (photo1(round(i * photo1.width / photo2.width),round(j * photo1.height / photo2.height),k)+photo2(i,j,k))/2; 
        }
      }
    } 
  }
  if (choice == '2')
  {
    photo3 = Image(min(photo1.width,photo2.width),min(photo1.height,photo2.height));
    for (int i = 0; i < photo3.width; i++)
    {
      for (int j = 0; j < photo3.height; j++)
      {
        for (int k = 0; k < 3; k++)
        {
          photo3(i,j,k) = (photo2(i,j,k) + photo1(i,j,k))/2; 
        }
      }
    } 
  }
  return photo3; 
}