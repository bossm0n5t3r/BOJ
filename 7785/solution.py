import sys


def sol():
    input = sys.stdin.readline
    company = {}
    for i in range(int(input())):
        record = list(map(str, input().split()))
        if record[1] == "enter":
            company[record[0]] = True
        elif record[1] == "leave" and record[0] in company:
            del company[record[0]]
    print("\n".join(sorted(company.keys(), reverse=True)))


if __name__ == "__main__":
    sol()
