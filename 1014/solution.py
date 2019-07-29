import sys
sys.setrecursionlimit(100000)


def sol():
    dy = [-1, -1, 0, 0, 1, 1]
    dx = [-1, 1, -1, 1, -1, 1]
    MAX_N = 10
    desk_map = [[''] * MAX_N for _ in range(MAX_N)]
    number = [[0] * MAX_N for _ in range(MAX_N)]
    visit_count = 1

    C = int(input())
    for _ in range(C):
        point= []
        N, M = map(int, input().split())
        for i in range(N):
            tmp = input()
            for j in range(M):
                desk_map[i][j] = tmp[j]
        adj = [[] for i in range(N * M + 1)]
        crash = 0
        cnt = 0
        for i in range(N):
            for j in range(M):
                if desk_map[i][j] == 'x':
                    crash += 1
                if j % 2 == 0:
                    point.append(cnt)
                number[i][j] = cnt
                cnt += 1
        for i in range(N):
            for j in range(0, M, 2):
                if desk_map[i][j] == 'x':
                    continue
                for k in range(6):
                    y = i + dy[k]
                    x = j + dx[k]
                    if x < 0 or y < 0 or x >= M or y >= N or desk_map[y][x] == 'x':
                        continue
                    adj[number[i][j]].append(number[y][x])
        ans = bipartiteMatch(N, M, point, adj, visit_count)
        print(N * M - ans - crash)


def bipartiteMatch(N, M, point, adj, visit_count):
    size = 0
    visit = [0] * (N * M + 1)
    aMatch = [-1] * (N * M + 1)
    bMatch = [-1] * (N * M + 1)
    for a in point:
        visit_count += 1
        size += dfs(a, visit, visit_count, aMatch, bMatch, adj)
    return size


def dfs(a, visit, visit_count, aMatch, bMatch, adj):
    if visit[a] == visit_count:
        return False
    visit[a] = visit_count
    for b in adj[a]:
        if bMatch[b] == -1 or dfs(bMatch[b], visit, visit_count, aMatch, bMatch, adj):
            aMatch[a] = b
            bMatch[b] = a
            return True
    return False


if __name__ == "__main__":
    sol()
