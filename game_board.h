//
// Created by timo0 on 18.05.2023.
//

#ifndef IN_GAME_COMBAT_SYSTEM_GAME_BOARD_H
#define IN_GAME_COMBAT_SYSTEM_GAME_BOARD_H

#include <cmath>
#include "character.h"

class game_board {
public:
    struct position{
        int x;
        int y;
    };

    explicit game_board();
    void move_cursor(int x, int y);
    void reset_cursor();
    void move_player(position cursor);
    void move_enemy(int x, int y);
    position get_player_position();
    position get_enemy_position();
    position get_cursor_position();
    bool move_possible(position character_position, int movement_points);
    bool attack_possible();
    void reset_board();
    char board1[9][9];
private:
    position cursor_position;
    position player_position;
    position enemy_position;

};


#endif //IN_GAME_COMBAT_SYSTEM_GAME_BOARD_H
