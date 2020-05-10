import sys


input = sys.stdin.readline
print = sys.stdout.writelines


def sol():
    while True:
        input_str = input().rstrip()
        if input_str == ".":
            break
        print("yes\n" if is_valid(input_str) else "no\n")


def is_valid(S):
    stack = []
    for c in S:
        if c in "([":
            stack.append(c)
        elif c in ")]":
            if not stack:
                return False
            if c == ")" and stack.pop() != "(":
                return False
            if c == "]" and stack.pop() != "[":
                return False
    return not stack


if __name__ == "__main__":
    sol()
