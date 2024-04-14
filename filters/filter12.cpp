#include "image_class.h"
#include <string>
using namespace std;

Image blur(Image image);

int main()
{
    string filename;
    cout << "please enter image name (as path) or image name (copy) if image exists in cmake: ";
    getline (cin, filename);
    Image image(filename);
     
    string strblur;
    cout << "Enter the precenteage of the blur that you want (1 / 10 ): ";
    cin >> strblur;

while (true)
  {
    if (strblur == "1" || strblur == "2" || strblur == "3" || strblur == "4" || strblur == "5" || strblur == "6" || strblur == "7" || strblur == "8" || strblur == "9" || strblur == "10")
        break;
    else

    {
        cout << "invalid!!\n" ;
        cout << "Enter the precenteage of the blur (from 1 to 10): " ;
        cin >> strblur;
        continue ;

    }
      
  }


int blur = stoi (strblur)  ;

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            
            for (int k = 0; k < image.channels; k++) {
                int count_pixel = 0;
                int sum = 0;
                for (int x = -blur; x <= blur; x++) {
                    for (int y = -blur; y <= blur; y++) {
                        if ((i + x >= 0 && i + x < image.width) && (j + y >= 0 && j + y < image.height))
                        {
                            count_pixel++;
                            sum += image.getPixel(i + x, j + y, k);
                        }

                    }
                 
                }
                    int avg = sum / count_pixel;

                       //Darken the pixel by subtracting a value 
                    int darkened_value = avg - 10;
                       //Ensure the pixel value stays within the valid range [0, 255]
                    darkened_value = max(0, darkened_value);
                    darkened_value = min(255, darkened_value);

                image.setPixel(i, j, k, darkened_value);
            }
            
        }
    }


    cout << "please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
    system(filename.c_str());

    return 0;
}

Image blur(Image image)
{
    string strblur;
    cout << "Enter the precenteage of the blur that you want (1 / 10 ): ";
    cin >> strblur;

while (true)
  {
    if (strblur == "1" || strblur == "2" || strblur == "3" || strblur == "4" || strblur == "5" || strblur == "6" || strblur == "7" || strblur == "8" || strblur == "9" || strblur == "10")
        break;
    else

    {
        cout << "invalid!!\n" ;
        cout << "Enter the precenteage of the blur (from 1 to 10): " ;
        cin >> strblur;
        continue ;

    }
      
  }


int blur = stoi (strblur)  ;

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            
            for (int k = 0; k < image.channels; k++) {
                int count_pixel = 0;
                int sum = 0;
                for (int x = -blur; x <= blur; x++) {
                    for (int y = -blur; y <= blur; y++) {
                        if ((i + x >= 0 && i + x < image.width) && (j + y >= 0 && j + y < image.height))
                        {
                            count_pixel++;
                            sum += image.getPixel(i + x, j + y, k);
                        }

                    }
                 
                }
                    int avg = sum / count_pixel;

                       //Darken the pixel by subtracting a value 
                    int darkened_value = avg - 10;
                       //Ensure the pixel value stays within the valid range [0, 255]
                    darkened_value = max(0, darkened_value);
                    darkened_value = min(255, darkened_value);

                image.setPixel(i, j, k, darkened_value);
            }
            
        }
    }
   return image; 
}