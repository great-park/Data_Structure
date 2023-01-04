"""
추가 순서와 상관없이 제거될 때 우선순위가 작은 순으로 제거된다.
PriorityQueue 클래스 in  queue 내장 모듈 사용
힙을 사용하니깐 O(logn)
"""
from queue import PriorityQueue

# 크기 설정 가능
queue = PriorityQueue(maxsize=10)

queue.put(30)
queue.put(10)
queue.put(20)

print(queue.get())  # 10
print(queue.get())  # 20
print(queue.get())  # 30

"""
우선 순위 부여 가능 (우선순위, 값) 튜플 전달,  
단 제거할 때도 튜플의 형식으로 나오므로 값을 꺼내기 위해 인덱스 붙일 것
"""
queue.put((3, "3등"))
queue.put((1, "1등"))
queue.put((2, "2등"))

print(queue.get()[1])
print(queue.get()[1])
print(queue.get()[1])

#Max우선순위큐
queue2 = MaxPriorityQueue()
