# 이코테 문제 : 효율적인 화폐 구성
N, M = map(int,input().split(" "))
currency = []
for i in range(N):
  currency.extend([int(input())])
currency.sort() # 오름차순으로 정렬

escape_flag = False
answer = -1

# 큰 수(맨처음들어가는 currency[i-j])부터 나눠보면서 결국 나눠떨어지면 그게 무조건 최소값임
# 큰 수를 내려보면서 나눠지는 값을 계속 찾음, 다 반복했는데도 없으면 -1 
for i in range(N-1,-1,-1):
  remainder = M
  count = 0
  for j in range(i):
    moc = remainder // currency[i-j]
    remainder %= currency[i-j]
    if moc != 0 and remainder == 0:
      count += moc
      answer = count
      escape_flag = True
      break
    elif moc != 0 and remainder != 0:
      count += moc
    else :
      pass
  if escape_flag :
    break;
    
print(answer)