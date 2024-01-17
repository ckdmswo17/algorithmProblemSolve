# 이코테 문제 : 볼링공 고르기
N,M = map(int,input().split(" "))
num = list(map(int,input().split(" ")))

result = 0
for i in range(N-1):
    for j in range(i+1,N):
        if num[i] == num[j]:
            pass
        else :
            result += 1
            print(i+1,"번 공 - ",j+1,"번 공")
print(result)