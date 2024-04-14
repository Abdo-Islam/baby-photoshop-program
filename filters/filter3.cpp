#include "image_class.h"
#include <string> 
using namespace std;


int main() 
{
string filename;
cout << "Please enter image name (as path) or image name (copy) if image exist in cmake: ";
getline (cin , filename);
Image photo(filename);

for (int i = 0; i < photo.width; i++) {   
        
   for (int j = 0; j < photo.height; j++) {

       for (int k = 0 ; k < photo.channels; k++)
       {
           photo(i, j, k) = 255 - photo(i, j, k) ;
       }            
   }
}
cout << "please enter image name to store new image\n";
cout << "and specify extension .jpg, .bmp, .png, .tga: ";

cin >> filename;
photo.saveImage(filename);
system(filename.c_str());

return 0;
}