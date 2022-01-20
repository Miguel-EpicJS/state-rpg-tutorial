#include "../includes/Enemy.h"

Enemy::Enemy(int level)
{
    this->level = level;

    this->lifeEssence = 10 * this->level;
    this->strength = 10 * this->level;
    this->vitalEnergy = 10 * this->level;
    this->dexterity = 10 * this->level;
    this->perception = 10 * this->level;
    this->absorption = 10 * this->level;

    std::random_device rd;
	std::default_random_engine generator(rd()); // rd() provides a random seed
	std::uniform_real_distribution<double> distribution(1,10);

    this->fortune = distribution(generator);

    this->hpMax = (this->vitalEnergy * 5) + (this->strength) + this->level*5;
    this->hp = this->hpMax;


	this->staminaMax = this->vitalEnergy + (this->strength / 2) + (this->dexterity / 3);
	this->stamina = this->staminaMax;

	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;

    this->qiMax = this->lifeEssence + this->vitalEnergy + (this->strength / 2) + (this->dexterity / 3);
    this->qi = this->qiMax;

    this->defense = this->dexterity + (this->perception / 2);

    this->hitChance = static_cast<float>((this->dexterity / 2) + this->perception);
    this->critChance = static_cast<float>(this->dexterity) / 60 + (static_cast<float>(this->perception) * static_cast<float>(this->fortune));

    this->damageMin = this->strength * 2;
    this->damageMax = this->strength * 4;

    this->spiritStones = 0;
}

Enemy::~Enemy()
{
}

void Enemy::takeDamage(const int damage)
{
    this->hp -= damage;

    if (this->hp <= 0)
    {
        this->setDead();
    }
    
}

void Enemy::setDead()
{
    this->hp = 0;
}

const std::string Enemy::toStringStats()
{
    std::stringstream ss;

    ss  << " Life Essence: " << this->lifeEssence << "\n"
        << " Strength : " << this->strength << "\n"
        << " Vital Energy: " << this->vitalEnergy << "\n"
        << " Dexterity: " << this->dexterity << "\n"
        << " Absorption: " << this->absorption << "\n"
        << " \n"
        << " Hp: " << this->hp << " / " << this->hpMax << "\n"
        << " Stamina: " << this->stamina << " / " << this->staminaMax << "\n"
        << " Qi: " << this->qi << " / " << this->qiMax << "\n"
        << " \n"    
        << " Defence: " << this->defense << "\n"
        << " Hit Chance: " << this->hitChance << "\n"
        << " Crit Chance: " << this->critChance << "\n"
        << " \n"
        << " Spirit Stones: " << this->spiritStones << "\n";

    return ss.str();
}