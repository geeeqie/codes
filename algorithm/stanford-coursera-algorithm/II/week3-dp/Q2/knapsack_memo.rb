knapsack_size, number_of_items = gets.split.map{|x| x.to_i}
$v = [0]
$w = [0]
number_of_items.times do
    value, weight = gets.split.map {|x| x.to_i}
    $v << value
    $w << weight
end

puts "read done!"

$a_cache = {}
def a(i, x)
    return 0 if i == 0
    ret = $a_cache[[i,x]]
    return ret if ret != nil
    if $w[i] <= x
        ret = [ a(i-1,x), a(i-1, x-$w[i])+$v[i] ].max
    else
        ret = a(i-1,x)
    end
    $a_cache[[i, x]] = ret
    return ret
end

puts a(number_of_items, knapsack_size)
