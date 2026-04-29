from Dado import Dado
from RolaDados import RolaDados
from Placar import Placar

if __name__ == "__main__":

    print("Digite a semente (zero para aleatório): ", end="")
    seed = int(input())

    rd = RolaDados(5, seed)
    pl = Placar()

    print(pl)

    for i in range(10):
        print(f"****** Rodada {i + 1}")
        print("Pressione ENTER para lançar os dados")
        input()

        # 1ª rolagem
        rd.rolar()
        print("1          2          3          4          5")
        print(rd)

        # 2ª rolagem
        print("Digite os números dos dados que quiser TROCAR. Separados por espaços.")
        muda = input()
        rd.rolar(muda)
        print("1          2          3          4          5")
        print(rd)

        # 3ª rolagem
        print("Digite os números dos dados que quiser TROCAR. Separados por espaços.")
        muda = input()
        valores = rd.rolar(muda)
        print("1          2          3          4          5")
        print(rd)

        print("\n\n")
        print(pl)

        while True:
            try:
                print("Escolha a posição que quer ocupar com essa jogada ===> ", end="")
                pos = int(input())

                if pos < 1 or pos > 10:
                    raise ValueError()

                pl.add(pos, valores)
                break

            except:
                print("Valor inválido. Posição ocupada ou inexistente.")

        print("\n\n")
        print(pl)

    print("***********************************")
    print("***")
    print(f"*** Seu escore final foi: {pl.getScore()}")
    print("***")
    print("***********************************")
