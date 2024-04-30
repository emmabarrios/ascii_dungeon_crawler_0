#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <locale>
#include <codecvt>
#include "./game.h"

int main() {
    Game game;
    
    game.Initialize("./map.txt");
    game.Start();

    while (game.IsRunning())
    {
        game.Render();
        game.ProcessInput();
        game.Update();
    }
    
    return 0;
}