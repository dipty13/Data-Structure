def basic_array():
    ar = [3, 2, 4, 5]

    ar.pop()

    ar.append(6)

    print(ar)
    print("Index of 4: ", ar.index(4))  # index of given value

    ar.remove(4)  # remove the first occurence of item with given value
    print("Removed 4: ", ar)

    ar.reverse()
    print("reversed: ", ar)
    print("sorted return: ", sorted(ar))

    ar.sort()
    print("sorted in place: ", ar)

if __name__=="__main__":
    basic_array()
