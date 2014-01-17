costs = {}
n = gets.chop.to_i
while true
    break if (line = gets) == nil
    u,v,cost = line.split.map(&:to_i)
    costs[[u,v]] = cost
end
sorted_costs = costs.sort_by(&:last)
#puts "sorted_costs #{sorted_costs}"

clusters = (1..n).map{|x| [x]}

while clusters.length > 4
    #puts "--\nclusters\n#{clusters}"
    (p, q), cost = sorted_costs.shift
    p_i = 0
    q_i = 0
    clusters.each_with_index do |c, i|
        if c.include? p
            p_i = i
        end
        if c.include? q
            q_i = i
        end
    end
    if p_i != q_i
        puts "Merge #{p_i}, #{q_i}"
        clusters[p_i] += clusters[q_i]
        clusters.delete_at q_i
    end
end

puts "#{clusters}"

which_cluster = {}
clusters.each_with_index do |c,i|
    c.each do |x|
        which_cluster[x] = i
    end
end

min_cost = 99999999

(1..n).each do |i|
    (i+1..n).each do |j|
        if which_cluster[i] != which_cluster[j]
            cost = costs[[i,j]]
            if cost != nil and cost < min_cost
                min_cost = cost
            end
        end
    end
end
puts min_cost
