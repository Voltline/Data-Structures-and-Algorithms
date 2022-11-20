from cmath import cos
from collections import deque
from concurrent.futures import process
from hashlib import new
from operator import ne
from tokenize import group

from sklearn import neighbors
graph = {}
costs = {}
parents = {}
graph['start'] = {}
graph['start']["a"] = 5
graph['start']["b"] = 2
graph["a"] = {}
graph["a"]["c"] = 2
graph["a"]["d"] = 4
graph["b"] = {}
graph["b"]["a"] = 8
graph["b"]["c"] = 7
graph["c"] = {}
graph["c"]["fin"] = 1
graph["d"] = {}
graph["d"]["c"] = 6
graph["d"]["fin"] = 3

graph["fin"] = {}

costs["a"] = 5
costs["b"] = 2
costs["c"] = float("inf")
costs["d"] = float("inf")
costs["fin"] = float("inf")

parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["c"] = None
parents["d"] = None
parents["fin"] = None

def find_lowest_cost_node(costs : dict):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for i in costs:
        if costs[i] < lowest_cost and i not in processed:
            lowest_cost = costs[i]
            lowest_cost_node = i
    return lowest_cost_node
processed = []
node = find_lowest_cost_node(costs)
while node is not None:
    cost = costs[node]
    neighbors = graph[node]
    print("现在的节点为", node)
    for n in neighbors.keys():
        new_cost = cost + neighbors[n]
        if costs[n] > new_cost:
            costs[n] = new_cost
            parents[n] = node
    processed.append(node)
    node = find_lowest_cost_node(costs)

print(costs)
print(parents)