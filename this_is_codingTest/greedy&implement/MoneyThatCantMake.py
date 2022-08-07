# 이코테 문제 : 만들 수 없는 금액

N = int(input())
money = list(map(int,input().split(" ")))

money.sort(reverse=True)
flag = False
for i in range(1,sum(money)+1):
  cur = i
  for j in range(N):
    if money[j] > i:
      continue
    tmp = cur-money[j]
    # print(cur,money[j],tmp)
    if tmp < 0:
      pass # i값 변화시키지않고 현재 j값 뒤부터 다시 뺄셈해봄
    elif tmp > 0:
      cur -= money[j]
    else : # 만들 수 있을 때, 탈출
      break
    if j == N-1: # 최솟값을 찾았을 때
      flag = True
  if flag:
    print(i)
    break 