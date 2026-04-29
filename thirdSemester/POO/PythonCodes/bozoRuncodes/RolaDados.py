import random
from Dado import Dado

class RolaDados:
    def __init__(self, n, seed):
        self.dados = []
        rd = random.Random(seed)
        for _ in range(n):
            if seed != 0:
                self.dados.append(Dado(6, rd.randint(1, 10000)))
            else:
                self.dados.append(Dado())


    def rolar(self, arg=None):
        if arg is None:
            r = []
            for i in range(len(self.dados)):
                r.append(self.dados[i].rolar())
            return r

        if isinstance(arg, str):
            b = [False] * len(self.dados)

            for x in arg.split():
                if x.isdigit():
                    i = int(x) - 1
                    if 0 <= i < len(self.dados):
                        b[i] = True

            return self.rolar(b)

        if isinstance(arg, list):
            r = [0] * len(self.dados)
            i = 0

            for b in arg:
                if i >= len(self.dados):
                    break
                if b:
                    self.dados[i].rolar()
                r[i] = self.dados[i].getLado()
                i += 1

            return r

    def __str__(self):
        s = ""

        for i in range(5):
            base = i * 8
            for d in self.dados:
                p = str(d)
                s += p[base:base+7]
                s += "    "
            s += "\n"

        return s
