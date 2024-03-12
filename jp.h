    #include <string>
    #include <iostream>
    #include <fstream>
    using namespace std;

    const int MAX_JP = 100;
    const int MAX_JSON_LINES = 1000;

    struct DailyJapanese {
        string word[MAX_JP];
        string pronounciation[MAX_JP];
    };

    const DailyJapanese null_daily;

    struct UniqueKanji {
        string kanji[MAX_JP];
        string meaning[MAX_JP];
    };

    const UniqueKanji null_kanji;

    struct EnglishDefinitions {
        string word[MAX_JP];
        string definition[MAX_JP];
    };

    const EnglishDefinitions null_definitions;

    /*
        Takes in a json file, and returns my custom struct DailyJapanese, consisting of two arrays of strings "word" and "pronounciaton"
    */
    DailyJapanese jsonWords(ifstream &file) {
        if(file.is_open());
        else { return null_daily; }

        string json[MAX_JSON_LINES] = {};
        for(int i = 0; file >> json[i] && i < MAX_JSON_LINES; i++) {
            cout << json[i] << endl;
        }
        return null_daily; // dont forget to change this
    }

    /*
        Takes in a json file, and returns my custom struct UniqueKanji, consisting of two arrays of strings "kanji" and "meaning"
    */
    UniqueKanji jsonKanji(fstream &file)  {
        return null_kanji; // dont forget to change this
    }

    /*
        Takes in a json file, and returns my custom struct EnglishDefinitions, consisting of two arrays of strings "word" and "definition"
    */
    EnglishDefinitions jsonEnglish(fstream &file) {
        return null_definitions; // dont forget to change this
    }