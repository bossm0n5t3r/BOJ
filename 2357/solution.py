import sys
import math


def sol():
    input = sys.stdin.readline
    print = sys.stdout.write
    N, M = map(int, input().split())
    data = [0] * N
    for i in range(N):
        data[i] = int(input())
    k = math.ceil(math.log(N, 2))
    tree_size = 2 ** (k + 1)
    max_tree = [0] * tree_size
    min_tree = [0] * tree_size
    max_segment_tree(data, max_tree, 1, 0, N - 1)
    min_segment_tree(data, min_tree, 1, 0, N - 1)
    for i in range(M):
        a, b = map(int, input().split())
        print("%d %d\n" % (find_min(min_tree, 1, 0, N - 1, a - 1, b - 1), find_max(max_tree, 1, 0, N - 1, a - 1, b - 1)))


def max_segment_tree(data, tree, node, start, end):
    if start == end:
        tree[node] = data[start]
        return tree[node]
    mid = (start + end) // 2
    tree[node] = max(max_segment_tree(data, tree, node * 2, start, mid), max_segment_tree(data, tree, node * 2 + 1, mid + 1, end))
    return tree[node]


def min_segment_tree(data, tree, node, start, end):
    if start == end:
        tree[node] = data[start]
        return tree[node]
    mid = (start + end) // 2
    tree[node] = min(min_segment_tree(data, tree, node * 2, start, mid), min_segment_tree(data, tree, node * 2 + 1, mid + 1, end))
    return tree[node]


def find_max(tree, node, start, end, left, right):
    if left > end or right < start:
        return 0
    if left <= start and end <= right:
        return tree[node]
    mid = (start + end) // 2
    return max(find_max(tree, node * 2, start, mid, left, right), find_max(tree, node * 2 + 1, mid + 1, end, left, right))


def find_min(tree, node, start, end, left, right):
    if left > end or right < start:
        return 1000000001
    if left <= start and end <= right:
        return tree[node]
    mid = (start + end) // 2
    return min(find_min(tree, node * 2, start, mid, left, right), find_min(tree, node * 2 + 1, mid + 1, end, left, right))


if __name__ == "__main__":
    sol()
