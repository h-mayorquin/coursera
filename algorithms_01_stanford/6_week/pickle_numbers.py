filename = './data.txt'

numbers = set()

with open(filename) as f:
    for line in f:
        numbers.add(int(line))
