def sol(N):
    save = [[0 for j in range(10)] for i in range(101)]
    mod = 1000000000
    result = 0
    for i in range(1, 10):
        result += stair_number(N, i, save, mod)
    return result % mod


def stair_number(pos, last_number, save, mod):
    if save[pos][last_number] != 0:
        return save[pos][last_number]
    if pos <= 1:
        return 1
    if last_number == 0:
        save[pos][last_number] = stair_number(pos - 1, 1, save, mod) % mod
        return save[pos][last_number]
    elif last_number == 9:
        save[pos][last_number] = stair_number(pos - 1, 8, save, mod) % mod
        return save[pos][last_number]
    else:
        save[pos][last_number] = stair_number(pos - 1, last_number - 1, save, mod) % mod + stair_number(pos - 1, last_number + 1, save, mod) % mod
        return save[pos][last_number]


if __name__ == "__main__":
    N = int(input())
    print(sol(N))
