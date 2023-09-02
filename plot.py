# read input from initial_data.txt in each line one number
# plot the data in a graph
# save the graph as a png file

import matplotlib.pyplot as plt
import numpy as np
import sys

# get filename as command line argument
filename = sys.argv[1]

# read data from file
data = np.loadtxt(filename)

# plot data and set x and y labels x = participant number, y = coin value
plt.xlabel('Participant')
plt.ylabel('Coin value')
plt.plot(data)

# remove file extension from filename
filename = filename.split('.')[0]

# save plot as png file
plt.savefig(filename + '.png')

# show plot
plt.show()

