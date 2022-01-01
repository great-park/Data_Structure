# 1. 리스트로 구현
class Queue():
    def __init__(self):
        self.queue = []

    def push(self, data):
        self.queue.append(data)

    def pop(self):
        value = None

        if self.isEmpty():
            print("큐가 비었음")
        else:
            value = self.queue[0]
            self.queue = self.queue[1:]  # 앞에서 한 칸 줄이기
        return value

    def peek(self):
        value = None

        if self.isEmpty():
            print("큐가 비었음")
        else:
            value = self.queue[0]

        return value

    def isEmpty(self):
        if len(self.queue) == 0:
            return True
        else:
            return False


que = Queue()
que.push(1)
que.push(2)
que.push(3)
print(que.pop())
print(que.pop())
print(que.pop())

# 2. singly linked list로 구현
print("연결리스트로 구현")


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Queue2:
    def __init__(self):
        self.head = None
        self.rear = None

    def push(self, data):
        newNode = Node(data)

        if self.head == None:
            self.head = newNode
            self.rear = newNode
        else:
            self.rear.next = newNode
            self.rear = newNode

    def pop(self):
        value = None

        if self.head is None:
            print("큐가 비었음")
        else:
            value = self.head.data
            self.head = self.head.next

        if self.head is None:
            self.rear = None
        return value

    def peek(self):
        value = None

        if self.head is None:
            print("큐가 비었음")
        else:
            value = self.head.data
        return value


que2 = Queue2()
que2.push(1)
que2.push(2)
que2.push(3)
print(que2.pop())
print(que2.pop())
print(que2.pop())
