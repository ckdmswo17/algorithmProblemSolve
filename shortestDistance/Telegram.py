# 이코테 문제 : 전보
import heapq

def dijkstraWithHeapq(start):
	q = []
	heapq.heappush(q,(0,start))
	distance[start] = 0
	print("----------Process----------")
	while(q):
		print("heapq : ",q)
		dist, node = heapq.heappop(q)
		if distance[node] < dist:
			continue
		for i in graph[node]:
			cost = dist + i[1]
			if distance[i[0]] > cost:
				distance[i[0]] = cost
				heapq.heappush(q,(cost,i[0]))
		print("distance : ",distance)
		
		
INF = int(1e9)
N, M, C = map(int,input().split(" "))

graph = [[] for i in range(N+1)]
distance = [INF] * (N+1)

for i in range(M):
	X,Y,Z = map(int,input().split(" "))
	graph[X].append((Y,Z))

print()
dijkstraWithHeapq(C)
print()

print("----------Result----------")
print("graph : ",graph)
print("distance : ",distance)

totalAmount = 0
totalTime = 0
for i in range(1,N+1):
	if i != C and distance[i] != INF:
		totalAmount += 1
		totalTime = max(totalTime,distance[i])
print("TotalAmount : ",totalAmount,", TotalTime : ",totalTime)