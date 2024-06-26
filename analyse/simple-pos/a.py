import numpy as np
import matplotlib.pyplot as plt
from scipy.special import comb, beta

# Parameters
# n = 50
# a1 = 2
# b1 = 3
# a2 = 5
# b2 = 2

# # Calculate PMFs
# k_values = np.arange(0, n+1)
# pmf1 = comb(n, k_values) * beta(k_values + a1, n - k_values + b1) / beta(a1, b1)
# pmf2 = comb(n, k_values) * beta(k_values + a2, n - k_values + b2) / beta(a2, b2)


a1 = 0.66
b1 = 0.33
pmf1 = beta(a1, b1)

# plot the beta distribution
x = np.linspace(0, 1, 100)
y = beta.pdf(x, a1, b1)
plt.plot(x, y, 'r-', lw=5, alpha=0.6, label='beta pdf')

# Plotting
# plt.bar(k_values, pmf1, label='PMF 1', color='blue', alpha=0.5)
# plt.bar(k_values, pmf2, label='PMF 2', color='red', alpha=0.5)
# plt.xlabel('k (Number of Successes)')
# plt.ylabel('Probability')
plt.title('Beta-Binomial Distribution Comparison')
plt.legend()
plt.show()