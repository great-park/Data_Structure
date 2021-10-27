class Node:

    def __init__(self, data):
        self.data = data
        self.next = Node


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

    def __str__(self):
        res_str = "|"
        iterator = self.head
        while iterator is not None:
            res_str += f" {iterator.data} |"
            iterator = iterator.next
        return res_str


linked_list = LinkedList()

linked_list.append(2)
linked_list.append(3)
linked_list.append(5)
linked_list.append(7)
linked_list.append(12)

print(linked_list)
