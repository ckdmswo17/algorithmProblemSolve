# 이코테 문제 : 인구 이동

from collections import deque

N, L, R = map(int,input().split(" "))
A = []
for i in range(N):
    A.append(list(map(int,input().split(" "))))
print(A)

dy = [-1,0,1,0]
dx = [0,1,0,-1]
flag = True
count = 0
while flag:
    visited = [False]*(N**2)
        
def bfs(graph,start,visited):
    queue = deque([start])
    visited[start] = True
    sum = 0
    while queue:
        v = queue.popleft()
        for i in graph[v]:
            
