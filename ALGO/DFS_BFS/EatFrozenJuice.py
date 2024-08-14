# 이코테 문제 : 음료 얼려 먹기
def dfs(ququ,y,x):
  if not(0<=y<N) or not(0<=x<M):
    return False
  
  if ququ[y][x] == 0 :
    ququ[y][x] = 1
    dfs(ququ,y-1,x)
    dfs(ququ,y,x+1)
    dfs(ququ,y+1,x)
    dfs(ququ,y,x-1)
    return True
  return False

N, M = map(int,input().split(" "))

queue = []
for i in range(N):
  a = list(map(int,input()))
  queue.append(a)

print(queue)

count = 0
for i in range(N):
  for j in range(M):
    v = dfs(queue,i,j)
    if v:
      count += 1

print(count)