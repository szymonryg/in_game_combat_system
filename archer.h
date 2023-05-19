//
// Created by timo0 on 19.05.2023.
//

#ifndef IN_GAME_COMBAT_SYSTEM_ARCHER_H
#define IN_GAME_COMBAT_SYSTEM_ARCHER_H

#include "character.h"

class archer : public character{
public:
    explicit archer();
    int get_arrows();
private:
    int arrows;
};


#endif //IN_GAME_COMBAT_SYSTEM_ARCHER_H
