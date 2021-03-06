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
        iterator = self.head
        for _ in range(id):
            iterator = iterator.next
        return iterator
    """ 
    def get_node(self, id):
        cnt = 0
        cur = self.head
        while cnt < id:
            cnt += 1
            cur = cur.next
        return cur
    """

    def insert_node(self, index, data):
        newNode = Node(data)
        if index == 0:
            newNode.next = self.head
            self.head = newNode
            return
        previous_node = self.get_node(index - 1)
        temp = previous_node.next
        previous_node.next = newNode
        newNode.next = temp

    def delete_node(self, index):
        previous_node = self.get_node(index-1)

        if previous_node.next.next == None:
            previous_node.next = None
        else:
            previous_node.next = previous_node.next.next

    def print_all(self):
        iterator = self.head
        while iterator is not None:
            print(iterator.data)
            iterator = iterator.next

    """__str__ 메소드, 생성한 인스턴스를 출력시 호출"""

    def __str__(self):
        res_str = "|"
        iterator = self.head

        while iterator is not None:
            res_str += f" {iterator.data} |"
            iterator = iterator.next
        return res_str


# test
my_list = LinkedList()

my_list.append(1)
my_list.append(2)
my_list.append(3)
my_list.append(4)
my_list.append(5)
my_list.print_all()

print("2번 인덱스 삭제")
my_list.delete_node(2)


"or"
print(my_list)
