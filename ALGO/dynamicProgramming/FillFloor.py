# 이코테 문제 : 바닥 공사
def fillFloor(width):
  if width == 1:
    return 1
  elif width == 2:
    return 3
  return fillFloor(width-1) + fillFloor(width-2)*2

if __name__=="__main__":
  N = int(input())

  print(fillFloor(N)%796796)
