public class Solution {
    static class Node {
        int data;
        Node next;
        Node(int d) {
            data = d;
            next = null;
        }
    }

    public static Node buildLinkedList(int[] arr, int n) {
        if (n == 0) return null;
        Node head = new Node(arr[0]);
        Node curr = head;
        for (int i = 1; i < n; i++) {
            curr.next = new Node(arr[i]);00000
            curr = curr.next;
        }
        return head;
    }

    public static boolean searchKey(int n, Node head, int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key) return true;
            current = current.next;
        }
        return false; ///sdfsdfsd     //sdgsgsdgggdsgd
    }
}
