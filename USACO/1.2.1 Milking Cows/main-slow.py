# 3
# 300 1000
# 700 1200
# 1500 2100
# 
# 900 300

def get_intervals():
    n = input()
    intervals = []
    for i in range(n):
       intervals.append(map(int, raw_input().split()))
    return intervals

# merge intv1 to intv2, if no overlap, return intv2
def merge(intv1, intv2):
    low1,high1 = intv1
    low2,high2 = intv2
    if low1 > high2 or low2 > high1: #no overlap
        return intv2
    else:
        new_low = min(low1, low2)
        new_high = max(high1, high2)
    return [new_low, new_high]

def merge_intervals(intervals):
    n = len(intervals)
    for i in range(n):
        for j in range(i+1, n):
            intervals[j] = merge(intervals[i], intervals[j])

def find_max_interval(intervals):
    n = len(intervals)
    max_interval = 0
    for i in range(n):
        interval = intervals[i][1] - intervals[i][0]
        if interval > max_interval:
            max_interval = interval
    return max_interval

def subtract(gaps, intv):
    for i in range(len(gaps)-1, -1, -1):
        low1,high1 = gaps[i]
        low2,high2 = intv
        if low1 > high2 or low2 > high1:
            continue
        elif low1 >= low2 and high1 <= high2:
            del gaps[i]
        elif low1 <= low2 and high1 <= high2:
            gaps[i][1] = low2
        elif low1 >= low2 and high1 >= high2:
            gaps[i][0] = high2
        else:
            gaps[i] = [low1, low2]
            gaps.append([high2, high1])

def find_max_gap(intervals):
    max_high = 0
    min_low = 1000000000000
    for low,high in intervals:
        if high > max_high:
            max_high = high
        if low < min_low:
            min_low = low

    gaps = [[min_low, max_high]]
    for intv in intervals:
        subtract(gaps, intv)

    max_gap = 0
    for low,high in gaps:
        gap = high - low
        if gap > max_gap:
            max_gap = gap
    return max_gap

intervals = get_intervals()
merge_intervals(intervals)
max_interval = find_max_interval(intervals)
max_gap = find_max_gap(intervals)

print max_interval, max_gap
