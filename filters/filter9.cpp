#include <iostream>
#include <string>
#include "image_class.h"
using namespace std;


int main() 
{
    string filename;
cout << "please enter image name (as path) or image name (copy) if image exist in cmake: ";
     getline (cin , filename );
    Image image(filename);


string  num; 
cout << "this filter adding a frame to the picture please enter (** 1 Is Simple, 2 Is Fancy, 3 Is Fancy **) to add frame: ";
cin >> num;

while (true)
{
    if (num == "1")
        break;
    else if (num == "2")
        break;
    else if (num == "3")
        break;
    else
    {
        cout << "invalid please enter 1 or 2 or 3: ";
        cin >> num;
    }


}

cout << "if you want  frame color white enter 1: ";
cout << "\nif you want  frame color black enter 2: ";
cout << "\nif you want  frame color blue enter 3: ";
cout << "\nif you want  frame color green enter 4: ";

string  num_color ;
cin >> num_color;

while (true)
{
    if (num_color == "1")
        break;
    else if (num_color == "2")
        break;
    else if (num_color == "3")
        break;
    else if (num_color == "4")
        break;
    else
    {
        cout << "invalid please enter 1 or 2 or 3 or 4: ";
        cin >> num_color;
    }
   

}

if (num == "1" )
{
    for (int i = 0; i < image.width; i++)
    {

        for (int j = 0; j < 7; j++)
        {

                if (num_color == "3") 
                {
           
                    image(i, j, 0) = 0;   
                    image(i, j, 1) = 0;   
                    image(i, j, 2) = 255; 
                }


                if (num_color == "4")
                {
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 0;
                }

            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1" )
                  image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;
              

            }
        }

    }

    
        for (int i = 0; i < 7 ; i++)
        {
    
            for (int j = 0 ; j < image.height ; j++)
            {
           

                 if (num_color == "3")
                 {
                   
                     image(i, j, 0) = 0;  
                     image(i, j, 1) = 0;   
                     image(i, j, 2) = 255; 
                 }


           
                 if (num_color == "4")
                 {
                     image(i, j, 0) = 0;
                     image(i, j, 1) = 255;
                     image(i, j, 2) = 0;
                 }
    
                for (int k = 0; k < image.channels; k++)
                {
                    if (num_color == "1")
                        image(i, j, k) = 255;
                    else if (num_color == "2")
                        image(i, j, k) = 0;
                 
    
                }
            }
        }
    
        for (int i = image.width-1; i >= image.width -7 ; i--)
        {
    
            for (int j = image.height - 1; j >= 0 ; j--)
            {
            
                 if (num_color == "3")
                 {
          
                     image(i, j, 0) = 0;   
                     image(i, j, 1) = 0;  
                     image(i, j, 2) = 255;
                 }


            
                 if (num_color == "4")
                 {
                     image(i, j, 0) = 0;
                     image(i, j, 1) = 255;
                     image(i, j, 2) = 0;
                 }
                for (int k = 0; k < image.channels; k++)
                {
                    if (num_color == "1")
                        image(i, j, k) = 255;
                    else if (num_color == "2")
                        image(i, j, k) = 0;
                
    
                }
            }
        }
    
        for (int i = image.width - 1; i >= 0 ; i--)
        {
    
            for (int j = image.height - 1; j >= image.height -7 ; j--)
            {
             if (num_color == "3")
            {
                     image(i, j, 0) = 0;  
                     image(i, j, 1) = 0;   
                     image(i, j, 2) = 255; 
            }
             if (num_color == "4")
             {
                 image(i, j, 0) = 0;
                 image(i, j, 1) = 255;
                 image(i, j, 2) = 0;
             }
    
                for (int k = 0; k < image.channels; k++)
                {
                    if (num_color == "1")
                        image(i, j, k) = 255;
                    else if (num_color == "2")
                        image(i, j, k) = 0;
                   
    
                }
            }
        }
    

    cout << "pleaes enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
    system(filename.c_str());
}


 else if (num == "2")
     {
           for (int i = 0; i < image.width ; i++)
    {

        for (int j = 0; j <  7  ; j++)
        {
             

                      if (num_color == "3")
                      {

                          image(i, j, 0) = 0;
                          image(i, j, 1) = 0;
                          image(i, j, 2) = 255;
                      }

          
                      if (num_color == "4")
                      {
                          image(i, j, 0) = 0;
                          image(i, j, 1) = 255;
                          image(i, j, 2) = 0;
                      }
                 
            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }

    }

    for (int i = 0; i < 7 ; i++)
    {

        for (int j = 0 ; j < image.height ; j++)
        {
            if (num_color == "3")
            {

                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }

            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }

    for (int i = image.width-1; i >= image.width -7 ; i--)
    {

        for (int j = image.height - 1; j >= 0 ; j--)
        {
            if (num_color == "3")
            {

                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }

            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }

    for (int i = image.width - 1; i >= 0 ; i--)
    {

        for (int j = image.height - 1; j >= image.height -7 ; j--)
        {
            if (num_color == "3")
            {

                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }

            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;;

            }
        }
    }

         for (int i = 17; i < image.width - 15; i++)
         {

             for (int j = 17; j < 19; j++)
             {
                 if (num_color == "3")
                 {
                     image(i, j, 0) = 0;
                     image(i, j, 1) = 0;
                     image(i, j, 2) = 255;
                 }

            
                 if (num_color == "4")
                 {
                     image(i, j, 0) = 0;
                     image(i, j, 1) = 255;
                     image(i, j, 2) = 0;
                 }

                 for (int k = 0; k < image.channels; k++)
                 {
                     if (num_color == "1")
                         image(i, j, k) = 255;
                     else if (num_color == "2")
                         image(i, j, k) = 0;

                 }
             }

         }

        for (int i = 17; i < 19; i++)
         {

             for (int j = 17; j < image.height - 20; j++)
             {
                 if (num_color == "3")
                 {

                     image(i, j, 0) = 0;
                     image(i, j, 1) = 0;
                     image(i, j, 2) = 255;
                 }
                 if (num_color == "4")
                 {
                     image(i, j, 0) = 0;
                     image(i, j, 1) = 255;
                     image(i, j, 2) = 0;
                 }
                 for (int k = 0; k < image.channels; k++)
                 {
                     if (num_color == "1")
                         image(i, j, k) = 255;
                     else if (num_color == "2")
                         image(i, j, k) = 0;

                 }
             }
         }

         for (int i = image.width - 16; i >= image.width - 17; i--)
         {

             for (int j = image.height - 20; j >= 19; j--)
             {
                 if (num_color == "3")
                 {

                     image(i, j, 0) = 0;
                     image(i, j, 1) = 0;
                     image(i, j, 2) = 255;
                 }
                 if (num_color == "4")
                 {
                     image(i, j, 0) = 0;
                     image(i, j, 1) = 255;
                     image(i, j, 2) = 0;
                 }

                 for (int k = 0; k < image.channels; k++)
                 {
                     if (num_color == "1")
                         image(i, j, k) = 255;
                     else if (num_color == "2")
                         image(i, j, k) = 0;

                 }
             }
         }

         for (int i = image.width - 17; i >= 17; i--)
         {

             for (int j = image.height - 19; j >= image.height - 20; j--)
             {
                 if (num_color == "3")
                 {

                     image(i, j, 0) = 0;
                     image(i, j, 1) = 0;
                     image(i, j, 2) = 255;
                 }
                 if (num_color == "4")
                 {
                     image(i, j, 0) = 0;
                     image(i, j, 1) = 255;
                     image(i, j, 2) = 0;
                 }
                 for (int k = 0; k < image.channels; k++)
                 {
                     if (num_color == "1")
                         image(i, j, k) = 255;
                     else if (num_color == "2")
                         image(i, j, k) = 0;

                 }
             }
         }


         for (int i = 25; i < image.width - 25; i++)
         {

             for (int j = 25; j < 27; j++)
             {
                 if (num_color == "3")
                 {

                     image(i, j, 0) = 0;
                     image(i, j, 1) = 0;
                     image(i, j, 2) = 255;
                 }
                 if (num_color == "4")
                 {
                     image(i, j, 0) = 0;
                     image(i, j, 1) = 255;
                     image(i, j, 2) = 0;
                 }
                 for (int k = 0; k < image.channels; k++)
                 {
                     if (num_color == "1")
                         image(i, j, k) = 255;
                     else if (num_color == "2")
                         image(i, j, k) = 0;;

                 }
             }

         }

         for (int i = 25; i < 27; i++)
         {

             for (int j = 25; j < image.height - 25; j++)
             {
                 if (num_color == "3")
                 {

                     image(i, j, 0) = 0;
                     image(i, j, 1) = 0;
                     image(i, j, 2) = 255;
                 }
                 if (num_color == "4")
                 {
                     image(i, j, 0) = 0;
                     image(i, j, 1) = 255;
                     image(i, j, 2) = 0;
                 }
                 for (int k = 0; k < image.channels; k++)
                 {
                     if (num_color == "1")
                         image(i, j, k) = 255;
                     else if (num_color == "2")
                         image(i, j, k) = 0;

                 }
             }
         }

         for (int i = image.width - 26; i >= image.width - 27; i--)
         {

             for (int j = image.height - 26; j >= 25; j--)
             {
                 if (num_color == "3")
                 {

                     image(i, j, 0) = 0;
                     image(i, j, 1) = 0;
                     image(i, j, 2) = 255;
                 }
                 if (num_color == "4")
                 {
                     image(i, j, 0) = 0;
                     image(i, j, 1) = 255;
                     image(i, j, 2) = 0;
                 }

                 for (int k = 0; k < image.channels; k++)
                 {
                     if (num_color == "1")
                         image(i, j, k) = 255;
                     else if (num_color == "2")
                         image(i, j, k) = 0; 

                 }
             }
         }

         for (int i = image.width - 26; i >= 25; i--)
         {

             for (int j = image.height - 26; j >= image.height - 27; j--)
             {
                 if (num_color == "3")
                 {

                     image(i, j, 0) = 0;
                     image(i, j, 1) = 0;
                     image(i, j, 2) = 255;
                 }
                 if (num_color == "4")
                 {
                     image(i, j, 0) = 0;
                     image(i, j, 1) = 255;
                     image(i, j, 2) = 0;
                 }
                 for (int k = 0; k < image.channels; k++)
                 {
                     if (num_color == "1")
                         image(i, j, k) = 255;
                     else if (num_color == "2")
                         image(i, j, k) = 0;

                 }
             }
         }
         cout << "pleaes enter image name to store new image\n";
         cout << "and specify extension .jpg, .bmp, .png, .tga: ";

         cin >> filename;
         image.saveImage(filename);
         system(filename.c_str());
     }

else if (num == "3")
{
    for (int i = 0; i < image.width; i++)
    {

        for (int j = 0; j < 7; j++)
        {

            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }

            
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }
            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }

    }

    for (int i = 0; i < 7; i++)
    {

        for (int j = 0; j < image.height; j++)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }

            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }

    for (int i = image.width - 1; i >= image.width - 7; i--)
    {

        for (int j = image.height - 1; j >= 0; j--)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }
            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }

    for (int i = image.width - 1; i >= 0; i--)
    {

        for (int j = image.height - 1; j >= image.height - 7; j--)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }

            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }

    for (int i = 8; i < image.width-7 ; i++)
    {

        for (int j = 12; j < 13; j++)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }

            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }

    }

    for (int i = 14; i < image.width-14; i++)
    {

        for (int j = 15; j < 16; j++)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }
            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }
    for (int i = 8; i < image.width - 7; i++)
    {

        for (int j = 16; j < 17; j++)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }
            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }

    }
    for (int i = 17; i < 18; i++)
    {

        for (int j = 7; j < image.height  -7 ; j++)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }
            for (int k = 0 ; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }
    for (int i = 18; i < 20; i++)
    {

        for (int j = 10; j < image.height - 10; j++)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }
            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }

    for (int i = image.width - 8; i >= 7; i--)
    {

        for (int j = image.height - 18; j >= image.height - 19; j--)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }
            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }
    for (int i = image.width - 12; i >= 11; i--)
    {

        for (int j = image.height - 17; j >= image.height - 18; j--)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }
            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }
    for (int i = image.width - 8; i >= 7; i--)
    {

        for (int j = image.height - 13; j >= image.height - 14; j--)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }
            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }
    for (int i = image.width - 17; i >= image.width - 18; i--)
        {

            for (int j = image.height - 8; j >= 7  ; j--)
            {
                if (num_color == "3")
                {
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 255;
                }
                if (num_color == "4")
                {
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 0;
                }
                for (int k = 0; k < image.channels; k++)
                {
                    if (num_color == "1")
                        image(i, j, k) = 255;
                    else if (num_color == "2")
                        image(i, j, k) = 0;
                }
            }
        }
    for (int i = image.width - 21; i >= image.width - 22; i--)
    {

        for (int j = image.height - 11; j >= 10; j--)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }
            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }
    }
    for (int i = image.width - 22; i >= image.width - 23; i--)
    {

        for (int j = image.height - 8; j >= 7; j--)
        {
            if (num_color == "3")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
            if (num_color == "4")
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 255;
                image(i, j, 2) = 0;
            }
            for (int k = 0; k < image.channels; k++)
            {
                if (num_color == "1")
                    image(i, j, k) = 255;
                else if (num_color == "2")
                    image(i, j, k) = 0;

            }
        }

    }
}


    cout << "pleaes enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
    system(filename.c_str());

return 0;
}