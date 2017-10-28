#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    int operations = 0;
    vector<string> queue;

    cin >> operations;

    while (--operations >= 0) {
        string operation;

        cin >> operation;

        if (operation == "COME") {
            int count;

            cin >> count;
            if (count > 0) {
                while(--count >= 0) {
                    queue.push_back("QUIET");
                }
            } else {
                queue.resize(queue.size() + count);
            }
        }

        if (operation == "WORRY") {
            int index;

            cin >> index;
            queue[index] = "WORRY";
        }

        if (operation == "QUIET") {
            int index;

            cin >> index;
            queue[index] = "QUIET";
        }

        if (operation == "WORRY_COUNT") {
            int count = 0;

            for(string item: queue) {
                if (item == "WORRY") count++;
            }
            cout << count << endl;
        }
    }


    return 0;
}