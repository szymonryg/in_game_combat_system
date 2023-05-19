//
// Created by timo0 on 18.05.2023.
//

#ifndef IN_GAME_COMBAT_SYSTEM_CHARACTER_H
#define IN_GAME_COMBAT_SYSTEM_CHARACTER_H


class character {
public:
    explicit character();
    void take_damage(int dmg);
    void basic_attack();
    void special_attack();
    int get_health();
    int get_stamina();
    int get_movement();
    int get_attack();
private:
    int hp;
    int stamina;
    int movement;
    int attack_points;
};


#endif //IN_GAME_COMBAT_SYSTEM_CHARACTER_H
