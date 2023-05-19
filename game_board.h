//
// Created by timo0 on 18.05.2023.
//

#ifndef IN_GAME_COMBAT_SYSTEM_GAME_BOARD_H
#define IN_GAME_COMBAT_SYSTEM_GAME_BOARD_H

#include "character.h"

class game_board {
public:
    struct position{
        int x;
        int y;
    };

    void move_player();
    void move_enemy();
    position get_player_position();
    position get_enemy_position();
    bool attack_possible();
    void reset_board();
private:
    character board1[10][10];
    position player_position;
    position enemy_position;

};


#endif //IN_GAME_COMBAT_SYSTEM_GAME_BOARD_H
