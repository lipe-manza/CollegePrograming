import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        GrafoListaAdjacencia grafoLista = new GrafoListaAdjacencia();
        GrafoMatrizAdjacencia grafoMatriz = new GrafoMatrizAdjacencia();
        GrafoPonderadoMatriz grafoPonderado = new GrafoPonderadoMatriz();

        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) {

            String linha = sc.nextLine().trim();

            if (linha.isEmpty())
                continue;

            String[] cmd = linha.split(" ");

            String op = cmd[0];

            switch (op) {

                // INSERIR ARESTA
                case "i": {

                    String v1 = cmd[1];
                    String v2 = cmd[2];
                    int peso = Integer.parseInt(cmd[3]);

                    grafoLista.adicionarAresta(v1, v2);

                    grafoMatriz.adicionarAresta(v1, v2);

                    grafoPonderado.adicionarAresta(v1, v2, peso);

                    break;
                }

                // REMOÇÃO
                case "d": {

                    if (cmd.length == 3) {
                        // remove aresta
                        String v1 = cmd[1];
                        String v2 = cmd[2];

                        grafoLista.removerAresta(v1, v2);
                        grafoMatriz.removerAresta(v1, v2);
                        grafoPonderado.removerAresta(v1, v2);
                    }

                    else if (cmd.length == 2) {
                        // remove vértice
                        String v = cmd[1];

                        grafoLista.removerVertice(v);
                        grafoMatriz.removerVertice(v);
                        grafoPonderado.removerVertice(v);
                    }

                    break;
                }

                // PRINT
                case "p": {

                    System.out.println("Lista de Adjacencia");
                    System.out.println(grafoLista.toString());

                    System.out.println("Matriz de Adjacencia");
                    System.out.println(grafoMatriz.toString());

                    System.out.println("Ponderado - Matriz de Adjacencia");
                    System.out.println(grafoPonderado.toString());

                    break;
                }
            }
        }

        sc.close();
    }
}
