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
using namespace CppUnit;
#include "Characters.h"
#include "Fighter.h"

class FighterTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(FighterTest);
	CPPUNIT_TEST(testValidNewCharacter);
	CPPUNIT_TEST(testHitPoints);
	CPPUNIT_TEST(testProficiencyBonus);
	CPPUNIT_TEST_SUITE_END();
protected:
	void testValidNewCharacter();
	void testHitPoints();
	void testProficiencyBonus();
};


//! test case registration
CPPUNIT_TEST_SUITE_REGISTRATION(FighterTest);

void FighterTest::testValidNewCharacter()
{
	Fighter *conan = new Fighter(1, "Conan");
	CPPUNIT_ASSERT(conan->validateNewCharacter());
}

void FighterTest::testHitPoints()
{
	Fighter *conan = new Fighter(1, "Conan");
	CPPUNIT_ASSERT(conan->validateHitPoints());
	conan = new Fighter(2, "Conan");
	CPPUNIT_ASSERT(conan->validateHitPoints());
}

void FighterTest::testProficiencyBonus()
{
	Fighter* conan = new Fighter(3, "Conan");
	CPPUNIT_ASSERT(conan->validateProficiency());
	conan = new Fighter(6, "Conan");
	CPPUNIT_ASSERT(conan->validateProficiency());
	conan = new Fighter(9, "Conan");
	CPPUNIT_ASSERT(conan->validateProficiency());
	conan = new Fighter(12, "Conan");
	CPPUNIT_ASSERT(conan->validateProficiency());
	conan = new Fighter(15, "Conan");
	CPPUNIT_ASSERT(conan->validateProficiency());
	conan = new Fighter(18, "Conan");
	CPPUNIT_ASSERT(conan->validateProficiency());
}
