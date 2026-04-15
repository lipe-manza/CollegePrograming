import math

class Game:

    def __init__(self, *numbers):
        size = int(math.sqrt(len(numbers)))
        self.table = [[0]*size for _ in range(size)]

        count = 0
        for i in range(size):
            for j in range(size):
                self.table[i][j] = numbers[count]
                if numbers[count] == 0:
                    self.zeroI = i
                    self.zeroJ = j
                count += 1

    def getZeroI(self):
        return self.zeroI

    def getZeroJ(self):
        return self.zeroJ

    def upgradeZeroIJ(self, i, j):
        self.zeroI = i
        self.zeroJ = j

    def getTableSize(self):
        return len(self.table)

    def moveDown(self):
        i = self.getZeroI()
        j = self.getZeroJ()

        if i - 1 < 0:
            return

        self.table[i][j] = self.table[i - 1][j]
        self.table[i - 1][j] = 0

        self.upgradeZeroIJ(i - 1, j)

    def moveUp(self):
        i = self.getZeroI()
        j = self.getZeroJ()

        if i + 1 >= self.getTableSize():
            return

        self.table[i][j] = self.table[i + 1][j]
        self.table[i + 1][j] = 0

        self.upgradeZeroIJ(i + 1, j)

    def moveRight(self):
        i = self.getZeroI()
        j = self.getZeroJ()

        if j - 1 < 0:
            return

        self.table[i][j] = self.table[i][j - 1]
        self.table[i][j - 1] = 0

        self.upgradeZeroIJ(i, j - 1)

    def moveLeft(self):
        i = self.getZeroI()
        j = self.getZeroJ()

        if j + 1 >= self.getTableSize():
            return

        self.table[i][j] = self.table[i][j + 1]
        self.table[i][j + 1] = 0

        self.upgradeZeroIJ(i, j + 1)

    def printTable(self):
        size = self.getTableSize()
        border = "+------" * size + "+"

        for i in range(size):
            print(border)
            for j in range(size):
                if self.table[i][j] == 0:
                    print("|      ", end="")
                else:
                    print(f"|{self.table[i][j]:4d}  ", end="")
            print("|")
        print(border)
        print()

    def isSolved(self):
        count = 0
        for i in range(self.getTableSize()):
            for j in range(self.getTableSize()):
                if count != self.table[i][j]:
                    return False
                count += 1
        return True
