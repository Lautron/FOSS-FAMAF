import matplotlib.pyplot as plt
import numpy as np

def graph_func(func, I, label, color=None):
    xs = np.linspace(*I)
    ys = [func(x) for x in xs]
    if color:
        plt.plot(xs, ys, label=label, color=color)
    else:
        plt.plot(xs, ys, label=label)

def basic(xs, ys, label, color=None):
    if color:
        plt.plot(xs, ys, label=label, color=color)
    else:
        plt.plot(xs, ys, label=label)

def scatter(data, label: str, color=None, last_color="r"):
    last = [ [data[0][-1]], [data[1][-1]] ]
    data2 = [ [data[0][:-1]], [data[1][:-1]] ]
    if color:
        plt.scatter(*data2, label=label, color=color)
        plt.scatter(*last, label=f'{label} (last)', color=color)
    else:
        plt.scatter(*data2, label=label)
        plt.scatter(*last, label=f'{label} (last)')

def stetic():
    plt.axhline(0, color='black')
    plt.axvline(0, color='black')
    plt.legend()
    plt.grid()

def show():
    stetic()
    plt.show()

def save(path):
    stetic()
    plt.savefig(path, dpi=100)
    plt.close()

def main():
    data = [[0, 1, 2], [0, 1, 2]]
    scatter(data, "test")
    show()

if __name__ == "__main__":
    main()
