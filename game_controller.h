//
// Created by timo0 on 18.05.2023.
//

#ifndef IN_GAME_COMBAT_SYSTEM_GAME_CONTROLLER_H
#define IN_GAME_COMBAT_SYSTEM_GAME_CONTROLLER_H

#include "game_model.h"
#include "game_view.h"

class game_controller {
public:
    explicit game_controller(game_model& model, game_view& view);
    void launch();
    void player_turn();
    void enemy_turn();
private:
    game_model& model;
    game_view& view;
};


#endif //IN_GAME_COMBAT_SYSTEM_GAME_CONTROLLER_H
