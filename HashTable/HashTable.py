from LinkedList_for_HashTable import LinkedList  # 해시 테이블에서 사용할 링크드 리스트 임포트


class HashTable:
    """해시 테이블 클래스"""

    def __init__(self, capacity):
        self.capacity = capacity
        self.table = [LinkedList() for _ in range(
            self.capacity)]  # _table은 해시 테이블에서 사용하는 리스트, 각 인덱스에 연결리스트 저장

    def hash_function(self, key):
        return hash(key) % self.capacity

    def get_linked_list_for_key(self, key):
        hashed_index = self.hash_function(key)
        return self.table[hashed_index]

    def get_node(self, key):
        linked_list = self.get_linked_list_for_key(key)
        return linked_list.find_node_with_key(key)

    def get_value(self, key):
        return self.get_node(key).value

    def insert(self, key, value):
        existing_node = self.get_node(key)  # 이미 저장된 key인지 확인한다

        if existing_node is not None:
            existing_node.value = value
        else:
            linked_list = self.get_linked_list_for_key(key)
            linked_list.append(key, value)

    def delete_by_key(self, key):
        node_to_delete = self.get_node(key)
        LinkedList = self.get_linked_list_for_key(key)
        LinkedList.delete(node_to_delete)

    def __str__(self):
        """해시 테이블 문자열 메소드"""
        res_str = ""

        for linked_list in self.table:
            res_str += str(linked_list)

        return res_str[:-1]


test_scores = HashTable(50)

test_scores.insert("a", 85)
test_scores.insert("b", 90)
test_scores.insert("c", 87)
test_scores.insert("d", 99)
test_scores.insert("e", 88)
test_scores.insert("f", 97)
test_scores.insert("g", 90)

print(test_scores)

print(test_scores.get_value("a"))
print(test_scores.get_value("b"))
print(test_scores.get_value("c"))

print("삽입")
test_scores.insert("a", 10)
test_scores.insert("b", 20)
test_scores.insert("c", 30)

print(test_scores)

print("삭제")
test_scores.delete_by_key("a")
test_scores.delete_by_key("c")
test_scores.delete_by_key("d")
test_scores.delete_by_key("f")
test_scores.delete_by_key("g")

print(test_scores)
