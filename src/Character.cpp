#include "../includes/Character.h"

void Character::updateStats()
{

    this->expNext = static_cast<int>(
		(50 / 3)*((pow(level, 3)
			- 6 * pow(level, 2))
			+ 17 * level - 12)) + 100;

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

}

void Character::resetStatus()
{

    this->hp = this->hpMax;
	this->stamina = this->staminaMax;
    this->qi = this->qiMax;
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

    this->lifeEssence = 10;
    this->strength = 10;
    this->vitalEnergy = 10;
    this->dexterity = 10;
    this->perception = 10;
    this->absorption = 10;

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

std::string Character::flee()
{
    std::stringstream ss;

    int lostExp = rand() % (this->level * 5) + 1;
    int lostGold = rand() % (this->level * 5) + 1;
    
    ss << "Exp lost: " << lostExp << " | " << "Gold lost: " << lostGold;

    this->exp -= lostExp;

    if (this->exp  < 0)
    {
        this->exp = 0;
    }
    
    this->spiritStones -= lostGold;

    if (this->spiritStones  < 0)
    {
        this->spiritStones = 0;
    }
    return ss.str();
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

        this->updateStats();

        return true;
    }
    return false;
}