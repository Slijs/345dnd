/******************************************************************************
 * Base class for all containers. 
 *
 * For COMP 345
 * Author: Philip Brink
 * v 0.0.1
 *
 * ***************************************************************************/

#include<string>
#include<vector>
#include<stdexcept>
#include "Container.h"

using std::string;
using std::vector;

// Constructors
Container::Container() : maxContents(5), numContents(0) {}

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
string Container::toString() {
	string containerState;
	containerState += "----------- Container Properties --------------\n";
	containerState += "Maximum size: " + std::to_string(maxContents)+ 
		"\nNumber of Items: " + std::to_string(numContents) + "\n";
	return containerState;
}

// Return a string listing the details of every item in the container.
string Container::contentsToString() {
	string itemList;
	itemList += "----------------- Container Contents -----------------\n";
	for (int i = 0; i < contents.size(); i++) {
		itemList += "\t\t\tITEM " + std::to_string(i+1) + "\n";
		itemList += contents.at(i)->toString() + "\n";
	}
	return itemList;
}
