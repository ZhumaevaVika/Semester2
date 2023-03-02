import matplotlib.pyplot as plt


def read(filename):
    a = open(filename, 'r').read().split()
    tA = []
    tB = []
    tC = []
    tN = []
    N = []
    for i in range(len(a)):
        if i%5 == 0:
            N.append(float(a[i]))
        elif i%5 == 1:
            tA.append(float(a[i]))
        elif i%5 == 2:
            tB.append(float(a[i]))
        elif i%5 == 3:
            tC.append(float(a[i]))
        else:
            tN.append(float(a[i]))
    return N, tA, tB, tC, tN


N, tA, tB, tC, tN = read('LAB1/FREQUENT/data.txt')
plt.plot(N, tA, N, tB, N, tC, N, tN)
plt.legend(['A', 'B', 'C', 'N'])
plt.xlabel(r'$N, элем.$')
plt.ylabel(r'$t, мс$')
plt.title(r'$t(N)$ A, B, C неравномерн, N равномер')
plt.grid(True)
plt.savefig('LAB1/FREQUENT/data.png')
plt.show()

