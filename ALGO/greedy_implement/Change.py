# 이코테 문제 : 거스름돈
if __name__ == "__main__":
  N = int(input())
  money = [500,100,50,10]
  sum = 0
  
  for i in money:
    sum += N//i
    N %= i

  print(sum)