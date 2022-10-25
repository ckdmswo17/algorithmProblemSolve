# 이코테 문제 : 치킨 배달

if __name__ == "__main__":
    N, M = map(int,input().split(" "))
    maps = []
    for i in range(N):
        maps.append(list(map(int,input().split(" "))))
    
    houses = []
    chickenHouses = []
    for i in range(N):
        for j in range(N):
            if maps[i][j] == 1:
                houses.append([i,j])
            if maps[i][j] == 2:
                chickenHouses.append([i,j])
    
    sum = 0