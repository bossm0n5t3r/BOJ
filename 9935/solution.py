def sol():
    origin_str = input()
    boom_str = list(input())
    boom_str_length = len(boom_str)
    stack = []
    for c in origin_str:
        stack.append(c)
        while boom_str == stack[-boom_str_length:]:
            for i in range(boom_str_length):
                stack.pop()
    print("".join(stack) or "FRULA")


if __name__ == "__main__":
    sol()
