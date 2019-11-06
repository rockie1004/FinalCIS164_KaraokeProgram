#pragma once
#include <string>
#include "Artist.h"
using namespace std;
class Song
{
	std::string title;
	Artist artist;

public:
	Song(string, Artist);
	void setSongKey(int newKey);
	void setTitle(string newTitle);
	void setArtist(Artist newArtist);
	int getSongKey();
	string getTitle();
	Artist getArtist();

	string display();
};

