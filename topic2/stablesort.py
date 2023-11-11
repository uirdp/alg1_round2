mylist = list(input())
new_list = list(filter(lambda x: x != " ", mylist))


for i in range (len(new_list)):
    if i%2 != 0 : new_list[i] = int(new_list[i])

for i in range (len(new_list)):
    if i%2 != 0 : continue 
    for j in range (len(new_list) - 1, i+2, -1):
        if new_list[j] < new_list[j-2]:
            tmp = new_list[j]
            new_list[j] = new_list[j-2]
            new_list[j-2] = tmp

print(new_list)