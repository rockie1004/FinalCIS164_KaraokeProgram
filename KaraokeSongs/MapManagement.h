#pragma once
#include <map>
#include <iterator>

template <typename T>  bool addObjectToMap(multimap<string, T>& , T , string );
template <typename T>  bool addObjectToMap(map<string, T>& , T );
//use with any ordered map that has string as the key, for testing only - replace with save to file
template <typename T>  void displayMap(map<string, T>& );
template <typename T> bool SelectByKey(map<string, T> , string , T* );
template <typename T> bool UserInputSelectByKey(map<string, T> , string , T* );











//use with any multimap that has string as the key
//http://www.cplusplus.com/reference/map/map/emplace/ returns the bool that emplace returns (second part of pair that emplace returns)
template <typename T>  bool addObjectToMap(typename multimap<string, T>& existingMap, T newObject, string newKey)
{
	bool successfulInsert = existingMap.emplace(newKey, newObject).second;//the .second used here gets the bool portion of the pair that emplace returns. It would be nice to collect the iterator that it also returns but I couldn't figure out how...
	return successfulInsert;
};


//use with any ordered map that has string as the key and an object of a class that has a key field, and updateKey() and getKey() functions in the class.
//http://www.cplusplus.com/reference/map/map/emplace/ returns the bool that emplace returns (second part of pair that emplace returns)
template <typename T>  bool addObjectToMap(typename map<string, T>& existingMap, T newObject)
{
	newObject.updateKey();//ensures that the key field in the object has most current data
	string newKey = newObject.getKey(); //uses the key field in the object as the key for the map
	bool successfulInsert = existingMap.emplace(newKey, newObject).second;//the .second used here gets the bool portion of the pair that emplace returns. It would be nice to collect the iterator that it also returns but I couldn't figure out how...
	return successfulInsert;
};


//use with any ordered map that has string as the key, for testing only - replace with save to file
template <typename T>  void displayMap(map<string, T>& existingMap) {

	for (auto& element : existingMap) {
		cout << "Key:" <<element.first << " Object: " << element.second.display() << endl;
	}
};
template <typename T>  void displayMap(multimap<string, T>& existingMap) {

	for (auto& element : existingMap) {
		cout << "Key:" << to_string(element.first) << " Object: " << element.second.display() << endl;
	}
};



//include instructions to show the user for entering a useful search string.
template <typename T> bool UserInputSelectByKey(map<string, T> myMap, string userInputInstructions, T* storeObject)
{
	////menu management
	string sectionTitle = "";//gives a header to next menu section so it is easier to read
	string sectionPrompt = "";//defines the prompt with options for this section
	int menuSelected = -1; //stores the user input

	string searchString;
	bool isKeepLooking = true;

	cout << userInputInstructions;
	cin >> searchString;



	if (SelectByKey(myMap, searchString, storeObject))//if it is not map.end then the search found a match
	{
		return true;
	}

	//full key not found, try substring search and ask user if that is what they were looking for
typename	map<string, T>::iterator it = myMap.begin();//start searching from beginning
	while (isKeepLooking)
	{
		while (it != myMap.end())//stop search after end reached without match
		{
			if (it.first.find(searchString) != std::string::npos)//possible match
			{//check if possible match is what user wants
				string sectionTitle = "\n----Select This One?---\n " + it->display() + "\n";
				enum ConfirmMenu { CANCEL, SELECT, AGAIN };
				string sectionPrompt = sectionTitle + "\n  0:Cancel, go back without selection\n  1:Confirm, select this \n  2: Keep looking, see next match \nSelect an option: "; //define the prompt string.
				int menuSelected = getInputReprompt(sectionPrompt, CANCEL, AGAIN); //get input within menu option range.

				switch (menuSelected)
				{
				case CANCEL:
					return false;
					break;
				case SELECT:
					return true;
					break;
				case AGAIN:
					isKeepLooking = true;
					break;
				default:
					cerr << "Error in select object\n";
					return false;
					break;
				}//end switch
			}//end if
			else
			{
				cout << "That was not found";
				return false;
			}//end else

			advance(it, 1);
		}//end while
	}//end while
};//end func





//include instructions to show the user for entering a useful search string.
template <typename T> bool SelectByKey(map<string, T> myMap, string searchString, T* storeObject)
{
	//attempt finding exact match
	typename map<string, T>::iterator it;
	it = myMap.find(searchString);
	if (it != myMap.end())//if it is not map.end then the search found something and it is in the iterator
	{
		storeObject = &it.second;
		return true;//iterator has been updated and can be used back where the function was called from.
	}
	return false;
};




/////////////////////////////////////////////////////////////////
///////////////////////may not need this/////////////////////////
///////////////////////////////////////////////////////////////////







//use with any ordered map that has int as the key, will return next higher int that is available to use as a new key
//adapted from https://stackoverflow.com/questions/1660195/c-how-to-find-the-biggest-key-in-a-stdmap
//use crbegin to get pointer to last element which will have highest key http://www.cplusplus.com/reference/map/map/crbegin/
template <typename T> int createNextKey(map<int, T>& existingMap)
{
	const int STARTING_KEY = 100;

	if (existingMap.empty()) return STARTING_KEY;
	int largestKey = existingMap.crbegin()->first;
	return (++largestKey);
}
