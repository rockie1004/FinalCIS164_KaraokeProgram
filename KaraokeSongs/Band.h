//This is the class Band.h. This class is derived from Artist.h class, and is specific to bands, not individual artists. 
//Mysti Freed
//4-NOV-2019
//mrfreed@dmacc.edu

#pragma once
#ifndef BAND_H
#define BAND_H
#include <string>
#include "Genre.h"
#include "Artist.h"

using namespace std;

class Band : public Artist
{
/*private:
	string leadSinger; //holds the current lead singer for the band
	//thoughts on discography? We could maybe do a friend class, or another smaller class that could hold all the albums?
public:
	//default constructor
	Band() : Artist()
	{
		leadSinger = "";
	}
	//constructor
	Band(string n) : Artist(n) { leadSinger = n; } //double check this...is it n or " "??

	//mutator (setters)
	void setLeadSinger(string n) { leadSinger = n; }*/

};


#endif BAND_H
