import numpy as np

filename = './data.txt'

numbers = set()

with open(filename) as f:
    for line in f:
        numbers.add(int(line))


results = np.arange(-10000, 10000)

number_of_target_values = 0
hits = np.zeros_like(results)

t = 1000
for index, t in enumerate(results):
    print 't = ', t
    number_of_target_values = 0
    for x in numbers:
        if(t - x in numbers):
            if(2 * x == t):
                pass
            else:
                number_of_target_values += 1

    hits[index] = number_of_target_values


result = np.sum(hits != 0)
