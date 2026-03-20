this is an implementation of a series of header files aimed on creating a version of specker's game


------Game description-------------------------------------
this is a multi-plyaer game.It consists of a number of heaps where each heaps contains a number of coins.
the players take turns removing m coins from one heap and adding n coins to any (one) other where 0 <= n < m. the game ends when there are not any coins left in any heap and the winner is th elast person to play.


--------------------description of header files---------------------

specker_move_state : 
    this contains the class definitions and implementations of the methods for the Class : Move which defines ,as the name says, the move that is about to take place.
    also the class State: which handles the game's state (how many players there are, who is playing, and the coins per heap as well as the amount of heaps) throwing exceptions for any invalid state. 
        this class has the following methods:
        
        - State(int heaps, const int coins[], int number_of_players) : constructor. takes as parameters the amount of heaps, an array of integers representing the coins in each heap and the number of players

        - void next(const Move& move) it takes a move object as a parameter and updates the state that arises as if that move had been played, if the move is invalid according to the current state, an exception is thrown

        -bool winning() const : checks if the game has ended

        -friend ostream& operator<<(ostream& out, const State &state) : prints the state 


specker_players : 

    this contains the class player which represents the Player and his way of playing. its main goal is to be inherited by the classe "typeofplayer"Player which define diferent plaing types. these playing types will be described later.
        we have the following methods:

        -Player(const string& n) : constructor takes as input the player name, if ommited it gives a default name

        -virtual const string& getType() const = 0; : virtual method meant to return the type of the player 

        -virtual Move play(const State& s) = 0;   : virtual and is meant to produce the move of the player according to the state that is given.

        - friend ostream& operator << (ostream& out, const Player& player) : print the type and name of the player 

        types of players:
            -GreedyPlayer : takes all the coins from the heap with the most amount of coins and puts back nothing

            -SpartanPlayer : takes one coin from the heap with the most coins and return nothing 

            -SneakyPlayer : takes all the coins from the heap with the least amount of coins and puts nothing

            -RighteousPLayer : takes all the coins from the heap with the most amount of coins and puts half in the heap with the least coins 


specker_game :

    this is the only one that needs to be included in order to play since it includes all the others. the goal of this class is to simulate the actual game taking place.
        We have th efollowing methods:

        -Game(int heaps, int players) : constructor takes the amount of heaps and players

        -void addHeap(int coins) : adds heap to the game with coins amount of coins. if with the added player the number of heaps is exceded or the number of coins is negative exceptions are thrown

        -void addPlayer(Player *player) : adds the player to the game, if with that addition there are more players than the number given in the constructor an exception is thrown

        -void play(ostream& out) : runs te actuall game and prints each new state and the winner.

there is also included a piece of code to act as an example upon the use of these. 




