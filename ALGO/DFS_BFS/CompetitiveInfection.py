# 이코테 문제 : 경쟁적 전염 (시간초과)

from copy import deepcopy

def bfs(flask,copy_flask, y, x,num):
    if not 0<=y<len(copy_flask) or not 0<=x<len(copy_flask):
        return

    if copy_flask[y][x] != 0 and copy_flask[y][x] > num:
        if flask[y][x] == 0:
            copy_flask[y][x] = num
    elif copy_flask[y][x] == 0:
        copy_flask[y][x] = num
    return
    
if __name__=="__main__":
    dy = [-1,0,1,0]
    dx = [0,1,0,-1]

    N, K = map(int,input().split(" ")) # 시험관의 가로세로 크기, 바이러스의 종류 개수
    flask = []
    for i in range(N):
        flask.append(list(map(int,input().split(" "))))
    copy_flask = deepcopy(flask)
    # print(flask)
    S, X, Y = map(int,input().split(" ")) # S초 후 X,Y 좌표에 있는 바이러스의 종류

    for i in range(S):
        for j in range(N):
            for z in range(N):
                if flask[j][z] != 0:
                    bfs(flask,copy_flask,j+dy[0],z+dx[0],flask[j][z])
                    bfs(flask,copy_flask,j+dy[1],z+dx[1],flask[j][z])
                    bfs(flask,copy_flask,j+dy[2],z+dx[2],flask[j][z])
                    bfs(flask,copy_flask,j+dy[3],z+dx[3],flask[j][z])
        flask = deepcopy(copy_flask)
        # print(flask)
    
    print(flask[X-1][Y-1])