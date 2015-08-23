import numpy as np

filename = './Median.txt'

heap = 0
numbers = []

with open(filename) as f:
    for line in f:
        numbers.append(int(line))

k = 10
aux = numbers[0:k]
aux = numbers
limit = len(numbers)
medians = np.zeros(limit)
verbose = False


for index, number in enumerate(aux):
    print 'index', index
    print 'Limit', limit
    numbers_so_far = numbers[:index + 1]
    numbers_so_far.sort(reverse=False)
    if (len(numbers_so_far) % 2 == 0):
        median = numbers_so_far[(index + 0) / 2]
    else:
        median = numbers_so_far[(index + 1) / 2]

    medians[index] = median
    if verbose:
        print numbers_so_far
        print 'median', median
        print '--------------------'


result = medians.sum() % 10000
print 'result', result
