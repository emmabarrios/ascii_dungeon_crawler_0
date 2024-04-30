#include "./Game.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

#include <conio.h>
#include <vector>
#include <locale>
#include <codecvt>
#include "./map.h"
#include "./game_manager.h"

Game::Game(){
    // std::cout<<"Game started"<<std::endl;
}
Game::~Game(){
    // std::cout<<"Game destroyed"<<std::endl;
}
int Game::GetInput(){
    if (p_direction){
        return *p_direction;
    }
    return 0;
}
void Game::SetInput(){
    *p_direction =  _getch();
}
void Game::SetInput(int a){
    *p_direction = a;
}
void Game::ProcessInput(){
    SetInput(0);
    while (GetInput() == 0)
    {
        if (_kbhit()){

            SetInput(); 

            if (GetInput() == 27)
            {
                 Stop(); 
            }
        }
    }
}
bool Game::IsRunning(){
    return gameState == on;
}
void Game::Stop(){
    gameState = off;
}
void Game::Start(){
    gameState = on;
}
void Game::Update(){

    wchar_t* newLocation;
    newLocation = player.loc;

    // update movement
    switch (GetInput())
    {
    case 75:
        newLocation = player.loc - 1;
        player.UpdateDirection(3);
        
        if (*newLocation != L'█')
        {
            if (*newLocation == L'×')
            {
                gm.AddItem(1);
                *newLocation = L'·';
            }
            std::swap(*player.loc, *newLocation);
            player.loc = newLocation;
        }
        break;
    case 77:
        newLocation = player.loc + 1;
        player.UpdateDirection(1);

        if (*newLocation != L'█')
        {
            if (*newLocation == L'×')
            {
                gm.AddItem(1);
                *newLocation = L'·';
            }
            std::swap(*player.loc, *newLocation);
            player.loc = newLocation;
        }
        break;
    case 72:
        newLocation = player.loc - map.GetColumns();
        player.UpdateDirection(0);

        if (*newLocation != L'█')
        {
            if (*newLocation == L'×')
            {
                gm.AddItem(1);
                *newLocation = L'·';
            }
            std::swap(*player.loc, *newLocation);
            player.loc = newLocation;
        }
        break;
    case 80:
        newLocation = player.loc + map.GetColumns();
        player.UpdateDirection(2);

        if (*newLocation != L'█')
        {
            if (*newLocation == L'×')
            {
                gm.AddItem(1);
                *newLocation = L'·';
            }
            std::swap(*player.loc, *newLocation);
            player.loc = newLocation;
        }
        break;
    default:
        break;
    }


}
void Game::Render(){

    // render map
    if (map.IsMapLoaded())
    {
        system("cls");

        for (int i = 0; i < map.GetRows(); ++i) {
            for (int j = 0; j < map.GetColumns(); ++j) {
                std::wcout << map.map[i][j] << "";
            }
            std::wcout << std::endl;
        }
    }
   
   // render UI
   if (gm.GetItemCounter()>=5)
   {
    std::cout<<"CONGRATS! YOU'VE FOUND ALL THE ITEMS!"<<std::endl;
    Stop();
   }
   
   std::cout<<"Items found: "<<gm.GetItemCounter()<<std::endl;

   
}
void Game::Initialize(std::string mapFilePath){
    std::setlocale(LC_ALL, "en_US.UTF-8");  // Set locale to use UTF-8
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    map = Map();
    map.LoadMap(mapFilePath);

    player = Player(map.GetStartingLocation(), L'►');
    SetPlayerOnMap();

    gm = GameManager();
}
void Game::SetPlayerOnMap(){
    *player.loc =  player.c;
}
