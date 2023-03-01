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

t_g, N, s_g = read('LAB2/SHELL_SORT/text_data/geom_prog.txt')
t_h, N, s_h = read('LAB2/SHELL_SORT/text_data/hibb.txt')
t_f, N, s_f = read('LAB2/SHELL_SORT/text_data/fib.txt')
plt.plot(N, t_g, N, t_h, N, t_f)
plt.legend(['Геом прог', 'Хиббар', 'Фибоначи'])
plt.xlabel(r'$N, элем.$')
plt.ylabel(r'$t, мс$')
plt.title(r'$t(N)$ время сорт Шелла, cnt = 1000')
plt.grid(True)
plt.savefig('LAB2/SHELL_SORT/pictures/together_time.png')
plt.show()

plt.plot(N, s_g, N, s_h, N, s_f)
plt.legend(['Геом прог', 'Хиббар', 'Фибоначи'])
plt.xlabel(r'$N, элем.$')
plt.ylabel(r'$s, раз$')
plt.title(r'$s(N)$ количество перестановок сорт Шелла, cnt = 1000')
plt.grid(True)
plt.savefig('LAB2/SHELL_SORT/pictures/together_swap.png')
plt.show()