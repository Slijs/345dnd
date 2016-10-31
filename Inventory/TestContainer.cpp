//! @file 
//! @brief File containing the Test Class and the Test Methods
//!

#include <iostream>
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
#include "Container.h"

//#include "stdafx.h"
using namespace CppUnit;
using namespace std;

//! Test Class for the Container class
//! It must be a subclass of CppUnit::TestFixture
//! It then uses CPPUNIT_TEST_SUITE() to create the test suite, and CPPUNIT_TEST() to include the test methods in the test suite. 
//! CPPUNIT_TEST_SUITE_REGISTRATION() is then used to register the test class in the test registry.
class TestContainer : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestContainer);
	CPPUNIT_TEST(testAddItem);
	CPPUNIT_TEST(testGetItem);
	CPPUNIT_TEST(testValidItem);
	CPPUNIT_TEST(testInvalidItem);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp(void);
	void tearDown(void);
protected:
	void testAddItem(void);
	void testGetItem(void);
	void testValidItem(void);
	void testInvalidItem();
private:
	Container *ContainerObject;

};

//!Register for running the test
CPPUNIT_TEST_SUITE_REGISTRATION(TestContainer);//most important

//! test method to test the insertItem() method of the Container class 
//! Test Case: the size of the container is increased by one after adding an item to it
void TestContainer::testAddItem(void)
{
	std::cout << "Testing insertion into containers...\n";
	Item* newItem = new Item();
	int OldSize = ContainerObject->getContents().size();
	ContainerObject->insertItem(newItem);
	int NewSize = ContainerObject->getContents().size();
	CPPUNIT_ASSERT(OldSize == NewSize - 1);
}

//! test method to test the GetItem() method of the Container class 
//! Test Case: if we put an item of a certain type in the container,
//! getItem() will return this object
//! THIS TEST IS MODIFIED. We will test getItem() by putting an item
//! with a unique name into the container, and we should get an item
//! with the same name back out of the container.
void TestContainer::testGetItem(void)
{
	std::cout << "Testing if putting an item in a container and taking it back out again results in the same item...\n";
	Item* newItem = new Item("A unique name", 10, 2, "/some/image/path", {0,0,0,0,0,0,0,0,0});
	ContainerObject->insertItem(newItem);
	Item* retreivedItem= ContainerObject->getItem("A unique name");
	CPPUNIT_ASSERT(newItem->getName() == retreivedItem->getName());
	return;
}

//! test method to thest the validateItem() method of the Item class
//! Test Case: calling validateItem() on a valid item should return true 
void TestContainer::testValidItem(void)
{
	std::cout << "Testing whether a valid item can be made...\n";
	CPPUNIT_ASSERT_NO_THROW(Item newItem("Random Item", 10, 2, "/some/image/path", { 0,0,0,0,0,0,0,0,0 }));
}

//! test method to thest the validateItem() method of the Item class
//! Test Case: calling validateItem() on an invalid item should return true 
void TestContainer::testInvalidItem(void)
{
	std::cout << "Testing whether an invalid item can be made...\n";
	CPPUNIT_ASSERT_THROW(Item newItem("Random Item", 10, 2, "/some/image/path", { 0,0,0,10,0,0,0,0,0 }), invalid_argument);
}

//! setUp() method that is executed before all the test cases that the test class includes 
void TestContainer::setUp(void)
{
	ContainerObject = new Container();
}

//! tearDown() method that is executed after all the test cases that the test class includes 
void TestContainer::tearDown(void)
{
	delete ContainerObject;
}
