#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

string FindNameByYear(const map<int, string> &names, int year) {
    string name;

    for (const auto &item : names) {
        if (item.first <= year) {
            name = item.second;
        } else {
            break;
        }
    }

    return name;
}

vector<string> FindNameByYearWithHistory(const map<int, string> &names, int year) {
    vector<string> name_history;
    string last = "";

    for (const auto &item : names) {
        if (item.first <= year && item.second != last) {
            name_history.push_back(item.second);
            last = item.second;
        } else {
            break;
        }
    }

    reverse(begin(name_history), end(name_history));

    return name_history;
}

string FormatNames(const vector<string> &names) {
    int size = names.size();
    string first = names[0];

    if (size == 1) {
        return first;
    }

    string others = "";

    for(int i=1; i<size-1; i++) {
        others += names[i] +", ";
    }

    return first + " (" + others + names[size-1] + ")";
};

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) {
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        }

        if (first_name.empty()) {
            return last_name + " with unknown first name";
        }

        if (last_name.empty()) {
            return first_name + " with unknown last name";
        }

        return first_name + " " + last_name;
    }

    string GetFullNameWithHistory(int year) {
        const vector<string> first_name = FindNameByYearWithHistory(first_names, year);
        const vector<string> last_name = FindNameByYearWithHistory(last_names, year);

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        }

        if (first_name.empty()) {
            return FormatNames(last_name) + " with unknown first name";
        }

        if (last_name.empty()) {
            return FormatNames(first_name) + " with unknown last name";
        }

        return FormatNames(first_name) + " " + FormatNames(last_name);
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
