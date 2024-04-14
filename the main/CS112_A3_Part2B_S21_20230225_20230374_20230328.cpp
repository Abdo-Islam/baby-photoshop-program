// File: CS112_A3_Part1_S21_20230225_20230374_20230328.cpp
//this is a program for some filters that changes the photo as wanted   
// Author: Abdullah Islam Fathy Ibrahim , S21 , 20230225
//         Mahmoud Ali Anwar Mohammed , S21 , 20230374
//         Mohamed Gamal Abd-Elmalek Abd-Elrehem , S21 , 20230328 
// Emails: Abdullah : abdoislam2050@gmail.com
//         Mahmoud : mahmoud.ali.ashor@gmail.com
//         Mohamed : mg4803558@gmail.com
//      Abdullah : 20230225 , did the main menu + Filter 1: Grayscale Conversion + Filter 7: Darken and Lighten
//                    
//      Mahmoud : 20230374 , did Filter 3 : Invert image, Filter 6 : Rotate Image, filter 9 : Add frame
//                    
//      Mohamed : 20230328 , 

#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include "Image_Class.h"
using namespace std; 

Image Grayscale(Image photo);
Image black_and_white(Image photo);
Image Invert_image(Image photo);
Image merge(Image photo1, Image photo2);
Image flip_image(Image photo);
Image Rotate_image(Image photo);
Image lighter_Darker(Image photo);
Image crop(Image photo);
Image Add_frame(Image image);
Image detect_edges(Image photo);
Image resize(Image photo);
Image blur(Image image); 
Image sunlight(Image photo);
Image oil_painting(Image photo);
Image TV_effect(Image photo);

int main()
{
  string name; 
  Image photo;
  cout << "please enter the photo name (with the extention) or path : ";
  getline(cin,name); 
  while (true)
  {
    try 
    {
      photo.loadNewImage(name); 
      break;
    } catch (invalid_argument) {
      cout << "please enter a valid name or path : ";
      getline(cin,name); 
    }
  } 
  while (true)
  {
    string choice; 
    cout << "Dear user, what do you want to do now ? \n";
    cout << "0-Load a new image\n";
    cout << "1-Filter 1: Grayscale Conversion           2-Filter 2: Black and White\n";
    cout << "3-Filter 3: Invert Image                   4-Filter 4: Merge Images\n";
    cout << "5-Filter 5: Flip Image                     6-Filter 6: Rotate Image\n";
    cout << "7-Filter 7: Darken and Lighten Image       8-Filter 8: Crop Images\n";
    cout << "9-Filter 9: Adding a Frame to the Picture  10-Filter 10: Detect Image Edges\n";
    cout << "11-Filter 11: Resizing Images              12-Filter 12: Blur Images\n";
    cout << "13-Filter 13: adding sunlight              14-Filter 14: oil paint image\n";
    cout << "15-Filter 15: TV effect \n";
    cout << "16-Save the image                          17-exit\n";
    cin >> choice; 
    while ((int(choice[0]) < 48 || int(choice[0]) > 57) && (choice != "11" || choice != "12" || choice != "13" || choice != "14" || choice != "15" || choice != "16" || choice != "17"))
    {
      cout << "please enter a valid choice : ";
      cin >> choice; 
    }
    if (choice == "0")
    {
      cout << "please enter the photo name (with the extention) or path : ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      getline(cin,name); 
      while (true)
      {
        try 
        {
          photo.loadNewImage(name); 
          break;
        } catch (invalid_argument) {
          cout << "please enter a valid name or path : ";
          getline(cin,name); 
        }
      } 
    }
    if (choice == "1")
    {
      photo = Grayscale(photo);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "2")
    {
      photo = black_and_white(photo);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "3")
    {
      photo = Invert_image(photo);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "4")
    {
      string name2; 
      cout << "please enter the second photo name and extention : ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      getline(cin,name2); 
      Image photo2; 
      while (true)
      {
        try 
        {
          photo2.loadNewImage(name); 
          break;
        } catch (invalid_argument) {
          cout << "please enter a valid name ot path : ";
          getline(cin,name2); 
        }
      }
      photo = merge(photo, photo2);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "5")
    {
      photo = flip_image(photo);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "6")
    {
      photo = Rotate_image(photo);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "7")
    {
      photo = lighter_Darker(photo);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "8")
    {
      photo = crop(photo);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "9")
    {
      photo = Add_frame(photo);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "10")
    {
      photo = detect_edges(photo);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "11")
    {
      photo = resize(photo);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "12")
    {
      photo = blur(photo); 
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "13")
    {
      photo = sunlight(photo);
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "14")
    {
      photo = oil_painting(photo); 
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "15")
    {
      photo = TV_effect(photo); 
      cout << "the filter has worked successfully !\n";
    }
    if (choice == "16")
    {
      string choice2; 
      cout << "Do you want to save the photo in a new file or in the same file ?\n";
      cout << "1-save in the same file \n2-save in a new file \n";
      cin >> choice2; 
      while (choice2 != "1" && choice2 != "2")
      {
        cout << "please enter a valid choice : ";
        cin >> choice2; 
      }
      if (choice2 == "1")
      {
        photo.saveImage(name); 
        system(name.c_str());
      }
      else if (choice2 == "2")
      {
      cout << "please enter a name of the new photo (with it's extention) : ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      getline(cin,name); 
      while (true)
      {
        try 
        {
          photo.saveImage(name);
          break;
        } catch (invalid_argument) {
          cout << "please enter a name with a valid extention : ";
          getline(cin,name);
        }
      }
      photo.saveImage(name);
      system(name.c_str());
      }
    }
    if (choice == "17")
    {
      string choice3; 
      cout << "Do you want to save before exit ?\n";
      cout << "1-No   \n2-Yes\n";
      cin >> choice3; 
      while (choice3 != "1" && choice3 != "2")
      {
        cout << "please enter a valid choice ";
        cin >> choice3; 
      }
      if (choice3 == "2")
      {
        string choice2; 
        cout << "Do you want to save the photo in a new file or in the same file ?\n";
        cout << "1-save in the same file \n2-save in a new file \n";
        cin >> choice2; 
        while (choice2 != "1" && choice2 != "2")
        {
          cout << "please enter a valid choice : ";
          cin >> choice2; 
        }
        if (choice2 == "1")
        {
          photo.saveImage(name); 
          system(name.c_str());
        }
        else if (choice2 == "2")
        {
        cout << "please enter a name of the new photo (with it's extention) : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,name); 
        while (true)
        {
          try 
          {
            photo.saveImage(name);
            break;
          } catch (invalid_argument) {
            cout << "please enter a name with a valid extention : ";
            getline(cin,name);
          }
        }
        photo.saveImage(name);
        system(name.c_str());
        }
      }
      break; 
    }
  }
  return 0; 
}


Image Grayscale(Image photo)
{
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
  return photo; 
}

Image black_and_white(Image photo)
{
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
      if (avg >= 127)
      {
        for (int k = 0; k < 3; k++)
        {
            photo(i,j,k) = 255;
        }
      }
      else if (avg < 127)
      {
        for (int k = 0; k < 3; k++)
        {
            photo(i,j,k) = 0;
        }
      }
    }
  }
  return photo; 
}

Image Invert_image(Image photo)
{
  for (int i = 0; i < photo.width; i++) 
  {    
    for (int j = 0; j < photo.height; j++) 
    {
       for (int k = 0 ; k < photo.channels; k++)
       {
           photo(i, j, k) = 255 - photo(i, j, k) ;
       }            
    }
  }
  return photo; 
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

Image flip_image(Image photo)
{
  Image photo1(photo.width,photo.height);
  string choice; 
  cout << "how do you wnat to flip the photo ?\n1-Vertical Flip\n2-Horizontal Flip\n";
  cin >> choice; 
  while (choice != "1" && choice != "2")
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

Image Rotate_image(Image photo)
{
  Image rotate1(photo.height, photo.width);
  int angle;
  cout << "This filter allows the user to rotate the image clockwise by 90º, 180º or 270º  plese enter your choise: ";
  cin >> angle;
  while (true)
  {
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
  return rotate1;
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
    return rotate2;
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
    return rotate1;
  }
  else 
  {
    cout << "Invalid angle please enter (90 or 180 or 270 ): ";
    cin >> angle; 
  }
  }
}

Image lighter_Darker(Image photo)
{
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
  return photo; 
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

Image Add_frame(Image image)
{
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
  return image; 
}

Image detect_edges(Image photo)
{
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
  Image photo1(photo.width,photo.height); 
  for (int i = 1; i < photo.width-1; i += 1)
  {
    for (int j = 1; j < photo.height-1; j += 1)
    {
      if (abs(photo(i-1,j,0) - photo(i+1,j,0)) > 50) photo1(i,j,0) = photo1(i,j,1) = photo1(i,j,2) = 0;
      else if (abs(photo(i,j-1,0) - photo(i,j+1,0)) > 50) photo1(i,j,0) = photo1(i,j,1) = photo1(i,j,2) = 0;
      else photo1(i,j,0) = photo1(i,j,1) = photo1(i,j,2) = 255;
    }
  }
  return photo1; 
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

Image sunlight(Image photo)
{
  for (int i = 0; i < photo.width; i++)
  {
    for (int j = 0; j < photo.height; j++)
    {
      if (photo(i,j,0) + 50 > 255) photo(i,j,0) = 255;
      else photo(i,j,0) += 50;
      if (photo(i,j,1) + 50 > 255) photo(i,j,1) = 255;
      else photo(i,j,1) += 50;
    }
  }
  return photo; 
}

Image oil_painting(Image photo)
{
  Image photo1(photo.width, photo.height);
  for (int i = 2; i < photo.width - 3; i++)
  {
    for (int j = 2; j < photo.height - 3; j++)
    {
      int colorr[256] = {0};
      int colorg[256] = {0};
      int colorb[256] = {0};
      for (int l = i - 2; l <= i + 2; l++)
      {
        for (int m = j - 2; m <= j + 2; m++)
        {
          colorr[photo(l, m, 0)]++;
          colorg[photo(l, m, 1)]++;
          colorb[photo(l, m, 2)]++;
        }
      }
      int maxCountR = 0, maxCountG = 0, maxCountB = 0;
      int maxIndexR = 0, maxIndexG = 0, maxIndexB = 0;
      for (int c = 0; c < 256; c++)
      {
        if (colorr[c] > maxCountR)
        {
          maxCountR = colorr[c];
          maxIndexR = c;
        }
        if (colorg[c] > maxCountG)
        {
          maxCountG = colorg[c];
          maxIndexG = c;
        }
        if (colorb[c] > maxCountB)
        {
          maxCountB = colorb[c];
          maxIndexB = c;
        }
      }
      photo1(i, j, 0) = maxIndexR;
      photo1(i, j, 1) = maxIndexG;
      photo1(i, j, 2) = maxIndexB;
    }
  }
  return photo1; 
}

Image TV_effect(Image photo)
{
  for (int i = 0; i < photo.width; i++)
  {
    for (int j = 0; j < photo.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        if (j % 2 == 0) 
        {
          unsigned int temp = photo(i,j,k);
          temp = (photo(i,j,k)) * 1.5; 
          if (temp > 255) temp = 255; 
          photo(i,j,k) = temp;
        } 
        else 
        {
          unsigned int temp = photo(i,j,k);
          temp = (photo(i,j,k)) / 1.5; 
          if (temp < 0) temp = 0; 
          photo(i,j,k) = temp;
        }
      }
    }
  }
  return photo; 
}