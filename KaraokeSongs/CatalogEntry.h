#pragma once
#include <string>
using namespace std;

class CatalogEntry
{
public:
	const string BLANK_FIELD = "Unknown";
	CatalogEntry() {};
	///Pure virtual functions require child class to implement
	//return a string that describes the object in a way that is readable to a user.
	virtual string display() = 0;
	//return a string that can be saved to file. Takes delimiter as a parameter
	virtual string toFile(string delimiter) = 0;

	//set the key field using one of the other fields in the class. update the key any time that field changes.
	virtual void updateKey() = 0;
	//return the key string from the class
	virtual string getKey() = 0;
};

