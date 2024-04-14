import numpy as np
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import beta

# IMPORTANT: change this based on your test cases
totall_coins_value = 40000


simple_data = "simple.txt"
pow_data = "pow.txt"
zahra_data = "zahra.txt"
geometric_data = "geometric-1.txt"
geometric_t_4_data = "./results/geometric_t_4.txt"
timevariant = "time_variant.txt"
demo = "simple-demo.txt"

file_name = demo
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

# divide all samples to totall_coins_value for normalization
samples = samples / totall_coins_value

plt.hist(samples, bins=100, density=True, histtype='stepfilled', label='Samples')


# Parameters
a = 0.33
b = 0.66

# Generate x values
x = np.linspace(0, 1, 1000)

# Calculate PDF
pdf = beta.pdf(x, a, b)

# Plotting
plt.plot(x, pdf, lw=2, label='Beta Distribution')

# x range from 0 to 1
plt.xlim(-0.1,1.1)

# find mean and variance of samples
mean = np.mean(samples)
variance = np.var(samples)

# print mean and variance
print("Mean: ", mean)
print("Variance: ", variance)

plt.grid(True)
plt.legend()
plt.title("Simple POS Beta Distribution")

# show plot
plt.show()

# legends for the plot
plt.legend(["Beta Distribution", "Samples"])

# save plot as png file
# plt.savefig(file_name +".png")




