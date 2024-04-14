import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import beta

# Parameters
a = 0.33
b = 0.66

# Generate x values
x = np.linspace(0, 1, 1000)

# Calculate PDF
pdf = beta.pdf(x, a, b)

# Plotting
plt.plot(x, pdf, 'b-', lw=2)
plt.xlabel('x')
plt.ylabel('Probability Density')
plt.title('Beta Distribution (a = 0.33, b = 0.66)')
plt.show()