# 이코테 문제 : 무지의 먹방 라이브(효율성 테스트 통과 X 버전)
def solution(food_times, k):
    if sum(food_times) == k:
        return -1

    step = 0
    while(k != 0):
        if food_times[step%len(food_times)] <= 0:
            pass
        else :
            food_times[step%len(food_times)] -= 1
            k -= 1
        step += 1
    
    while(food_times[step%len(food_times)] == 0):
        step += 1
    return step%len(food_times)+1