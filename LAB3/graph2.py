import matplotlib.pyplot as plt
import numpy as np

def read(filename):
    a = open(filename, 'r').read().split()
    t = []
    S = []
    step = []
    for i in range(len(a)):
        if i%3 == 0:
            S.append(float(a[i]))
        elif i%3 == 1:
            t.append(float(a[i]))
        else:
            step.append(float(a[i]))
    return t, S, step

t, S, step = read('LAB3/data4.txt')
plt.plot(S, t)
plt.xlabel(r'$S_{дис}/S_{атом}$')
plt.ylabel(r'$t, мс$')
plt.title(r'Время от отношения площадей')
plt.grid(True)
plt.show()

plt.plot(S, step)
plt.xlabel(r'$S_{дис}/S_{атом}$')
plt.ylabel(r'$step$')
plt.title(r'колличество шагов от отношения площадей')
plt.grid(True)
plt.show()
