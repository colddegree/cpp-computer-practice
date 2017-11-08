#include <iostream>
#include <ctime>

using namespace std;

typedef struct listNode {
    int data;
    listNode *next = NULL;
} listNode;

void listPushBack(listNode**, int);
void listPrint(listNode*);


typedef struct multiListNode {
    listNode *data;
    multiListNode *next = NULL;
} multiListNode;

void multiListPushBack(multiListNode**, listNode*);
void multiListPrint(multiListNode*);


int getRandomNumber(int, int);


const int LIST_NODES_MAX_QUANTITY = 10;
const int BAD_SIZE = 1;

int main() {

    setlocale(LC_ALL, "Russian");

    srand( time(NULL) );

    int n;
    wcout << L"Введите размерность мультисписка: ";
    cin >> n;

    if (n < 0) {
        wcout << L"Размерность не может быть отрицательной." << endl;
        return BAD_SIZE;
    }
    multiListNode *head = NULL;

    for (int i = 0; i < n; i++) {
        listNode *listHead = NULL;
        for (int j = 0; j < getRandomNumber(0, LIST_NODES_MAX_QUANTITY); j++) {
            listPushBack(&listHead, getRandomNumber(0, 100));
        }
        multiListPushBack(&head, listHead);
    }

    multiListPrint(head);

    return 0;
}

int getRandomNumber(int a, int b) {
    // return random number from a to b inclusive

    return rand() % (b - a + 1) + a;
}

void listPushBack(listNode **head, int a) {
    listNode *p = new listNode;
    p->data = a;

    if (*head == NULL) {
        *head = p;
    } else {
        listNode *tmp = *head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = p;
    }
}

void listPrint(listNode *head) {
    if (head == NULL) return;

    listNode *tmp = head;

    do {
        cout << tmp->data << ' ';
    } while ( (tmp = tmp->next) != NULL );

    cout << endl;
}

void multiListPushBack(multiListNode **head, listNode *a) {
    multiListNode *p = new multiListNode;
    p->data = a;

    if (*head == NULL) {
        *head = p;
    } else {
        multiListNode *tmp = *head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = p;
    }
}

void multiListPrint(multiListNode* head) {
    if (head == NULL) return;

    multiListNode *tmp = head;

    do {
        listPrint(tmp->data);
    } while ( (tmp = tmp->next) != NULL );
}
