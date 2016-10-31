#include "Character.h"
#include "Dwarf.h"
#include "Fighter.h"
#include "Entity.h"
#include <random>
#include <ctime>
#include "Equipment.h"
#include <string>
#include <random> 
#include <iostream>


using namespace std;


int Character::d6()
{
	// Create a random number each time 
	std::mt19937 Rng;
	Rng.seed(std::random_device()());
	// Randomly choose between 1 to 6
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 6);

	return dist6(Rng);
}

int Character::d20()
{
	// Create a random number each time 
	std::mt19937 Rng;
	Rng.seed(std::random_device()());
	// Randomly choose between 1 to 6
	std::uniform_int_distribution<std::mt19937::result_type> dist20(1, 20);

	return dist20(Rng);
}


//default constructor
Character::Character() {

	dexterity = 0;
	strength = 0;
	constitution = 0;
	intelligence = 0;
	wisdom = 0;
	charisma = 0;

	dexterityModifier = 0;
	strengthModifier = 0;
	constitutionModifier = 0;
	intelligenceModifier = 0;
	wisdomModifier = 0;
	charismaModifier = 0;

	size = "";
	speed = 0;
	hitPoints = 0;
	armorClass = 0;
}


//truly randomized character stats
Character::Character(Race characterRace, Class characterClass, int characterLevel, int meleeOrRanged) {

	charLevel = characterLevel;

	if (meleeOrRanged == 0) {
		equipval = new Equipment("Handaxe", 0);
	}
	else if (meleeOrRanged == 1) {
		equipval = new Equipment("Crossbow", 1);
	}

	//setting your ability values with d6 dice
	this->dexterity = d6() + d6() + d6();
	this->strength = d6() + d6() + d6();
	this->constitution = d6() + d6() + d6();
	this->wisdom = d6() + d6() + d6();
	this->charisma = d6() + d6() + d6();
	this->intelligence = d6() + d6() + d6();

	//modiify stats in respect to Race
	if (characterRace == Race::Dwarf) {
		this->constitution += Dwarf::constScoreIncrease;
		this->size = Dwarf::size;
		this->speed = Dwarf::speed;
	}

	//setting ability modifiers using the ability modifier calculation method
	this->dexterityModifier = AbilityModifierCalculation(dexterity);
	this->strengthModifier = AbilityModifierCalculation(strength);
	this->constitutionModifier = AbilityModifierCalculation(constitution);
	this->wisdomModifier = AbilityModifierCalculation(wisdom);
	this->charismaModifier = AbilityModifierCalculation(charisma);
	this->intelligenceModifier = AbilityModifierCalculation(intelligence);

	//armor class
	this->armorClass = ArmorClassCalculation(dexterity);


	//Hit point stats in respect to Fighter Class 
	if (characterClass == Class::Fighter) {

		//hit points for level 1 fighter class
		this->hitPoints = constitutionModifier + (Fighter::lvlOneHitPoints);

		//calculates the remaining Hit Points in respect to a fighter class level higher than 1
		if (characterLevel > 1) {

			this->hitPoints += Fighter::HitPointLvlCalculation(charLevel, constitutionModifier);
		}
	}
	//calculate Attack Bonus
	if (equipval->weaponType == 0)
		this->attackBonus = (Fighter::CalculateProficiency(characterLevel)) + (strengthModifier)+d20();

	else if (equipval->weaponType == 1)
		this->attackBonus = (Fighter::CalculateProficiency(characterLevel)) + (dexterityModifier)+d20();

	//calculate Damage Bonus
	if (equipval->weaponType == 0)
		this->damageBonus = (strengthModifier)+d6();

	else if (equipval->weaponType == 1)
		this->damageBonus = (dexterityModifier)+d6();
}

string Character::toString() {

	string Race[] = {
		"Dwarf",
		"Elf",
		"Halfling",
		"Human"
	};

	string Class[] = {
		"Fighter"
	};

	return

		"Race: " + (Race[charRace]) + "\nClass: " + (Class[charClass]) + "\nLevel: " + to_string(charLevel) + "\n"     
		"strength: " + to_string(strength) + "\n" +
		"strength modifier: " + to_string(strengthModifier) + "\n"
		"dexterity: " + to_string(dexterity) + "\n" +
		"dexterity modifier: " + to_string(dexterityModifier) + "\n"
		"constitution: " + to_string(constitution) + "\n" +
		"constitution modifier: " + to_string(constitutionModifier) + "\n"
		"intelligence: " + to_string(intelligence) + "\n" +
		"intelligence modifier: " + to_string(intelligenceModifier) + "\n"
		"wisdom: " + to_string(wisdom) + "\n" +
		"wisdomModifier: " + to_string(wisdomModifier) + "\n" +
		"charisma: " + to_string(charisma) + "\n" +
		"charisma modifier: " + to_string(charismaModifier) + "\n" +
		"armor class: " + to_string(armorClass) + "\n" +
		"hit points: " + to_string(hitPoints) + "\n" +
		"attack bonus: " + to_string(attackBonus) + "\n" +
		"damage bonus: " + to_string(damageBonus) + "\n" +
		"speed: " + to_string(speed) + "\n" +
		"size: " + size + "\n";
}

bool Character::validateNewCharacter() {
	if (strength >= 3 && strength <= 18 && dexterity >= 3 && dexterity <= 18 && intelligence >= 3 && intelligence <= 18 && constitution >= 3 && constitution <= 18 && wisdom >= 3 && wisdom <= 18 && charisma >= 3 && charisma <= 18)
		return true;
	else
		return false;
}


//getters and setters
void Character::hit(int damage) {
	this->hitPoints = this->hitPoints - damage;      //monstern hits me!!!!!! and it's my HP minus the hitpoint by the monster 
	if (this->hitPoints < 0)
		this->hitPoints = 0;
}

int Character::getHitPoints() {
	return this->hitPoints;
}



//destructor
Character::~Character() {
	delete this->equipval;
}

//this is to calculate your ability modifier values
int Character::AbilityModifierCalculation(int ability) {

	double abilityModifierValue = floor((double)(ability - 10) / 2);    //TODO: check that negative numbers are rounded down not up 
	return (int)abilityModifierValue;
}

//calculates the Armor Class in respect to character's dexterity
int Character::ArmorClassCalculation(int dexterityValue) {
	int ac = dexterityValue + 10;
	return ac;
}


//cppunit test constructor
Character::Character(int dexterityVal, int strengthVal, int constitutionVal, int intelligenceVal, int wisdomVal, int charismaVal) {

	hitPoints = 10;
	charRace = Dwarf;
	charClass = Fighter;

	dexterity = dexterityVal;
	strength = strengthVal;
	constitution = constitutionVal;
	intelligence = intelligenceVal;
	wisdom = wisdomVal;
	charisma = charismaVal;

	charLevel = 1;

	equipval = new Equipment("Handaxe", 0);

	//modiify stats in respect to Race
	if (charRace == Race::Dwarf) {
		this->constitution += Dwarf::constScoreIncrease;
		this->size = Dwarf::size;
		this->speed = Dwarf::speed;
	}

	//setting ability modifiers using the ability modifier calculation method
	this->dexterityModifier = AbilityModifierCalculation(dexterity);
	this->strengthModifier = AbilityModifierCalculation(strength);
	this->constitutionModifier = AbilityModifierCalculation(constitution);
	this->wisdomModifier = AbilityModifierCalculation(wisdom);
	this->charismaModifier = AbilityModifierCalculation(charisma);
	this->intelligenceModifier = AbilityModifierCalculation(intelligence);

	//armor class
	this->armorClass = ArmorClassCalculation(dexterity);


	//calculate Attack Bonus
	if (equipval->weaponType == 0)
		this->attackBonus = (Fighter::CalculateProficiency(charLevel)) + (strengthModifier)+d20();

	else if (equipval->weaponType == 1)
		this->attackBonus = (Fighter::CalculateProficiency(charLevel)) + (dexterityModifier)+d20();

	//calculate Damage Bonus
	if (equipval->weaponType == 0)
		this->damageBonus = (strengthModifier)+d6();

	else if (equipval->weaponType == 1)
		this->damageBonus = (dexterityModifier)+d6();
}

void Character::characterArtwork() {
	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:..:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:..:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:..:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~" << "\n\n";
	cout << "                  {}\n" << endl;

	cout << "  ,   A           {}\n" << endl;

	cout << " / \\, | ,        .--.\n" << endl;

	cout << "|  =|= >        /.--.\\\n" << endl;

	cout << " \\ /` | `       |====|\n" << endl;

	cout << "  `   |         |`::`|\n" << endl;

	cout << "      |     .-;`\\..../`;_.-^-._\n" << endl;

	cout << "     /\\\\/  /  |...::..|`   :   `|\n" << endl;

	cout << "     |:'\\ |   /'''::''|   .:.   |\n" << endl;

	cout << "      \\ /\\;-,/\\   ::  |..     ..|\n" << endl;

	cout << "      |\\ <` >  >._::_.| ':   :' |\n" << endl;

	cout << "      | `""`_/   ^^/>/> |   ':'   |\n" << endl;

	cout << "      |       |       \\    :    /\n" << endl;
	cout << "      |       |        \\   :   /\n" << endl;

	cout << "      |       |___/\\___|`-.:.-`\n" << endl;

	cout << "      |        \\_ || _/    `\n" << endl;

	cout << "      |        <_ >< _>\n" << endl;

	cout << "      |        |  ||  |\n" << endl;

	cout << "      |        |  ||  |\n" << endl;

	cout << "      |       _\\.:||:./_\n" << endl;

	cout << "      |      /____/\\____\\" << endl;

	cout << "" << endl;

	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:..:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:..:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:..:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~" << "\n\n";
}

	void Character::titleArtwork() {
	cout << "________     ____   ________			________     ____   ________			________     ____   ________			________     ____   ________" << endl;
	cout << "\\______ \\   /  _ \\  \\______ \\			\\______ \\   /  _ \\  \\______ \\			\\______ \\   /  _ \\  \\______ \\			\\______ \\   /  _ \\  \\______ \\" << endl;
	cout << " |     | \\  >  _ </\\ |     | \\			 |     | \\  >  _ </\\ |     | \\			 |     | \\  >  _ </\\ |     | \\			 |     | \\  >  _ </\\ |     | \\" << endl;
	cout << " |     `  \\/  <_\\ \\/ |     `  \\			 |     `  \\/  <_\\ \\/ |     `  \\			 |     `  \\/  <_\\ \\/ |     `  \\			 |     `  \\/  <_\\ \\/ |     `  \\" << endl;
	cout << "/_______  /\\_____\\ \\/_______  /			/_______  /\\_____\\ \\/_______  /			/_______  /\\_____\\ \\/_______  /			/_______  /\\_____\\ \\/_______  /" << endl;
	cout << "        \\/        \\/        \\/			        \\/        \\/        \\/			        \\/        \\/        \\/			        \\/        \\/        \\/" << endl;
	cout << "\n\n";
}