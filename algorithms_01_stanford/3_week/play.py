import networkx as nx

# First we read the file
filename = 'kargerMinCut.txt'
with open(filename) as f:
    content = f.readlines()


# Now we get every line and create the graph
graph_list = []
for line in content:
    # Parse the line
    line = line.rstrip('\r\n')
    parsed_line = str.split(line, '\t')
    graph_list.append(parsed_line)


# Intiliaze the graphs
graph = nx.Graph()

# Fill the graph nodes
for node_connections in graph_list:
    # Get the node
    node = int(node_connections[0])
    for connect_to in node_connections:
        if connect_to != '':
             aux = int(connect_to)
             if aux != node:
                 graph.add_edge(node, aux )


# Calculate the minimal cut
minimal_cut = nx.algorithms.minimum_edge_cut(graph)
print minimal_cut
print 'Number of minimal cut', len(minimal_cut)
