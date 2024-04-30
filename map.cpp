#include "./headers/map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <locale>
#include <codecvt>


Map::Map(){
}
bool Map::IsMapLoaded(){
    return mapLoaded;
}
void Map::LoadMap(std::string filepath){
    std::wifstream file(filepath);
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));

    std::wstring line;
    int row = 0; // Start at the first row

    if (!file.is_open()) {
        std::wcerr << L"Failed to open the file." << std::endl;
        return;
    }

    std::cout<<"printing map"<<std::endl;

    while (getline(file, line) && row < ROWS) {
        for (int col = 0; col < line.size() && col < COLUMNS; ++col) {
            map[row][col] = line[col];
        }
        row++;
    }
    p_start = &map[1][1];
    file.close();
    mapLoaded = true;
}
int Map::GetRows(){
    return ROWS;
}
int Map::GetColumns(){
    return COLUMNS;
}
wchar_t* Map::GetStartingLocation(){
    return p_start;
}
