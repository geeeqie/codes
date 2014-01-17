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
    v = $w[0,0]*x[0] + $w[1,0]*x[1]
    if v > 0
        return 1
    elsif v == 0
        return 0
    else
        return -1
    end
end

def E_out()
    disagree = 0
    n = 1000
    n.times do
        p = randp
        if f(p) != g(p)
            disagree += 1
        end
    end
    return disagree / n.to_f
end

def E_in(x)
    count = 0
    x.each_with_index do |_x, i|
        count += 1 if g(_x) != f(_x)
    end
    count / x.length.to_f
end

require "matrix"

class Matrix
    def dagger
        (self.t*self).inverse * self.t
    end
end
###################

N = 100
NTEST=1000

total_Ein = 0.0
total_Eout = 0.0

(1..NTEST).each do |i|
    $a,$b = ab(randp, randp)

    x = Array.new(N) {randp}
    y = x.map {|p| [f(p)]}
    _X = Matrix.rows(x)
    _Y = Matrix.rows(y)
    $w = _X.dagger * _Y
    total_Ein += E_in(x)
    total_Eout += E_out()
end

puts "E_in = #{total_Ein / NTEST}"
puts "E_out = #{total_Eout / NTEST}"
