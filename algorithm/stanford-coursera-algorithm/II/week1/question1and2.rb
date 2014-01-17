#!/usr/bin/ruby
#
# Job Schedule problem
#

jobs = []
gets.chop.to_i.times do
    gets =~ /(\d+) (\d+)/
    jobs << {weight: $1.to_i,length: $2.to_i, diff:$1.to_f - $2.to_f}
end


total_length = 0
total_completion_time = 0

jobs.sort_by! do |j|
    [-j[:diff], -j[:weight],-j[:length]]
end

puts jobs

jobs.each do |job|
    total_length += job[:length]
    total_completion_time += total_length * job[:weight]
end

puts total_completion_time
