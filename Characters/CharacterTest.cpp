//! @file CharacterTest.cpp
//! @brief Implementation file for the Character Testing class  
//! <p> This document includes the test suite which is used to test the Character class
//!     and all of its components.

#include "stdafx.h"
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include "Character.h"
#include "Classes.h"
#include <iostream>
using namespace CppUnit;


//! Test Class for the Character class
class CharacterTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(CharacterTest);
	CPPUNIT_TEST(testValidNewCharacter);
	CPPUNIT_TEST(testInvalidNewCharacter);
	CPPUNIT_TEST(testHit);
	CPPUNIT_TEST(testClassAssignment);
	CPPUNIT_TEST(testRaces);
	CPPUNIT_TEST(testArmourClass);
	CPPUNIT_TEST(testAttackBonus);
	CPPUNIT_TEST(testDamageBonus);
	CPPUNIT_TEST(testProficiencyBonus);
	CPPUNIT_TEST(testLevelSetting);
	CPPUNIT_TEST(testInventory);
	CPPUNIT_TEST_SUITE_END();
protected:
	void testValidNewCharacter();
	void testInvalidNewCharacter();
	void testHit();
	void testClassAssignment();
	void testRaces();
	void testArmourClass();
	void testAttackBonus();
	void testDamageBonus();
	void testProficiencyBonus();
	void testLevelSetting();
	void testInventory();
};

//! test case registration
CPPUNIT_TEST_SUITE_REGISTRATION(CharacterTest);

//! test method to test the validateNewCharacter() method of the Character class 
//! Test Case: a valid newly created character should have all its ability scores in the [3-18] range
//! Tested item: Character::validateNewCharacter()
void CharacterTest::testValidNewCharacter()
{
	Character *conan = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Rogue, Hum);
	CPPUNIT_ASSERT(conan->validateNewCharacter());
}

//! test method to test the validateNewCharacter() method of the Character class 
//! Test Case: an invalid newly created character should have any of its ability scores outside the [3-18] range
//! Tested item: Character::validateNewCharacter()
void CharacterTest::testInvalidNewCharacter()
{
	Character *conan = new Character("Conan", 1, 20, 12, 12, 12, 12, 12, Rogue, Hum);
	CPPUNIT_ASSERT(conan->validateNewCharacter() == true);
	// Will be true because will override and set max to 18
}

//! test method to test the hit() method of the Character class 
//! Test Case: a character that has been hit(x) should have its hit points reduced by x 
//! Tested item: Character::hit()
void CharacterTest::testHit()
{
	Character *conan = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Rogue, Hum);
	conan->hit(4);
	CPPUNIT_ASSERT(conan->getCurrentHP() == 5);
}


/**
* Tests to ensure that Classes are assigned properly to Characters, and affect HP properly.
* Test Case: Level 1 Rogue w/ 12 Const should start with a base HP of 9 (Class Base 8 + Constitution Mod 1)
* Test Case: Level 1 Wizard w/ 12 Const has baseHP 7 (Class Base 6 + Const Mod 1)
* Test Case: Level 1 Fighter w/ 12 Const has baseHP 11 (Class Base 10 + Const Mod 1)
* Test Case: Level 1 Cleric w/ 12 Const  has base HP 9 (Class Base 8 + Const Mod 1)
* Tested Item: Classes class and Classes assignment in Character constructor
*/
void CharacterTest::testClassAssignment() {
	Character* myChar = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Rogue, Hum);
	CPPUNIT_ASSERT(myChar->getMaxHP() == 9);
	CPPUNIT_ASSERT(myChar->getClass().compare("Rogue") == 0);
	myChar = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Wizard, Hum);
	CPPUNIT_ASSERT(myChar->getMaxHP() == 7);
	CPPUNIT_ASSERT(myChar->getClass().compare("Wizard") == 0);
	myChar = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Fighter, Hum);
	CPPUNIT_ASSERT(myChar->getClass().compare("Fighter") == 0);
	CPPUNIT_ASSERT(myChar->getMaxHP() == 11);
	myChar = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Cleric, Hum);
	CPPUNIT_ASSERT(myChar->getClass().compare("Cleric") == 0);
	CPPUNIT_ASSERT(myChar->getMaxHP() == 9);

}

// Tests that Races are assigned to Characters properly. Ensures that the Character is able to access
// the speed associated witht he race, and checks that modifiers are initialized correctly based on Race
/**
* Tets that Races are assigned to Characters properly, and that Characters can access their Race attributes.
* Test Case: Human with Strength 12 should access its speed of 30 and should have overall Strength 15 (12 + 1 from mod + 2 from Human)
* Test Case: Elf with Strength 12 should have overall Dexterity of 15 (12 + 1 from mod + 2 from Human)
* Tested Item: Race class and Race assignment in Character constructor
*/
void CharacterTest::testRaces() {
	Character *myChar = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Fighter, Hum);
	CPPUNIT_ASSERT(myChar->getSpeed() == 30);
	CPPUNIT_ASSERT(myChar->getStrength() == 15);
	myChar = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Rogue, El);
	CPPUNIT_ASSERT(myChar->getDexterity() == 15);

}

/**
* Ensures that Armour Class is being calculated properly.
* Test Case: Rogue w/ Dexterity 12 should have base Armour Class 11 (Base 10 + 1 from Dext Mod)
* Test Case: Same Rogue w/ shield having bonus 5 should have AC 16 (10 + 1 Dext Mod + 5 from Shield)
* Test Case: SameRogue w/ shield 5 and armour bonus 2 has AC 18 (previous sum + 2 from armour)
* Tested Item: getArmourClass() method
*/
void CharacterTest::testArmourClass() {
	Character *myChar = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Rogue, Hum);
	CPPUNIT_ASSERT(myChar->getArmourClass() == 11);
	myChar->equipShield(5);
	CPPUNIT_ASSERT(myChar->getArmourClass() == 16);
	myChar->equipArmour(2);
	CPPUNIT_ASSERT(myChar->getArmourClass() == 18);
}

/**
* Tests that Attack Bonus is being calculated properly
* Test Case: Level 1 Hum w/ Str 12 should have AB 4 (1 from level + 1 from 12 Dext + 2 from Human modifier)
* Test Case: Same Rogue w/ weapon 12 bonus attached should have AB 16
* Tested Item: getAttackBonus() method
*/
void CharacterTest::testAttackBonus() {
	Character *myChar = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Rogue, Hum);
	CPPUNIT_ASSERT(myChar->getAttackBonus() == 4);
	myChar->equipWeapon(12);
	CPPUNIT_ASSERT(myChar->getAttackBonus() == 16);
}

/**
* Tests that damageBonus is being calculated properly.
* Test Case: Level 1 Human w/ str 12 should have 5 (+2 from Human, +1 from 12 str, +2 from level 1 proficiency bonus)
* Tested Item: getDamageBonus() method
*/
void CharacterTest::testDamageBonus() {
	Character *myChar = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Rogue, Hum);
	CPPUNIT_ASSERT(myChar->getDamageBonus() == 5);
}

/**
* Tests that Proficiency Bonus is calculated properly based on level
* Test Case: Level 1 has proficiency bonus 2
* Test Case: Level 5 has proficiency bonus 3
* Test Case: Level 20 has proficiency bonus 20
*/
void CharacterTest::testProficiencyBonus() {
	Character *myChar = new Character("Conan", 1, 12, 12, 12, 12, 12, 12, Rogue, Hum);
	CPPUNIT_ASSERT(myChar->getProficiencyBonus() == 2);
	myChar->addXP(6500);
	CPPUNIT_ASSERT(myChar->getProficiencyBonus() == 3);
	myChar->addXP(355000);
	CPPUNIT_ASSERT(myChar->getProficiencyBonus() == 6);
}

/**
* Tests to ensure that Character level is being set properly by adding experience points
* Test Case: Ensures that level gets set to 5 by constructor
* Test Case: Ensures that level threshold experience is set properly by constructor, and that level 6 is achieved by 
*			 exceeding the next threshold
* Tested Item: addXP() method
*/
void CharacterTest::testLevelSetting() {
	Character *myChar = new Character("Conan", 5, 12, 12, 12, 12, 12, 12, Rogue, Hum);
	CPPUNIT_ASSERT(myChar->getLevel() == 5);
	myChar->addXP(7500);
	CPPUNIT_ASSERT(myChar->getLevel() == 6);
}


/**
* Tests to ensure that items can be added to and removed from inventory
* Test Case: Attaches items to ensure they register as attached, then does the same after removed.
* Tested Item: equip() and remove() methods
*/
void CharacterTest::testInventory() {
	Character *myChar = new Character("John", 1, 12, 12, 12, 12, 12, 12, Rogue, Hum);
	myChar->equipArmour(12);
	myChar->equipBoots();
	myChar->equipHelmet();
	myChar->equipRing();
	myChar->equipShield(12);
	myChar->equipWeapon(12);
	CPPUNIT_ASSERT(myChar->isArmourEquipped());
	CPPUNIT_ASSERT(myChar->isHelmetEquipped());
	CPPUNIT_ASSERT(myChar->areBootsEquipped());
	CPPUNIT_ASSERT(myChar->isRingEquipped());
	CPPUNIT_ASSERT(myChar->isShieldEquipped());
	CPPUNIT_ASSERT(myChar->isWeaponEquipped());
	myChar->removeArmour();
	myChar->removeBoots();
	myChar->removeHelmet();
	myChar->removeRing();
	myChar->removeShield();
	myChar->removeWeapon();
	CPPUNIT_ASSERT(!myChar->isArmourEquipped());
	CPPUNIT_ASSERT(!myChar->isHelmetEquipped());
	CPPUNIT_ASSERT(!myChar->areBootsEquipped());
	CPPUNIT_ASSERT(!myChar->isRingEquipped());
	CPPUNIT_ASSERT(!myChar->isShieldEquipped());
	CPPUNIT_ASSERT(!myChar->isWeaponEquipped());
} 