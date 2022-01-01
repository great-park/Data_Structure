from collections import deque
# deque, 리스트로 구현  메소드 이름도 같음
stack = deque()
#stack = []

stack.append(1)
stack.append(2)
stack.append(3)
stack.append(4)

print("맨 위 : ", stack[-1])

print("pop")
print(stack.pop())
print(stack.pop())
print(stack.pop())
print(stack)
