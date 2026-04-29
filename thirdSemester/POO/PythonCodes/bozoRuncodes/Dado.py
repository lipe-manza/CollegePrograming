import random

class Dado:
    def __init__(self, n=6, seed=None):
        self.lados = n
        self.r = random.Random(seed) if seed is not None else random.Random()
        self.rolar()

    def rolar(self):
        self.atual = self.r.randint(1, self.lados)
        return self.atual

    def getLado(self):
        return self.atual

    def __str__(self):
        if self.lados != 6:
            return "Não há representação para esse dados"

        s010 = "|  *  |\n"
        s100 = "|*    |\n"
        s001 = "|    *|\n"
        s000 = "|     |\n"
        s101 = "|*   *|\n"
        s111 = "|* * *|\n"

        s = "+-----+\n"

        lado = self.getLado()

        if lado == 1:
            s += s000 + s010 + s000
        elif lado == 2:
            s += s100 + s000 + s001
        elif lado == 3:
            s += s100 + s010 + s001
        elif lado == 4:
            s += s101 + s000 + s101
        elif lado == 5:
            s += s101 + s010 + s101
        elif lado == 6:
            s += s111 + s000 + s111

        s += "+-----+\n"
        return s



