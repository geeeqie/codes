#!/usr/bin/ruby
#
# Prim Algorithm
#

graph = {}

nodes, edges = gets.split.map {|x| x.to_i}
edges.times do
#    [one_node_of_edge_1] [other_node_of_edge_1] [edge_1_cost]
    u, v, cost = gets.split.map{|x| x.to_i}
    graph[u] = [] if graph[u] == nil
    graph[u] << [v, cost]

    graph[v] = [] if graph[v] == nil
    graph[v] << [u, cost]
end

def deletemin(h, cost)
    min = h[0]
    min_cost = cost[min]
    h.each do |v|
        if cost[v] < min_cost
            min_cost = cost[v]
            min = v;
        end
    end

    h.delete min
    min
end

def prim(g)
    cost = {}
    prev = {}

    g.keys.each do |u|
        cost[u] = 12345678
        prev[u] = nil
    end
    cost[g.keys[0]] = 0
    h = g.keys
    while h.length > 0
        v = deletemin(h, cost)
        g[v].each do |z, w|
            if h.include? z and cost[z] > w
                cost[z] = w
                prev[z] = v
            end
        end
    end
    cost.values.reduce {|x,y| x+y}
end

puts prim(graph)
