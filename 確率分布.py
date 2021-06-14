#各ｎの出現割合のヒストグラムを出力
import random
import matplotlib.pyplot as plt

def coin():
    n=0
    for _ in range(10):
        x=random.randint(0,1)
        if x==1:
            n+=1
    return n

box=[0,0,0,0,0,0,0,0,0,0,0]
for i in range(10000):
    a=coin()
    box[a]+=1
for i in range(11):
    print(str(i)+'回＝'+str(box[i]))
x=[0,1,2,3,4,5,6,7,8,9,10]
plt.xlabel("omote-time",fontsize=20)
plt.ylabel("frequency",fontsize=20)
plt.bar(x,box)
plt.show()