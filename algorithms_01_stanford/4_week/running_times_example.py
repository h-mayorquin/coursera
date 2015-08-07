import networkx as nx
import matplotlib.pyplot as plt

###
# Some functions
###

###
# The program
###


plot = True
DG = nx.DiGraph()

# Construct the edges
DG.add_edge(1, 7)
DG.add_edge(7, 4)
DG.add_edge(4, 1)

DG.add_edge(7, 9)

DG.add_edge(9, 6)
DG.add_edge(6, 3)
DG.add_edge(3, 9)

DG.add_edge(6, 8)

DG.add_edge(8, 2)
DG.add_edge(2, 5)
DG.add_edge(5, 8)


# Add labels to the nodes equal to integers
for i in DG.nodes():
    DG.node[i]['label'] = i


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


for node, node_data in reversed(DG.nodes(data=True)):
    label = node_data['label']
    if node not in explored:
        s = label
        DFS(DG, node)

verbose = False
if verbose:
    print 'explored', explored
    print 'leaders', leaders
    print 'finishing_time', finishing_time
    print 't', t
    print 's', s


# Reverse the graph and calculate the leaders again
DG_reverse = DG.reverse()

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
        DFS2(DG_reverse, node)


correct = [x for x in nx.strongly_connected_components(DG_reverse)]
print 'explored order', explored2
print 'leaders', leaders2
print 'correct', correct


plot = False
if plot:
    pos = nx.spring_layout(DG_reverse)
    nx.draw_networkx(DG_reverse, pos)
    nx.draw_networkx_labels(DG_reverse, pos)
    plt.axis('off')
    plt.show()


