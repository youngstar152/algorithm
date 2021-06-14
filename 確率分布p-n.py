#確率分布Ｐ（ｎ）のヒストグラムを出力
import matplotlib.pyplot as plt

a=[1.0,10.0,45.0,120.0,210.0,252.0,210.0,120.0,45.0,10.0,1.0]
b=[c*pow(0.5,10) for c in a ]
x=[0,1,2,3,4,5,6,7,8,9,10]
plt.xlabel("omote-time",fontsize=20)
plt.ylabel("frequency",fontsize=20)
plt.bar(x,b)
plt.show()