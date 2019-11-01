#include "Song.h"
Song::Song(string newTitle, Artist newArtist) { title = newTitle; artist = newArtist; };
void Song::setTitle(string newTitle) { title = newTitle; };
void Song::setArtist(Artist newArtist) { artist = newArtist; };
string Song::getTitle() { return title; };
Artist Song::getArtist() { return artist; };
string Song::display() { return title + " by " + "dummyArtist"; }