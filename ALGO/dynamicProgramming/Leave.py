# 이코테 문제 : 퇴사

import sys

def Max(work,x):
    max = 0
    for i in range(x,N):
        sum = 0
        if i+work[i][0] <= len(work):
            sum = work[i][1] + Max(work,i+work[i][0])
            # print(x,i,sum)
        if max < sum:
            max = sum
    # print(max)
    return max
        
input = sys.stdin.readline
N = int(input())
work  = []
for i in range(N):
    work.append(list(map(int,input().split(" "))))

print(Max(work,0))