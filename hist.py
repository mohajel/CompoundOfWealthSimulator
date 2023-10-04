# sketch PDF from lots of samples of random variables
# plot histogram of samples

import numpy as np
import matplotlib.pyplot as plt

# IMPORTANT: change this based on your test cases
totall_coins_value = 40000

file_name = "simple_consense_protocol_test.txt"
# file_name = "zahra_consense_protocol_test.txt"
# file_name = "geometric_consense_protocol_test.txt"

print("File name: ", file_name)

# read data from file
data = np.loadtxt(file_name)

plt.xlabel("Fraction Of Stake")
plt.ylabel("Density")

# get only second set of samples
samples = data[:,1]
# samples = data[:,0]

# print samples 
print(samples)


# divide all samples to 10000
samples = samples / totall_coins_value

plt.hist(samples, bins=50, density=True, histtype='stepfilled')

# x range from 0 to 1
# plt.xlim(0,1)

# find mean and variance of samples
mean = np.mean(samples)
variance = np.var(samples)

# print mean and variance
print("Mean: ", mean)
print("Variance: ", variance)

# # show plot
plt.show()

# save plot as png file
plt.savefig('histogram.png')




