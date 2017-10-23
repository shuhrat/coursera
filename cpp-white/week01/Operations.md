# Операции с контейнерами

```с++

#include<algorithm>

// подсчёт
vector<int> nums = {1, 5, 2, 3, 4, 5};
int quantity = count(begin(things), end(things), 5);

// сортировка
vector<string> things = {"hello", "world", "milk"};
sort(begin(things), end(things))

for(auto thing: things) {
    cout << thing << endl;
}
```