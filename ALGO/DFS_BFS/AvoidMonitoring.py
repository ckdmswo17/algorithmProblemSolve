# 이코테 문제 : 감시 피하기

from itertools import combinations
import copy

N = int(input())
maps = []
for i in range(N):
    maps.append(list(input().split(" ")))
# print(maps)

T_index = []
for i in range(N):
    for j in range(N):
        if maps[i][j] == "T":
            T_index.append([i,j])
# print(T_index)

nums = list(range(N**2))
combi = list(combinations(nums,3))

dx = [0,1,0,-1]
dy = [-1,0,1,0]
flag = True
for i in combi:
    flag = True
    copy_maps = copy.deepcopy(maps)
    for r in range(3):
        if (0<=i[r]//N<N) and (0<=i[r]%N<N) and copy_maps[i[r]//N][i[r]%N] == "X":
            copy_maps[i[r]//N][i[r]%N] = "O"
        else : 
            flag = False
            break

    if not flag:
        continue

#    for w in range(N):
#        for e in range(N):
#            print(copy_maps[w][e],end=" ")
#        print()

    for j in T_index: # 주의) for문에서 in으로 가져오는 배열도 주소를 가져오는 것이기때문에 원본이 수정될수 있다!
        # print("현재 T : ",j)
        if not flag:
            break
        for z in range(4):
            if not flag:
                break
            j = copy.deepcopy(j)
            j[0] += dy[z]
            j[1] += dx[z]
            while (0 <= j[0] < N) and (0 <= j[1] < N):
                # print("현재 j : ",j)
                if copy_maps[j[0]][j[1]] == "X":
                    j[0] += dy[z]
                    j[1] += dx[z]
                elif copy_maps[j[0]][j[1]] == "S":
                    flag = False
                    break
                else :
                    break
            # print(z,flag)
    if flag:
        break

if flag :
    print("YES")
else :
    print("NO")
            
