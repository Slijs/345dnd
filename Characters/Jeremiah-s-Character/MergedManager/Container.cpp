/**
 * @brief Base class for all containers.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */
 
#include<string>
#include<vector>
#include<stdexcept>
#include "Container.h"
#include "Armor.h"

using std::string;
using std::vector;

IMPLEMENT_SERIAL(Container, CObject, 1);
// Constructors
/**
 * @brief 
 */
Container::Container() : maxContents(5), numContents(0) {}

/**
 * @brief 
 *
 * @param m_maxContents
 * @param m_contents
 */
Container::Container(int m_maxContents, vector<Item*> m_contents) {
	if (m_maxContents >= m_contents.size()) {
		maxContents = m_maxContents;
		contents = m_contents;
		numContents = contents.size();
	} else {
		throw std::invalid_argument("maxContents must be >= the number of items.");
	}
}

// Accessors and Mutators
int Container::getMaxContents() {
	return maxContents;
}

int Container::getNumContents() {
	return numContents;
}

string Container::getImage() {
	return image;
}

vector<Item*> Container::getContents() {
	return contents;
}

/**
 * @brief 
 *
 * @param m_contentsIndex
 *
 * @return 
 */
Item* Container::removeItem(int m_contentsIndex) {
	if (m_contentsIndex < 0 || m_contentsIndex >= contents.size()) {
		throw std::invalid_argument("The index must be between 0 and " + (contents.size()-1));
	} else {
		Item* removedItem = contents.at(m_contentsIndex);
		contents.erase(contents.begin() + m_contentsIndex);
		return removedItem;
	}
}

// Insert an item into the container. If size allowes, put the item in and
// return true. If not, return false.
/**
 * @brief 
 *
 * @param m_item
 *
 * @return 
 */
bool Container::insertItem(Item *m_item) {
	if (numContents < maxContents) {
		contents.push_back(m_item);
		return 1;
	} else {
		return 0;
	}
}

// Misc methods

// Return a string with the current state of the container.
/**
 * @brief 
 *
 * @return 
 */
string Container::toString() {
	string containerState;
	containerState += "----------- Container Properties --------------\n";
	containerState += "Maximum size: " + std::to_string(maxContents)+ 
		"\nNumber of Items: " + std::to_string(numContents) + "\n";
	return containerState;
}

// Return a string listing the details of every item in the container.
/**
 * @brief 
 *
 * @return 
 */
string Container::contentsToString() {
	string itemList;
	itemList += "----------------- Container Contents -----------------\n";
	for (int i = 0; i < contents.size(); i++) {
		itemList += "\t\t\tITEM " + std::to_string(i+1) + "\n";
		itemList += contents.at(i)->toString() + "\n";
	}
	return itemList;
}

/**
* Allows a Container to be serialized.
*/
void Container::Serialize(CArchive &ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << maxContents;
		ar << numContents;
		for (int i = 0; i < numContents; i++) {

			// Will Serialize for EACH item the type of the item, so that deserialization will work properly
			if (typeid(*(contents.at(i))) == typeid(Armor))
				ar << ItemType::Armor;
			else if (typeid(*(contents.at(i))) == typeid(Boots))
				ar << ItemType::Boots;
			else if (typeid(*(contents.at(i))) == typeid(Helmet))
				ar << ItemType::Helmet;
			else if (typeid(*(contents.at(i))) == typeid(Ring))
				ar << ItemType::Ring;
			else if (typeid(*(contents.at(i))) == typeid(Shield))
				ar << ItemType::Shield;
			else if (typeid(*(contents.at(i))) == typeid(Weapon))
				ar << ItemType::Weapon;
			else
				ar << ItemType::Item;
			contents.at(i)->Serialize();
		}
		CString c_name(image.c_str());
		ar << c_name;	// Archive's Character's Name
	}
	else {
		ar >> maxContents;
		ar >> numContents;
		for (int i = 0; i < numContents; i++) {
			int tempf = 0;
			ar >> tempf;
			Item *temp = ItemFactory::create(ItemType(tempf));
			temp->Serialize(ar);
			contents.push_back(temp);
		}
		CString c_name = "";
		ar >> c_name;
		image = "";
		int strlen = c_name.GetLength();
		for (int i = 0; i < strlen; ++i) {
			image += c_name.GetAt(i);
		}
	}
}