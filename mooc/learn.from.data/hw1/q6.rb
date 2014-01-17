x_out = [[1,0,1], [1,1,0], [1,1,1]]
hypo = [
    [0,0,0],
    [0,0,1],
    [0,1,0],
    [0,1,1],
    [1,0,0],
    [1,0,1],
    [1,1,0],
    [1,1,1],
]
def fa(x1,x2,x3)
    1
end
def fb(x1,x2,x3)
    0
end
def fc(x1,x2,x3)
    x1^x2^x3
end
def fd(x1,x2,x3)
    x1^x2^x3^1
end

func = [:fa, :fb, :fc, :fd]

func.each do |f|
    l = hypo.map do |h|
        xs = x_out.collect { |x| method(f).call(*x)}
        h.zip(xs).count {|z| z.first == z.last}
    end
    puts l.reduce(&:+)
    puts "--"
end
