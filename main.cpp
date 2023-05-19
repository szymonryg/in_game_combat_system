#include <iostream>
#include "game_controller.h"

int main() {
    game_board board{};
    game_model model(board);
    game_view view(model);
    game_controller game(model, view);

    game.launch();
    return 0;
}
