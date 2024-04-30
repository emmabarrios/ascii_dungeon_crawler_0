#include<iostream>
#include "./headers/player.h"

Player::Player(){};
Player::Player(wchar_t* loc, wchar_t c){
    this-> loc = loc;
    this-> c = c;
}
void Player::UpdateDirection(int dir){
    this->dir = dir;
    switch (dir)
    {
    case 0:
    c = L'▲';
        break;
    case 1:
    c = L'►';
        break;
    case 2:
    c = L'▼';
        break;
    case 3:
    c = L'◄';
        break;
    default:
        break;
    }
    *loc = c;
}