import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

data_names = ['10', '30', '100']

for node in data_names:
    data = np.loadtxt('data'+node+'.dat')/np.max(np.loadtxt('data'+node+'.dat'))
    x = np.linspace(-1,1,data.shape[1])
    t = np.linspace(0,1,data.shape[0])

    X,T = np.meshgrid(x,t)

    fig = plt.figure()
    ax = fig.gca(projection='3d')
    surf = ax.plot_surface(X,T,data)
    ax.set( title = 'Nx '+node+', N_iter = '+str( data.shape[0] ), xlabel = 'Space', ylabel = 'Time')
    plt.savefig('grafica'+node+'.png')