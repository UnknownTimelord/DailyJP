#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp" // https://github.com/nlohmann/json - Thank you for this library!
using namespace std;
using json = nlohmann::json;

/*
 * Programmer: ダンカリ〜ジョン
 */

namespace jp {
    struct word {
        vector<string> word;
        vector<string> onyomi;
        vector<string> romaji;
        vector<string> definition;
    };
    struct kanji {
        vector<string> kanji;
        vector<string> meaning;
    };
    const word null_word = {};
    const kanji null_kanji = {};
    const vector<string> hiragana = {"あ", "い", "う", "え", "お",
                                     "か", "き", "く", "け", "こ",
                                     "さ", "し", "す", "せ", "そ",
                                     "た", "ち", "つ", "て", "と",
                                     "な", "に", "ぬ", "ね", "の",
                                     "は", "ひ", "ふ", "へ", "ほ",
                                     "ま", "み", "む", "め", "も",
                                     "や", "ゆ", "よ",
                                     "わ", "を", "ん",
                                     "ら", "り", "る", "れ", "ろ"};
    const vector<string> romaji = {"a", "i", "u", "e", "o",
                                   "ka", "ki", "ku", "ke", "ko",
                                   "sa", "shi", "su", "se", "so",
                                   "ta", "chi", "tsu", "te", "to",
                                   "na", "ni", "nu", "ne", "no",
                                   "ha", "hi", "fu", "he", "ho",
                                   "ma", "mi", "mu", "me", "mo",
                                   "ya", "yu", "yo",
                                   "wa", "o", "n",
                                   "ra", "ri", "ru", "re", "ro"};
    word dailyWords(json &j) {
        word word {
            j["words"].template get<vector<string>>(),
                j["onyomi"].template get<vector<string>>(),
                        j["romaji"].template get<vector<string>>(),
                j["english_definitions"].template get<vector<string>>()
        };
        return word;
    }

    kanji dailyKanji(json &j) {
        kanji kanji {
                j["unique_kanji"].template get<vector<string>>(),
                j["meanings"].template get<vector<string>>()
        };
        return kanji;
    }
}

