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

const int MAX_WORDS = 100;

namespace jp {
    struct word {
        vector<string> word;
        vector<string> onyomi;
        vector<string> definition;
    };
    struct kanji {
        vector<string> kanji;
        vector<string> meaning;
    };
    struct hiragana {
        vector<string> hiragana;
        vector<string> romaji;
    };
    const word null_word = {};
    const kanji null_kanji = {};
    const hiragana null_hira = {};

    word dailyWords(json &j) {
        word word {
            j["words"].template get<vector<string>>(),
                j["onyomi"].template get<vector<string>>(),
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

    hiragana hiraganaAndRomaji(json &j) {
        hiragana hiragana {
                j["hiragana"].template get<vector<string>>(),
                j["romaji"].template get<vector<string>>()
        };
        return hiragana;
    }
}

