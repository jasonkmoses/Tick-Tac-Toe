//  tick tac toe for ternimal
//  Created by jason Moses on 2019/09/13.
//  Copyright Â© 2019 jason Moses. All rights reserved.
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <vector>
#include <numeric>
#include <tuple>
const int width = 80, height = 16; //NB NB NB NB NB Use Width and height to set for your consoles size 
const int SIZE_OF_NAME_ARRAY = 20;
int x , y;
int Inp;
bool gameOVER;
std::string name;
std::ifstream ofile;
std::string NAMES[SIZE_OF_NAME_ARRAY];
std::string Names_To_Printed[SIZE_OF_NAME_ARRAY];
std::vector<bool> grid_values_to_pass;
std::vector<int> value_to_pass_OX;
std::vector<int> value_vector_of_int_x;
std::vector<int> value_vector_of_int_y;
void displayHowToPlay() {
    std::cout<<"Type the alternative letter as shown in the figure below to place either a O or a X depending on the player!";
    for (y = 0; y < height; y++)
    {
     for (x = 0 ; x < width; x++)
      {
         if (x == 79 || x == 0)
         {
            std::cout<<" ";
         }
          //draws '|'
          else if
          (

           (x==34 && y==9) || (x==38 && y==9) || (x==43 && y==9) ||
           (x==47 && y==9) || (x==34 && y==7) || (x==38 && y==7) ||
           (x==43 && y==7) || (x==47 && y==7) || (x==34 && y==5) ||
           (x==38 && y==5) || (x==43 && y==5) || (x==47 && y==5)

           )
           {
           std::cout<<"|";
           }
          //draws '-'
          else if (

          (x>=35 && x<=38 && y==4)  ||
          (x<=43 && x>=38 && y==4)  ||
          (x>=43 && x<=46 && y==4)  ||
          (x>=35 && x<=38 && y==6)  ||
          (x<=43 && x>=38 && y==6)  ||
          (x<=46 && x>=43 && y==6)  ||
          (x>=35 && x<=38 && y==8)  ||
          (x<=43 && x>=38 && y==8)  ||
          (x<=46 && x>=38 && y==8)  ||
          (x>=35 && x<=38 && y==10) ||
          (x<=43 && x>=38 && y==10) ||
          (x>=43 && x<=46 && y==10)

          )
          {
           std::cout<<'_';
          }
          else if (x == 45 && y == 9)
          {
           std::cout<<'A';
          }
          else if (x == 45 && y == 7)
          {
           std::cout<<'B';
          }
          else if (x == 45 && y == 5)
          {
           std::cout<<'C';
          }
          else if (x == 40 && y == 9)
          {
           std::cout<<'D';
          }
          else if (x == 40 && y == 7)
          {
           std::cout<<'E';
          }
          else if (x == 40 && y == 5)
          {
           std::cout<<'F';
          }
          else if (x == 36 && y == 9)
          {
           std::cout<<'G';
          }
          else if (x == 36 && y == 7)
          {
           std::cout<<'H';
          }
          else if  (x == 36 && y == 5)
          {
           std::cout<<'I';
          }
          else {
           std::cout<<" ";
          }
     }
 }
   std::cout<<"Please ENTER letters (a b c d e f g h or i) as instructed by the grid above Player 1 now! So the game may start";
}
void Logic(std::vector<bool> grids_vector,std::vector<int> O_X) {
      for (y = 0; y < height; y++)
      {
       for (x = 0 ; x < width; x++)
        {
        //draws '#'
           if (x == 79 || x == 0)
           {
              std::cout<<"#";
           }
            //draws '|'
            else if
            (

             (x==34 && y==9) || (x==38 && y==9) || (x==43 && y==9) ||
             (x==47 && y==9) || (x==34 && y==7) || (x==38 && y==7) ||
             (x==43 && y==7) || (x==47 && y==7) || (x==34 && y==5) ||
             (x==38 && y==5) || (x==43 && y==5) || (x==47 && y==5)

             )
             {
             std::cout<<"|";
             }
            //draws '-'
            else if (

            (x>=35 && x<=38 && y==4) ||
            (x<=43 && x>=38 && y==4) ||
            (x>=43 && x<=46 && y==4) ||
            (x>=35 && x<=38 && y==6) ||
            (x<=43 && x>=38 && y==6) ||
            (x<=46 && x>=43 && y==6) ||
            (x>=35 && x<=38 && y==8) ||
            (x<=43 && x>=38 && y==8) ||
            (x<=46 && x>=38 && y==8) ||
            (x>=35 && x<=38 && y==10) ||
            (x<=43 && x>=38 && y==10) ||
            (x>=43 && x<=46 && y==10)

            )
             {
             std::cout<<'_';
            }
            else if (

            (
             ((grids_vector[0] == true && (x == 45 && y == 9)) && (O_X[0] == 1)) ||
             ((grids_vector[1] == true && (x == 45 && y == 7)) && (O_X[1] == 1)) ||
             ((grids_vector[2] == true && (x == 45 && y == 5)) && (O_X[2] == 1)) ||
             ((grids_vector[3] == true && (x == 40 && y == 9)) && (O_X[3] == 1)) ||
             ((grids_vector[4] == true && (x == 40 && y == 7)) && (O_X[4] == 1)) ||
             ((grids_vector[5] == true && (x == 40 && y == 5)) && (O_X[5] == 1)) ||
             ((grids_vector[6] == true && (x == 36 && y == 9)) && (O_X[6] == 1)) ||
             ((grids_vector[7] == true && (x == 36 && y == 7)) && (O_X[7] == 1)) ||
             ((grids_vector[8] == true && (x == 36 && y == 5)) && (O_X[8] == 1))
            )

            )
            {
              std::cout<<"O";
            }
            //check 3 O's underneath each other player one wins
            else if
            (
             ((O_X[0] == 1) && (O_X[1] == 1) && (O_X[2] == 1)) ||
             ((O_X[3] == 1) && (O_X[4] == 1) && (O_X[5] == 1)) ||
             ((O_X[6] == 1) && (O_X[7] == 1) && (O_X[8] == 1))
            )
            {
                std::cout<<"player one has won! (O)";
                gameOVER = true;
            }
            //check 3 O's next to each other player one wins
            else if
            (
             ((O_X[0] == 1) && (O_X[3] == 1) && (O_X[6] == 1)) ||
             ((O_X[1] == 1) && (O_X[4] == 1) && (O_X[7] == 1)) ||
             ((O_X[2] == 1) && (O_X[5] == 1) && (O_X[8] == 1))
            )
            {
                std::cout<<"player one has won! (O)";
                gameOVER = true;
            }
            //check 3 O's diagonal to each other player one wins
            else if
            (
             ((O_X[8] == 1) && (O_X[4] == 1) && (O_X[0] == 1)) ||
             ((O_X[2] == 1) && (O_X[4] == 1) && (O_X[6] == 1))
            )
            {
                std::cout<<"player one has won! (O)";
                gameOVER = true;
            }
            else if (

            (
             ((grids_vector[0] == true && (x == 45 && y == 9)) && (O_X[0] == 2)) ||
             ((grids_vector[1] == true && (x == 45 && y == 7)) && (O_X[1] == 2)) ||
             ((grids_vector[2] == true && (x == 45 && y == 5)) && (O_X[2] == 2)) ||
             ((grids_vector[3] == true && (x == 40 && y == 9)) && (O_X[3] == 2)) ||
             ((grids_vector[4] == true && (x == 40 && y == 7)) && (O_X[4] == 2)) ||
             ((grids_vector[5] == true && (x == 40 && y == 5)) && (O_X[5] == 2)) ||
             ((grids_vector[6] == true && (x == 36 && y == 9)) && (O_X[6] == 2)) ||
             ((grids_vector[7] == true && (x == 36 && y == 7)) && (O_X[7] == 2)) ||
             ((grids_vector[8] == true && (x == 36 && y == 5)) && (O_X[8] == 2))
            )

            )
            {
              std::cout<<"X";
            }
            //check 3 X's diagonal to each other player two wins
            else if
            (
             ((O_X[0] == 2) && (O_X[1] == 2) && (O_X[2] == 2)) ||
             ((O_X[3] == 2) && (O_X[4] == 2) && (O_X[5] == 2)) ||
             ((O_X[6] == 2) && (O_X[7] == 2) && (O_X[8] == 2))
            )
            {
                std::cout<<"player two has won! (X)";
                gameOVER = true;
            }
            //check 3 X's diagonal to each other player two wins
            else if
            (
             ((O_X[0] == 2) && (O_X[3] == 2) && (O_X[6] == 2)) ||
             ((O_X[1] == 2) && (O_X[4] == 2) && (O_X[7] == 2)) ||
             ((O_X[2] == 2) && (O_X[5] == 2) && (O_X[8] == 2))
            )
            {
                std::cout<<"player two has won! (X)";
                gameOVER = true;
            }
            //check 3 X's diagonal to each other player two wins
            else if
            (
             ((O_X[8] == 2) && (O_X[4] == 2) && (O_X[0] == 2)) ||
             ((O_X[2] == 2) && (O_X[4] == 2) && (O_X[6] == 2))
            )
            {
                std::cout<<"player two has won! (X)";
                gameOVER = true;
            }
            else {
             std::cout<<" ";
            }}
       }}
void Input() {
bool flag = false;
for (int t = 0; t < 9; t++)
{
  grid_values_to_pass.push_back(false);
  value_to_pass_OX.push_back(0);
}
    char input = '\0';
    if (flag == false)
    {
     std::cin>>input;
    }
    //For loop code tracks which key user types into the ternimal
    //into logic function and returns the flag of that grid to true all grids by defualt are set to false.
    //when a grid flag is set to true one of the player icons will appear either X or O
    //When set to false nothing will appear
    for (
       int i = 0;
       (
       input == 'a' || input == 'b' || input == 'c' ||
       input == 'd' || input == 'e' || input == 'f' ||
       input == 'g' || input == 'h' || input == 'i'
       )
       && gameOVER == false; i++
       )
       {
    std::cin>>input;
    std::cout<<"\a"<<std::endl;
    if (i % 2 == 0) {
        switch ((int)input) {
          case 97:
              grid_values_to_pass.at(0) = true;
              value_to_pass_OX[0] = 1;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 98:
              grid_values_to_pass.at(1) = true;
              value_to_pass_OX[1] = 1;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 99:
              grid_values_to_pass.at(2) = true;
              value_to_pass_OX[2] = 1;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 100:
              grid_values_to_pass.at(3) = true;
              value_to_pass_OX[3] = 1;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 101:
              grid_values_to_pass.at(4) = true;
              value_to_pass_OX[4] = 1;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 102:
              grid_values_to_pass.at(5) = true;
              value_to_pass_OX[5] = 1;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 103:
              grid_values_to_pass.at(6) = true;
              value_to_pass_OX[6] = 1;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 104:
              grid_values_to_pass.at(7) = true;
              value_to_pass_OX[7] = 1;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 105:
              grid_values_to_pass.at(8) = true;
              value_to_pass_OX[8] = 1;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
            }
           std::cout<<"Player 2:"<<std::endl;
    }
    else {
        switch ((int)input) {
          case 97:
              grid_values_to_pass.at(0) = true;
              value_to_pass_OX[0] = 2;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 98:
              grid_values_to_pass.at(1) = true;
              value_to_pass_OX[1] = 2;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 99:
              grid_values_to_pass.at(2) = true;
              value_to_pass_OX[2] = 2;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 100:
              grid_values_to_pass.at(3) = true;
              value_to_pass_OX[3] = 2;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 101:
              grid_values_to_pass.at(4) = true;
              value_to_pass_OX[4] = 2;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 102:
              grid_values_to_pass.at(5) = true;
              value_to_pass_OX[5] = 2;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 103:
              grid_values_to_pass.at(6) = true;
              value_to_pass_OX[6] = 2;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 104:
              grid_values_to_pass.at(7) = true;
              value_to_pass_OX[7] = 2;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
          case 105:
              grid_values_to_pass.at(8) = true;
              value_to_pass_OX[8] = 2;
              Logic(grid_values_to_pass, value_to_pass_OX);
              break;
            }
          std::cout<<"Player 1:"<<std::endl;
    }
    }
}
void StartGame()
 {
displayHowToPlay();
if (gameOVER == false) { Input(); }
 }
void loadCredits()
{
for (int r=0;r==15;r++)
{
while (r < 13)
{
std::cout<<" \n";
}
}
std::cout<<"Thank you for playing this simple snake game :)\n";
std::cout<<"\n";
std::cout<<"***********************************************\n";
std::cout<<"\n";
std::cout<<"***********************************************\n";
std::cout<<"\n";
std::cout<<"Developer: Jason K Moses\n"; }
void SideMenu()
{
printf("WELCOMNE TO THE MENU PLZ ENTER YOUR NAMES BELOW.\n");
std::cout<<"Name:";
std::cin>>name;
std::ofstream outputFile;
outputFile.open
(
"names.txt",
std::ios::app|std::ios::out|std::ios::in
);
//saves names
for(int p=0;p<1 && name!="";p++)
{
    NAMES[p] = name;
    std::string str;
    (p==0)?str=NAMES[p]+"\n":str=","+NAMES[p]+"\n";
    outputFile<<str;
}
outputFile.close();
std::cout<<"Please Select a option only write the number"<<std::endl;
std::cout<<"1.) Start Game\n";
std::cout<<"2.) Records\n";
std::cout<<"3.) Exit Game\n";
std::cout<<"4.) Credits\n";
std::cin>>Inp;
switch(Inp)
{
  case 1:StartGame();break;
  case 2:ofile.open("names.txt");
  for (int e = 0; e < SIZE_OF_NAME_ARRAY; e++)
  {
   ofile >> Names_To_Printed[e];
      std::cout<<"Names of Players:"<<std::endl;
   std::cout<<Names_To_Printed[e];
  }
  break;
  case 3:exit(0);break;
  case 4:loadCredits();break;
  }
}
int main()
  {
    gameOVER = false;
    std::cout<<"Tick Tack Toe  ðŸ"<<std::endl;
    std::cout<<"Made by Jason Moses \n";
    std::cout<<"Created in C++ \n";
    std::cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<std::endl;
    SideMenu();
   }



