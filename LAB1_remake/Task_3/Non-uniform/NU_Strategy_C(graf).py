import numpy as np
from matplotlib import pyplot as plt
import pandas as pd
f = pd.read_csv("NU_Strategy_C.csv")

x = f["Number"]
y = np.array(f["Microseconds"])
err = np.array(x)
plt.scatter(f["Number"],(f["Microseconds"]),s=5,c='r',label = 'поиск со стратегией C')


k=(((y*x).mean())/((x*x).mean()))
print(k,"\n")
x=np.linspace(0,100000,1000)
y=np.array([k*i for i in x])
plt.plot(x,y,'g',linestyle = '--',label = 'по МНК')


plt.xlabel("Number")
plt.ylabel("Microseconds")
plt.grid()
plt.minorticks_on()
plt.legend()
plt.show()