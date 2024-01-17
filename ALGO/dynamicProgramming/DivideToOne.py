# 이코테 문제 : 1로 나누기
import sys
sys.setrecursionlimit(10**4)

def getMincount(n):
  if n==1:
    return 0
  print(n)

  a = []
  if n%5==0:
    a.append(getMincount(n/5))
  if n%3==0:
    a.append(getMincount(n/3))
  if n%2==0:
    a.append(getMincount(n/2))
  a.append(getMincount(n-1))
  return 1+int(min(a))

x = int(input())
print("답 :",getMincount(x))