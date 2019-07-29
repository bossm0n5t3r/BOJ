def sol():
    N = int(input())
    file_names = []
    for i in range(N):
        file_names.append(input())
    result = list(file_names[0])
    for i in range(len(result)):
        for names in file_names:
            if result[i] != names[i]:
                result[i] = "?"
                break
    print("".join(result))


if __name__ == "__main__":
    sol()
