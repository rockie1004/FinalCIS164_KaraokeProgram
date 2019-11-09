// KaraokeSongs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Song.h"
#include "MapManagement.h"
#include "FileManagement.h"
#include "CatalogEntry.h"
#include "maps.h"
#include <map>

void startup();
int main()
{
	startup();
	
	string artistKey = "dummyArtist";


	Song s = Song("manual input", artistKey);
	for (int i = 0; i < 5; i++) {
		Song tempSong = userInputSong(artistKey);
		if (addSongToCatalogs(tempSong)) { cout << "Added to map\n"; }
		else { cout << "Error\n"; };
	}

	
	//not ready...WriteMapToFile(songMap, songFstream);


	cout << "For Testing, display contents of map \n";
		displayMap(songMap);
	//	//displayMap(songCatalogByArtist);

	};

void startup() {
	cout << "open song fstream: " << openFileInOut(songFstream, songFileTXT) << endl;
};
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
