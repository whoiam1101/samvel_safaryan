#ifndef HUMAN_HUMAN_H
#define HUMAN_HUMAN_H

#include "enums/myenums.h"

using HumanEnums::Gender;
using DrinkAndFoodEnums::Drink;
using DrinkAndFoodEnums::Food;
using Colors::Color;

class Human {
private:
    Gender _gender;

    Color _eye_color;
    Color _hair_color;

    Human* _mother;
    Human* _father;

    unsigned int _physical_health_level;
    unsigned int _mental_health_level;

protected:
    virtual void work()  = 0;
    virtual void dance() = 0;

public:
    Human() {
        _physical_health_level = 100;
        _mental_health_level   = 100;
    }

    Human(
        Gender gender,
        unsigned int physical_health_level,
        unsigned int mental_health_level,
        Human* mother,
        Human* father
    ) {
        _gender = gender;

        _physical_health_level = physical_health_level;
        _mental_health_level   = mental_health_level;

        _mother = mother;
        _father = father;
    }

    char* speak(char*) const;

    void think();
    void walk();
    void digestion(Food);
    void digestion(Drink);
    void drink(Drink);
    void eat(Food);

    void setHairColor(Color);
};

#endif