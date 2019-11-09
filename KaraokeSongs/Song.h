#pragma once
#include <string>
#include "Artist.h"
#include "CatalogEntry.h"
#include <map>
using namespace std;
class Song : public CatalogEntry
{
	string songKey;
	std::string title = "";
	string artistKey = "";

	
public:
	Song() :CatalogEntry() {};
	Song(string newTitle, string newArtistKey) :CatalogEntry() {
		title = newTitle;
		artistKey = newArtistKey;
	}
	void setTitle(string newTitle);
	string getTitle();
	void setArtistKey(string artistKey);//checks whether artist key exists in map?
	string getArtistKey();

	
	virtual string	display();
	virtual string	toFile(string);
	virtual string	getKey();
	virtual void	updateKey();

};

//Class implementation
//#include "Song.h"
void Song::setTitle(string newTitle) { title = newTitle; };
void Song::setArtistKey(string newArtistKey) { artistKey = newArtistKey; };

string Song::getTitle() { return title; };
string Song::getArtistKey() { return artistKey; };
string Song::getKey() { return songKey; };
void Song::updateKey() {
	cout << "\n test in update key\n";
songKey = title + " - " + artistKey; };
string Song::display() { return title + " by " + "findArtistbyTheKeyAndUseDisplayName"; }
string Song::toFile(string delimiter) { return title + delimiter + artistKey; }
