# 이코테 문제 : 떡 자르기
if __name__ == "__main__":
  N, M = map(int,input().split())
  origin_ddeok = []
  origin_ddeok.extend(list(map(int,input().split(" "))))
  origin_ddeok.sort()

  # num 배열은 새로 만들지 않고 high, row 숫자만 이용해서 이진탐색 수행
  row = 0
  high = origin_ddeok[N-1]
  middle = (high+row)//2
  
  big = {}
  answer = 0

  repeat_flag = True
  while repeat_flag:
    if high <= row :
      repeat_flag = False
    middle_sum = 0
    for i in range(N):
      if origin_ddeok[i]-middle>0:
        middle_sum += origin_ddeok[i]-middle
    print(row,high,middle,middle_sum)
    if middle_sum > M: 
      big={middle_sum:middle}
      row = middle+1
      middle = (high+row)//2
    elif middle_sum < M:
      high = middle-1
      middle = (high+row)//2
    else :
      answer = middle
      break

  print(big)
  if not(answer == 0) :
    print("최대길이 :",answer)
  else :
    big = sorted(big.items())
    answer = big[0][1]
    print("최대길이 :",answer)