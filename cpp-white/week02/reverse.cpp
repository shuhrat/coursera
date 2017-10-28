#include<iostream>
#include<string>
#include<vector>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Reverse(vector<int>& v) {
    int size = v.size();

    for(int i=0; i < size/2; i++) {
        swap(v[i], v[size-i]);
    }
}
