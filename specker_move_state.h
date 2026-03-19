#pragma once

#include<iostream>  
#include<exception>  
#include<stdexcept>  
using namespace std;  
  
  
  
class Move {  
protected:  
    int source_h, source_c, target_h, target_c;  
  
public:  
    Move(int sh, int sc, int th, int tc) {  
        source_h = sh;  
        source_c = sc;  
        target_h = th;  
        target_c = tc;  
    }  
  
    int getSource() const {  
        return source_h;  
    }  
  
    int getSourceCoins() const {  
        return source_c;  
    }  
  
    int getTarget() const {  
        return target_h;  
    }  
  
    int getTargetCoins() const {  
        return target_c;  
    }  
  
    friend ostream& operator <<(ostream& out, Move& move) {  
        if (move.target_c > 0) {  
            out << "takes " << move.source_c << " coins from heap " << move.source_h <<  
                " and puts " << move.target_c << " coins to heap " << move.target_h;  
        }  
        else {  
            out << "takes " << move.source_c << " coins from heap " << move.source_h <<  
                " and puts nothing";  
        }  
        return out;  
    }  
};  
  
  
class State {  
protected:  
  
    int heaps;  
    int* coins;  
    int players;  
    int playing ;  
  
public:  
  
    State(int h, const int c[], int n) {  
        heaps = h;  
        coins = new int[heaps];  
  
        for (int i = 0; i < heaps; i++) {  
            coins[i] = c[i];  
        }  
  
        players = n - 1;  
        playing = 0;  
  
    }  
  
    ~State() {  
        delete [] coins;  
    }  
  
    void next(const Move& move) {  
            bool a = (move.getSource() < 0 || move.getSource() >= heaps  
                || move.getSourceCoins() <= 0  
                || move.getSourceCoins() > coins[move.getSource()]  
                || move.getTarget() < 0 || move.getTarget() >= heaps  
                || move.getTargetCoins() >= move.getSourceCoins()  
                || move.getTargetCoins()<0);  
  
            if (a) { throw logic_error("invalid move"); }  
  
            coins[move.getSource()] -= move.getSourceCoins();  
            coins[move.getTarget()] += move.getTargetCoins();  
  
            //if (winning())return;  
            /*else*/ if (playing == players) playing = 0;  
            else playing ++;  
  
          
    }  
  
    bool winning() const {  
        bool a = true;  
        for (int i = 0; i < heaps; i++) {  
            if (coins[i] != 0) { a = false; break; }  
        }  
  
        return a;  
    };  
  
    int getHeaps() const {  
        return heaps;  
    }  
  
    int getCoins(int h) const {  
            if (h >= heaps || h < 0) { throw logic_error("invalid heap"); }    
            return coins[h];  
          
    }  
  
    int getPlayers() {  
        return players+1;  
    }  
  
    int getPlaying() {  
        return playing;  
    }  
  
    friend ostream& operator<<(ostream& out, const State &state) {  
      
        for (int i = 0; i < state.heaps - 1; i++) {  
            out << state.coins[i] << ", ";  
        }  
        out << state.coins[state.heaps - 1] << " with " << state.playing << "/" << state.players + 1 << " playing next";  
        return out;  
    }  
  
};