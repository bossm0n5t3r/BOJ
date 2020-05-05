def sol():
    string = input()
    answer = ""
    for c in string:
        # 대문자
        if "A" <= c <= "Z":
            answer += chr((ord(c) - ord("A") + 13) % 26 + ord("A"))
        # 소문자
        elif "a" <= c <= "z":
            answer += chr((ord(c) - ord("a") + 13) % 26 + ord("a"))
        else:
            answer += c
    print(answer)


if __name__ == "__main__":
    sol()
