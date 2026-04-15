from game import Game


def main():
    try:

        linha = input().strip()
        partes = linha.split()

        nums = [int(x) for x in partes]

        table = Game(*nums)
        table.printTable()


        try:
            linha = input().strip()

            for c in linha:
                if c == 'u':
                    table.moveUp()
                elif c == 'd':
                    table.moveDown()
                elif c == 'l':
                    table.moveLeft()
                elif c == 'r':
                    table.moveRight()
                else:
                    print(f"Comando invalido: {c}")

                table.printTable()

        except EOFError:
            pass  

        print("Posicao final:", table.isSolved())

    except Exception as e:
        print("An error occurred:", e)


if __name__ == "__main__":
    main()
