nrCoins = 1000
nrFlip = 10

nrTest = 100000

total_v_1 = 0
total_v_rand = 0
total_v_min = 0

nrTest.times do |i|
    coins = Array.new(nrCoins, 0)

    nrFlip.times do
        coins.each_with_index do |c, j|
            if [true, false].sample
                coins[j] += 1
            end
        end
    end

    v_1 = coins[0] / nrFlip.to_f
    v_rand = coins[rand(0...1000)] / nrFlip.to_f
    v_min = coins.min / nrFlip.to_f

    total_v_1 += v_1
    total_v_rand += v_rand
    total_v_min += v_min
    
    puts i
end

avg_v_1 = total_v_1 / nrTest.to_f
avg_v_rand = total_v_rand / nrTest.to_f
avg_v_min = total_v_min / nrTest.to_f

puts "#{avg_v_1}, #{avg_v_rand}, #{avg_v_min}"
