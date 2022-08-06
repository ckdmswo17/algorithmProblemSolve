# 이코테 문제 : 커리큘럼 (위상 정렬 안 쓴 버전, 시간제한은 초과 x)

from collections import deque

N = int(input())
graph = [[] for i in range(N+1)]
time =  [0] * (N+1)
for i in range(1,N+1):
  node = list(map(int,input().split(" ")))
  time[i] = node[0]
  for j in range(1,len(node)-1):
    graph[i].append(node[j]) # 평소 graph와는 다르게 연결당한 정보를 담는 리스트 

print("\n","Graph : ",graph,"\n")

for i in range(1,N+1):
  max = time[i]
  for j in graph[i]:
    if max < time[j]:
      max = time[j]
  if len(graph[i]) == 0:
    pass
  else :
    time[i] += max 
    
for i in range(1,N+1):
  print(time[i])