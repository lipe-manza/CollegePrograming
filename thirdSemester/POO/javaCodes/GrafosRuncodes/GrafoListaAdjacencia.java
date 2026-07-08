import java.util.*;

public class GrafoListaAdjacencia extends Grafo {

    private final Map<String, LinkedList<String>> listaAdjacencia;

    public GrafoListaAdjacencia() {
        this.listaAdjacencia = new TreeMap<>();
        this.numArestas = 0;
    }

    @Override
    public void adicionaVertice(String vertice) {
        if (!listaAdjacencia.containsKey(vertice)) {
            listaAdjacencia.put(vertice, new LinkedList<>());
        }
    }

    @Override
    public void removerVertice(String vertice) {

        if (!listaAdjacencia.containsKey(vertice))
            return;

        LinkedList<String> vizinhos = listaAdjacencia.get(vertice);

        int removidas = vizinhos.size();

        for (String v : vizinhos) {
            listaAdjacencia.get(v).remove(vertice);
        }

        numArestas -= removidas;

        listaAdjacencia.remove(vertice);
    }

    @Override
    public void adicionarAresta(String origem, String destino) {

        adicionaVertice(origem);
        adicionaVertice(destino);

        if (!listaAdjacencia.get(origem).contains(destino)) {

            listaAdjacencia.get(origem).add(destino);
            listaAdjacencia.get(destino).add(origem);

            numArestas++;
        }
    }

    @Override
    public void removerAresta(String origem, String destino) {

        if (!existeAresta(origem, destino))
            return;

        listaAdjacencia.get(origem).remove(destino);
        listaAdjacencia.get(destino).remove(origem);

        numArestas--;
    }

    @Override
    public boolean existeVertice(String vertice) {
        return listaAdjacencia.containsKey(vertice);
    }

    @Override
    public boolean existeAresta(String origem, String destino) {

        if (!existeVertice(origem) || !existeVertice(destino))
            return false;

        return listaAdjacencia.get(origem).contains(destino);
    }

    @Override
    public int grau(String vertice) {

        if (!existeVertice(vertice))
            return -1;

        return listaAdjacencia.get(vertice).size();
    }

    @Override
    public int ordem() {
        return listaAdjacencia.size();
    }

    @Override
    public int tamanho() {
        return numArestas;
    }

    @Override
    public String toString() {

        ArrayList<String> isolados = new ArrayList<>();
        ArrayList<String> arestas = new ArrayList<>();

        for (Map.Entry<String, LinkedList<String>> entry : listaAdjacencia.entrySet()) {

            String v1 = entry.getKey();

            if (entry.getValue().isEmpty()) {
                isolados.add("    \"" + v1 + "\";");
            }

            for (String v2 : entry.getValue()) {

                if (v1.compareTo(v2) < 0) {
                    arestas.add("    \"" + v1 + "\" -- \"" + v2 + "\";");
                }
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