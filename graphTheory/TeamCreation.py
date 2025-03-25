# 이코테 문제 : 팀 결성 (서로소집합)

class Myerror(Exception): # 실험차 잘못된 연산 번호 입력에 대한 예외 클래스를 추가해봤습니다
  def __str__(self):
    return "없는 연산 번호입니다."

def findParent(parent,x):
  if parent[x] != x:
    parent[x] = findParent(parent,parent[x])
  return parent[x]

def unionParent(parent,a,b):
  a = findParent(parent,a)
  b = findParent(parent,b)
  if a < b :
    parent[b] = a
  else : 
    parent[a] = b

N,M = map(int,input().split(" "))
parent = [0] * (N+1)
for i in range(0,N+1):
  parent[i] = i
result = []

for i in range(M):
  try :
    cal,a,b = map(int,input().split(" "))
    if cal == 0:
      unionParent(parent,a,b)
    elif cal == 1:
      if findParent(parent,a) == findParent(parent,b):
        result.append([i+1,"YES"])
      else :
        result.append([i+1,"NO"])
    else :
      raise Myerror()
  except Myerror as e :
    print(e)

for i in range(len(result)):
  print(result[i][1])