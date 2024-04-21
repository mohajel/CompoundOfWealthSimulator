import numpy as np
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import beta

# IMPORTANT: change this based on your test cases
totall_coins_value = 40030

zahra_data = "zahra-divide.txt"

file_name = zahra_data
print("File name: ", file_name)

# read data from file
data = np.loadtxt(file_name)

# get samples
a_samples = data[:,0]
b1_samples = data[:,1]
b2_samples = data[:,2]
b3_samples = data[:,3]
b4_samples = data[:,4]

# print samples 
# print(samples)

# divide all samples to totall_coins_value for normalization
a_samples = a_samples / totall_coins_value
b1_samples = b1_samples / totall_coins_value
b2_samples = b2_samples / totall_coins_value
b3_samples = b3_samples / totall_coins_value
b4_samples = b4_samples / totall_coins_value

b_samples = b1_samples + b2_samples + b3_samples + b4_samples


plt.hist(b_samples, bins=100, density=True, histtype='stepfilled', label='Samples')



# find mean and variance of samples
mean = np.mean(b_samples)
variance = np.var(b_samples)

# print mean and variance
print("Mean: ", mean)
print("Variance: ", variance)

# add labels
plt.xlabel("Fraction Of Stake")
plt.ylabel("Density")

# add grid, legend and title AND show plot
plt.grid(True)
plt.legend()
plt.title("Zahra-divide POS Distribution")
plt.show()

# save plot as png file
# plt.savefig("simple"+".png")




