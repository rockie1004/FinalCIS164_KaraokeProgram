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
#include "CatalogEntry.h"
#include "FileManagement.h"
#include <map>

using namespace std;

class Artist : public CatalogEntry
{
private:
	//int id; holds the identifier for the artist
	string alphaName; //holds the artist' name alphabetically
	string displayName; //holds the name of the artist
	Genre primaryGenre; //holds the primary genre for the artist
public:
	//default constructor
	Artist() : CatalogEntry() {}

	//constructor
	Artist(string an, string dn, Genre g) : CatalogEntry()
	{	
		alphaName = an;
		displayName = dn;
		primaryGenre = g;
	}

	//constructor where there's only an alphabetical name (for example, Prince)
	Artist(string an, Genre g) : CatalogEntry()
	{
		alphaName = an;
		displayName = alphaName; //sets the alphaName to the displayName
		primaryGenre = g;
	}

	//constructor that allows for setup without a Genre, when it's not known
	Artist(string an, string dn) : CatalogEntry()
	{
		alphaName = an;
		displayName = dn; 
		primaryGenre = g;
	}

	//constructor where there's only an alphabetical name (for example, Prince)
	//and no genre selected
	Artist(string an) : CatalogEntry()
	{
		alphaName = an;
		displayName = alphaName; //sets the alphaName to the displayName
	}
	
	//setters/mutators
	void setAlphaName(string an)		{ alphaName = an; }
	void setDisplayName(string dn)		{ displayName = dn; }
	void setGenre(Genre g)				{ primaryGenre = g; }

	//accessors (getters)
	string getAlphaName() /*const*/		{ return alphaName; }
	string getDisplayName() /*const*/	{ return displayName; }
	Genre getPrimaryGenre() /*const*/	{ return primaryGenre; }

	virtual string display(); //from CatalogEntry.h
	virtual string toFile(); //from CatalogEntry.h
	virtual void fromFile(vector<string>::iterator iter); //from CatalogEntry.h
	virtual string getKey(); //from CatalogEntry.h
	virtual void updateKey(); //from CatalogEntry.h
};

//Class Implementation

void Artist::setAlphaName(string an)	{ alphaName = an; };
void Artist::setDisplayName(string dn)	{ displayName = dn; };

string Artist::getAlphaName()			{ return alphaName; };
string Artist::getDisplayName()			{ return displayName; };
Genre Artist::getPrimaryGenre()			{ return primaryGenre; };

void Artist::updateKey()
{
	cout << "pending functionality stub";
}

string Artist::display()
{
	return "Artist: " + displayName;
}

string Artist::toFile()
{
	return alphaName + FIELD_DELIMITER; //not sure if we're using the same delimiter for all?
}

void Artist::fromFile(std::vector<string>::iterator iter)
{
	alphaName = *iter;
	//I think this is all we need here, but lets chat, I want to make sure
}

#endif ARTIST_H