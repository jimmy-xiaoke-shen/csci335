import random


def quick_sort(a):
    if len(a) <= 1:
        return a
    idx = random.choice(range(len(a)))
    print(idx)
    pivot = a[idx]
    """
    left part is <= pivot
    right part is > pivot
    """
    left = [a[i] for i in range(len(a)) if a[i] <= pivot and i != idx]
    right = [a[i] for i in range(len(a)) if a[i] > pivot]
    return quick_sort(left) + [pivot] + quick_sort(right)


nums = [1, 2, -1, 100, 900, -11000]
print(quick_sort(nums))
