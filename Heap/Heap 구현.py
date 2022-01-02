def swap(tree, index_1, index_2):
    temp = tree[index_1]
    tree[index_1] = tree[index_2]
    tree[index_2] = temp


def heapify(tree, index, tree_size):
    left_child_index = 2 * index
    right_child_index = 2 * index + 1

    largest = index
    if left_child_index < tree_size and tree[largest] < tree[left_child_index]:
        largest = left_child_index
    if right_child_index < tree_size and tree[largest] < tree[right_child_index]:
        largest = right_child_index
    if largest != index:
        swap(tree, largest, index)
        heapify(tree, largest, tree_size)


# 실행 코드
tree = [None, 15, 5, 12, 14, 9, 10, 6, 2, 11, 1]  # heapify하려고 하는 완전 이진 트리
heapify(tree, 2, len(tree))  # 노드 2에 heapify 호출
print(tree)
