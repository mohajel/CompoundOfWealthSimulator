import numpy as np
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import beta

# IMPORTANT: change this based on your test cases
totall_coins_value = 40030

zahra_data = "zahra.txt"

file_name = zahra_data
print("File name: ", file_name)

# read data from file
data = np.loadtxt(file_name)

# get only second set of samples
# samples = data[:,1]
samples = data[:,0]

# print samples 
print(samples)

# divide all samples to totall_coins_value for normalization
samples = samples / totall_coins_value

plt.hist(samples, bins=100, density=True, histtype='stepfilled', label='Samples')



# find mean and variance of samples
mean = np.mean(samples)
variance = np.var(samples)

# print mean and variance
print("Mean: ", mean)
print("Variance: ", variance)

# add labels
plt.xlabel("Fraction Of Stake")
plt.ylabel("Density")

# add grid, legend and title AND show plot
plt.grid(True)
plt.legend()
plt.title("Zahra POS Distribution")
plt.show()

# save plot as png file
# plt.savefig("simple"+".png")




