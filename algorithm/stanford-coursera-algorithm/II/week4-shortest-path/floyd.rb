#!/usr/bin/ruby
# n is the number of vertex
# m is the number of edge
Infinity = 9999999999
n, m = gets.split.map(&:to_i)
graph = Array.new(n) {Array.new(n, Infinity)}
m.times do
    u, v, dist = gets.split.map(&:to_i)
    graph[u-1][v-1] = dist
end

def floyd(g, n)
    d = Array.new(n) {Array.new(n, Infinity)}
    n.times do |i|
        n.times do |j|
            d[i][j] = g[i][j] if g[i][j] != Infinity
        end
    end

    n.times do |k|
        n.times do |i|
            n.times do |j|
                d[i][j] = [ d[i][j], d[i][k]+d[k][j] ].min
            end
        end
        puts "#{k}"
    end
    puts "#{d}"
end

floyd(graph, n)
