import networkx as nx
#  import matplotlib.pyplot as plt

### 
#  Load the Graph
### 

filename = 'dijkstraData.txt'
DG = nx.DiGraph()

with open(filename) as f:
    for line in f:
        # Parse the line
        parsed_line = line.rsplit('\t')
        node_from = int(parsed_line.pop(0))
        # Get rid of the line element
        parsed_line.pop()
        for node_weight in parsed_line:
            node_to = int(node_weight.rsplit(',')[0])
            weight = int(node_weight.rsplit(',')[1])
            DG.add_edge(node_from, node_to, weight=weight)
        

### 
# Dijkstra algorithm
### 

total_nodes = set(DG.nodes())

source = 1
X = set()
A = {i : 0 for i in range(DG.number_of_nodes() + 1)}
# A = [0] * (DG.number_of_nodes() + 1)
X.add(source)  # Nodes already calculated
Y = total_nodes.difference(X)

while(X != total_nodes):
    print 'X has size', len(X)
    print 'Y has size', len(Y)
    print 'Total number of nodes', len(total_nodes)
    aux = []
    for v in X:
        for w in Y:
            if w in DG.neighbors(v):
                score = A[v] + DG[v][w]['weight']
                aux.append((score, v, w))

    score_start, v_star, w_star = min(aux)

    X.add(w_star)
    A[w_star] = score_start
    Y = total_nodes.difference(X)


# This is the one by nx
correct =  nx.single_source_dijkstra_path_length(DG, source)

# Print the result
print 'Result'
print A[7], A[37], A[59],A[82], A[99], A[115],A[133],A[165], A[188], A[197]

