# 이코테 문제 : 문자열 압축
def solution(s):
    min = len(s)
    for i in range(1,len(s)//2+1):
        j = 0
        entire_leng = len(s)
        while j+i <= len(s):
            main = s[j:j+i]
            j += i
            sub = s[j:j+i]
            count = 1
            while main == sub : 
                count += 1
                if count == 2 : # 2번째 겹치면 앞에 숫자를 추가해야하기 때문에 길이+1 
                    entire_leng += 1
                    print(main, sub, i, j, "에서 길이 1 추가로 총 길이 :",entire_leng)
                elif count == 10 or count == 100 or count == 1000 : # 10, 100, 1000번째 겹치면 앞에 숫자 자릿수를 추가해야하기 때문에 길이+1
                    entire_leng += 1
                    print(main, sub, i, j, "에서 길이 1 추가로 총 길이 :",entire_leng)         
                entire_leng -= i
                print(main, sub, i, j, "에서 길이", i,"감소로 총 길이 :",entire_leng)
                if j+i > len(s):
                    break
                else :
                    j += i
                    sub = s[j:j+i]
        if min > entire_leng :
            min = entire_leng
    return min

while(True):
    a = input()
    print("최소길이 :",solution(a))