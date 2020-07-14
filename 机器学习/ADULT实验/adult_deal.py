import csv

less = hash('<=50K')
more = hash('>50K')
whitelist = [1,3,5,11,12,13]
with open("adult.csv", 'r') as f1, \
        open('adult_dealt.csv', 'w', newline='') as f2:
    reader = csv.reader(f1)
    writer = csv.writer(f2, dialect='excel')
    for row in reader:
        new_row = []
        idx = 0
        flag = True
        for s in row:
            s = s.strip()
            idx += 1
            HASH = hash(s)
            if s == "?":
                flag = False
                break
            else:
                if idx in whitelist:
                    new_row.append(int(s))
                    continue

                if HASH == less:
                    new_row.append(0)
                elif HASH == more:
                    new_row.append(1)
                else:
                    new_row.append(hash(s) % 10999997 / 100000)
        if flag:
            writer.writerow(new_row)
    pass
