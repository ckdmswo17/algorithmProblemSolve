# 이코테 문제 : 부품찾기
def binary_search(array,target):
  start = 0
  end = len(array)-1

  while start <= end:
    middle = (start+end)//2
    if array[middle] > target:
      end = middle-1
    elif array[middle] < target:
      start = middle+1
    elif array[middle] == target:
      return middle

  return None

if __name__ == "__main__":
  N = int(input())
  shopGoods = list(map(int,input().split(" ")))
  M = int(input())
  requestGoods = list(map(int,input().split(" ")))
  shopGoods.sort()

  for i in range(M):
    if binary_search(shopGoods,requestGoods[i])==None:
      print("no",end=" ")
    else :
      print("yes",end=" ")
  print()