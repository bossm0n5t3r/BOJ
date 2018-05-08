'''
2007

https://www.acmicpc.net/problem/1924
'''

month, day = map(int, input().split())
NamesOfTheDays = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
DaysInEachMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
if month == 1 and day == 1:
    print(NamesOfTheDays[1])
else:
    count = 0
    for i in range(1, month):
        count += DaysInEachMonth[i-1]
    count += day
    print(NamesOfTheDays[count % 7])
