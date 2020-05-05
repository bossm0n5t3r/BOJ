import sys


def sol():
    for string in sys.stdin:
        answer = [0, 0, 0, 0]
        for c in string:
            if "a" <= c <= "z":
                answer[0] += 1
            elif "A" <= c <= "Z":
                answer[1] += 1
            elif "0" <= c <= "9":
                answer[2] += 1
            elif c == " ":
                answer[3] += 1
        print(*answer)


if __name__ == "__main__":
    sol()
