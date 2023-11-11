class data_struc:

    def __init__ (self, ch, num):
        self.ch = ch
        self.num = int(num)

    def setch(self, ch):
        self.ch = ch

    def setnum(self, num):
        self.num = num

def bubblesort(list, list_size):
    for index in range(list_size, 0, -1): #未ソート部分の選択
        for j in range(index):
            if list[j].num > list[j+1].num:
                tmp = list[j]
                list[j] = list[j+1]
                list[j+1] = tmp
            
            
    return list
    
def selection_sort(list, list_size):
    for i in range(list_size):
        minj = i 
        #iより先でi未満の最小値をみつける
        for j in range(i, list_size):
            if list[j].num < list[minj].num:
                minj = j
                
        if list[i].num != list[minj].num:
            tmp = list[i]
            list[i] = list[minj]
            list[minj] = tmp

    return list

def is_stable(stable_list, cmp_list):
    #直接文字列で'Stable'とかリターンしたいけど、そうすると勝手に改行が入っちゃうみたい
    for i in range(len(stable_list)):
        if stable_list[i].num != cmp_list[i].num or stable_list[i].ch != cmp_list[i].ch : return False
    return True
    

n = int(input())
mylist = list(input())

new_list = list(filter(lambda x: x != " ", mylist))

data_list = []
for i in range (0, len(new_list), 2):
    data_list.append(data_struc(new_list[i], new_list[i+1]))


bubble_list = bubblesort(data_list.copy(), len(data_list) - 1)
selection_list = selection_sort(data_list.copy(), len(data_list))

for i in range(len(data_list)):
    print(bubble_list[i].ch, end = '')
    if i != (len(data_list) - 1) : print(bubble_list[i].num, end = ' ')
    else :  print(bubble_list[i].num, end = '')

print()
print('Stable')

for i in range(len(data_list)):
    print(selection_list[i].ch, end = '')
    if i != (len(data_list) - 1) : print(selection_list[i].num, end = ' ')
    else : print(selection_list[i].num, end = '')

print()
if is_stable(bubble_list, selection_list) : print('Stable')
else : print('Not stable')
