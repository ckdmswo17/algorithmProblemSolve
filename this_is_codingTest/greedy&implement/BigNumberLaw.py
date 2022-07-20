# 이코테 문제 : 큰 수의 법칙
if __name__ == "__main__":
  N,M,K = map(int,input().split(" "))
  num = list(map(int,input().split(" ")))

  num.sort(reverse=True)
  sum = 0
  count = 0
  if num[0] == num[1]:
    flag = False
  else :
    flag = True
    
  while not(count >= M):
    for i in range(K):
      if count >= M:
        break
      sum += num[0] 
      count += 1
    if flag and not(count >= M):
      sum += num[1]
      count += 1
    else :
      for i in range(K):
        if count >= M:
          break
        sum += num[0] 
        count += 1
  print(sum)