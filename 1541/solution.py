def sol():
    expression = [sum(map(int, x.split("+"))) for x in input().split("-")]
    print(expression[0] - sum(expression[1:]))


if __name__ == "__main__":
    sol()
