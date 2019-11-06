#pragma once
#include <string>
#include "Artist.h"
#include "CatalogEntry.h"
#include <map>
using namespace std;
class Song : public CatalogEntry
{
	string songKey;
	std::string title;
	string artistKey;

	
public:
	Song(string, string);
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
Song::Song(string newTitle, string newArtistKey) { title = newTitle; artistKey = newArtistKey; updateKey(); };
void Song::setTitle(string newTitle) { title = newTitle; };
void Song::setArtistKey(string newArtistKey) { artistKey = newArtistKey; };

string Song::getTitle() { return title; };
string Song::getArtistKey() { return artistKey; };
string Song::getKey() { return songKey; };
void Song::updateKey() { songKey = title + "-" + artistKey; };
string Song::display() { return title + " by " + "findArtistbyTheKeyAndUseDisplayName"; }
string Song::toFile(string delimiter) { return title + delimiter + artistKey; }
