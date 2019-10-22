import sys


def sol(N, seq, M, queries):
    mod = 10 ** 9 + 7
    ans = ""
    for query in queries:
        case = query[0]
        if case == 1:
            for i in range(query[1] - 1, query[2]):
                seq[i] = (seq[i] + query[3]) % mod
        elif case == 2:
            for i in range(query[1] - 1, query[2]):
                seq[i] = (seq[i] * query[3]) % mod
        elif case == 3:
            for i in range(query[1] - 1, query[2]):
                seq[i] = query[3]
        else:
            result = 0
            for i in range(query[1] - 1, query[2]):
                result += seq[i]
            ans += str(result % mod) + "\n"
    return ans


if __name__ == "__main__":
    input = sys.stdin.readline
    print = sys.stdout.write
    N = int(input())
    seq = list(map(int, input().split()))
    M = int(input())
    queries = [list(map(int, input().split())) for _ in range(M)]
    print(sol(N, seq, M, queries))
