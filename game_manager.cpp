#include "./headers/game_manager.h"

void GameManager::AddItem(int n){
    this->itemCounter += n;
}
int GameManager::GetItemCounter(){
    return itemCounter;
}