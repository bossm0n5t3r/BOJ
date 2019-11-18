import sys


def sol():
    input = sys.stdin.readline
    N = int(input())
    students = []
    for i in range(N):
        name, kor, eng, math = map(str, input().split(" "))
        students.append([name, int(kor), int(eng), int(math)])
    students = sorted(students, key=lambda x: (-x[1], x[2], -x[3], x[0]))
    students = [x[0] for x in students]
    print("\n".join(students))


if __name__ == "__main__":
    sol()
