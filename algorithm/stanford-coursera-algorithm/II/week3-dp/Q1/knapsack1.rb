knapsack_size, number_of_items = gets.split.map{|x| x.to_i}
v = [0]
w = [0]
number_of_items.times do
    value, weight = gets.split.map {|x| x.to_i}
    v << value
    w << weight
end

puts "read done!"

a = Array.new(number_of_items+1) {Array.new(knapsack_size+1,0)}

puts "Array a[][] done!"

(1..number_of_items).each do |i|
    (0..knapsack_size).each do |x|
        if w[i] > x
            a[i][x] = a[i-1][x]
        else
            a[i][x] = [ a[i-1][x], a[i-1][x-w[i]]+v[i] ].max
        end
    end
end

puts a[number_of_items][knapsack_size]
