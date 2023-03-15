import numpy as np
from matplotlib import pyplot as plt
import pandas as pd
import math as m
f = pd.read_csv("LAB1_remake/Task_1/binsearch.csv")
plt.yscale("log")

x1 = np.array(f["Number"])
y1 = np.array(f["Microseconds"])

plt.scatter(y1, x1, s=5, c='r',
                label='бинарный поиск (время в зависимости от длины массива)')
print('нетрудно видеть, что начиная с 1000 микросекунд данные хорошо аппроксимируются прямой. '
      'Отсюда и следует, что исходная функция с некоторого значения N начинает вести себя, как логарифм')

plt.xlabel("Microseconds")
plt.ylabel("log(Number)")
plt.grid()
plt.minorticks_on()
plt.legend()
plt.show()