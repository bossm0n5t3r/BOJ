def sol():
    N, M = map(int, input().split())
    board = []
    for i in range(N):
        board.append(input().replace('W', '1').replace('B', '0'))
    all_chessboards = [
        [170, 85, 170, 85, 170, 85, 170, 85],
        [85, 170, 85, 170, 85, 170, 85, 170]
    ]
    count_repaint = 64
    for i in range(N - 7):
        for j in range(M - 7):
            tmp_board = [string[j : j + 8] for string in board[i : i + 8]]
            for chessboard in all_chessboards:
                count = 0
                for k in range(8):
                    count += bin(int('0b' + tmp_board[k], 2) ^ chessboard[k]).count('1')
                if count < count_repaint:
                    count_repaint = count
                if count == 0:
                    print(0)
                    exit()
    print(count_repaint)


if __name__ == "__main__":
    sol()
