# 이코테 문제 : 카드 정렬하기

import sys, heapq

input = sys.stdin.readline # 반복문(엔터키)으로 입력받는 경우 input()을 시간초과를 유도할수 있다.
N = int(input())
card = []
for i in range(N):
    heapq.heappush(card,int(input()))

# print(card)
sum = 0

while len(card) > 1:
    # print(card)
    cur = heapq.heappop(card) + heapq.heappop(card)
    sum += cur
    heapq.heappush(card,cur)

print(sum)