#pragma once

struct GameManager{
private:
    int itemCounter;
public:
    int GetItemCounter();
    void AddItem(int n);
};