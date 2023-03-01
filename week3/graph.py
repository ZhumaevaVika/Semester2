import matplotlib.pyplot as plt


def read(filename):
    a = open(filename, 'r').read().split()
    tA = []
    tB = []
    N = []
    for i in range(len(a)):
        if i%3 == 0:
            tA.append(int(a[i]))
        elif i%3 == 1:
            tB.append(int(a[i]))
        else:
            N.append(int(a[i]))
    return tA, tB, N


tA, tB, N = read('week3/text_data.txt')
plt.plot(N, tA, N, tB)
plt.legend(('selectSort','doubleSelectSort'))  
plt.xlabel(r'$N, элем.$')
plt.ylabel(r'$t, мс$')
plt.title(r'$t(N)$ Сравнение сортировок, cnt = 100')
plt.grid(True)
plt.savefig('week3/picture.png')
plt.show()
