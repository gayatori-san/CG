#include <iostream>
#include <string>
using namespace std;

struct Node { int id; string name; Node* next; };
Node *frontNode = NULL, *rearNode = NULL;

void enqueue(int id, string name) {
    Node* p = new Node{id, name, NULL};
    if (frontNode == NULL) frontNode = rearNode = p;
    else { rearNode->next = p; rearNode = p; }
    rearNode->next = frontNode;
}
void dequeue() {
    if (frontNode == NULL) { cout << "Queue empty\n"; return; }
    Node* p = frontNode;
    cout << "Removed: " << p->id << " " << p->name << endl;
    if (frontNode == rearNode) frontNode = rearNode = NULL;
    else { frontNode = frontNode->next; rearNode->next = frontNode; }
    delete p;
}
void display() {
    if (frontNode == NULL) { cout << "Queue empty\n"; return; }
    Node* p = frontNode;
    do { cout << p->id << " " << p->name << endl; p = p->next; } while (p != frontNode);
}
int main() {
    enqueue(101,"Aarav"); enqueue(102,"Meera"); enqueue(103,"Kabir");
    cout << "Waiting list:\n"; display();
    dequeue();
    cout << "After confirmation:\n"; display();
    return 0;
}