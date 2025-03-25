# 이코테 문제 : 특정 거리의 도시 찾기

from collections import deque

def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    shortestDistance = [300001 for i in range(len(graph))]
    shortestDistance[start] = 0
    while queue:
        v = queue.popleft()
        for i in graph[v]:            
            if not visited[i]:
                if shortestDistance[v]+1 < shortestDistance[i]:
                    shortestDistance[i] = shortestDistance[v]+1
                queue.append(i)
                visited[i] = True
    return shortestDistance

if __name__ == "__main__":
    N, M, K, X = map(int,input().split(" ")) # 도시의 개수, 도로의 개수, 거리 정보, 출발 도시 번호
    graph = [[] for i in range(N+1)]
    for i in range(M):
        start, end = map(int,input().split(" "))
        graph[start].append(end)
    for i in range(N+1):
        graph[i].sort()
    # print(graph)
    visited = [False] * (N+1)

    shortestDistance = bfs(graph,X,visited)
    # print(shortestDistance)
    flag = False
    for i in range(N+1):
        if shortestDistance[i] == K:
            print(i)
            flag = True
    if not flag :
        print(-1)