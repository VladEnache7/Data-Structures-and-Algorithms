
class Bag:
    def __init__(self):
        self.__elements = []
        self.__curentIndex = 0

    @property
    def elements(self):
        return self.__elements

    def add(self, elementToBeAdded):
        self.__elements.append(elementToBeAdded)

    def remove(self, elementToBeRemoved):
        if elementToBeRemoved in self.__elements:
            self.__elements.remove(elementToBeRemoved)
            return True
        else:
            return False

    def search(self, elementToBeSearched):
        return elementToBeSearched in self.__elements

    def size(self):
        return len(self.__elements)

    def nrOccurrences(self, element):
        return self.__elements.count(element)

    def iterator(self, i):
        return BagIterator(self)

class BagIterator:
    def __init__(self, bag: Bag):
        if bag.size() == 0:
            raise ValueError
        self.__bag = bag
        self.__current = 0

    def valid(self):
        if self.__current < self.__bag.size():
            return True
        return False

    def first(self):
        self.__current = 0

    def next(self):
        if self.__current == self.__bag.size() - 1:
            raise ValueError
        self.__current += 1

    def getCurrent(self):
        if self.valid():
            return self.__bag.elements[self.__current]
        else:
            raise ValueError("Invalid index!")

def createIntBag():
    intBag = Bag()
    intBag.add(1)
    intBag.add(2)
    intBag.add(3)
    intBag.add(4)
    intBag.add(5)
    intBag.add(6)
    intBag.add(7)
    return intBag

def createStringBag():
    string



