import matplotlib.pyplot as plt


def read(filename):
    a = open(filename, 'r').read().split()
    t = []
    N = []
    s = []
    for i in range(len(a)):
        if i%3 == 0:
            t.append(int(a[i]))
        elif i%3 == 1:
            s.append(int(a[i]))
        else:
            N.append(int(a[i]))
    return t, N, s

t, N, s = read('LAB2/COMB_SORT/data.txt')
plt.plot(N, t)
plt.xlabel(r'$N, элем.$')
plt.ylabel(r'$t, мс$')
plt.title(r'$t(N)$ Comb sort, cnt = 10000')
plt.grid(True)
plt.savefig('LAB2/COMB_SORT/time.png')
plt.show()

plt.plot(N, s)
plt.xlabel(r'$N, элем.$')
plt.ylabel(r'$s, раз$')
plt.title(r'$s(N)$ Comb sort, cnt = 10000')
plt.grid(True)
plt.savefig('LAB2/COMB_SORT/swap.png')
plt.show()