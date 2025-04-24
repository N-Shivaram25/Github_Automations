class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def searchKey(self, n, head, key):
        current = head
        while current:
            if current.data == key:
                return True
            current = current.next
        return False
#jhgjhgdddssssssssssssxccswsssssss
def build_linked_list(arr):
    if not arr:
        return None
    head = Node(arr[0])
    current = head
    for val in arr[1:]:
        current.next = Node(val)
        current = current.next
    return head
#jfkjsdhfkjsxddsd
