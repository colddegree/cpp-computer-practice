#include <iostream>
#include <ctime>

using namespace std;

typedef struct node {
    int data;
    node *next = NULL;
} node;

void listPushBack(node**, int);
void listPrint(node*);
void listSort(node*);

int getRandomNumber(int, int);

const int NODES_IN_LIST = 10;

int main() {

    srand( time(NULL) );

    node *head = NULL;

    for (int i = 0; i < NODES_IN_LIST; i++)
        listPushBack(&head, getRandomNumber(0, 100));

    listPrint(head);
    listSort(head);
    listPrint(head);

    return 0;
}

int getRandomNumber(int a, int b) {
    // return random number from a to b inclusive

    return rand() % (b - a + 1) + a;
}

void listPushBack(node **head, int a) {
    node *p = new node;
    p->data = a;

    if (*head == NULL) {
        *head = p;
    } else {
        node *tmp = *head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = p;
    }
}

void listPrint(node *head) {
    if (head == NULL) return;

    node *tmp = head;

    do {
        cout << tmp->data << ' ';
    } while ( (tmp = tmp->next) != NULL );

    cout << endl;
}

void listSort(node *head) {

    while (true) {
        bool swapped = false;
        node *p = head;
        while (p->next != NULL) {
            if (p->data > p->next->data) {
                swap(p->data, p->next->data);
                swapped = true;
            }
            p = p->next;
        }
        if (!swapped) break;
    }
}
