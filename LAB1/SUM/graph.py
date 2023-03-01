import matplotlib.pyplot as plt


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


t, N = read('LAB1/SUM/text_data/N_2.txt')
plt.plot(N, t)
plt.xlabel(r'$N, элем.$')
plt.ylabel(r'$t, мс$')
plt.title(r'$t(N)$ сумма двух O(N), cnt = 10000')
plt.grid(True)
plt.savefig('LAB1/SUM/pictures/N_2.png')
plt.show()

# 'LAB1/SUM/text_data/N2_1.txt'