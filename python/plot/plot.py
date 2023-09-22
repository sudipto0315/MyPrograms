import numpy as np
import matplotlib.pyplot as plt

def makePlot(outputFilename='Asymptote02.svg'):
    plt.rc('grid', linewidth=1, linestyle='-', color='#a0a0a0')
    plt.rc('xtick', labelsize=15)
    plt.rc('ytick', labelsize=15)
    plt.rc('font', **{'family': 'serif', 'serif': ['Palatino'], 'size': 15})
    plt.rc('text', usetex=False)

    fig = plt.figure()
    ax = fig.add_axes([0.12, 0.12, 0.76, 0.76])
    n = 14
    t = np.arange(0.07, 12.0, 0.01)
    x = t + np.cos(n * t) / t
    y = t + np.sin(n * t) / t
    ax.plot(x, y, color='#ee8d18', lw=2)
    ax.plot([-4, 12], [-4, 12], lw=1, color='k')
    ax.set_aspect('equal')
    plt.grid(True)
    ax.set_xlabel('$x$')
    ax.set_ylabel('$y$', rotation=0)
    ax.set_title(r'$x=t+\frac{\cos(nt)}{t}, y=t+\frac{\sin(nt)}{t}, t>0, n = ' + str(n) + r'$',fontsize=15)
    fig.savefig(outputFilename)
    plt.show()
makePlot()