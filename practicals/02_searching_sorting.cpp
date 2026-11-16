#include <iostream>
#include <string>
using namespace std;

struct Book { int id; string title; };

int main() {
    Book b[5] = {{105,"C++"},{102,"Python"},{104,"Java"},{101,"DS"},{103,"DBMS"}};
    int n = 5, key = 104, i, j;

    for (i = 0; i < n; i++)
        if (b[i].id == key) { cout << "Linear: Found at " << i << endl; break; }

    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (b[j].id > b[j+1].id) swap(b[j], b[j+1]);

    int low = 0, high = n-1, mid, found = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (b[mid].id == key) { found = mid; break; }
        else if (b[mid].id < key) low = mid + 1;
        else high = mid - 1;
    }
    if (found != -1) cout << "Binary: Found at " << found << endl;

    cout << "Books sorted by ID: ";
    for (i = 0; i < n; i++) cout << b[i].id << " ";
    cout << endl;

    for (i = 1; i < n; i++) {
        Book temp = b[i]; j = i-1;
        while (j >= 0 && b[j].title > temp.title) { b[j+1] = b[j]; j--; }
        b[j+1] = temp;
    }
    cout << "Books sorted by title: ";
    for (i = 0; i < n; i++) cout << b[i].title << " ";
    return 0;
}