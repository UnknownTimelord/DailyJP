#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include "jp.h"
#include "json.hpp"
using namespace std;
using namespace jp;

/*
    Programmer:　ダンカリ〜ジョン
    このプログラムに私が日本語を学習を試す。
*/

vector<string> shuffleWords(vector<string>);
bool compareGuess(const string&, word, const string&);
string convertToRomaji(string guess);

void guessRomaji(const word &);

int main () {
    ifstream japanese;
    japanese.open("jp.json");
    if(!japanese.is_open()) {
        cout << "'jp.json' not found. Exiting...";
        return 1;
    }

    json jsonObject = json::parse(japanese);

    word dailyWords = jp::dailyWords(jsonObject);
    kanji dailyKanji = jp::dailyKanji(jsonObject);

    cout << "Welcome to DailyJP!\n"
         << "Reads a json file full of Japanese words, their pronunciations and definitions, as well as unique kanji from those words and their individual meanings.\n"
         << "The json provided is a list of daily words a friend of mine is graciously lending me, but if you follow the format you could easily use other kanji.\n\n"
         << "Special thanks:\nMy friend for giving me the opportunity to learn new words everyday.\n"
         << "The creator of the json library I'm using, found here:\n"
         << "https://github.com/nlohmann/json\n\n";

    cout << "Please choose an option: \n"
         << "1.) Guess the kana of a given Japanese word.\n"
         << "2.) Quit.\n";

    int choice;
    cin >> choice;

    while(choice < 0 || choice > 2) {
        cout << "Please input a valid option: ";
        cin >> choice;
    }

    switch(choice) {
        case(1): guessRomaji(dailyWords);
        case(2) : {
            cout << "Thank you for using DailyJP! Goodbye.";
            return 0;
        }
    }
    return 0;
}

/*
 * Asks user to guess the word based of the onyomi pronunciation in kana.
 * We convert the kana to romaji because roman characters are far easier to parse.
 */
void guessRomaji(const word& dailyWords) {
    vector<string> randomWords = dailyWords.word;
    randomWords = shuffleWords(randomWords);

    cin.clear();
    cin.ignore(100, '\n');

    for(const auto & randomWord : randomWords) {
        string guess;
        cout << "Input the kana for " << randomWord << ": ";
        getline(cin, guess);
        guess = convertToRomaji(guess);
        bool correct = false;
        while(!correct) {
            if(compareGuess(guess, dailyWords, randomWord)) { correct = true; cout << "Correct!\n"; }
            else {
                cout << "Incorrect, please try again: ";
                getline(cin, guess);
                guess = convertToRomaji(guess);
            }
        }
    }
}

/*
 * Shuffles the vector of words
 */
vector<string> shuffleWords(vector<string> words) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(begin(words), end(words), default_random_engine(seed));
    return words;
}

/*
 * Compares users guess to the list of Japanese words in romaji.
 */
bool compareGuess(const string& guess, word dailyWords, const string& randomWord) {
    int index = 0;
    for(int i = 0; i < dailyWords.word.size(); i++) {
        if(dailyWords.word.at(i) == randomWord) index = i;
    }

    string correctRomaji = dailyWords.romaji.at(index);

    if(guess == correctRomaji) return true;
    return false;
}

/*
 * Converts kana from the user into romaji.
 * The array is what makes the romaji appear in the correct order for later parsing.
 */
string convertToRomaji(string guess) {
    string temp_romaji_array[100];
    int index = 0;
    for(int i = 0; i < hiragana.size(); i++) {
        if(guess.find(hiragana.at(i)) != std::string::npos) {
            temp_romaji_array[guess.find(hiragana.at(i))] = romaji.at(i);
        }
    }

    string temp_romaji;
    for(string a: temp_romaji_array) {
        temp_romaji += a;
    }
    return temp_romaji;
}