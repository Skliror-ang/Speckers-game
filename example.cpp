#include "specker_game.h"
using namespace std;

int main(){

    Game letsplay(10, 8);

for (int i=0 ; i<8;i++){
    letsplay.addHeap(i*4);       //adds i*4 coins to the ith heap 
}

    letsplay.addHeap(94);          //adds 94 coins to the 9th heap
    letsplay.addHeap(0);           //adds 0 coint to the 10th heap 

    // we have heaps with coins: 4 8 12 16 20 24 28 32 94 0
    
    GreedyPlayer greedy1("Babis") ;
    GreedyPlayer* player1 = &greedy1 ;
    letsplay.addPlayer(player1);

    GreedyPlayer greedy2("player2") ;
    GreedyPlayer* player2 = &greedy2 ;
    letsplay.addPlayer(player2);

    SpartanPlayer spartan1("leonidas");
    SpartanPlayer* player3 = &spartan1;
    letsplay.addPlayer(player3);

    SpartanPlayer spartan2("player4");               //add all the players 
    SpartanPlayer* player4 = &spartan2;
    letsplay.addPlayer(player4);

    SneakyPlayer sneaky1("nick");
    SneakyPlayer* player5 = &sneaky1;
    letsplay.addPlayer(player5);

    SneakyPlayer sneaky2("player6");
    SneakyPlayer* player6 = &sneaky2;
    letsplay.addPlayer(player6);

    RighteousPlayer right1("chris");
    RighteousPlayer* player7 = &right1;
    letsplay.addPlayer(player7);

    RighteousPlayer right2("player8");
    RighteousPlayer* player8 = &right2;
    letsplay.addPlayer(player2);

    letsplay.play();

}

