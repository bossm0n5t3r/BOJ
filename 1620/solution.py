from sys import stdin


def sol():
    N, M = map(int, stdin.readline().rstrip().split())
    pokemon = {}
    reverse_pokemon = {}
    for i in range(N):
        name = stdin.readline().rstrip()
        pokemon[i + 1] = name
        reverse_pokemon[name] = (i + 1)
    for i in range(M):
        user_input = stdin.readline().rstrip()
        if user_input.isdigit():
            print(pokemon[int(user_input)])
        else:
            print(reverse_pokemon[user_input])


if __name__ == "__main__":
    sol()
