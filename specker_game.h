#pragma once

#include<iostream>  
#include"specker_players.h"  
#include"specker_move_state.h"  
  
using namespace std;  
  
class Game {  
  
protected:  
    int noheaps;  
    int* c;  
    int noplayers;  
    int cheaps;  
    int cplayers;  
    Player* * p;  
public:  
  
    Game(int heaps, int players) {  
        noheaps = heaps;  
        noplayers = players;  
        c = new int[noheaps];  
        cheaps = 0;  
        cplayers = 0;  
        p = new Player *[noplayers];  
    }  
  
    ~Game() {  
        delete[]c;  
    }  
  
    void addHeap(int coins) {  
          
        if (coins < 0) throw logic_error("invalid number of coins");  
        if (cheaps >= noheaps)throw logic_error("too many heaps");  
          
        c[cheaps++] = coins;  
    }  
  
    void addPlayer(Player *player) {  
        if (cplayers >= noplayers)throw logic_error("too many players");  
        p[cplayers++] = player;  
    }  
  
    void play(ostream& out) {  
  
        State s(noheaps, c, noplayers);  
        int i = 0;  
  
        while (!s.winning()) {  
            Move m(p[i]->play(s));  
  
            out << "State: " << s << '\n'  
                << *p[i] << " " << m << '\n';  
  
            s.next(m);  
  
            if (!s.winning()) {  
                i++;  
                i %= noplayers;  
            }  
  
        }  
  
        if (s.winning()) {  
            out << "State: " << s << '\n' << *p[i] << " wins" << '\n';  
        }  
    }  
  
    int getPlayers() const {  
        return noplayers;  
    }  
  
    const Player* getplayer(int ap) const {  
          
        if (ap >= noplayers)throw logic_error("invalid player");  
        return p[ap];  
    }  
  
  
};  