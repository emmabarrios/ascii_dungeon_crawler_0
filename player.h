#pragma once

#include <iostream>

struct Player{
    Player();
    Player(wchar_t* loc, wchar_t c);
    void UpdateLocation(wchar_t* loc);
    void UpdateDirection(int dir);
    wchar_t* loc;
    wchar_t c;
    int dir;
};