import random

def test_sorting(func, tests=10000):
    for num in range(tests):
        rand_arr = random.sample(range(0, 1000), 14)
        res = func(rand_arr)
        test = sorted(rand_arr)
        if res != test: 
            print(f"unsorted: {rand_arr}\nsorted:   {res}\n\ncorrect: {test}\n{'-'*50}")

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def selection_sort(arr):
    # Por cada posicion del array
    for i, _ in enumerate(arr):
        # Encontrar menor elemento en una posicion mayor
        min_pos = arr.index(min(arr[i:]))
        # Intercambiar elemento mayor con elemento menor
        swap(arr, i, min_pos)
    return arr

def insertion_sort(arr):
    # Por cada posicion del array
    for i in range(1, len(arr)):
        j = i
        # Mientras el elemento anterior sea mayor
        while j > 0 and arr[j-1] > arr[j]:
            # Intercambiar con elemento anterior
            swap(arr, j, j-1)
            # Reducir elemento
            j = j-1
    return arr

def merge_sort(arr):
    length = len(arr)
    if length == 1:
        return arr
    piv = length // 2
    left = merge_sort(arr[:piv])
    right = merge_sort(arr[piv:])
    res = merge(left, right)
    print(f"array: {arr}\nleft: {arr[:piv]}\nright: {arr[piv:]}\nmerge: {res}\n{'-'*50}")
    return res

def merge(left, right):
    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

if __name__ == "__main__":
    #test_sorting(selection_sort)
    #test_sorting(insertion_sort)
    test_sorting(merge_sort, tests=1)
