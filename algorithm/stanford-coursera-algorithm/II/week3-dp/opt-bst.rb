#p = [0,0.05,0.4,0.08,0.04,0.1,0.1,0.23]
p = [0, 0.2, 0.05, 0.17, 0.1, 0.2, 0.03, 0.25]
n = 7
$a = Array.new(n+2) {Array.new(n+2,0)}
(0..n-1).each do |s|
    (1..n).each do |i|
        if i+s <= n
            m = (i..(i+s)).map{|r| $a[i][r-1]+$a[r+1][i+s]}
            $a[i][i+s] = p[i..(i+s)].reduce(:+) + m.min
        end
    end
end
puts "#{$a}"
puts "#{$a[1][n]}"
