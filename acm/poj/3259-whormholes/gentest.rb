#!/usr/bin/ruby
F = 5
N = 500
M = 2500
W = 5
MAX = 10000
puts F
F.times do
    puts "#{N} #{M} #{W}"
    M.times do
        puts "#{1+rand(N)} #{1+rand(N)} #{1+rand(MAX)}"
    end
    W.times do
        puts "#{1+rand(N)} #{1+rand(N)} #{1+rand(MAX)}"
    end
end
