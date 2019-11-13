#pragma once
#include <map>
#include <utility>
/*int createNextKey(const map& myMap);*/

//crbegin is a pointer to the last element, so that can be used to find the largest key used; Accepts map where key is int, value as any class
//http://www.cplusplus.com/reference/map/map/crbegin/

/*template <typename T> int createNextKey(const map<int, T>& myMap) {
	int highestKey = myMap.crbegin()->first;
	int nextKey = highestKey + 1;
	return nextKey;
}*/