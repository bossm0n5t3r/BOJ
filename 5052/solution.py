import sys


def sol():
    input = sys.stdin.readline
    t = int(input())
    while t:
        t -= 1
        contact = []
        n = int(input())
        for i in range(n):
            contact.append(input()[:-1])
        print(checkConsistency(contact))
        # check = False
        # trie = Trie()
        # n = int(input())
        # for i in range(n):
        #     phone_num = input()[:-1]
        #     if check:
        #         continue
        #     if not check and trie.search(phone_num):
        #         check = True
        #     trie.insert(phone_num)
        # if check:
        #     print("NO")
        #     continue
        # print("YES")


def checkConsistency(contact):
    contact = sorted(contact)
    check = contact[0]
    for phone_num in contact[1:]:
        if check in phone_num:
            return "NO"
        check = phone_num
    return "YES"


class TrieNode:
    def __init__(self):
        self.children = [None] * 10
        self.isEndOfNum = False


class Trie:
    def __init__(self):
        self.root = self.getNode()

    def getNode(self):
        return TrieNode()

    def insert(self, key):
        root = self.root
        length = len(key)
        for i in range(length):
            index = int(key[i])
            if not root.children[index]:
                root.children[index] = self.getNode()
            root = root.children[index]
        root.isEndOfNum = True

    def search(self, key):
        root = self.root
        length = len(key)
        for i in range(length):
            index = int(key[i])
            if root.isEndOfNum:
                return True
            if not root.children[index]:
                return False
            root = root.children[index]
        return not root.isEndOfNum


if __name__ == "__main__":
    sol()
