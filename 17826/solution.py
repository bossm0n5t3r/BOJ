def sol():
    scores = list(map(int, input().split()))
    my_score = int(input())
    my_rank = scores.index(my_score)
    if my_rank < 5:
        print("A+")
    elif my_rank < 15:
        print("A0")
    elif my_rank < 30:
        print("B+")
    elif my_rank < 35:
        print("B0")
    elif my_rank < 45:
        print("C+")
    elif my_rank < 48:
        print("C0")
    elif my_rank < 50:
        print("F")


if __name__ == "__main__":
    sol()
