from collections import deque
from queue import Queue
# 1. deque 사용 - 보편적으로 사용, O(1) 소요
queue = deque()

queue.append(1)
queue.append(2)
queue.append(3)

queue.pop()
print(queue)

queue.popleft()
print(queue)
print(queue.popleft())

"""2. queue 모듈의 Queue 클래스 사용, 주로 멀티 쓰레딩(threading) 환경에서 사용되며, 내부적으로 라킹(locking)을 지원하여 여러 개의 쓰레드가 동시에 데이터를 추가하거나 삭제 가능
    deque와 달리 방향성이 없다!
"""
queue2 = Queue()
queue2.put(1)
queue2.put(2)
queue2.put(3)
print(queue2.get())  # 1
print(queue2.get())  # 2
print(queue2.get())  # 3

# 3. list 사용 - 성능적으로 불리하므로 쓰지말자
queue3 = [1, 2, 3, 4, 5]
queue3.append(6)
print(queue3)

queue3.pop(0)
print(queue3)
