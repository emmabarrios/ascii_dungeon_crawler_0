#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <locale>
#include <codecvt>

class Map{
private:
    bool mapLoaded = false;
    static const int ROWS = 8;
    static const int COLUMNS = 20;
    wchar_t* p_start;
public:
    int GetRows();
    int GetColumns();
    wchar_t map[ROWS][COLUMNS];
    Map();
    bool IsMapLoaded();
    void LoadMap(std::string filepath);
    wchar_t* GetStartingLocation();
};