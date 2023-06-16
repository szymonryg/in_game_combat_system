//
// Created by timo0 on 18.05.2023.
//

#ifndef IN_GAME_COMBAT_SYSTEM_CHARACTER_H
#define IN_GAME_COMBAT_SYSTEM_CHARACTER_H

#include <string>

class character {
public:
    explicit character();
    void take_damage(int dmg);
    virtual void special_attack(character* en);
    int get_health();
    int get_stamina();
    int get_movement();
    int get_attack();
    std::string get_name();
    std::string get_stamina_name();
    std::string get_ability_name();
protected:
    int hp;
    int stamina;
    int movement;
    int attack_points;
    std::string stamina_name;
    std::string name;
    std::string ability_name;
};

class warrior : public character{
public:
    warrior();
    void special_attack(character* en) override;
};

class archer : public character{
public:
    archer();
    void special_attack(character* en) override;
};

class sorcerer : public character{
public:
    sorcerer();
    void special_attack(character* en) override;
};

class enemy : public character{
public:
    enemy();
};


#endif //IN_GAME_COMBAT_SYSTEM_CHARACTER_H
