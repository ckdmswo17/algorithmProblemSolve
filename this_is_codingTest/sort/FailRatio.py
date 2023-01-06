# 이코테 문제 : 실패율 (메모리 문제인지 뭔지 모르는 런타임에러 때문에 미해결..)

import copy

def solution(N, stages):
    leng = len(stages)
    for i in stages:
        if i==N+1:
            stages.remove(N+1)

    noclear_count = [0] * N
    for i in stages:
        noclear_count[i-1] += 1
    # print(noclear_count)

    clear_count = [leng] * N
    fail_ratio = []
    for i in range(N):
        for j in range(i-1,-1,-1):
            clear_count[i] -= noclear_count[j]
        if clear_count[i] == 0 :
            fail_ratio.append([0,i+1])
        else :
            fail_ratio.append([noclear_count[i]/clear_count[i],i+1])
    # print(clear_count)
    # print(fail_ratio)

    b = sorted(fail_ratio,key=lambda x:x[0],reverse=True)
    answer = []
    for i in b:
        r = copy.deepcopy(i)
        answer.append(r[1])
    
    return answer

N = int(input())
stages = list(map(int,input().split(" ")))
print(solution(N,stages))

# 성공한 버전(다른사람 코드 참고)
# def solution(N, stages):
#     k = len(stages)
#     s = []
#     for i in range(1,N+1):
#         c = 0
#         for j in range(len(stages)):
#             if stages[j] == i:
#                 c += 1
#         if c == 0:
#             s.append(0)
#         else :
#             s.append(c/k)
#         k = k-c
        
#     a = sorted(s,reverse=True)
#     answer = []
    
#     for i in range(len(a)):
#         answer.append(s.index(a[i])+1)
#         s[s.index(a[i])]=2
        
#     return answer