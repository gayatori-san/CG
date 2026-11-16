#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
void display(vector<T> v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main() {
    vector<int> roll = {1, 2, 3};
    vector<string> name = {"Asha", "Riya", "Neha"};
    vector<float> sgpa = {8.5, 9.1, 8.8};

    cout << "Roll numbers: "; display(roll);
    cout << "Names: "; display(name);
    cout << "SGPA: "; display(sgpa);
    return 0;
}