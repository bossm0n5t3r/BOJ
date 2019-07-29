import sys
import math


def sol():
    input = sys.stdin.readline
    print = sys.stdout.write
    N, M, K = map(int, input().split())
    data = [0] * N
    for i in range(N):
        data[i] = int(input())
    k = math.ceil(math.log(N, 2))
    tree_size = 2 ** (k + 1)
    tree = [0] * tree_size
    init(data, tree, 1, 0, N - 1)
    M += K
    while M > 0:
        M -= 1
        a, b, c = map(int, input().split())
        if a == 1:
            b -= 1
            diff = c - data[b]
            data[b] = c
            update(tree, 1, 0, N - 1, b, diff)
        else:
            print("%d\n" % (calculate_interval(tree, 1, 0, N - 1, b - 1, c - 1)))


def init(data, tree, node, start, end):
    if start == end:
        tree[node] = data[start]
        return tree[node]
    mid = (start + end) // 2
    tree[node] = init(data, tree, node * 2, start, mid) + init(data, tree, node * 2 + 1, mid + 1, end)
    return tree[node]


def calculate_interval(tree, node, start, end, left, right):
    if left > end or right < start:
        return 0
    if left <= start and end <= right:
        return tree[node]
    mid = (start + end) // 2
    return calculate_interval(tree, node * 2, start, mid, left, right) + calculate_interval(tree, node * 2 + 1, mid + 1, end, left, right)


def update(tree, node, start, end, index, diff):
    if index < start or index > end:
        return
    tree[node] = tree[node] + diff
    mid = (start + end) // 2
    if start != end:
        update(tree, node * 2, start, mid, index, diff)
        update(tree, node * 2 + 1, mid + 1, end, index, diff)


if __name__ == "__main__":
    sol()
