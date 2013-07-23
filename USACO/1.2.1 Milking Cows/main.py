# 3
# 300 1000
# 700 1200
# 1500 2100
# 
# 900 300

n = input()
intervals = []
for i in range(n):
    intervals.append(map(int, raw_input().split()))
intervals.sort()
cur_low, cur_high = intervals[0]
max_interval = cur_high - cur_low
max_gap = 0
for low, high in intervals:
    if low > cur_high:
        if low - cur_high > max_gap:
            max_gap = low - cur_high
        cur_low = low
        cur_high = high
    else:
        if high > cur_high:
            cur_high = high

    if cur_high - cur_low > max_interval:
        max_interval = cur_high - cur_low

print max_interval, max_gap
