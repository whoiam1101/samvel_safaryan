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

    unsigned int _eye_color;
    unsigned int _hair_color;

    Human* _mother;
    Human* _father;

    unsigned int _physical_health_level;
    unsigned int _mental_health_level;

protected:
    virtual void work();
    virtual void dance();

public:
    Human() {
        _physical_health_level = 100;
        _mental_health_level   = 100;
    }

    Human(
        Gender _human_gender,
        unsigned int _human_physical_health_level,
        unsigned int _human_mental_health_level,
        Human* _human_mother,
        Human* _human_father
    ) {
        _gender = _human_gender;

        _physical_health_level = _human_physical_health_level;
        _mental_health_level   = _human_mental_health_level;

        _mother = _human_mother;
        _father = _human_father;
    }

    char* speak(char*) const;

    void think();
    void walk();
    void digestion(Food);
    void digestion(Drink);
    void drink(Drink);
    void eat(Food);
    void colorHair(Color);
};

#endif