class Node:
    data = None
    next = None
    head = None
    tmp = None
    new_node = None

    def insert_elements(n):
        new_node = Node()
        if Node.head == None:
            new_node.data = n
            Node.head = new_node
            Node.tmp = new_node
        else:
            new_node.data = n
            Node.tmp.next = new_node
            Node.tmp = Node.tmp.next

    def print_elements():
        currentNode = Node.head;
        while currentNode != None:
            print(currentNode.data)
            currentNode = currentNode.next
    """
    adds element to the front of the list
    Time Complexity: O(1)
    """
    def pushFront(n):
        currentNode = Node()
        currentNode.data = n
        currentNode.next = Node.head
        Node.head = currentNode

    """
    adds element to the end of the list
    Time Complexity: O(1)
    """
    def pushBack(n):
        currentNode = Node()
        currentNode.data = n
        Node.tmp.next = currentNode
        Node.tmp = Node.tmp.next
    """
    returns data of first element
    Time complexity: O(1)
    """
    def topFront():
        return Node.head.data;
    """
    removes first element from the list
    Time complexity: O(1)
    """
    def popFront():
        currentNode = Node.head
        Node.head = currentNode.next
    """
    find element from the list
    return true or false depending on
    whether the element is in the list or not
    Time complexity: O(n)
    """
    def find(value):
        currentNode = Node.head
        while currentNode.next != None:
            if currentNode.data == value:
                return True
            currentNode = currentNode.next
        return False


if __name__ == '__main__':
    Node.insert_elements(2)
    Node.insert_elements(4)
    Node.insert_elements(1)
    Node.print_elements()
    Node.pushFront(90)
    print("After pushFront() call: ")
    Node.print_elements()
    Node.pushBack(20)
    print("After pushBack() call: ")
    Node.print_elements()
    print("Top element of the list: ", Node.topFront())
    Node.popFront()
    print("After popFront() call: ")
    Node.print_elements()
    if Node.find(22):
        print("Found the value")
    else:
        print("Didn't find the value")
