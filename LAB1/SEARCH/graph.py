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


def main(path):
    t, N = read('LAB1/SEARCH/text_data' + path + 'txt')
    plt.plot(N, t)
    plt.xlabel(r'$N, элем.$')
    plt.ylabel(r'$t, мс$')
    plt.title(r'$t(N)$ перебор в среднем случае, cnt = 10000')
    plt.grid(True)
    plt.savefig('LAB1/SEARCH/pictures' + path + 'png')
    plt.show()

paths1 = ['/worst_perebor1.', '/worst_perebor2.', '/worst_perebor3.', '/worst_perebor4.', '/worst_perebor5.']
paths2 = ['/worst_binsearch1.', '/worst_binsearch2.', '/worst_binsearch3.', '/worst_binsearch4.', '/worst_binsearch5.']
paths3 = ['/mean_perebor1.', '/mean_perebor2.', '/mean_perebor3.', '/mean_perebor4.', '/mean_perebor5.']
paths4 = ['/mean_binsearch1.', '/mean_binsearch2.', '/mean_binsearch3.', '/mean_binsearch4.', '/mean_binsearch5.']
for path in paths3:
    main(path)