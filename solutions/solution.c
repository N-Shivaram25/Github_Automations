#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool searchKey(int n, struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {///sfsfgds
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;//sdfzsgzsd
}
