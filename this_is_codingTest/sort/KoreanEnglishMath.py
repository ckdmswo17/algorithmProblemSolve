# 이코테 문제 : 국영수

N = int(input())

student = []
for i in range(N):
    stu = list(input().split(" "))
    student.append([stu[0],int(stu[1]),int(stu[2]),int(stu[3])])

student.sort(key=lambda x:(-x[1],x[2],-x[3],x[0]))

for i in range(N):
    print(student[i][0])