import java.util.ArrayList;
import java.util.Collections;

public class GrafoPonderadoMatriz extends Grafo {

    private final ArrayList<ArrayList<Integer>> matriz;
    private final ArrayList<String> vertices;

    public GrafoPonderadoMatriz() {
        this.matriz = new ArrayList<>();
        this.vertices = new ArrayList<>();
        numArestas = 0;
    }

    private int indice(String vertice) {
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices.get(i).equals(vertice)) {
                return i;
            }
        }
        return -1;
    }

    @Override
    public void adicionaVertice(String vertice) {
        if (indice(vertice) != -1)
            return;

        vertices.add(vertice);

        for (ArrayList<Integer> linha : matriz) {
            linha.add(0);
        }

        matriz.add(new ArrayList<>(Collections.nCopies(vertices.size(), 0)));
    }

    @Override
    public void removerVertice(String vertice) {

        int i = indice(vertice);

        if (i == -1)
            return;

        numArestas -= grau(vertice);

        vertices.remove(i);

        for (ArrayList<Integer> linha : matriz) {
            linha.remove(i);
        }

        matriz.remove(i);
    }

    @Override
    public void adicionarAresta(String origem, String destino) {
        adicionarAresta(origem, destino, 1);
    }

    public void adicionarAresta(String origem, String destino, int peso) {

        if (indice(origem) == -1)
            adicionaVertice(origem);

        if (indice(destino) == -1)
            adicionaVertice(destino);

        int i = indice(origem);
        int j = indice(destino);

        if (matriz.get(i).get(j) == 0) {
            numArestas++;
        }

        matriz.get(i).set(j, peso);
        matriz.get(j).set(i, peso);
    }

    @Override
    public void removerAresta(String origem, String destino) {

        int i = indice(origem);
        int j = indice(destino);

        if (i == -1 || j == -1)
            return;

        if (matriz.get(i).get(j) != 0) {
            matriz.get(i).set(j, 0);
            matriz.get(j).set(i, 0);
            numArestas--;
        }
    }

    @Override
    public boolean existeVertice(String vertice) {
        return indice(vertice) != -1;
    }

    @Override
    public boolean existeAresta(String origem, String destino) {

        int i = indice(origem);
        int j = indice(destino);

        if (i == -1 || j == -1)
            return false;

        return matriz.get(i).get(j) != 0;
    }

    @Override
    public int grau(String vertice) {

        int i = indice(vertice);

        if (i == -1)
            return -1;

        int grau = 0;

        for (int j = 0; j < vertices.size(); j++) {
            if (matriz.get(i).get(j) != 0)
                grau++;
        }

        return grau;
    }

    @Override
    public int ordem() {
        return vertices.size();
    }

    @Override
    public int tamanho() {
        return numArestas;
    }

    @Override
    public String toString() {

        ArrayList<String> isolados = new ArrayList<>();
        ArrayList<String> arestas = new ArrayList<>();

        for (int i = 0; i < vertices.size(); i++) {

            boolean temAresta = false;

            for (int j = i; j < vertices.size(); j++) {

                int grau = grau(vertices.get(i));

                if (grau > 0) {
                    int peso = matriz.get(i).get(j);

                    temAresta = true;
                    
                    if (peso == 0)
                        continue;
                    

                    String v1 = vertices.get(i);
                    String v2 = vertices.get(j);

                    if (v1.compareTo(v2) > 0) {
                        String temp = v1;
                        v1 = v2;
                        v2 = temp;
                    }

                    arestas.add(
                            "    \"" + v1 + "\" -- \"" + v2 +
                                    "\" [label=\"" + peso + "\"];");
                }
            }

            if (!temAresta) {
                isolados.add("    \"" + vertices.get(i) + "\";");
            }
        }

        Collections.sort(isolados);
        Collections.sort(arestas);

        StringBuilder sb = new StringBuilder();
        sb.append("graph {\n");

        for (String v : isolados)
            sb.append(v).append("\n");

        for (String a : arestas)
            sb.append(a).append("\n");

        sb.append("}");

        return sb.toString();
    }
}