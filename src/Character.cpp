#include "../includes/Character.h"

void Character::updateStats()
{
    this->hpMax = this->vitalEnergy * 10 + this->vitalEnergy;
    this->hp = this->hpMax;

    this->staminaMax = this->vitalEnergy * 2 + this->strength;
    this->stamina = this->staminaMax;

    this->qiMax = this->vitalEnergy * 10 + this->level * 10;
    this->qi = this->qiMax;

    this->defense = this->lifeEssence * 10 + this->strength;

    this->hitChance = static_cast<float>(this->dexterity) * (static_cast<float>(this->perception) * 10.f/*  * static_cast<float>(this->fortune) */);
    this->critChance = static_cast<float>(this->dexterity) / 60 + (static_cast<float>(this->perception) * static_cast<float>(this->fortune));

    this->damageMin = this->strength * 2;
    this->damageMax = this->strength * 4 * this->fortune;

}

Character::Character(std::string name, std::string bio)
{
    this->x = 0;
    this->y = 0;

    this->name = name;
    this->bio = bio;

    this->level = 1;
    this->exp = 1000;
    this->expNext = 46;
    this->statpoints = 0;

    this->lifeEssence = 1;
    this->strength = 1;
    this->vitalEnergy = 1;
    this->dexterity = 1;
    this->perception = 1;
    this->absorption = 1;

    std::random_device rd;
	std::default_random_engine generator(rd()); // rd() provides a random seed
	std::uniform_real_distribution<double> distribution(1,10);

    this->fortune = distribution(generator);

    this->spiritStones = 0;

    this->updateStats();
}

Character::~Character()
{
}

void Character::takeDamage(const int damage)
{
    this->hp -= damage;

    if (this->hp <= 0)
    {
        this->setDead();
    }
}

void Character::setPosition(const int x, const int y)
{
    this->x = x;
    this->y = y;
}

void Character::move(const int x, const int y)
{
    if (static_cast<int>(this->x) + x < 0)
    {
        this->x = 0;
    }
    else
    {
        this->x += x;       
    }
    
    if (static_cast<int>(this->y) + y < 0)
    {
        this->y = 0;
    }
    else
    {
        this->y += y;
    }
    
    
    
}

void Character::setDead()
{
    this->hp = 0;

    this->exp -= rand() % (this->level * 10) + 1;

    if (this->exp  < 0)
    {
        this->exp = 0;
    }
    
    this->spiritStones -= rand() % (this->level * 10) + 1;

    if (this->spiritStones  < 0)
    {
        this->spiritStones = 0;
    }

}

void Character::addExp(const unsigned exp)
{
    this->exp  += exp;
}

const std::string Character::toString()
{
    /*Send all variables as string*/
    std::stringstream ss;

    ss
        << " Name: " << this->name << "\n\n"
        << " Bio: " << this->name << "\n\n"
        << " Level: " << this->level << "\n"
        << " Exp: " << this->exp << " / " << this->expNext << "\n"
        << " \n"
        << " Life Essence: " << this->lifeEssence << "\n"
        << " Strength : " << this->strength << "\n"
        << " Vital Energy: " << this->vitalEnergy << "\n"
        << " Dexterity: " << this->dexterity << "\n"
        << " Absorption: " << this->absorption << "\n"
        << " \n"
        << " Hp: " << this->hp << " / " << this->hpMax << "\n"
        << " Stamina: " << this->stamina << " / " << this->staminaMax << "\n"
        << " Qi: " << this->qi << " / " << this->qiMax << "\n"
        << " \n"    
        << " Damage: " << this->damageMin << " - " << this->damageMax << "\n"
        << " Defence: " << this->defense << "\n"
        << " Hit Chance: " << this->hitChance << "\n"
        << " Crit Chance: " << this->critChance << "\n"
        << " \n"
        << " Spirit Stones: " << this->spiritStones << "\n"
        ;

    return ss.str();
}

const std::string Character::toStringNameBio()
{
    std::stringstream ss;

    ss
        << " Name: " << this->name << "\n\n"
        << " Bio: " << this->bio << "\n\n";

    return ss.str();
}

const std::string Character::toStringPosition()
{
    std::stringstream ss;

    ss 
        << " x: " << this->x << " "
        << " y: " << this->y << "\n\n";

    return ss.str();
}

const std::string Character::toStringsStats()
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

const std::string Character::getMenuBar()
{
    std::stringstream ss;

    ss 
    << " Name: " << this->name << " | "
    << " Level: " << this->level << " | "
    << " Exp: " << this->exp << " / " << this->expNext << " | "
    << " Hp: " << this->hp << " / " << this->hpMax << " | "
    << " Stamina: " << this->stamina << " / " << this->staminaMax << " | "
    << " Qi: " << this->qi << " / " << this->qiMax << " | " << "\n"
    << " Stat points avaible: " << this->statpoints << " | "
    << " Spirit Stones: " << this->spiritStones << "\n"
    ;

    return ss.str();
}

bool Character::canLevelUp()
{
    if(this->exp >= this->expNext)
    {
        this->level++;
        this->exp -= this->expNext;
        this->expNext = (50/3) * (std::pow(this->level, 3) - 6*std::pow(this->level, 2) + (this->level * 17) - 12);
        this->statpoints++;

        return true;
    }
    return false;
}