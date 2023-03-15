import numpy as np
from matplotlib import pyplot as plt
import pandas as pd
f = pd.read_csv("LAB1_remake/Task_3/Non-uniform/NU_Strategy_A.csv")

x = f["Number"]
y = np.array(f["Microseconds"])
err = np.array(x)
plt.scatter(f["Number"],(f["Microseconds"]),s=5,c='r',label = 'поиск со стратегией А')

x1 = x
y1 = y
k1=(((y1*x1).mean())/((x1*x1).mean()))
print(k1,"\n")
x1=np.linspace(0,200000,1000)
y1=np.array([k1*i for i in x1])
plt.plot(x1,y1,'g',linestyle = '--',label = 'по МНК')

x2 = x
y2 = y
k2=(((y2*x2).mean())/((x2*x2).mean()))
print(k2,"\n")
x2=np.linspace(0,200000,1000)
y2=np.array([k2*i for i in x2])
plt.plot(x2,y2,'b',linestyle = '--',label = 'по МНК')

plt.xlabel("Number")
plt.ylabel("Microseconds")
plt.grid()
plt.minorticks_on()
plt.legend()
plt.show()