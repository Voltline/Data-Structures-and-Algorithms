from random import *
import time as t

def bubble_sort(nums):
    for i in range(len(nums) - 1):  # 这个循环负责设置冒泡排序进行的次数
        for j in range(len(nums) - i - 1):  # j为列表下标
            if nums[j] > nums[j + 1]:
                nums[j], nums[j + 1] = nums[j + 1], nums[j]
    return nums

def QSort(array):
    if len(array) <= 1:
        return array
    else:
        pivot = array[0]
        left = []
        mid = []
        right = []
        for i in array:
            if i < pivot:
                left.append(i)
            elif i > pivot:
                right.append(i)
            else:
                mid.append(i)
        return QSort(left) + mid + QSort(right)

nums = [randint(0, 10000) for i in range(10000)]

s1 = t.time()
QSort(nums)
s2 =t.time()
print(s2-s1)

print("--------")

s1 = t.time()
bubble_sort(nums)
s2 =t.time()
print(s2-s1)
    
