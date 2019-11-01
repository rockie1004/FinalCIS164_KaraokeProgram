#pragma once

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

/*Use for menus where choices are letters. 
Amy's input validating function for character within a range of allowed uppercase characters. Useful for menu input. Continues reprompting until input is acceptable.
char getInputReprompt(std::string, char, char);
char getInputReprompt(std::string promptMessage, char minRange, char maxRange){};
*///Amy
char getInputReprompt(std::string promptMessage, char minRange, char maxRange) {
	char input;
	bool isInvalidInput;
	string low(1, minRange);//convert char to string
	string high(1, maxRange);//convert char to string
	std::string invalidMessage = "Error: Enter a character between " + low + " and " + high + ". ";

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
/*Use for menus where choices are numbers.
Amy's input validating function for integer within a range. Continues reprompting until input is acceptable. Useful for menu input.
int getInputReprompt(std::string, int, int);
int getInputReprompt(std::string promptMessage, int minRange, int maxRange) {};

*///Amy
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



//file handling variables
const char FIELD_DELIMITER = '$';
const char VECTOR_ELEMENT_DELIMITER = '|';

//file handling functions/
void GoBeginningOfFile(fstream& inputReader);
vector<string> SeparateLineByDelimiter(string);

//vector<string> ReadLineByID(fstream&, string);//can find any substring, not just ID
//bool FindStringInFile(fstream&, string, string&, int&);
//bool IsStringInFile(fstream&, string);
//int FindMaxUniqueID(fstream& inputReader);//

//template functions
//template <typename T> void DisplayAllFromFile(fstream&, T&);
//template <typename T> bool FindStringDisplayAll(fstream& , string , T& );
//template <typename T> vector<T> ReadInAllObjects(fstream&, T& );

template <typename T> void WriteClassMapToFile(fstream& inputFile, T& storeObject, map& mapOfObjects);

//sets reader back to start of file //Amy
void GoBeginningOfFile(fstream& inputReader) {
	inputReader.clear();
	inputReader.seekg(0, ios::beg);
};

//Returns true if string is found in file. You must handle if false/not found. 
//You can store the the actual text of the line and the line number if you provide variables to save them in.
//!!!Starts at current location of the fstream, open the file before calling this and close it after!!! //Amy
/*
bool FindStringInFile(fstream& inputReader, string findString, string& storeLine, int& storeLineNumber) {
	bool IsFound = false;
	string line = "";
	int lineNumber = 0;
	while (!IsFound && inputReader) //keep searching until found or end of file
	{
		lineNumber++;
		getline(inputReader, line, '\n');
		size_t foundLoc = line.find(findString);//this section adapted from Craig's findString function to store the line number and line
		// if not not found
		if (foundLoc != string::npos)
		{
			storeLineNumber = lineNumber;//save to variables outside function
			storeLine = line;//save to variables outside function
			IsFound = true;
		}
	}
	return IsFound;
};
*/
//turns a string line with delimiters into individual strings, stored in a vector. //Amy
//adapted from http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
vector<string> SeparateLineByDelimiter(string line) {
	vector<string> inputFields;
	std::stringstream ss(line);
	std::string nextField;
	while (std::getline(ss, nextField, DELIMITER)) {
		inputFields.push_back(nextField);
	}
	return inputFields;
};

/*
//gets fields from file after locating the line that contains the findIDString. Starts at beginning of file. //Amy
//must be in a try catch block to handle situation where ID not found. Example below. 			
//try { vector<string> h = ReadLineByID(AddressFile, "600109999") );} 
//catch (exception& e) { cout << e.what(); }
vector<string> ReadLineByID(fstream& inputReader, string findIDString) {
	GoBeginningOfFile(inputReader);
	if (DEBUGUSEFULTHINGS)cout << "starting ReadLineByID " << findIDString << "\n";
	string line;
	int lineNum;
	bool foundID = FindStringInFile(inputReader, findIDString, line, lineNum);

	if (DEBUGUSEFULTHINGS) cout << "\ntest in ReadLineByID " << foundID << " " << lineNum << " " << line << "\n";
	vector<string> inputFields;
	if (foundID) {
		inputFields = SeparateLineByDelimiter(line);
	}
	else {
		inputFields = { "" };
		throw std::runtime_error("Not found in file!");
	}
	return inputFields;
};
*/



/*Amy's find max ID in file fuction *///Amy
int FindMaxUniqueID(fstream& inputReader) {
	string maxID = "100100000";
	string nextID = "0";
	string line;
	int maxUniqueID;

	GoBeginningOfFile(inputReader);
	while (inputReader) //keep searching until end of file
	{
		getline(inputReader, line, '\n');//get line
		std::stringstream ss(line);
		std::string nextID;
		std::getline(ss, nextID, DELIMITER);//get first field from the line, which is ID

		if (nextID > maxID) {
			maxID = nextID;
		};
	}

	GoBeginningOfFile(inputReader);//reset reader
	//remove prefix
	maxUniqueID = stoi(maxID.substr(3, 6));

	return maxUniqueID;//not created yet
};


//Mysti's function to ensure that a file opens appropriately for read/write for reuse by the team
//pass by reference (Gaddis p673)
bool openFileOutIn(fstream &fstreamName, string fileTXT)
{
	fstreamName.open(fileTXT, ios::out | ios::in);
	if (fstreamName.fail())
	{
		return false;
	}
	else
	{
		return true;
	}
}
/*

//saves string to output file, closes and reopens //Amy
void WriteToFile(string classOutput, fstream& outputFile, string textFileToOpen) {
	if (!outputFile || !outputFile.is_open()) { outputFile.clear(); outputFile.open(textFileToOpen, ios::app | ios::in); };

	outputFile << classOutput;
	outputFile.close();
	outputFile.clear();
	outputFile.open(textFileToOpen, ios::app | ios::in);//reopen the file
}
*/

/*
//for tempObject parameter, declare a variable of the object type that matches your file, then pass that variable to the function.//Amy
template <typename T> bool FindStringDisplayAll(fstream& searchFile, string searchString, T &tempObject)
{
	int storeLineNum;
	string storeLine;
	
	GoBeginningOfFile(searchFile);

	try {
		if (FindStringInFile(searchFile, searchString, storeLine, storeLineNum))
		{	 //returns true if found
			do
			{
				tempObject = T(SeparateLineByDelimiter(storeLine));//uses the object constructor that takes vector of strings.	
				cout << tempObject.display() << "\n";
			} while (FindStringInFile(searchFile, searchString, storeLine, storeLineNum));

			cout << "--End of List--\n";
			GoBeginningOfFile(searchFile);//reset file to beginning
			return true; //at least one found
		}
		else
		{
			cout << "None found\n";
		return false;
		}
	}
		catch (...)
		{
			cout << "None found";
			GoBeginningOfFile(searchFile);//reset file to beginning
			return false;
		}
};

//reads each line from file and adds to a vector of the same object type as tempObject
//for tempObject parameter, declare a variable of the object type that matches your file, then pass that variable to the function.
template <typename T> vector<T> ReadInAllObjects(fstream& inputFile, T& tempObject) {
	GoBeginningOfFile(inputFile);//sets to start of file
	vector<T> allObjectVector;
	string line = "";
	while (inputFile) //keep going until end of file
	{
		getline(inputFile, line, '\n');
		if (line == "") {//skip blank line
		}
		else
		{
			try {
				if (DEBUGUSEFULTHINGS) cout <<"debug "<< line << endl;

				tempObject = T(SeparateLineByDelimiter(line)); //creates an object fro the line, adds it to vector
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
/*
//requires object to have a display() function that returns a string
//for tempObject parameter, declare a variable of the object type that matches your file, then pass that variable to the function.
template <typename T> void DisplayAllFromFile(fstream& inputFile, T& tempObject) {
	vector<T> allObjectVector = ReadInAllObjects(inputFile, tempObject);
	try {
		for (T e : allObjectVector) {
			cout << e.display() << endl;
		}
	}
	catch (exception& e) {
		cerr << "Error in DisplayAllFromFile:Unable to read in object, skipping:  " << e.what();
	}
	catch (runtime_error& e) {
		cerr << "Error in DisplayAllFromFile:Unable to read in object, skipping:  " << e.what();
	}
};

*/
/*
template <typename T> void MenuObjectSelectFromFile(fstream& inputFile, T& storeObject, string className, const int BLANK_ID)
{
	////menu management
	string sectionTitle = "";//gives a header to next menu section so it is easier to read
	string sectionPrompt = "";//defines the prompt with options for this section
	int menuSelected = -1; //stores the user input

	string searchString;
	int storeLineNum;
	string storeLine;
	bool isKeepLooking = true;
	cout << "Enter the ID or text that you would like to search for.";
	cin >> searchString;
	GoBeginningOfFile(inputFile);
	do {
		try {
			if (FindStringInFile(inputFile, searchString, storeLine, storeLineNum)) //returns true if found
			{
				storeObject = T(SeparateLineByDelimiter(storeLine));//uses the object constructor that takes vector of strings.

				sectionTitle = "\n----Select This "+className+"---\n " + storeObject.display() + "\n";
				enum ConfirmMenu { CANCEL, SELECT, AGAIN };
				sectionPrompt = sectionTitle + "\n  0:Cancel, go back without selection\n  1:Confirm, select this \n  2: Keep looking, see next match \nSelect an option: "; //define the prompt string.
				menuSelected = getInputReprompt(sectionPrompt, CANCEL, AGAIN); //get input within menu option range.

				switch (menuSelected) {
				case CANCEL:
					GoBeginningOfFile(inputFile);//reset file to beginning
					storeObject = T(BLANK_ID);
					return; 
					break;
				case SELECT:
					GoBeginningOfFile(inputFile);//reset file to beginning
					return; //value is stored in the storeObject that was given as parameter
					break;
				case AGAIN:
					isKeepLooking = true;
					break;
				default:
					cerr << "Error in select object\n";
					GoBeginningOfFile(inputFile);//reset file to beginning
					storeObject = T(BLANK_ID);
					return;
					break;
				}
			}//end if
			else {
				cout<< "That was not found.\n";
				GoBeginningOfFile(inputFile);//reset file to beginning
				storeObject = T(BLANK_ID);
				return;
			}
		}
		catch (...)
		{
			cout << "That was not found";
			GoBeginningOfFile(inputFile);//reset file to beginning
			storeObject = T(BLANK_ID);
			return;
		}
	} while (isKeepLooking);
};


*/

