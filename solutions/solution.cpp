struct Node {
  int data;
  Node* next;
};

class Solution {
  public:
    // Function to search for a key in the linked list.
    bool searchKey(int n, Node* head, int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return true;//fdfgd  //dsfsdgsd
            }
            current = current->next;//sfsfgg
        }
        return false;
    }  
};
