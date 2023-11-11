def insertion_sort(list):
    for i in range (0, len(list)):
        v = list[i]
        j = i - 1 #iのひとつまえからひかくして
        while j >= 0 and list[j] > v:
            list[j+1] = list[j] #比較対象よりも大きいものは、その隣までもっていく
            j -= 1 #比較対象より左側を見ていく
        list[j+1] = v #比較が終わったらj+1に格納、最後に入れ替えた値はj+1に保存されてる
        for k in range (0, len(list)):
            if k : print(' ', end = '')
            print(list[k], end = '')
            print()

length = int(input("n: ")) #配列の大きさ
#list = input("x: ").split()

list = [int(n) for n in input().split()]

insertion_sort(list)

            



