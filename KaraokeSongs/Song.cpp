#include "Song.h"
Song::Song(string newTitle, Artist newArtist) { title = newTitle; artist = newArtist; };
void Song::setSongKey(int newKey) { songKey = newKey; };
void Song::setTitle(string newTitle) { title = newTitle; };
void Song::setArtist(Artist newArtist) { artist = newArtist; };
int Song::getSongKey() { return songKey; };
string Song::getTitle() { return title; };
Artist Song::getArtist() { return artist; };
string Song::display() { return title + " by " + "dummyArtist"; }