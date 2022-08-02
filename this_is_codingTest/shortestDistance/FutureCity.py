# 이코테 문제 : 미래 도시
if __name__ == "__main__":
    INF = int(1e9)
    N, M = map(int, input().split(" "))
    graph = [[INF] * (N + 1) for i in range(N + 1)]

    for i in range(1, N + 1):
        graph[i][i] = 0
    for i in range(M):
        a, b = map(int, input().split(" "))
        graph[a][b] = 1
        graph[b][a] = 1

    X, K = map(int, input().split(" "))
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            for z in range(1, N + 1):
                graph[j][z] = min(graph[j][z], graph[j][i] + graph[i][z])

    answer = graph[1][K] + graph[K][X]
    if answer >= INF:
        print(-1)
    else:
        print(answer)