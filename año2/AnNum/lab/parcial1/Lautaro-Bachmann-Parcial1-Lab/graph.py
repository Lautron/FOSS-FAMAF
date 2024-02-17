import matplotlib.pyplot as plt

def stetic():
    plt.axhline(0, color='black')
    plt.axvline(0, color='black')
    plt.legend()
    plt.grid()
    
def show():
    stetic()
    plt.show()
    
def graph(xs, ys, label):
    plt.plot(xs, ys, label=label)

def scatter(xs, ys, label: str, color=None, last_color="r"):
    size = 15
    last_x = xs[-1]
    last_y = ys[-1]
    xs = xs[:-1]
    ys = ys[:-1]
    if color:
        plt.scatter(xs, ys, label=label, color=color, s=size)
        plt.scatter(last_x, last_y, label=f'{label} (last)', color=last_color, s=size)
    else:
        plt.scatter(xs, ys, label=label, s=size)
        plt.scatter(last_x, last_y, label=f'{label} (last)', color=last_color, s=size)

