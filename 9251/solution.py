def sol(str1, str2):
    c = [[0 for j in range(len(str2) + 1)] for i in range(len(str1) + 1)]
    for i in range(1, len(str1) + 1):
        for j in range(1, len(str2) + 1):
            if str1[i - 1] == str2[j - 1]:
                c[i][j] = c[i - 1][j - 1] + 1
            else:
                c[i][j] = max(c[i][j - 1], c[i - 1][j])
    return c[len(str1)][len(str2)]


if __name__ == "__main__":
    str1 = input()
    str2 = input()
    print(sol(str1, str2))
