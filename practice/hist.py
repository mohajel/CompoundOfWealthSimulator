# sketch PDF from lots of samples of random variables
# plot histogram of samples

import numpy as np
import matplotlib.pyplot as plt

# # IMPORTANT: change this based on your test cases
# totall_coins_value = 40000


file_name = "geo-250.txt"
print("File name: ", file_name)

# read data from file
data = np.loadtxt(file_name)

# get only second set of samples
# samples = data[:,1]
# samples = data[:,0]

plt.plot(data, ".")

# print samples 
print(data)


# # divide all samples to 10000
# samples = samples / totall_coins_value


# find mean and variance of samples
mean = np.mean(data)

# print mean and variance
print("Mean: ", mean)

# # show plot
plt.show()

# # save plot as png file
# plt.savefig(file_name +".png")




