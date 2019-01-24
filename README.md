# Final Project 
# teaMancala
Fareeha Tabassum and Tania Cao
Period 5

## Description of Project:
Mancala: A two-player board game using marbles or stones.

## Instructions on how to use this project
1. make
2. run ./server
3. on another terminal run ./client
4. complete the directions there (or do step 5-- will result in the same thing) 
5. on another terminal run ./client
6. play the game!

### Rules of the Game:
1.  Each user gets six cups and one mancala(M). The cups and mandala will be formatted as shown below.
    Each player's cups and mancala will be located at the bottom of the board.
        
        M{ } | { } { } { } { } { } { } |      <-- opponent's side
	         | { } { } { } { } { } { } | M{ }  <-- player's side
            
2.  At the start of the game, each cup has 4 marbles
        
        M{ } | {4} {4} {4} {4} {4} {4} |
             | {4} {4} {4} {4} {4} {4} | M{ }

3.  Taking turns, each player inputs their cup of choice.
	All the marbles in that cup will be distributed counter-clockwise into the other cups
    and to the current player's mancala (one per cup).
     a) If the last marble distributed ends up in the current player's mancala, they get an extra play.
	 b) If the last marble distributed ends up in an empty cup located on the current player's side, all
        marbles in the cup directly above as well as the current cup will be placed in the player's mancala.

        M{6} | {3} {5} {1} {3} {6} {2} |
             | {0} {4} {2} {3} {1} {8} | M{4}
                A  B  C  D  E  F
        [Player A] Cup of Choice: F
	    ----- Current Board -----
	    M{6} | {0} {6} {2} {4} {7} {3} |
	         | {0} {4} {2} {3} {1} {0} | M{10}
      
4.  The game ends when all six cups on either side of the board are empty. The player with remaining marbles
    in their cups at the end of a game automatically places the marbles into their own mancala.
    The player with the most marbles in their mancala is the winner of the game.
