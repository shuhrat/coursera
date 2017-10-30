#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;


int main() {
    int operations = 0;
    map<string, string> countries;


    cin >> operations;

    while (--operations >= 0) {
        string operation;

        cin >> operation;

        if (operation == "CHANGE_CAPITAL") {
            string country, new_capital;

            cin >> country >> new_capital;

            if (countries.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            } else if (countries[country] == new_capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else {
                cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << new_capital << endl;
            }

            countries[country] = new_capital;
        }

        if (operation == "RENAME") {
            string old_country_name, new_country_name;

            cin >> old_country_name >> new_country_name;

            if (old_country_name == new_country_name || countries.count(old_country_name) == 0 || countries.count(new_country_name) == 1 ) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << old_country_name << " with capital " << countries[old_country_name] << " has been renamed to " << new_country_name << endl;
                countries[new_country_name] = countries[old_country_name];
                countries.erase(old_country_name);
            }
        }

        if (operation == "ABOUT") {
            string country;

            cin >> country;

            if (countries.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << countries[country] << endl;
            }
        }

        if (operation == "DUMP") {

            if (countries.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                for(auto country: countries) {
                    cout << country.first << "/" << country.second << endl;
                }
            }
        }


    }

    return 0;
}