#pragma once

#include<iostream>  
#include"specker_move_state.h"  
using namespace std;  
  
  
  
class Player {  
protected:  
    string name;  
  
public:  
    Player() { name = "no name player"; }  
  
    Player(const string& n) {  
        name = n;  
    }  
  
    virtual ~Player() {  
          
    }  
  
    virtual const string& getType() const = 0;  
  
    virtual Move play(const State& s) = 0;  
  
    friend ostream& operator << (ostream& out, const Player& player)  
    {  
        out << player.getType() << " player " << player.name;  
        return out;  
    }  
  
};  
  
  
class GreedyPlayer : public Player {  
protected:  
    string type;  
  
public:  
  
    GreedyPlayer(const string& n) :  
        Player(n),  
        type("Greedy") {}  
      
    ~GreedyPlayer() override { ; }  
      
    const string& getType() const override {  
        return type;  
    }  
  
    Move play(const State& s) override{  
          
        int maxcoins = s.getCoins(0);  
        int maxheaps = 0;  
  
        for (int i = 0; i < s.getHeaps(); i++) {  
            if (s.getCoins(i) > maxcoins) {  
                maxcoins = s.getCoins(i);  
                maxheaps = i;  
                }  
        }  
        return Move(maxheaps, s.getCoins(maxheaps), 0,0);  
    }  
  
};  
  
  
class SpartanPlayer : public Player {  
protected:  
    string type;  
  
public:  
  
    SpartanPlayer(const string& n) :  
        Player(n),  
        type("Spartan") {  
    }  
  
    ~SpartanPlayer() override { ; }  
  
    const string& getType() const override {  
        return type;  
    }  
  
    Move play(const State& s) override {  
  
        int maxcoins = s.getCoins(0);  
        int maxheaps = 0;  
  
        for (int i = 0; i < s.getHeaps(); i++) {  
            if (s.getCoins(i) > maxcoins) {  
                maxcoins = s.getCoins(i);  
                maxheaps = i;  
            }  
        }  
        return Move(maxheaps, 1,0,0);  
    }  
};  
  
  
class SneakyPlayer : public Player {  
protected:  
    string type;  
  
public:  
  
    SneakyPlayer(const string& n) :  
        Player(n),  
        type("Sneaky") {  
    }  
  
    ~SneakyPlayer() override { ; }  
  
    const string& getType() const override {  
        return type;  
    }  
  
    Move play(const State& s) override {  
  
        int mincoins = 44343;  
        int minheaps = 0;  
  
        for (int i = 0; i < s.getHeaps(); i++) {  
            if (s.getCoins(i) < mincoins && s.getCoins(i)!=0) {  
                mincoins = s.getCoins(i);  
                minheaps = i;  
            }  
        }  
        return Move(minheaps, s.getCoins(minheaps),0,0);  
    }  
};  
  
class RighteousPlayer : public Player {  
protected:  
    string type;  
  
public:  
  
    RighteousPlayer(const string& n) :  
        Player(n),  
        type("Righteous") {  
    }  
  
    ~RighteousPlayer() override { ; }  
  
    const string& getType() const override {  
        return type;  
    }  
  
    Move play(const State& s) override {  
  
        int maxcoins = s.getCoins(0);  
        int maxheaps = 0;  
  
        for (int i = 0; i < s.getHeaps(); i++) {  
            if (s.getCoins(i) > maxcoins) {  
                maxcoins = s.getCoins(i);  
                maxheaps = i;  
            }  
        }  
  
        int mincoins = 56758;  
        int minheaps = 0;  
  
        for (int i = 0; i < s.getHeaps(); i++) {  
            if (s.getCoins(i) < mincoins ) {  
                mincoins = s.getCoins(i);  
                minheaps = i;  
            }  
        }  
        if (maxcoins % 2 == 0) {  
            return Move(maxheaps, maxcoins / 2, minheaps, maxcoins / 2 - 1);  
        }  
        else {  
            return Move(maxheaps, maxcoins / 2 + 1, minheaps, maxcoins / 2);  
        }  
          
    }  
};  