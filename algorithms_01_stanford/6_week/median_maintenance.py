import heapq

filename = './Median.txt'

heap = 0
numbers = []

with open(filename) as f:
    for line in f:
        numbers.append(int(line))


k = 10
heap_min = []
heap_max = []

# Initialize
numbers_init = numbers[0:2]
numbers_init.sort
print numbers_init
# Put to heap max
heapq.heappush(heap_max, -numbers_init[1])
# Put to heap-min
heapq.heappush(heap_min, numbers_init[0])

# Rest of the algorithm
numbers_test = numbers[2:k]
sorted_test = numbers[:k]
sorted_test.sort()

for index, number in enumerate(numbers_test):
    Hmin = heapq.heappop(heap_min)
    Hmax = -heapq.heappop(heap_max)

    # Put to heap max
    heapq.heappush(heap_max, -Hmax)
    # Put to heap-min
    heapq.heappush(heap_min, Hmin)

    print 'number', number
    print 'Hmax', Hmax
    print 'Hmin', Hmin

    if(number < Hmax):
        print 'to heap max'
        # Put to heap max
        heapq.heappush(heap_max, -number)
    elif(number > Hmin):
        print 'to heap min'
        # Put to heap-min
        heapq.heappush(heap_min, number)
    else:
        print 'Send to the middle'
        if(len(heap_min) < len(heap_max)):
            heapq.heappush(heap_min, number)
        else:
            heapq.heappush(heap_max, -number)

    print 'Hmax, Hmin', Hmax, Hmin
    print 'test', numbers[0:k]
    aux = numbers[:index + 3]
    print 'in test so far', aux
    aux.sort()
    print 'sort so far', aux
    print 'len max and len min', len(heap_max), len(heap_min)
    print '----------------------'

