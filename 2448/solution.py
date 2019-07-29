import sys


def sol():
    N = int(sys.stdin.readline())
    space = []
    for j in range(N):
        temp = []
        for i in range(2*N):
            temp.append(" ")
        space.append(temp)
    printStars(space, 0, 0, N)
    for j in range(N):
        sys.stdout.write(''.join(space[j]))
        sys.stdout.write("\n")


def printStars(space, x, y, N):
    if N == 3:
        space[y][x+2] = "*"
        space[y+1][x+1] = "*"
        space[y+1][x+3] = "*"
        space[y+2][x] = "*"
        space[y+2][x+1] = "*"
        space[y+2][x+2] = "*"
        space[y+2][x+3] = "*"
        space[y+2][x+4] = "*"
        return
    div = N // 2
    printStars(space, x + div, y, div)
    printStars(space, x, y + div, div)
    printStars(space, x + N, y + div, div)


if __name__ == "__main__":
    sol()
