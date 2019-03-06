




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

struct WordFamily {
	int freq;
	set<string> family;
};

typedef map< string, WordFamily>  wordFamilyMap;
int getInt( string& s);
bool getChoice( string& s);
char getChar( string s);
bool checkUsed( char nextCh, set<char> lettersUsed );

void readDictionary( ifstream& infile, set<string>& dic);
void trimDictionary( size_t wordLen, set<string>& master, set<string>& dic,
		string s);

void formWordFamilies( char nextCh, set<string> masterList, wordFamilyMap& wordFamilies);
bool mapCompare(const pair<string, WordFamily >& lhs,
		const pair<string, WordFamily >& rhs);

string badGuessString( int wordLen );
int updateWord( string wordCode, string badGuess, char nextCh, vector<char>& word);

void printVector( vector<char> word );
void printSet( set<char> setOfChar );
void printSetOfStrings( set<string>& setOfString );
void printResult( vector<char> word, int noGuesses, bool showWords,
		set<char> lettersUsed, set<string>& masterList );





//print user result, #of guess letf and runing number
void printResult( vector<char> word, int noGuesses, bool showWords,
		set<char> lettersUsed, set<string>& masterList )
{
	printVector( word);
	cout << "#of guess left: " << noGuesses << endl;
	cout << "Letter already Used: " ;
	printSet( lettersUsed );
	cout << endl;

	if ( showWords ) {
		cout << "running number in the list: " << masterList.size() << endl;

		cout << endl;
	}
}

//update the word on the letter used
int updateWord( string wordCode, string badGuess, char nextCh, vector<char>& word)
{
	if ( wordCode == badGuess )
		return 0;

	int count = 0;
	for (int i = 0; i < wordCode.length(); i++){
		if ( wordCode[i] == '1') {
			word[i] = nextCh;
			count++;
		}
	}
	return count;
}

/* Forms the Map of word Families with their Frequencies */
void formWordFamilies( char nextCh, set<string> masterList, wordFamilyMap& wordFamilies)
{

	string tempWord;
	for (set<string>::iterator itr = masterList.begin(); itr != masterList.end(); ++itr) {
		tempWord = *itr;



		for (int i = 0; i < tempWord.length(); i++) {
			if (tempWord[i] == nextCh)
				tempWord[i] = '1';
			else tempWord[i] = '0';
		}



		if ( wordFamilies.find(tempWord) == wordFamilies.end() ) {

			WordFamily wordFamily;

			wordFamily.freq = 1;
			wordFamily.family.insert( *itr );
			wordFamilies.insert( pair<string, WordFamily> (tempWord, wordFamily) );
		} else {
			wordFamilies[tempWord].freq++;
			wordFamilies[tempWord].family.insert( *itr);
		}
	}


}

//find the biggest set
bool mapCompare(const pair<string, WordFamily >& lhs,
		const pair<string, WordFamily >& rhs)
{
	return lhs.second.freq < rhs.second.freq;
}


void printSetOfStrings( set<string>& setOfString )
{
	for ( set<string>::iterator itr = setOfString.begin(); itr != setOfString.end(); ++itr ){
		cout << *itr << ", ";
	}
	cout << "??? " << endl;
}


void printSet( set<char> setOfChar )
{
	for ( set<char>::iterator itr = setOfChar.begin(); itr != setOfChar.end(); ++itr ){
		cout << *itr << ", ";
	}
	cout << "???" << endl;
}

// Prints a Vector on Screen
void printVector( vector<char> word)
{
	for (size_t i = 0; i < word.size(); i++) {
		cout << word[i];
	}
	cout << '\n' << endl;
}

// Checks whether the Letter Entered by User was Used Already
bool checkUsed( char nextCh, set<char> lettersUsed )
{
	if ( lettersUsed.find(nextCh) == lettersUsed.end() )
		return false;
	else
		return true;
}

//update the dictionary after every user input
void trimDictionary( size_t wordLen, set<string>& masterList, set<string>& dic,
		string s)
{
	while( masterList.empty() ) {
		for( set<string>::iterator itr = dic.begin(); itr != dic.end(); ++itr) {
			if ( (*itr).length() == wordLen ) {  
				masterList.insert(*itr);
				//cout << *itr << endl;
			}
		}

		if( masterList.empty()) {
			cout << "No word that long in the dictionary, try again!" << endl;
			wordLen = getInt( s);
		}
	}
	return;
}

//the string of wrong guess
string badGuessString( int wordLen )
{
	string zeros;
	for (int i = 0; i < wordLen; i++ ) {
		zeros += '0';
	}
	return zeros;
}

//read dic to a set
void readDictionary( ifstream& infile, set<string>& dic)
{
	string temp;
	while( getline(infile, temp))
		dic.insert( temp);
}



//get user input char
char getChar( string s)
{
	string temp;

	while( true){
		cout << s;
		getline(cin, temp);

		
		if (temp[temp.size() - 1] == '\r') temp.resize(temp.size() - 1);

		if (temp.length()>1 || !isalpha(temp[0])) {
			cout << "this is not a char,try again" << endl;
		} else {
			cout<< endl;
			return temp[0];
		}
	}
}

//get yes or no
bool getChoice( string& s )
{
	string temp;

	cout << s;
	getline( cin, temp);

	if(temp=="yes"||temp=="y")
		return true;
	else
		return false;

}

//get the int from user
int getInt( string& s)
{
	string temp; int number;
	while (true) {
		cout << s;

		getline( cin, temp);
		istringstream checkInt(temp);
		checkInt >> number;

		if (checkInt.fail() || number< 0)
			cout << "int must bigger than 0" << endl;
		else
			return number;
	}
}




int main() {


	ifstream infile;
	infile.open("dictionary.txt");

	if( !infile.is_open() ) {
		cout << "can not load file" << endl;
		return 0;
	}

	set<string> dic;
	readDictionary( infile, dic);


	bool moreGame = true;

	while( moreGame ) {



		string s = "please enter the number of guess  ";
		int noGuesses = getInt( s);

		if (!noGuesses) {
			s = "Game over, play again?(y/n)? ";
			moreGame = getChoice( s);

			if (moreGame)
				continue;
			else
				break;
		}


		s = "Do you want to see the remaining words list (Y/N)?  ";
		bool showWords = getChoice( s);

		s = "Enter the Word Length for the Hangman: ";
		size_t wordLen = getInt( s);
		cout << endl;


		string badGuess = badGuessString( wordLen );


		set<string> masterList;
		trimDictionary( wordLen, masterList, dic, s);



		vector<char> word(wordLen, '-');


		set<char> lettersUsed;

		printVector( word);//print word

		while( wordLen > 0 && noGuesses > 0 ) {


			s = "please enter your guess: ";
			char nextCh = getChar( s);


			bool isBadCh = checkUsed( nextCh, lettersUsed );
			if (isBadCh) {
				cout << "letter already used" << endl;
				continue;
			} else
				lettersUsed.insert( nextCh );

			wordFamilyMap wordFamilies;

			formWordFamilies( nextCh, masterList, wordFamilies);

			pair<string, WordFamily> maxWordFamily = *max_element( wordFamilies.begin(),
					wordFamilies.end(), mapCompare);

			masterList.clear();
			masterList = maxWordFamily.second.family;

			string wordCode = maxWordFamily.first;
			int lettersGuessed = updateWord( wordCode, badGuess, nextCh,  word);

			if( lettersGuessed == 0 )
				noGuesses--;
			else
				wordLen -= lettersGuessed;


			printResult( word, noGuesses, showWords, lettersUsed, masterList );



		}

		if ( noGuesses == 0 ) {
			cout << "sorry, you lose" << endl;
			cout << "The Word was: " << *masterList.begin() << "\n" << endl;
		} else
			cout << "You Win! \n" << endl;


		s = "do you want to play again (y or n)? ";
		moreGame = getChoice( s);
		cout << endl;
	}

	return 0;
}
