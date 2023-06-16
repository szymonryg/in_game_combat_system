//
// Created by timo0 on 18.05.2023.
//


#include "game_controller.h"


game_controller::game_controller(game_model& model, game_view& view) : model(model), view(view) {

}

bool game_controller::menu() {
    this->view.menu();
    int key;
    do {
        key = getch();
        this->view.menu();
        if(key == 49 || key == 50 || key == 51){

            this->model.choose_character(key - 48);
            return true;
        }
    }
    while(key != 27);
    return false;
}

void game_controller::player_turn() {
    int key;
    bool move = true;
    bool attack = true;
    comm = "Your turn";
    this->view.turn_update(comm);
    comm = "";
    do {
        key = getch();
        this->view.turn_update(comm);
        if(key == 49 && move) {
            this->move();
            this->view.turn_update(comm);
            move = false;
        }
        else if(key == 50  && this->model.board.attack_possible() && attack) {
            this->model.get_enemy()->take_damage(this->model.get_player()->get_attack());
            this->view.turn_update(comm);
            attack = false;
        }
        else if(key == 51 && attack) {
            this->model.get_player()->special_attack(this->model.get_enemy());
            this->view.turn_update(comm);
            attack = false;
        }
        if(this->model.win())
            break;
        if(!attack && !move)
            break;
    }
    while(key != 52);
}

void game_controller::cursor() {
    this->model.board.board1[this->model.board.get_cursor_position().y][this->model.board.get_cursor_position().x] = '+';
    comm = "Move";
    this->view.turn_update(comm);
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
        this->view.turn_update(comm);
    }
    while(key != 32);
    comm = "";
}

void game_controller::move() {
    while(true) {
        this->cursor();
        if (this->model.board.move_possible(this->model.board.get_player_position(),
                                            this->model.get_player()->get_movement())) {
            if((this->model.board.get_cursor_position().x != this->model.board.get_player_position().x) || (this->model.board.get_cursor_position().y != this->model.board.get_player_position().y )) {
                if((this->model.board.get_cursor_position().x != this->model.board.get_enemy_position().x) || (this->model.board.get_cursor_position().y != this->model.board.get_enemy_position().y )) {
                    this->model.board.move_player(this->model.board.get_cursor_position());
                    this->model.board.reset_cursor();
                    break;
                }
            }

        }
    }

}

void game_controller::enemy_turn() {
    this->view.turn_update("Enemy turn");
    getch();
    if(this->model.board.attack_possible()){
        this->model.get_player()->take_damage(this->model.get_enemy()->get_attack());
    }
    else {
        this->model.get_player()->take_damage(5);
    }
}

bool game_controller::play_again() {
    int key;
    do {
        key = getch();
        if(key == 49)
            return true;
    }
    while(key != 27);
    return false;
}

void game_controller::launch() {
    bool play = true;
    bool new_game = false;
    play = this->menu();
    while(play) {
        if(new_game){
            if(!this->menu())
                break;
            this->model.board.reset_board();
            this->view.turn_update(comm);
            new_game = false;
        }

        this->player_turn();
        if(this->model.win()){
            this->view.win();
            play = this->play_again();
            new_game = play;
        }

        this->enemy_turn();
        if (this->model.lose()) {
            this->view.lose();
            play = this->play_again();
            new_game = play;
        }
    }
}

