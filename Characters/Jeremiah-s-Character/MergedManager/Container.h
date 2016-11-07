/**
 * @brief Base class for all containers.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */
 
// Include guard
#ifndef Container_H
#define Container_H

#include <string>
#include <vector>
#include "Item.h"
#include <afx.h>

using std::string;
using std::vector;

enum ItemType {Armor, Belt, Boots, Helmet, Ring, Shield, Weapon, Item};

class Container : public CObject{
	protected:
		// Attributes common to all containers
		int maxContents;
		int numContents;
		vector<Item*> contents;
		string image;
		DECLARE_SERIAL(Container);
	public:
		// Constructors
		Container();
		Container(int m_maxContents, vector<Item*> m_contents);
		// Accessors and Mutators
		int getMaxContents();
		int getNumContents();
		string getImage();
		vector<Item*> getContents();
		Item* removeItem(int m_contentsIndex);
		bool insertItem(Item *m_item);

		// Misc methods
		string toString();
		string contentsToString();
		virtual void Serialize(CArchive &ar);
};

#endif // Include guard
