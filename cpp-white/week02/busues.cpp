#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;


int main() {
    int operations = 0;
    map<string, vector<string>> buses;
    vector<string> bus_order;


    cin >> operations;

    while (--operations >= 0) {
        string operation;

        cin >> operation;

        if (operation == "NEW_BUS") {
            string bus;
            int stop_count;

            cin >> bus >> stop_count;

            bus_order.push_back(bus);

            while(stop_count > 0) {
                string bus_stop;

                cin >> bus_stop;
                buses[bus].push_back(bus_stop);
                stop_count--;
            }
        }

        if (operation == "BUSES_FOR_STOP") {
            string stop;
            bool found = false;

            cin >> stop;

            for(auto bus: bus_order) {
                for(auto bus_stop: buses[bus]) {
                    if (bus_stop == stop) {
                        found = true;
                        cout << bus << " ";
                    }
                }
            }

            if (!found) {
                cout << "No stop";
            }

            cout << endl;
        }

        if (operation == "STOPS_FOR_BUS") {
            string bus;

            cin >> bus;
            if (buses.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                for(auto bus_stop: buses[bus]) {
                    bool found = false;

                    cout << "Stop " << bus_stop << ":";

                    for(auto b: bus_order) {
                        if (b == bus) continue;

                        for(auto bs: buses[b]) {
                            if (bs == bus_stop) {
                                found = true;
                                cout << " " << b;
                            }
                        }
                    }

                    if(!found) {
                        cout << " no interchange";
                    }

                    cout << endl;
                }
            }
        }

        if (operation == "ALL_BUSES") {
            if(buses.size() == 0) {
                cout << "No buses" << endl;
            } else {
                for(auto bus: buses) {
                    cout << "Bus " << bus.first << ":";
                    for(auto stop: bus.second) {
                        cout <<" " << stop;
                    }
                    cout << endl;
                }
            }

        }
    }

    return 0;
}