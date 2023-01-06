# 이코테 문제 : 안테나

N = int(input())
house = list(map(int,input().split(" ")))

house.sort()
answer_index = 0
# 중간값이 그냥 최소거리임ㅋㅋ
if len(house) % 2 == 0: 
    answer_index = len(house)//2-1
else :
    answer_index = len(house)//2    
print(house[answer_index])