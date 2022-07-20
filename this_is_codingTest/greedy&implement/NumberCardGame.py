# 이코테 문제 : 숫자 카드 게임
N, M = map(int,input().split(" "))
data = []
for i in range(N):
  data.append(list(map(int,input().split(" "))))
  data[i].sort(reverse=False)

compareNum = []
for i in range(N):
  compareNum.extend([data[i][0]])

print(max(compareNum))