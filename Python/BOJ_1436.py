'''
Movie director

https://www.acmicpc.net/problem/1436
'''


def sol():
    res = set(map(int, make666(set(['666']))))
    res = sorted(list(res))
    print(int(res[int(input())-1]))


def make666(L):
    if len(L)>=10000:
        return L
    tmp = set()
    for num in L:
        for i in range(10):
            tmp.add(num+str(i))
            tmp.add(str(i)+num)
    L = L | tmp
    return make666(L)


if __name__ == "__main__":
    sol()
