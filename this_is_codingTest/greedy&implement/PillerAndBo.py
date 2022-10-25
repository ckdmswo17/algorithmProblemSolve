# 이코테 문제 : 기둥과 보 설치(틀림)
def solution(n, build_frame):
    print(build_frame)
    map = [[0] * (n+1) for _ in range(n+1)] # 0은 공백, 1은 기둥, 2는 보, 3은 둘 다 있을 때
    for i in range(len(build_frame)):
        print(build_frame[i])
        for x in range(len(map)):
            for y in range(len(map)):
                print(map[x][y],end=" ")
            print()
        print()

        if build_frame[i][3] == 1: # 설치
            if build_frame[i][2] == 0: # 기둥은
                if build_frame[i][1] == 0: # 바닥 위에 있거나
                    map[build_frame[i][0]][build_frame[i][1]] = 1
                elif bool(map[build_frame[i][0]-1][build_frame[i][1]] == 2) ^ bool(map[build_frame[i][0]+1][build_frame[i][1]] == 2): # 보의 한쪽 끝 부분 위에 있거나
                    map[build_frame[i][0]][build_frame[i][1]] = 1
                elif map[build_frame[i][0]][build_frame[i][1]-1] == 1: # 다른 기둥 위에 있어야 합니다.
                    map[build_frame[i][0]][build_frame[i][1]] = 1
            else : # 보는
                if map[build_frame[i][0]][build_frame[i][1]-1] == 1 or map[build_frame[i][0]+1][build_frame[i][1]-1] == 1: # 한쪽 끝 부분이 기둥 위에 있거나
                    map[build_frame[i][0]][build_frame[i][1]] = 2
                elif map[build_frame[i][0]-1][build_frame[i][1]] == 2 and map[build_frame[i][0]+1][build_frame[i][1]] == 2: # 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
                    map[build_frame[i][0]][build_frame[i][1]] = 2
        else : # 삭제, 설치의 반대과정 
            if build_frame[i][2] == 0: # 기둥
                if map[build_frame[i][0]][build_frame[i][1]+1] >= 1 and (not map[build_frame[i][0]+1][build_frame[i][1]+1] == 2 and not map[build_frame[i][0]-1][build_frame[i][1]+1] == 2) :
                    continue
                map[build_frame[i][0]][build_frame[i][1]] = 0
            elif build_frame[i][2] == 1: # 보
                if map[build_frame[i][0]][build_frame[i][1]] == 3 or map[build_frame[i][0]+1][build_frame[i][1]] == 1:
                    continue
                elif (map[build_frame[i][0]+1][build_frame[i][1]] == 2 and map[build_frame[i][0]+2][build_frame[i][1]] == 2) and (not map[build_frame[i][0]+1][build_frame[i][1]-1] == 1 and not map[build_frame[i][0]+2][build_frame[i][1]-1] == 1):
                    continue
                elif (map[build_frame[i][0]-1][build_frame[i][1]] == 2 and map[build_frame[i][0]-2][build_frame[i][1]] == 2) and (not map[build_frame[i][0]-1][build_frame[i][1]-1] == 1 and not map[build_frame[i][0]-2][build_frame[i][1]-1] == 1):
                    continue
                map[build_frame[i][0]][build_frame[i][1]] = 0
    
    for x in range(len(map)):
        for y in range(len(map)):
            print(map[x][y],end=" ")
        print()
    print()
    answer = []
    for i in range(n+1):
        for j in range(n+1):
            if map[i][j] == 3:
                answer.append([i,j,0])
                answer.append([i,j,1])
            elif map[i][j] != 0:
                answer.append([i,j,map[i][j]-1])

    return answer

a =solution(5, [[0, 0, 0, 1], [2, 0, 0, 1], [4, 0, 0, 1], [0, 1, 1, 1], [1, 1, 1, 1], [2, 1, 1, 1], [3, 1, 1, 1], [2, 0, 0, 0], [1, 1, 1, 0], [2, 2, 0, 1]])
print(a)
