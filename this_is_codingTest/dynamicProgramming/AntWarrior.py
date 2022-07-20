# 이코테 문제 : 개미전사 -- 다이나믹 프로그래밍으로 리팩토링 필요
import math
from itertools import combinations

N = int(input())
X = list(map(int,input().split(" ")))
x = []

for i in range(N):
  x.append([X[i],i])
print(x)
count = math.ceil(N / 2)
max = 0
for i in range(count,0,-1) :
  a = list(combinations(x,i))
  print(a)
  for z in a:
    flag = True
    for j in range(i-1):
      if not flag : 
        break
      for k in range(1,i-j):  
        if z[j+k][1] - z[j][1] == 1:
          flag = False
        if not flag :
          break
    cur = 0
    if flag : 
      for m in range(len(z)):
        cur += z[m][0]
      if max < cur:
        max = cur
    print("이번 차 max : ",z,max)
print("답 : ",max)