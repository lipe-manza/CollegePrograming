import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        System.out.print("Semente: ");
        int seed = cin.nextInt();

        System.out.print("Saldo inicial: ");
        int saldoAtual = cin.nextInt();

        boolean flag = saldoAtual > 0;

        if (!flag) {
            System.out.println("Seu saldo acabou. Tente jogar outra vez.");
            cin.close();
            return;
        }

        cin.nextLine();

        Deck deck = new Deck(seed);
        Verificador verificar = new Verificador();

        while (flag) {
            deck.preencher();

            while (true) {
                System.out.println("Saldo atual: $" + saldoAtual);

                System.out.print("Digite o valor da aposta of 'F' para terminar ==> ");
                String entrada = cin.nextLine().trim();

                if (entrada.equalsIgnoreCase("F")) {
                    flag = false;
                    break;
                }

                int aposta;
                try {
                    aposta = Integer.parseInt(entrada);
                } catch (NumberFormatException e) {
                    System.out.println("Aposta inválida. Digite um valor numérico of 'F'.");
                    continue;
                }

                if (aposta > saldoAtual) {
                    System.out.println("Saldo insuficiente. Tecle enter para continuar");
                    cin.nextLine();
                    continue;
                }
                System.out.println();
                System.out.print(deck);

                saldoAtual -= aposta;

                for (int i = 0; i < 2; i++) {
                    System.out.println("Digite o número das cartas que você deseja trocar, separados por espaços: ");

                    String trocasStr = cin.nextLine().trim();

                    if (!trocasStr.isEmpty()) {
                        String[] partes = trocasStr.split("\\s+");
                        int[] trocas = new int[partes.length];

                        for (int j = 0; j < partes.length; j++) {
                            try {
                                trocas[j] = Integer.parseInt(partes[j]);
                            } catch (NumberFormatException e) {
                                trocas[j] = -1;
                            }
                        }

                        deck.trocar(trocas);
                    }
                    System.out.print(deck);
                }

                int ganho = verificar.calcularPremio(aposta, deck.getCartas());
                saldoAtual += ganho;

                if (ganho == 0) {
                    System.out.println("Peninha... não ganhou nada nessa rodada");
                } else {
                    System.out.println("Parabéns. Você acrescentou $" + ganho + " ao seu saldo");
                }

                System.out.println("Tecle enter para continuar");
                cin.nextLine();

                if (saldoAtual <= 0) {
                    flag = false;
                    break;
                }
                deck.finalizarRodada();
                break;
            }
        }

        if (saldoAtual <= 0)
            System.out.println("Seu saldo acabou. Tente jogar outra vez.");
        else
            System.out.println("Terminando o jogo... Parabéns você ainda tem saldo de $" + saldoAtual);
        
        cin.close();
    }
}