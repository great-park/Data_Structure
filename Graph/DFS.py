# 리스트로 pop하는 것 보다 deque가 훨씬 성능이 좋다
def DFS(graph, start_node):
    from collections import deque
    visited = []
    need_visited = deque()

    # 시작 노드 설정해주기
    need_visited.append(start_node)

    # 방문이 필요한 리스트가 아직 존재한다면
    while need_visited:
        # 시작 노드를 지정하고
        node = need_visited.popleft()

        # 만약 방문한 리스트에 없다면
        if node not in visited:

            # 방문 리스트에 노드를 추가
            visited.append(node)
            # 인접 노드들을 방문 예정 리스트에 추가
            need_visited.extend(graph[node])

    return visited


def DFS_recursive(graph, start, visited=[]):
    visited.append(start)

    for node in graph[start]:
        if node not in visited:
            DFS_recursive(graph, node, visited)
    return visited
