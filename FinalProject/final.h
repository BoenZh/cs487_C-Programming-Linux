
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <typeinfo>
using namespace std;

#ifndef EVILHM_H_
#define EVILHM_H_

class evilHM{

public:

	void populateYesNoSets( set<string>& boolYes, set<string>& boolNo );
	int getNonNegInteger( string& prompt);
	bool getChoice( string& prompt, set<string> boolYes, set<string> boolNo);
	char getAlphabet( string prompt);
	bool isLetterUsed( char nextCh, set<char> lettersUsed );

	void readDictionary( ifstream& infile, set<string>& english);
	void trimDictionary( size_t wordLen, set<string>& master, set<string>& english,
			string prompt);

	void formWordFamilies( char nextCh, set<string> masterList, wordFamilyMap& wordFamilies);
	bool mapCompare(const pair<string, WordFamily >& lhs,
			const pair<string, WordFamily >& rhs);

	string badGuessString( int wordLen );
	int updateWord( string wordCode, string badGuess, char nextCh, vector<char>& word);

	void printVector( vector<char> word );
	void printSet( set<char> setOfChar );
	void printSetOfStrings( set<string>& setOfString );
	void printWordFamilyOthers( vector<char> word, int noGuesses, bool showWords,
			set<char> lettersUsed, set<string>& masterList );



};





#endif /* EVILHM_H_ */
