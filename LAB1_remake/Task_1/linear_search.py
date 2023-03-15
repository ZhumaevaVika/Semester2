import numpy as np
from matplotlib import pyplot as plt
import pandas as pd
f = pd.read_csv("LAB1_remake/Task_1/linear_search.py")

x = f["Number"]
y = np.array(f["Microseconds"])
err = np.array(x)
plt.scatter(f["Number"],(f["Microseconds"]),s=5,c='r',label = 'линейный поиск')


k=(((y*x).mean()-(x).mean()*(y.mean()))/((x*x).mean()-(x).mean()**2))
b=y.mean()-k*(x).mean()
print(k,"\n")
x=np.linspace(0,200000,1000)
y=np.array([k*i+b for i in x])
plt.plot(x,y,'g',linestyle = '--',label = 'по МНК')


plt.xlabel("Number")
plt.ylabel("Microseconds")
plt.grid()
plt.minorticks_on()
plt.legend()
plt.show()