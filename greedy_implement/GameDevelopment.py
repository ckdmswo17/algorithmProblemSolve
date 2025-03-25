# 이코테 문제 : 게임 개발 -- 지도 출력, 예외 처리 추가
N, M = map(int,input().split(" "))
x, y, direction = map(int,input().split(" "))
maps = []

for i in range(N):
  maps.append(list(map(int,input().split(" "))))

dx = [0,1,0,-1]
dy = [-1,0,1,0] # 북, 동, 남, 서 순서

endFlag = False
count = 1 # 시작지점부터 count 포함
while(not endFlag):

  print("-----------------------") # 현재 이동한 지도 표시
  for i in range(N):
      for j in range(M):
        if i == y and j == x:
          print("*",end=" ")
        else:
          print(maps[i][j],end=" ")
      print()
  
  if direction==0: # 반시계 90도로 한번 회전
    direction = 3
  else :
    direction -= 1

  for i in range(4): # 이동할 경로를 찾을 때까지 4번 회전  
    if 0<=(y+dy[direction])<N and 0<=(x+dx[direction])<M and maps[y+dy[direction]][x+dx[direction]] == 0: # 이동할 수 있는 경우, list out of index 예외처리도 완료
      maps[y][x] = 2 # 다녀온 위치라는 걸 표시
      y += dy[direction]
      x += dx[direction]
      count += 1        
      break 
    elif i == 3: # 네 방향 모두 갈 곳을 못 찾았을 때
      if 0<=(y+dy[(direction+2)%4])<N and 0<=(x+dx[(direction+2)%4])<M and maps[y+dy[(direction+2)%4]][x+dx[(direction+2)%4]] == 2: # 내 방향의 반대방향이 갔다온 곳일 경우
        maps[y][x] = 2
        y += dy[(direction+2)%4]
        x += dx[(direction+2)%4]
      elif 0<=(y+dy[(direction+2)%4])<N or 0<=(x+dx[(direction+2)%4])<M or maps[y+dy[(direction+2)%4]][x+dx[(direction+2)%4]] == 1: # 내 방향의 반대방향이 바다일 경우
        endFlag = True
      else : # 이상한 숫자일 경우
        print("Error")    
        
    else : # 이동할 경로 못찾았을 때의 회전
      if direction==0:
        direction = 3
      else :
        direction -= 1

print("막혀버려따..")
print("\nAnswer : ",count)