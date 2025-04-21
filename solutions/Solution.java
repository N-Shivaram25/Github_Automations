class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;///dfgdgsdsd //dsfsdfsd //dgdsgdsg
    }
}

class Solution {
    boolean searchKey(int n, Node head, int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key) {
                return true;
            }
            current = current.next;
        }
        return false;
    }
}
