#pragma once
#include <map>
#include <iterator>
const int STARTING_KEY = 100;


//use with any ordered map that has int as the key, will return next higher int that is available to use as a new key
//adapted from https://stackoverflow.com/questions/1660195/c-how-to-find-the-biggest-key-in-a-stdmap
//use crbegin to get pointer to last element which will have highest key http://www.cplusplus.com/reference/map/map/crbegin/
template <typename T> int createNextKey(map<int, T>& existingMap)
{
	if (existingMap.empty()) return STARTING_KEY;
	int largestKey = existingMap.crbegin()->first;
	return (++largestKey);
}

//use with any ordered map that has int as the key
//http://www.cplusplus.com/reference/map/map/emplace/ returns the bool that emplace returns (second part of pair that emplace returns)
template <typename T>  bool addObjectToMap(map<int, T>& existingMap, T newObject)
{
	int newKey = createNextKey(existingMap);
	bool successfulInsert = existingMap.emplace(newKey, newObject).second;//the .second used here gets the bool portion of the pair that emplace returns. It would be nice to collect the iterator that it also returns but I couldn't figure out how...

	return successfulInsert;
};

//use with any ordered map that has int as the key, for testing only - replace with save to file
template <typename T>  void displayMap(map<int, T>& existingMap) {

	for (auto& element : existingMap) {
		cout << "ID:" << to_string(element.first) << " Object: " << element.second.display() << endl;
	}
};