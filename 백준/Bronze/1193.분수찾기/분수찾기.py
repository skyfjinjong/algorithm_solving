num = int(input())
i = 0
n = 0
count = 0
while num > i:
    n += 1
    i += n
    count += 1

zigzag = count%2
dis = i - num
div = count - dis

if zigzag==1:
    print(str(dis + 1) + '/' + str(div))
else:
    print(str(div) + '/' + str(dis + 1))