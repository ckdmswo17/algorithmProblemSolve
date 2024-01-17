# 이코테 문제 : 커리큘럼 (위상 정렬 쓴 버전)

from collections import deque
import copy

def topology_sort():
    q = deque()
    result = copy.deepcopy(time)

    for i in range(1, N + 1):
        if indegree[i] == 0:
            q.append(i)

    while q:
        now = q.popleft()
        for i in graph[now]:
            indegree[i] -= 1
            result[i] = max(time[i] + result[now], result[i])
            if indegree[i] == 0:
                q.append(i)
    return result

N = int(input())
graph = [[] for i in range(N + 1)]
indegree = [0] * (N + 1)
time = [0] * (N + 1)
for i in range(1, N + 1):
    node = list(map(int, input().split(" ")))
    time[i] = node[0]
    for j in range(1, len(node) - 1):
        indegree[i] += 1
        graph[node[j]].append(i)

print("\n", "Graph : ", graph, "\n")

result = topology_sort()
for i in range(1, N + 1):
    print(result[i])
