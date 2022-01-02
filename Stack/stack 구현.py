# 1. 리스트로 구현
class Stack:
    def __init__(self):
        self.stack = []

    def push(self, data):
        self.stack.append(data)

    def pop(self):
        value = None
        if self.isEmpty():
            print("스택이 비었음")
        else:
            value = self.stack.pop()
        return value

    def peek(self):
        value = None
        if self.isEmpty():
            print("스택이 비었음")
        else:
            value = self.stack[-1]
        return value

    def isEmpty(self):
        if len(self.stack) == 0:
            return True
        else:
            return False

# 2. singly linked list로 구현
class Node:
    def __init__(self, data):
        self.data = data
        self.bottom = None

class Stack2():
    def __init__(self):
        self.top = None

    def push(self, data):
        newNode = Node(data)
        newNode.bottom = self.top
        self.top = newNode

    def pop(self):
        value = None
        if self.isEmpty():
            print("스택이 비었음")
        else:
            value = self.top.data
            self.top = self.top.bottom
        return value

    def peek(self):
        value = None
        if self.isEmpty():
            print("스택이 비었음")
        else:
            value = self.top.data
        return value

    def isEmpty(self):
        if self.top is None:
            return True
        else:
            return False
