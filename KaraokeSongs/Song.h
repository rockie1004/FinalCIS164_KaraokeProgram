#pragma once
#include <string>
#include "Artist.h"
#include "CatalogEntry.h"
#include "FileManagement.h"
using namespace std;
class Song : public CatalogEntry
{
		string songKey;
		std::string title = "";
		string artistKey = "";

	
	public:blank
		Song() :CatalogEntry() {};
		Song(string newTitle, string newArtistKey) :CatalogEntry()
		{
			title = newTitle;
			artistKey = newArtistKey;
		};

		void setTitle(string newTitle);
		string getTitle();
		void setArtistKey(string artistKey);//checks whether artist key exists in map?
		string getArtistKey();

	
		virtual string	display();
		virtual string	toFile();
		virtual void fromFile(vector<string>::iterator );

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

string Song::display()
{ 
		return getKey(); 
}
string Song::toFile() { return title + FIELD_DELIMITER + artistKey; }


void Song::fromFile(std::vector<string>::iterator iter) {
	title = *iter;//assign first field
	artistKey = *++iter;//assign next field

}

map<string, Song> songMap;
multimap<string, string> songCatalogByArtist; //key artistKey, value songKey ==will add using addSongToCatalogs

string songFileTXT = "Songs.txt";
fstream songFstream;// (songFileTXT, ios::in | ios::out);