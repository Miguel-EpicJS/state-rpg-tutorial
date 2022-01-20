#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <random>


//(50/3) * (pow(x, 3) - 6*pow(x, 2) + (x * 17) - 12)

class Character
{
private:
    
    int x;
    int y;
    
    std::string name;
    std::string bio;

    int level;
    int spiritStones;
    int statpoints;
    
    int exp;
    int expNext;

    int hp;
    int hpMax;

    int stamina;
    int staminaMax;

    int qi;
    int qiMax;

    int defense;

    //attributes
    int lifeEssence; // defense
    int strength; // attack
    int vitalEnergy; // health
    int dexterity; // doge chance and crit
    int perception; // learning
    int absorption; // 'talent'
    double fortune; // luck

    // chances
    int damageMin;
    int damageMax;
    float hitChance;
    float critChance;

    // functions
    void updateStats();


public:
    Character(std::string name, std::string bio);
    virtual ~Character();

    inline const unsigned getSeed() const { return this->x + this->y; }
    inline const int getX() const { return this->x; }
    inline const int getY() const { return this->y; }
    inline const int getLevel() const { return this->level; }
    inline const bool getIsDead() const { return this->hp <= 0; }
    inline const int getHP() const { return this->hp; }
    inline const int getMaxHP() const { return this->hpMax; }
    inline const int getStamina() const { return this->stamina; }
    inline const int getQi() const { return this->qi; }
    inline const int getDamageMin() const { return this->damageMin; }
    inline const int getDamageMax() const { return this->damageMax; }
    inline const int getDefence() const { return this->defense; }
    inline const int getHitChance() const { return this->hitChance; }

    void resetStatus();
    void takeDamage(const int damage);
    void setPosition(const int x, const int y);
    void move(const int x, const int y);
    void setDead();
    void addExp(const unsigned exp);
    bool canLevelUp();
    const std::string toString();
    const std::string getMenuBar();
    const std::string toStringNameBio();
    const std::string toStringPosition();
    const std::string toStringsStats();
};
