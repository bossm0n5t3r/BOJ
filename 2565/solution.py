import sys


def sol(n, cable):
    seq = [cable[key] for key in sorted(cable.keys())]
    result = [seq[0]]
    index = 0
    for i in range(1, n):
        if result[index] < seq[i]:
            result.append(seq[i])
            index += 1
        else:
            for j in range(index + 1):
                if result[j] >= seq[i]:
                    result[j] = seq[i]
                    break
    ans = n - index - 1
    return ans


if __name__ == "__main__":
    input = sys.stdin.readline
    n = int(input())
    cable = {}
    for i in range(n):
        a, b = map(int, input().split())
        cable[a] = b
    print(sol(n, cable))
