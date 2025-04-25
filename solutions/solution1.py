class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def searchKey(self, n, head, key):
        current = head
        count = 0
        while current and count < n:
            if current.data == key:
                return True
            current = current.next
            count += 1
        return False

def build_linked_list(arr):
    if not arr:
        return None
    head = Node(arr[0])
    current = head
    for i in range(1, len(arr)):
        current.next = Node(arr[i])
        current = current.next
    return head