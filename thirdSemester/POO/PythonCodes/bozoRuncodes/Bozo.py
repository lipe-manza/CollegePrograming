if __name__ == "__main__":

        print("Digite a semente (zero para aleatório): ")
        seed = int(input())

        RolaDados rd = RolaDados(5, seed)
        Placar pl = Placar()
        for i in range(0,10):
            print(f"****** Rodada {i + 1}")
            EntradaTeclado.leString()
            print("Digite os dados que deseja manter (ex: 1 3 5): ")
            dadosManter = input()
            # Aqui você pode implementar a lógica para manter os dados selecionados e rolar novamente os outros
