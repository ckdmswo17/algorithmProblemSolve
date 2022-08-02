# 이코테 문제 : 도시 분할 계획(최소신장트리 : 크루스칼 알고리즘)

def findParent(parent, x):
    if parent[x] != x:
        parent[x] = findParent(parent, parent[x])
    return parent[x]

def unionParent(parent, a, b):
    a = findParent(parent, a)
    b = findParent(parent, b)
    if a == b:
        return False
    else:
        if a < b:
            parent[b] = a
        else:
            parent[a] = b
        return True

N, M = map(int, input().split(" "))
parent = [0] * (N + 1)
edge = [[] for i in range(M)]
for i in range(1, N + 1):
    parent[i] = i

sum = 0
for i in range(M):
    A, B, C = map(int, input().split(" "))
    edge[i].append((A, B))
    edge[i].append(C)

edge.sort(key=lambda x: x[1])

max = 0
for i in range(M): # 이 반복이 모두 끝나면 최소 신장 트리는 만들어짐
    flag = False
    flag = unionParent(parent, edge[i][0][0], edge[i][0][1])
    if flag:
        sum += edge[i][1] 
        if max < edge[i][1]:
          max = edge[i][1]         
      
sum -= max # 최소신장트리에서 가장 큰 비용의 간선을 없애면 마을(트리)을 2개로 만들면서 최소 비용값을 구해낼 수 있음
print(sum)
