//This is the class IndividualArtist.h. This class is derived from Artist.h class, and is specific to individuals, not groups/bands.
//Mysti Freed
//4-NOV-2019
//mrfreed@dmacc.edu

#pragma once
#ifndef INDIVIDUALARTIST_H
#define INDIVIDUALARTIST_H
#include <string>
#include "Genre.h"
#include "Artist.h"

using namespace std;

class IndividualArtist : public Artist
{
private:
	string currentSideProject; //holds the band the artist is involved in, currently, if applicable
public:
	//default constructor, which is also used if the artist isn't currently involved in a project
	IndividualArtist() : Artist()
	{
		currentSideProject = "";
	}
	//constructor where there is a side project
	IndividualArtist(string s) : Artist(s) { currentSideProject = s; } //double check this...is it n or " "??

	//mutator (setters)
	void setCurrentSideProject(string s) { leadSinger = s; }

};


#endif BAND_H
