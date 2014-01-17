n, m = gets.split.map {|x| x.to_i}
bitmap = []
n.times do
    bitmap << gets.split.map(&:to_i)
end
puts "read done!"

####
# Union-find

$parent = {}
$rank = {}

def makeset(x)
    $parent[x] = x
    $rank[x] = 0
end

def union(x, y)
    rx = find(x)
    ry = find(y)
    return if rx == ry
    if $rank[rx] > $rank[ry]
        $parent[ry] = rx
    else
        $parent[rx] = ry
        $rank[ry]+=1 if $rank[rx]==$rank[ry]
    end
end

def find(x)
    if x != $parent[x]
        $parent[x] = find($parent[x]) 
    end
    return $parent[x]
end

def count()
    c = 0
    $parent.each do |k, v|
        c += 1 if k == v
    end
    return c
end
###

(0..n-1).each {|x| makeset(x) }

dict = {}

# merge vertex with distance = 0
bitmap.each_with_index do |bits, i|
    if dict[bits] == nil
        dict[bits] = i
    else
        union(i, dict[bits])
    end
end

# merge vertex with distance = 1
bitmap.each_with_index do |bits, i|
    (0..m-1).each do |j|
        bits[j] ^= 1
        if dict[bits] != nil
            union(i, dict[bits])
        end
        bits[j] ^= 1
    end
end

# merge vertex with distance = 2
bitmap.each_with_index do |bits, i|
    (0..m-1).each do |j|
        bits[j] ^= 1
        (j+1..m-1).each do |k|
            bits[k] ^= 1
            if dict[bits] != nil
                union(i, dict[bits])
            end
            bits[k] ^= 1
        end
        bits[j] ^= 1
    end
end

puts "#{$parent}"
puts count()
