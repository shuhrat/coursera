#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person {
    string name;
    string surname;
    int age;
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<Person> staff;


    staff.push_back({"Ivan", "Ivanov", 25});





    return 0;
}