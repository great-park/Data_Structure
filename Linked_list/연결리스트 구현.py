class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None

    def append(self, data):
        if self.head == None:
            self.head = Node(data)
            return
        cur = self.head
        while cur.next is not None:
            cur = cur.next
        cur.next = Node(data)

    def get_index(self, data):
        id = 0
        cur = self.head
        while cur.data != data:
            id += 1
            cur = cur.next
        return id

    def get_node(self, id):
        cnt = 0
        cur = self.head
        while cnt < id:
            cnt += 1
            cur = cur.next
        return cur

    def insert_node(self, index, data):
        newNode = Node(data)
        if index == 0:
            newNode.next = self.head
            self.head = newNode
            return
        cur = self.get_node(index - 1)
        temp = cur.next
        cur.next = newNode
        newNode.next = temp

    def delete_node(self, index):
        if index == 0:
            self.head = self.head.next
            return
        cur = self.get_node(index-1)
        cur.next = cur.next.next

    def print_all(self):
        iterator = self.head
        while iterator is not None:
            print(iterator.data)
            iterator = iterator.next


# test
my_list = LinkedList()

my_list.append(1)
my_list.append(2)
my_list.append(3)
my_list.append(4)
my_list.append(5)

my_list.print_all()
