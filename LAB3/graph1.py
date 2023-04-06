import matplotlib.pyplot as plt
import numpy as np

def read(filename):
    a = open(filename, 'r').read().split()
    t = []
    N = []
    for i in range(len(a)):
        if i%2 == 0:
            t.append(int(a[i]))
        else:
            N.append(int(a[i]))
    return t, N

N, t = read('LAB3/data3.txt')
N = np.array(N)
t = np.array(t)
plt.plot(N, t)
plt.xlabel(r'$N$')
plt.ylabel(r'$t$')
plt.title(r'N(t)')
plt.grid(True)
plt.show()