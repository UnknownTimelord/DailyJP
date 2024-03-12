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
void compareGuess(string);

int main () {
    ifstream japanese;
    japanese.open("jp.json");
    if(!japanese.is_open()) {
        cout << "'jp.json' does not exist! Exiting...";
        return 1;
    }

    json jsonObject = json::parse(japanese);

    word dailyWords = jp::dailyWords(jsonObject);
    kanji dailyKanji = jp::dailyKanji(jsonObject);

    cout << "Welcome to DailyJP!\n"
         << "The included jp.json is a collection of daily words a friend graciously supplies me with,\n"
         << "the english definitions of the words as well as every unique kanji,\n"
         << "as well as a complete list of hiragana and their respective romaji.\n"
         << "If you replicate the format, you could use any kanji you'd like, or even other languages.\n"
         << "Special thanks:\nMy friend for giving me the opportunity to learn new words everyday.\n"
         << "The creator of the json library I'm using, found here:\n"
         << "https://github.com/nlohmann/json" << endl;

    cout << dailyWords.word.size() << endl;

    vector<string> randomWords = dailyWords.word;
    randomWords = shuffleWords(randomWords);

    for(int i = 0; i < randomWords.size(); i++) {
        string guess;
        cout << "Input the romaji for this word: " << randomWords.at(i);
        getline(cin, guess);
        compareGuess();
    }

    return 0;
}

/*
 * Shuffles the vector of words
 */
vector<string> shuffleWords(vector<string> words) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(begin(words), end(words), default_random_engine(seed));
    return words;
}

void compareGuess(string guess) {
    // TO-DO
}