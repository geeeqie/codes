from heapq import *
import re

n = 0

# 1	80,982	163,8164	170,2620	145,648	200,8021	173,2069	92,647	26,4122	140,546	11,1913	160,6461	27,7905	40,9047	150,2183	61,9146	159,7420	198,1724	114,508	104,6647	30,4612	99,2367	138,7896	169,8700	49,2437	125,2909	117,2597	55,6399	
Graph = {}

while True:
    edges = dict()
    n += 1
    try:
        for item in raw_input().split():
            m = re.match(r'(\d+),(-?\d+)', item)
            if m:
                v = int(m.group(1))
                distance = int(m.group(2))
                edges[v] = distance
            else:
                u = int(item)
        Graph[u] = edges
    except EOFError:
        break;

d = [1000000]*n
pi = [0]*n

def initialize_single_source(G, s):
    d[s] = 0

def extract_min(Q):
    vmin = 0
    dmin = 1000000
    for v in Q:
        if d[v] < dmin:
            dmin = d[v]
            vmin = v
    Q.remove(vmin)
    return vmin

def relax(G, u, v):
    if d[v] > d[u] + G[u][v]:
        d[v] = d[u] + G[u][v]
        pi[v] = u
    
def dijkstra(G, s):
    initialize_single_source(G, s)
    S = set()
    Q = G.keys()
    while len(Q) > 0:
        u = extract_min(Q)
        S.add(u)
        for v in G[u].keys():
            relax(G, u, v)

dijkstra(Graph, 1)
#print(map(lambda x:d[x], [7,37,59,82,99,115,133,165,188,197]))
print d
print pi
