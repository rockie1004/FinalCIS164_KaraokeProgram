#pragma once
#include "Artist.h"
#include "Song.h"
#include "MapManagement.h"
#include <iostream>
#include <map>
using namespace std;

map<string, Artist> artistMap;
map<string, Song> songCatalogBySong;
multimap<Artist, Song> songCatalogByArtist;
multimap<string, Song> singerHistory; // map<singerAsString, map<dateAsString, Song>>
string userInputArtist();
Song userInputSong(string );
bool addSongToCatalogs(string , string );

/////////implementations/////////////////

string userInputArtist() { //temporary, need to complete this 
	//get input from user for fields
	//Artist a = Artist(use user input to create);
	return "dummyKey"; //change to return a.getKey();
};
Song userInputSong(string artistKey) {//temporary, need to complete this 
	string songTitle="";
	cout << "\nSong Title:";
	getline(cin, songTitle);
return Song(songTitle, artistKey);
};

//new songs must be inserted in all relevant maps
bool addSongToCatalogs(Song newSong, string artistKey) {
	if (!addObjectToMap(songCatalogBySong, newSong))
	{cout<<"Already exists in catalog, not added."; return false;}
	//if (!addObjectToMap(songCatalogByArtist, newSong, artistKey)) //should not fail, not restriction on multimap
	//		{ cout << "Failed to add to song catalog by artist."; return false; }
	return true;
};

