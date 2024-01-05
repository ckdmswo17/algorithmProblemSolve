# 이코테 문제 : 자물쇠와 열쇠(블로그 도움 받음)

def rotate(key):
    m = len(key)
    rotate_arr = [[0] * m for _ in range(m)]
    for i in range(m):
        for j in range(m):
            rotate_arr[j][m-1-i] = key[i][j]
    return rotate_arr

def check(lock_padding,lock_leng):
    # for i in range(len(lock_padding)):
    #     for j in range(len(lock_padding)):
    #         print(lock_padding[i][j],end=" ")
    #     print()
    # print()
    for x in range(lock_leng,lock_leng*2):
        for y in range(lock_leng,lock_leng*2):
            if lock_padding[x][y] != 1:
                return False
    return True

def keyIn(lock_padding,key,lock_leng):
    n = len(key)
    for x in range(lock_leng*2+1):
        for y in range(lock_leng*2+1):
            for i in range(n):
                for j in range(n):
                    lock_padding[x+i][y+j] += key[i][j]
            if check(lock_padding,lock_leng):
                return True
            for i in range(n):
                for j in range(n):
                    lock_padding[x+i][y+j] -= key[i][j]               
    return False

def solution(key, lock):
    # 오른쪽 90도 돌리면 : a = b , b = leng-1-a
    # 왼쪽 90도 돌리면 : a = leng-1-b, b = a
    # 평행이동 후 회전 / 회전 후 평행이동은 서로 차이가 있지만 방향의 차이일 뿐임, 어차피 못만드는건 못만든다. 
    n = len(lock)
    lock_padding = [[0] * (n*3) for _ in range(n*3)]
    rotate_count = 0
    for i in range(n):
        for j in range(n):
            lock_padding[n+i][n+j] = lock[i][j]
    while True :
        # for i in range(len(key)):
        #     for j in range(len(key)):
        #         print(key[i][j],end=" ")
        #     print()
        # print()        
        answer = keyIn(lock_padding,key,n)
        if answer or rotate_count == 3 :
            break
        else : 
            key = rotate(key)
            rotate_count += 1
    return answer

a = solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 0, 1], [0, 1, 1], [1, 1, 1]])
print(a)