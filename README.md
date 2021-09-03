# Tick-Tac-Toe
#How to play the game

1) The Game first starts with entering your names below saving a new record into the text file which can be read in the ternimal in the next steps

2) Next The menu will be presented with 4 options:

option 1) Start Game this will start the game by presenting a guide on how to play the actual game each grid represents a letter that can either be an O or X by default player one is O this can be changed in the code by switching all occurrences of the strings "O' with "X" around also since all consoles are different *change WIDTH and Height to values that fit your console this will draw the grid and everything on it for your specific console the default is the mac default terminal. The first player to get three of the symbols "X' or "O" into either a row, column or a diagonal line. Figure 1 shows the grid with which input letters will result in a place into the specific blocks of the grid While Figure 2 - 4 shows all the possible wins a player can do to win as discussed before X has been used but O could also be used.


         ____________                                                        
         | I | F | C |                                                                  
         ____________                                                                   
         | H | E | B |                                                                   
         ____________                                                                   
         | G | D | A |                                                                  
         ____________  
         
         Figure 1 ⬆︎
         
         ____________                                                        
         | I | F | X |                                                                  
         ____________                                                                   
         | H | E | X |                                                                   
         ____________                                                                   
         | G | D | X |                                                                  
         ____________  
         
         Figure 2 ⬆︎
         
         ____________                                                        
         | I | F | C |                                                                  
         ____________                                                                   
         | X | X | X |                                                                   
         ____________                                                                   
         | G  | D | A |                                                                  
         ____________  
         
         
         
         Figure 3 ⬆︎
         
         ____________                                                        
         | X | F | C |                                                                  
         ____________                                                                   
         | H | X | B |                                                                   
         ____________                                                                   
         | G | D | X |                                                                  
         ____________  
         
         Figure 4 ⬆︎
        
        
        
 Once the game has been won by a player a message of which player won will be promoted
        
       
 option 2) Will display all previous game records example: Jay Vs Jas Winner Jay
 
 option 3) Show all credits this includes social links and so on
 
 option 4) EXit terminal and console i.e exit game
 
 
 
 #How the game works
 
 Let's start with inputting to the file function is a basic inputting setup  with two names player ones and player twos names
 
 Secondly, we will draw the scene similarly to how I visualize the Snake Game also written in C++
 
 Figure 5 Shows a cartesian plane that best represents this concept 
 We first start by making a cartesian plane this will not be a physical render on our scene/terminal/console.
 But a concept using two for loops we draw an invisible plane this plane than can be used to map functions and points with both y and x values
 Please do note I have reversed the x and y-axis to make it easier to code so the x-axis is now the y axis do not worry about this too much it's just a mistake
 on my part Figure, 5 shows this reverse as well.
 Also please note x and y should only be positive values i.e 
 
 x , y ≥ 0
 
 
                              increase in x
                                  |
                                  |
                                  |
                                  |
        decrease in y ____________|____________ increase in y
                                  |
                                  |
                                  |
                                  |
                                  |
                             decrease in x
                      
                              
                              Figure 5 ⬆︎
                              
 
 Next, we plot the points (i.e we use if / else if / else statements in the loop to draw with parameters as x and y points and player identity 
 we will get to player identity shortly in the statements):
 
 First, we fill all spaces with empty values so we can draw freely think of this as getting a sheet of paper to draw on we std::cout<<" ";
 
 Now that we have our canvas let's paint now we draw the grid I have used a single else if to draw "|" I highly recommend u do as well to keep 
 understanding the code simpler as this is already complex code wise also don't waste your time.
 
 Set the points as shown in Figure 5 where u want them x and y in the else if parameters remember all points to be drawn and rendered must look like this:
 
 (x==34 && y==9) that itself draws a point but due to the power of conditions u will be able to draw many things at once of the same object
 
 an example of this is drawing "|" at the two points (34,9) and (34,7) this can be put into the else if statement as so 
 
 
 else if
        (

        (x==34 && y==9) || (x==38 && y==9)
        
        )
        
        {
          std::cout<<"|";
        }
        
        Code example 1 ⬆︎
        
 
 On our plane, the computer will find points (34,9) and (34,7) in the form (x,y) then draw the value "|" on the first point then the second
 
 now that we get the concept all that's left is to draw the rest "_" and "#" are also drawn the same way. As well as the guide, not the actual player position
 
 To create our player position I've created a vector to store the identity i.e the symbol of the player 'O' or 'X' true = O and false = X
 
 Every odd turn the player will be O and every even turns the player will be X to accomplish this we fix the first issue this is that our current else if statement places X and O values everywhere
 and when the if statement and else on lines 293 and 343 get triggered i.e player turn changes i.e odd turn or even turn the grid will only be filled with that X or O value TO Check the last condition
 
 Which is the state and identity of the player should the X turn into an O this will be separated with a && operator to check if the two other previous conditions were meet with this one the variable I have chosen to represent this is 
 
 O_X which is also the player known as O or X or player identity its an int with values either 
 
 O_X = { 0, 1 ,2 }    
 
 0_X can't be a bool cause " " is treated as its own identity or the program will get confused should it place 0 or 1 when there's nothing
 
 Therefore we use these two out of three numbers for whatever reason we don't include 0 I'm also not aware why in our code but yes we don't include zero at all 
 
#Now that we meet all the three pieces lets go over them:

#1) Which grid to place X or O i.e which grid value a to I will result in which placement.

#2) Which point is this at (x,y).

#3) Player Identity whose the player places.
 
 Lastly depending on which player one we can also write not mathematical plotting into our scene but what to do when constraints are reached you guessed it with an else if function:
  
  this may seem almost impossible but it is quite easy we just use one of our three important variables i.e player identity O_X can check this by checking which values in the vector are set to either {0, 1, 2}
  
    //sloped line check win x if right:
    
            else if
            (
            (O_X[8] == 2) && (O_X[4] == 2) && (O_X[0] == 2) ||
            (O_X[2] == 2) && (O_X[4] == 2) && (O_X[6] == 2)
            )
            {
                std::cout<<"player two has won!";
                gameOVER = true;
            }
            
            Code example 2 ⬆︎
            The above example will check whether the blocks in the grid that create a diagonal line are turned on i.e Figure 3
            
            Now that it is so and we can check who wins all that is left is to write to the file the winner we do this by returning the order of the players name who is the winner.
            
            
            
            #Thank you for the lengthy read I wanted to explain things best as possible 
            #created by Jason K Moses
 
 
 
 
