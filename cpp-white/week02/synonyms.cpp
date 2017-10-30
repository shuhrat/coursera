#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;


int main() {
    int operations = 0;
    map<string, set<string>> synonyms;


    cin >> operations;

    while (--operations >= 0) {
        string operation;

        cin >> operation;

        if (operation == "ADD") {
            string word1, word2;

            cin >> word1 >> word2;

            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        }

        if (operation == "COUNT") {
            string word;

            cin >> word;
            if (synonyms.count(word)) {
                cout << synonyms[word].size() << endl;
            } else {
                cout << 0 << endl;
            }
        }

        if (operation == "CHECK") {
            string word1, word2;

            cin >> word1 >> word2;

            if (synonyms.count(word1) && synonyms[word1].count(word2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

        if (operation == "DUMP") {
            string word;

            cin >> word;

            for(auto words: synonyms[word]) {
                cout << words << endl;
            }

            operations++;
        }


    }

    return 0;
}