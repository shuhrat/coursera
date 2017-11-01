#include<map>
#include<vector>
#include<string>
#include<algorithm>

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

    for (int i = 1; i < size - 1; i++) {
        others += names[i] + ", ";
    }

    return first + " (" + others + names[size - 1] + ")";
};

class Person {
public:
    Person(const string &first_name, const string &last_name, const int year) {
        birth = year;
        first_names[birth] = first_name;
        last_names[birth] = last_name;
    }

    void ChangeFirstName(int year, const string &first_name) {
        if (isValidYear(year)) {
            first_names[year] = first_name;
        }
    }

    void ChangeLastName(int year, const string &last_name) {
        if (isValidYear(year)) {
            last_names[year] = last_name;
        }
    }

    string GetFullName(int year) const {
        if (!isValidYear(year)) {
            return "No person";
        }

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

    string GetFullNameWithHistory(int year) const {
        if (!isValidYear(year)) {
            return "No person";
        }

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

    bool isValidYear(int year) const {
        return birth <= year;
    }

private:
    int birth;
    map<int, string> first_names;
    map<int, string> last_names;
};