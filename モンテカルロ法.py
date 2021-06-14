import random
import math

def f(x):
    return 4/(1+x**2)

def monte(y,a,b):
    i=0
    average=0
    box=[]
    while i <10:
        sum=0
        for _ in range(y):
            c=random.random()
            d=f(c)
            sum+=((b-a)/y)*d
        box.append(sum)
        average+=sum
        print('I'+str(i+1)+':'+str(sum))
        i+=1
    return (average,box)

def dev(arg1,average):
    sum=0
    for i in range(10):
        sum+=(arg1[i]-average)**2
    return math.sqrt((1/9)*sum)

print('n=10')
answer=monte(10,0,1)
average1=(1/10)*answer[0]
print('average:'+str(average1))
dev1=dev(answer[1],average1)
print('dev:'+str(dev1))

print('n=10**3')
answer=monte(10**3,0,1)
average1=(1/10)*answer[0]
print('average:'+str(average1))
dev1=dev(answer[1],average1)
print('dev:'+str(dev1))

print('n=10**5')
answer=monte(10**5,0,1)
average1=(1/10)*answer[0]
print('average:'+str(average1))
dev1=dev(answer[1],average1)
print('dev:'+str(dev1))

print('n=10**7')
answer=monte(10**7,0,1)
average1=(1/10)*answer[0]
print('average:'+str(average1))
dev1=dev(answer[1],average1)
print('dev:'+str(dev1))