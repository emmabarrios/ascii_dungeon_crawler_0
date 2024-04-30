#include <iostream>
#include "./map.h"
#include "./player.h"
#include "./game_manager.h"

class Game{
private:
    int direction;
    int* p_direction = &direction;
    Map map;
    Player player;
    GameManager gm;

public:
    enum GameState {on, off, combat, explore};
    GameState gameState = off;
    bool IsRunning();
    void Stop();
    void Start();
    Game();
    ~Game();
    int GetInput();
    void SetInput();
    void SetInput(int a);
    void ProcessInput();
    void Update();
    void Render();
    void Initialize(std::string mapFilePath);
    void SetPlayerOnMap();
};