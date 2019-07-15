'''
A good contest

https://www.acmicpc.net/problem/14610
'''


def sol():
    # 참가자의 수 N, 문제의 수 M
    N, M = map(int, input().split())
    # 참가자의 문제에 대한 결과
    contest_result = []
    # 참가자의 맞춘 문제 수
    k_list = []
    # 데이터 입력
    for i in range(N):
        tmp = list(map(int, input().split()))
        k_list.append(tmp[0])
        contest_result.append(tmp[1:])
    
    # 모든 참가자가 한 문제 이상을 풀어야 한다.
    if k_list[N - 1] == 0:
        print("NO")
    # 모든 문제를 푼 참가자는 없어야 한다.
    elif k_list[0] == M:
        print("NO")
    # 모든 문제는 한 명 이상의 참가자에게 풀려야 한다.
    else:
        # 각 문제에 대해서 맞춘 사람이 있다면,
        # 해당 문제 결과를 볼 수 없는 사람들이 못 풀었다고 가정
        for i in range(N - 1, -1, -1):
            for j in range(M - 1, -1, -1):
                if contest_result[i][j] == 1:
                    for k in range(i):
                        if contest_result[k][j] == -1:
                            contest_result[k][j] = 0
        # 참가자의 맞춘 문제 수에서 실제 맞춘 결과를 제거
        for i in range(N):
            k_list[i] -= contest_result[i].count(1)
        # 남은 맞춘 문제 수에서 모르는 결과에 대해 하나씩 치환
        # 치환 후 해당 문제에 대해 등수가 높은 사람들은 그 문제를 못 풀었다고 가정
        for i in range(N - 1, -1, -1):
            while k_list[i] > 0:
                for j in range(M):
                    if contest_result[i][j] == -1:
                        contest_result[i][j] = 1
                        for k in range(i):
                            if contest_result[k][j] == -1:
                                contest_result[k][j] = 0
                        break
                k_list[i] -= 1
            for j in range(M):
                if contest_result[i][j] == -1:
                    contest_result[i][j] = 0
        # 모든 문제에 대해서 한 명 이상의 참가자가 풀었는지 확인
        check_list = [False] * M
        for j in range(M):
            for i in range(N):
                if contest_result[i][j] == 1:
                    check_list[j] = True
                    break
        if sum(check_list) == M:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    sol()
