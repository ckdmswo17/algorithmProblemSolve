# 이코테 문제 : 괄호 변환

def solution(p):
    answer = dfs(p)
    return answer

def dfs(braket):
    count = 0
    correct_flag = False
    answer = ""
    # print(braket)
    for i in range(len(braket)):
        # print(i,braket[i])
        if braket[i] == '(':
            count += 1
            if count == 1 :
                correct_flag = True
        else :
            count -=1 
        if count == 0:
            if correct_flag:
                answer += braket[:i+1]
                answer += dfs(braket[i+1:])
            else :
                answer += "("
                answer += dfs(braket[i+1:])
                answer += ")"
                # print(braket[1:i],"는 자르고나서 문자열")
                braket = braket[1:i]
                table = str.maketrans('()', ')(')
                braket = braket.translate(table)
                answer += braket
            break
    return answer

# print(solution(input()))