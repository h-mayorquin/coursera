import heapq

filename = './Median.txt'

heap = 0
numbers = []

with open(filename) as f:
    for line in f:
        numbers.append(int(line))

