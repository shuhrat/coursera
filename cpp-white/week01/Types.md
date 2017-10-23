# Типы

```с++
int x = -5;
double pi = 3.14;
bool logical_value = false;
char symbol = 'Z';

// нужно добавить заголовок #include <string>
string hw = 'Hello World!';  

// нужно добавить заголовок #include <vector>
vector<int> nums = {1, 3, 5, 7};
num.size();

// нужно добавить заголовок #include <map>
map<string, int> name_to_value;
name_to_value["one"] = 1;
name_to_value["two"] = 2;

// кастомные типы 
struct Person {
    string name;
    string surname;
    int age;
};
vector<Person> staff;
staff.push_back({"Ivan", "Ivanov", 25});
staff.push_back({"Petr", "Petrov", 32});
staff[0].name // Ivan

```