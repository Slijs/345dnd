/**
 * @brief Class for helmets.
 * @author Philip Brink
 * @version 0.0.1
 * @date 2016-10-20
 */

// Include guard
#ifndef Helmet_H
#define Helmet_H


#include <string>
#include "Item.h"

class Helmet: public Item {
	protected:
		// Helmet Attributes
		int defense;
		DECLARE_SERIAL(Helmet);
		// Constructors
	public:
		Helmet();
		Helmet(const Helmet* otherHelmet);
		Helmet(string name, int weight, int value, string image, 
				array<int, 9> enchantmentValues, int defense);
		int getDefense();
		void incrementDefense();
		void decrementDefense();
		std::string toString();
		virtual void Serialize(CArchive &ar);
};

#endif // Include guard
