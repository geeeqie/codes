# USACO 1.1.2

money = {}
name_list = []
np = input()
for i in range(np):
    name = raw_input().strip()
    name_list.append(name)
    money[name] = 0

for i in range(len(name_list)):
    name = raw_input().strip()
    origin_money, n_receive_gift = map(int, raw_input().split())
    if n_receive_gift > 0:
        give_money = origin_money//n_receive_gift
        money[name] += - give_money*n_receive_gift
        for i in range(n_receive_gift):
            name = raw_input().strip()
            money[name] += give_money

for name in name_list:
    print "%s %d" % (name,money[name])
