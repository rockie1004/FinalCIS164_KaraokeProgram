#pragma once
#include <string>
using namespace std;

class CatalogEntry
{
protected:
	string objectKey;
public:
	//return a string that describes the object in a way that is readable to a user.
	virtual string display();
	//return a string that can be saved to file. Takes delimiter as a parameter
	virtual string toFile(string delimiter);

	//set the key field using one of the other fields in the class. update the key any time that field changes.
	virtual void updateKey();
	//return the key string from the class
	virtual string getKey();
};

