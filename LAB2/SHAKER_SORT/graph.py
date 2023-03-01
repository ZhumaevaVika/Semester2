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



t_sh, N = read('LAB2/SHAKER_SORT/text_data/backward_step.txt')
t_f, N = read('LAB2/SHAKER_SORT/text_data/forward_step.txt')
t_b, N = read('LAB2/SHAKER_SORT/text_data/backward_step.txt')
plt.plot(N, t_sh, N, t_f, N, t_b)
plt.legend(['shaker_sort', 'forward', 'backward'])
plt.xlabel(r'$N, элем.$')
plt.ylabel(r'$t, мс$')
plt.title(r'$t(N)$ together, cnt = 1000')
plt.grid(True)
plt.savefig('LAB2/SHAKER_SORT/pictures/together.png')
plt.show()
