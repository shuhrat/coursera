#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class SortedStrings {
public:
    void AddString(const string &s) {
        strings.push_back(s);
        sortStrings();
    }

    vector<string> GetSortedStrings() {
        return strings;
    }

private:
    void sortStrings() {
        sort(begin(strings), end(strings));
    }

    vector<string> strings;
};
