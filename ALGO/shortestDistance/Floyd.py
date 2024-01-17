# 이코테 문제 : 플로이드

import sys

input = sys.stdin.readline
INF = int(1e9)
n = int(input())
m = int(input())
adj = [[INF] * (n+1) for _ in range(n+1)]
for i in range(m):
    n1,n2,n3 = map(int,input().split(" "))
    adj[n1][n2] = min(n3,adj[n1][n2])

for i in range(1,n+1):
    for j in range(1,n+1):
        if i==j:
            adj[i][j] = 0 

for k in range(1,n+1):
    for a in range(1,n+1):
        for b in range(1,n+1):
            adj[a][b] = min(adj[a][b],adj[a][k]+adj[k][b])

for i in range(1,n+1):
    for j in range(1,n+1):
        if adj[i][j] == INF:
            print(0,end=" ")
        else :
            print(adj[i][j],end=" ")
    print()