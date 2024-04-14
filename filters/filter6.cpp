#include <string>
#include "Image_Class.h"
using namespace std;

int main ()
{
string filename;
cout << "Please enter image name (as path) or image name (copy) if image exist in cmake: ";
getline (cin,filename) ;
Image photo(filename);

  Image rotate1(photo.height, photo.width);
  int angle;
  cout << "This filter allows the user to rotate the image clockwise by 90º, 180º or 270º  plese enter your choise: ";
  cin >> angle;
  
  if (angle == 90)
  {
     for (int i = 0; i < photo.width; ++i)
     {
         for (int j = 0; j < photo.height; ++j)
         {
             rotate1(photo.height - j - 1, i, 0) = photo(i, j, 0);
             rotate1(photo.height - j - 1, i, 1) = photo(i, j, 1);
             rotate1(photo.height - j - 1, i, 2) = photo(i, j, 2);
         }
     }
  }
  
  else if (angle == 180)
  
  {
     for (int i = 0; i < photo.width; ++i)
     {
         for (int j = 0; j < photo.height; ++j)
         {
             rotate1(j, photo.width - i - 1, 0) = photo(i, j, 0);
             rotate1(j, photo.width - i - 1, 1) = photo(i, j, 1);
             rotate1(j, photo.width - i - 1, 2) = photo(i, j, 2);
         }
     }
  
     Image rotate2(photo.width, photo.height);
     for (int i = 0; i < rotate1.width; ++i)
     {
         for (int j = 0; j < rotate1.height; ++j)
         {
             rotate2(j, rotate1.width - i - 1, 0) = rotate1(i, j, 0);
             rotate2(j, rotate1.width - i - 1, 1) = rotate1(i, j, 1);
             rotate2(j, rotate1.width - i - 1, 2) = rotate1(i, j, 2);
         }
     }
  }
  
  else if (angle == 270)
  
  {
     for (int i = 0; i < photo.width; ++i)
     {
         for (int j = 0; j < photo.height; ++j)
         {
             rotate1(j, photo.width - i - 1, 0) = photo(i, j, 0);
             rotate1(j, photo.width - i - 1, 1) = photo(i, j, 1);
             rotate1(j, photo.width - i - 1, 2) = photo(i, j, 2);
         }
     }
  }

else
cout << "Invalid angle ";
return 0 ;
}