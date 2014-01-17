def randp()
    [rand(-1.0..1.0), rand(-1.0..1.0)]
end

def ab(p1, p2)
    x1 = p1[0]
    y1 = p1[1]
    x2 = p2[0]
    y2 = p2[1]
    a = (y2 - y1) / (x2 - x1)
    b = y1 - a*x1
    [a,b]
end

def f(p)
    px = p[0]
    py = p[1]
    if py > $a*px + $b
        return 1
    elsif py == $a*px + $b
        return 0
    else
        return -1
    end
end

def g(x)
    v = $w[0]*1 + $w[1]*x[0] + $w[2]*x[1]
    if v > 0
        return 1
    elsif v == 0
        return 0
    else
        return -1
    end
end

def update_w(x, y)
    $w[0] += y
    $w[1] += y * x[0]
    $w[2] += y * x[1]
end

def disagreement()
    disagree = 0
    1000.times do
        p = randp
        if f(p) != g(p)
            disagree += 1
        end
    end
    return disagree / 1000.0
end
###################

N = 10
NTEST=1000

total_count = 0
total_disagree = 0
(1..NTEST).each do |i|
    xset = Array.new(N) {randp}
    $a,$b = ab(randp, randp)
    $w = [0.0, 0.0, 0.0]
    count = 0
    while true
        count += 1

        missclassfied_points = Array.new
        xset.each do |x|
            if f(x) != g(x)
                missclassfied_points << x
            end
        end

        x = missclassfied_points.sample

        if x != nil
            update_w(x, f(x))
        else
            break
        end
#        puts "w = #{$w}"
    end
    puts "[#{i}] count = #{count}"
    total_count += count
    
    dis = disagreement()
    puts "disagreement = #{dis}"
    total_disagree += dis

end

puts "avg_count = #{total_count/NTEST.to_f}"
puts "avg_disagreement = #{total_disagree/NTEST.to_f}"

