//This is the abstract class Artist.h. This class can be instantiated through either the Band.h file or IndividualArtist.h files. This is the
//basic structure shared between the band or the individual artists.
//Mysti Freed
//4-NOV-2019
//mrfreed@dmacc.edu

#pragma once
#ifndef ARTIST_H
#define ARTIST_H
#include <string>
#include "Genre.h"

using namespace std;

class Artist
{
protected:
	int id; //holds the identifier for the artist
	string name; //holds the name of the artist
	Genre primaryGenre; //holds the primary genre for the artist
public:
	//default constructor
	Artist()
	{
		id = "";
		name = "";
		primaryGenre = "";
	}
	//constructor
	Artist(int i, string n, Genre g)	{ set(i, n, g); }
	
	//set function, to set the attribute data
	void set(int i, string n, Genre g)
	{
		id = i; //assign the id
		name = n; //assign the name
		primaryGenre = g; //assign the genre
	}

	//accessors (getters)
	const int getID() const				{ return id; }
	const string getName() const		{ return name; }
	const Genre getPrimaryGenre() const { return primaryGenre; }

};



#endif ARTIST_H



