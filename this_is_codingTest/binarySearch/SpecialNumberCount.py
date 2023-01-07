# 이코테 문제 : 정렬된 배열에서 특정 수의 개수 (직접 구현한 버전)
def bsect_left(lst,value):
  for i in range(len(lst)):
    if lst[i] == value:
      return i;
  return 0;

def bsect_right(lst,value):
  for i in range(len(lst)-1,0,-1):
    if lst[i] == value:
      return i+1
  return 0;

if __name__ == "__main__":
  n, x = map(int,input().split(" "))

  a = list(map(int,input().split(" ")))
  
  left = bsect_left(a,x)
  right = bsect_right(a,x)
  answer = right-left
  if answer == 0:
    print(-1)
  else :
    print(answer)