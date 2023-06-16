//
// Created by timo0 on 18.05.2023.
//

#ifndef IN_GAME_COMBAT_SYSTEM_GAME_VIEW_H
#define IN_GAME_COMBAT_SYSTEM_GAME_VIEW_H

#include <string>
#include "game_model.h"

class game_view {
public:
    explicit game_view(game_model& model);
    void menu();
    void turn_update(std::string comm);
    void win();
    void lose();
private:
    game_model& model;
};


#endif //IN_GAME_COMBAT_SYSTEM_GAME_VIEW_H
