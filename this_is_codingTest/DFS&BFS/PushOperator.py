# 이코테 문제 : 연산자 끼워 넣기

from itertools import permutations

N = int(input())
A = list(map(int,input().split(" ")))
op_num = list(map(int,input().split(" ")))

op = []
for i in range(len(op_num)):
    if i == 0:
        for j in range(op_num[i]):
            op.append('+')    
    elif i == 1:
        for j in range(op_num[i]):
            op.append('-')
    elif i == 2:
        for j in range(op_num[i]):
            op.append('*')
    else:
        for j in range(op_num[i]):
            op.append('/')
# print(op)

max = -1000000000
min = 1000000000
for i in permutations(op,len(op)):
    sum = A[0]
    for j in range(len(i)):
        if i[j] == '+':
            sum += A[j+1]
        elif i[j] == '-':
            sum -= A[j+1]
        elif i[j] == '*':
            sum *= A[j+1]
        else:
            if sum < 0 :
                sum = -(-(sum)//A[j+1])
            else :    
                sum //= A[j+1]
    # print(i, sum)
    if sum > max :
        max = sum
    if sum < min :
        min = sum

print(max)
print(min)