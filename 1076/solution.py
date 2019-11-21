def sol():
    table = [
        "black",
        "brown",
        "red",
        "orange",
        "yellow",
        "green",
        "blue",
        "violet",
        "grey",
        "white",
    ]
    answer = ""
    answer += str(table.index(input()))
    answer += str(table.index(input()))
    answer = int(answer)
    answer *= 10 ** table.index(input())
    print(answer)


if __name__ == "__main__":
    sol()
