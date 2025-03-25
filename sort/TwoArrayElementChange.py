# 이코테 문제 : 두 배열의 원소 교체
if __name__ == "__main__":
  N, K = map(int,input().split(" "))
  A = list(map(int,input().split(" ")))
  B = list(map(int,input().split(" ")))

  A.sort(reverse=False)
  B.sort(reverse=True)

  for i in range(K):
    if A[i] < B[i] :
      A[i],B[i] = B[i],A[i]
    else :
      break

  sum = 0
  for i in range(N):
    sum += A[i]
  print(sum)