import networkx as nx
import matplolib.pyplot as plt

filename = 'SCC.txt'
DG = nx.DiGraph()

with open(filename) as f:
    for line in f:
        # Parse the line
        parsed_line = line.rsplit(' ')
        DG.add_edge(int(parsed_line[0]), int(parsed_line[1]))



