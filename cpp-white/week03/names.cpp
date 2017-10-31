#include<string>
#include<map>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) {
        int first_name_index = getClosestYear(first_names, year);
        int last_name_index = getClosestYear(last_names, year);

        if (first_name_index == -1 && last_name_index == -1) {
            return "Incognito";
        }

        if (last_name_index == -1) {
            return first_names[first_name_index] + " with unknown last name";
        }

        if (first_name_index == -1) {
            return last_names[last_name_index] + " with unknown first name";
        }

        return first_names[first_name_index] + " " + last_names[last_name_index];
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;

    int getClosestYear(const map<int, string>& list, const int& year) {
        int index = -1;

        for(const auto& item: list) {
            if (year < item.first) {
                break;
            }

            index = item.first;
        }

        return index;
    }
};