//
// Created by timo0 on 18.05.2023.
//


#include "game_controller.h"


game_controller::game_controller(game_model& model, game_view& view) : model(model), view(view) {

}

void game_controller::menu() {
    this->view.menu();
    int key;
    do {
        key = getch();
        this->view.menu();

    }
    while(key != 27);
}

void game_controller::player_turn() {
    int key;
    bool move = true;
    do {
        key = getch();
        this->view.player_turn_update();
        if(key == 49 && move) {
            this->move();
            move = false;
        }
        else if(key == 50  && this->model.board.attack_possible()) {
            this->model.get_enemy().take_damage(20);
        }
        else if(key == 51) {
            this->model.get_player().special_attack();
        }
    }
    while(key != 52);

}

void game_controller::cursor() {
    this->view.player_turn_update();
    int key;
    do{
        key = getch();
        if(key == 119 && model.board.get_cursor_position().y != 0)
            this->model.board.move_cursor(0, -1);
        else if(key == 115 && model.board.get_cursor_position().y != 8)
            this->model.board.move_cursor(0, 1);
        else if(key == 97 && model.board.get_cursor_position().x != 0)
            this->model.board.move_cursor(-1, 0);
        else if(key == 100 && model.board.get_cursor_position().x != 8)
            this->model.board.move_cursor(1, 0);
        this->view.player_turn_update();
    }
    while(key != 32);
}

void game_controller::move() {
    while(true) {
        this->cursor();
        if (this->model.board.move_possible(this->model.board.get_player_position(),
                                            this->model.get_player().get_movement())) {
            if((this->model.board.get_cursor_position().x != this->model.board.get_player_position().x) || (this->model.board.get_cursor_position().y != this->model.board.get_player_position().y )) {
                if((this->model.board.get_cursor_position().x != this->model.board.get_enemy_position().x) || (this->model.board.get_cursor_position().y != this->model.board.get_enemy_position().y )) {
                    this->model.board.move_player(this->model.board.get_cursor_position());
                    break;
                }
            }

        }
    }

}

void game_controller::enemy_turn() {

}

void game_controller::launch() {
    this->player_turn();
    //this->cursor();
    //this->player_turn();
    //this->menu();
}








