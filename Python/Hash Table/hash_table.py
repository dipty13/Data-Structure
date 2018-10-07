class HashTable:
    HASH_MAX = 10

    class linkedList:
        data = None
        next = None
    hashTable = [1000]

    def Hashtable():
        i = 0
        while i <= HASH_MAX:
            HashTable.hashTable[i] = linkedList()
            HashTable.hashTable[i].linkedList.data = "empty"
            HashTable.hashTable[i].linkedList.next =  None
            i += 1

    def hashFunction(key):
        sum = 0
        for i in range(len(key)):
            sum += int(ord(key[i]))
        return sum % HashTable.HASH_MAX

    def insertItem(key):
        index = HashTable.hashFunction(key) -1
        print(index)
        if HashTable.hashTable[index].linkedList.data == "empty":
            HashTable.hashTable[index].linkedList.data = key
        else:
            tmp = HashTable.hashTable[index]
            x = HashTable.linkedList()
            x.linkedList.data = key
            x.linkedList.next = None
            while tmp.linkedList.next != None:
                tmp = tmp.linkedList.next

            tmp.linkedList.next = x


if __name__ == '__main__':
    HashTable.insertItem("John")
