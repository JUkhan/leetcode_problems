def merge(arr, l, m, h):
    left, right = arr[l:m + 1], arr[m + 1: h + 1]
    i, j, k = l, 0, 0
    while j < len(left) and k < len(right):
        if left[j] <= right[k]:
            arr[i] = left[j]
            j += 1
        else:
            arr[i] = right[k]
            k += 1
        i += 1
    while j < len(left):
        arr[i] = left[j]
        j += 1
        i += 1
    while k < len(right):
        arr[i] = right[k]
        k += 1
        i += 1


def mergeSort(arr, l, h):
    if l == h:
        return arr
    m = (l + h) // 2
    mergeSort(arr, l, m)
    mergeSort(arr, m + 1, h)
    merge(arr, l, m, h)
    return arr


print(mergeSort([5, 2, 8, 5], 0, 3))
