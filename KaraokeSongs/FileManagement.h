#pragma once
#ifndef USEFULTHINGS_H
#define USEFULTHINGS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <iomanip>
#include <sstream>

using namespace std;

// menu functions
char getInputReprompt(std::string, char, char);
int getInputReprompt(std::string, int, int);

//file handling variables
const char FIELD_DELIMITER = '$';
const char ELEMENT_DELIMITER = '|';

//file handling functions/
vector<string> ReadLineByID(fstream&, string);//can find any substring, not just ID
vector<string> SeparateLineByDelimiter(string);
void GoBeginningOfFile(fstream& inputReader);


//template functions
//template <typename T> void ReadInAllObjects(fstream&, T& map );


//sets reader back to start of file //Amy
void GoBeginningOfFile(fstream& inputReader) {
	inputReader.clear();
	inputReader.seekg(0, ios::beg);
};


//turns a string line with delimiter into individual strings, stored in a vector. //Amy
//adapted from http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
vector<string> SeparateLineByDelimiter(string line) {
	vector<string> inputFields;
	std::stringstream ss(line);
	std::string nextField;
	while (std::getline(ss, nextField, FIELD_DELIMITER)) {
		inputFields.push_back(nextField);
	}
	return inputFields;
};


/*Amy's input validating function for character within a range of allowed uppercase characters. Useful for menu input. Continues reprompting until input is acceptable.
char getInputReprompt(std::string, char, char);
char getInputReprompt(std::string promptMessage, char minRange, char maxRange){};
*///Amy
char getInputReprompt(std::string promptMessage, char minRange, char maxRange) {
	char input;
	bool isInvalidInput;
	string low(1,minRange);//convert char to string
	string high(1,maxRange);//convert char to string
	std::string invalidMessage = "Error: Enter a character between " + low + " and " + high+". ";

	do {
		std::cout << promptMessage;
		input = std::cin.get();
		input = toupper(input);
		if (isInvalidInput = std::cin.fail()) //invalid input 
		{
			std::cout << "Input Type " << invalidMessage;
		}
		if (input<toupper(minRange) || input>toupper(maxRange)) //outside range
		{
			std::cout << "Outside Range " << invalidMessage;
			isInvalidInput = true;
		}
		if (isInvalidInput) {//clear to reprompt
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	} while (isInvalidInput);//reprompt until valid
	return input;//return valid input
};
/*Amy's input validating function for integer within a range. Continues reprompting until input is acceptable. Useful for menu input.
int getInputReprompt(std::string, int, int);
int getInputReprompt(std::string promptMessage, int minRange, int maxRange) {};*/
int getInputReprompt(std::string promptMessage, int minRange, int maxRange) {
	int input;
	bool isInvalidInput;
	std::string invalidMessage = "Error: Enter an integer between " + std::to_string(minRange) + " and " + std::to_string(maxRange) + ". ";

	do {
		std::cout << promptMessage;
		std::cin >> input;
		if (isInvalidInput = std::cin.fail()) //invalid input 
		{
			std::cout << "Input Type " << invalidMessage;
		}
		if (input<minRange || input>maxRange) //outside range
		{
			std::cout << "Outside Range " << invalidMessage;
			isInvalidInput = true;
		}
		if (isInvalidInput) {//clear to reprompt
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	} while (isInvalidInput);//reprompt until valid
	return input;//return valid input
};



//Mysti's function to ensure that a file opens appropriately for read/write for reuse by the team
//pass by reference (Gaddis p673)
bool openFileInOut(fstream& file, string filenameTXT)
{
	file.open(filenameTXT, ios::out | ios::in);
	if (file.fail())
	{
		return false;
	}
	else
	{
		return true;
	}
}



/*might adjust for map?
//reads each line from file and adds to a vector of the same object type as tempObject
//for tempObject parameter, declare a variable of the object type that matches your file, then pass that variable to the function.
template <typename T> void ReadInAllObjects(fstream& inputFile, T& outputMap ){
GoBeginningOfFile(inputFile);//sets to start of file
	string line = "";
	while (inputFile) //keep going until end of file
	{
		getline(inputFile, line, '\n');
		if (line == "") {//skip blank line
		}
		else
		{
			try {

				tempObject = T(SeparateLineByFIELD_DELIMITER(line)); //creates an object fro the line, adds it to vector
				if (DEBUGUSEFULTHINGS) cout << "debug " << tempObject.display()<<endl;
				allObjectVector.push_back(tempObject);
			}
			catch (exception& e) {
				cerr << "Error in ReadInAllObjects:Unable to read in member, skipping:  " << e.what();
				GoBeginningOfFile(inputFile);//sets to start of file

			}
			catch (runtime_error& e) {
				cerr << "Error in ReadInAllObjects:Unable to read in member, skipping:  " << e.what();
				GoBeginningOfFile(inputFile);//sets to start of file

			}

		}
	}
	GoBeginningOfFile(inputFile);//sets to start of file

	return allObjectVector;
}
*/