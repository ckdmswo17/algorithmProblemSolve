# 이코테 문제 : 정수 삼각형 (재귀 = 시간초과. 메모이제이션 방법 안떠오름, 순열로 모든 경로 생성 = 메모리 초과, 결론은 반복문.보텀업으로 성공)

import sys

def max(a,b) :
    # print(n,x,y)
    # if x == N-2:
    #     if triangle[x+1][y] > triangle[x+1][y+1]:
    #         return triangle[x][y]+triangle[x+1][y]
    #     else :
    #         return triangle[x][y]+triangle[x+1][y+1]
    # else : 
    #     n1 = max(triangle,x+1,y)
    #     n2 = max(triangle,x+1,y+1)
    #     if n1 > n2:
    #         return triangle[x][y] + n1
    #     else :
    #         return triangle[x][y] + n2
    if a > b :
        return a
    else :
        return b

input = sys.stdin.readline
N = int(input())
triangle = []
for i in range(N):
    triangle.append(list(map(int,input().split(" "))))

# print(max(triangle,0,0))

for i in range(N-2,-1,-1):
    for j in range(len(triangle[i])):
        triangle[i][j] += max(triangle[i+1][j],triangle[i+1][j+1])
print(triangle[0][0])