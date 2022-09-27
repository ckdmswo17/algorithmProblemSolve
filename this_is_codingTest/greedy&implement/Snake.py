# 이코테 문제 : 뱀 
from collections import deque

if __name__ == "__main__":
    N = int(input()) # 보드의 크기 N x N
    K = int(input()) # 사과 개수
    apples = [] # 사과 위치 리스트
    for i in range(K):
        apples.append(list(map(int,input().split(" "))))
    L = int(input()) # 방향 변환 개수
    changeDirection = [] # 방향 변환 정보 리스트
    for i in range(L):
        changeDirection.append(list(input().split(" ")))
    
    maps = [[0]*(N+2) for _ in range(N+2)] # 보드의 테두리를 1로 채움, 만약 이동한 곳이 1이면 게임오버
    for i in range(len(maps)):
        for j in range(len(maps)):
            if i == 0 or j == 0 or i == len(maps)-1 or j == len(maps)-1:
                maps[i][j] = 1
    
    snake = deque()
    snake.appendleft([1,1])
    maps[1][1] = 1
    direction = 1 ## 북쪽 방향은 0, 시계방향으로 동서남은 1씩 커짐
    dy = [-1,0,1,0] 
    dx = [0,1,0,-1]
    time = 0

    while True: # 뱀이 박을때까지 반복 (snake 위치 표현부분이 번잡함, 리터칭 필요)
        print(snake)
        print("Apples : ",apples)
        print("Time : ",time)
        for i in range(len(maps)):
            for j in range(len(maps)):
                print(maps[i][j],end=" ")
            print()
        print()

        time += 1
        if maps[snake[0][0]+dy[direction]][snake[0][1]+dx[direction]] == 1:
            break
        snake.appendleft([snake[0][0]+dy[direction],snake[0][1]+dx[direction]])
        maps[snake[0][0]][snake[0][1]] = 1

        if len(apples) == 0: ## 사과를 모두 소진했을 때 처리 (깔끔히 리터칭 필요)
            maps[snake[len(snake)-1][0]][snake[len(snake)-1][1]] = 0
            snake.pop()
        for i in range(len(apples)):
            if snake[0][0] == apples[i][0] and snake[0][1] == apples[i][1]:
                apples.remove([apples[i][0],apples[i][1]])
                break
            if i == len(apples)-1:
                maps[snake[len(snake)-1][0]][snake[len(snake)-1][1]] = 0
                snake.pop()

        for i in range(L):
            if str(time) == changeDirection[i][0]:
                if changeDirection[i][1] == "L":
                    direction = (direction-1)%4
                    if direction < 0:
                        direction = 3
                else :
                    direction = (direction+1)%4

    print(time)
