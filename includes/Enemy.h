#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <random>

class Enemy
{
private:
    int level;

    int hp;
    int hpMax;

    int stamina;
    int staminaMax;

    int qi;
    int qiMax;

    int lifeEssence; // defense
    int strength; // attack
    int vitalEnergy; // health
    int dexterity; // doge chance and crit
    int perception; // learning
    int absorption; // 'talent'
    double fortune; // luck

    int damageMin;
    int damageMax;
    int defense;
    float hitChance;
    float critChance;

    int spiritStones;
public:
    Enemy(int level);
    virtual ~Enemy();

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

    void takeDamage(const int damage);
    void setDead();
    const std::string toStringStats();
};