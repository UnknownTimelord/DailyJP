#include <iostream>
#include <fstream>
#include "jp.h"
using namespace std;

    /*
        Programmer:　ダンカリ〜ジョン
        このプログラムに私が日本語を学習を試す。
    */

    //  I really want to try making this program output Kanji and take Kana/Kanji as input. I hate romaji, it confuses my brain.
    // Even when I type I imagine the Kana and Kanji I'm typing and not romaji.

int main () {
    ifstream japanese;
    japanese.open("jp.json");
    if(!japanese.is_open()) cout << "File does not exist.";

    DailyJapanese dailyWords;
    UniqueKanji uniqueKanji;
    EnglishDefinitions englishDefinitions;

    dailyWords = jsonWords(japanese);
}