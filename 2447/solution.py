import sys


def sol():
    input = sys.stdin.readline
    print = sys.stdout.write
    N = int(input())
    print("\n".join(printing_stars(N)))


def printing_stars(N):
    if N == 1:
        return ["*"]
    result = []
    block = printing_stars(N // 3)
    for line in block:
        result.append(line * 3)
    for line in block:
        result.append(line + " " * (N // 3) + line)
    for line in block:
        result.append(line * 3)
    return result


if __name__ == "__main__":
    sol()
