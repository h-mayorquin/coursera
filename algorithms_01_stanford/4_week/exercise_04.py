import networkx as nx


# Construct the node
filename = 'SCC.txt'
DG = nx.DiGraph()

with open(filename) as f:
    for line in f:
        # Parse the line
        parsed_line = line.rsplit(' ')
        DG.add_edge(int(parsed_line[0]), int(parsed_line[1]))


# Add labels to the nodes equal to integers
for i in DG.nodes():
    DG.node[i]['label'] = i


DG_reverse = DG.reverse()

# ###
# Algorithm
####

s = None
explored = set()
leaders = {}
finishing_time = {}
aux = []
t = 0


def DFS(DG, node):
    global explored
    global t
    global leaders
    global s

    # Mark the node as explored
    explored.add(node)
    leaders[node] = s
    # Get the edges
    sucessors = DG.successors(node)
    for sucessor in sucessors:
        if sucessor not in explored:
            DFS(DG, sucessor)

    # Increased the time and makr finishing time
    t = t + 1
    finishing_time[node] = t
    aux.append(node)


for node, node_data in reversed(DG_reverse.nodes(data=True)):
    label = node_data['label']
    if node not in explored:
        s = label
        DFS(DG_reverse, node)

# Reverse the graph and calculate the leaders again


s2 = None
explored2 = set()
leaders2 = {}
finishing_time2 = {}
t2 = 0


def DFS2(DG_reverse, node):
    global explored2
    global t2
    global leaders2
    global s2

    # Mark the node as explored
    explored2.add(node)
    leaders2[node] = s2
    # Get the edges
    sucessors = DG_reverse.successors(node)
    for sucessor in sucessors:
        if sucessor not in explored2:
            DFS2(DG_reverse, sucessor)

    # Increased the time and makr finishing time
    t2 = t2 + 1
    finishing_time[node] = t2


print 'finishing times,', finishing_time
print 'aux list', aux
aux.reverse()

for node in aux:
    print node
    if node not in explored2:
        s2 = node
        print 's2', s2
        DFS2(DG, node)


correct = [x for x in nx.strongly_connected_components(DG)]
print 'explored order', explored2
print 'leaders', leaders2
print 'correct', correct
