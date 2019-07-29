import queue


def sol():
    N, K = map(int, input().split())
    result = -1
    result = bfs(N, K, result)
    print(result)


def bfs(N, K, result):
    q = queue.Queue()
    q.put([str(N), K])
    length = len(str(N))
    check = [set() for i in range(K + 1)]
    while not q.empty():
        now = q.get()
        now_N = now[0]
        now_K = now[1]

        for i in range(length - 1):
            for j in range(i + 1, length):
                split = list(now_N)
                split[i], split[j] = split[j], split[i]
                tmp = ''.join(split)

                if tmp[0] == '0':
                    continue
                if tmp in check[now_K - 1]:
                    continue
                
                check[now_K - 1].add(tmp)

                if now_K > 0:
                    q.put([tmp, now_K - 1])
    if len(check[0]) == 0:
        return -1
    else:
        return max(check[0])


"""
# The following codes are worked, but TOO LATE

def bfs(N, K, result):
    q = queue.Queue()
    q.put(N)
    length = len(str(N))
    state = 0
    while not q.empty() and state < K:
        state += 1
        visited = [False] * (10 ** length + 1)
        size = q.qsize()
        while size > 0:
            size -= 1
            current = q.get()
            for i in range(length):
                for j in range(i + 1, length):
                    next_ = exchange(current, i, j)
                    if next_ < 10 ** (length - 1):
                        continue
                    if not visited[next_]:
                        if state == K:
                            result = max(result, next_)
                        visited[next_] = True
                        q.put(next_)
    return result


def exchange(n, from_, to_):
    split = list(str(n))
    split[from_], split[to_] = split[to_], split[from_]
    return int(''.join(split))
"""


if __name__ == "__main__":
    sol()
