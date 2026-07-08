import java.util.ArrayList;
import java.util.Collections;

public class GrafoMatrizAdjacencia extends Grafo {

  private final ArrayList<ArrayList<Boolean>> matriz;
  private final ArrayList<String> vertices;

  public GrafoMatrizAdjacencia() {
    this.matriz = new ArrayList<>();
    this.vertices = new ArrayList<>();
    this.numArestas = 0;
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

    for (ArrayList<Boolean> linha : matriz) {
      linha.add(false);
    }

    matriz.add(new ArrayList<>(Collections.nCopies(vertices.size(), false)));
  }

  @Override
  public void removerVertice(String vertice) {

    int i = indice(vertice);

    if (i == -1)
      return;

    numArestas -= grau(vertice);

    vertices.remove(i);

    for (ArrayList<Boolean> linha : matriz) {
      linha.remove(i);
    }

    matriz.remove(i);
  }

  @Override
  public void adicionarAresta(String origem, String destino) {

    if (indice(origem) == -1)
      adicionaVertice(origem);

    if (indice(destino) == -1)
      adicionaVertice(destino);

    int i = indice(origem);
    int j = indice(destino);

    if (!matriz.get(i).get(j)) {
      matriz.get(i).set(j, true);
      matriz.get(j).set(i, true);
      numArestas++;
    }
  }

  @Override
  public void removerAresta(String origem, String destino) {

    int i = indice(origem);
    int j = indice(destino);

    if (i == -1 || j == -1)
      return;

    // só remove se a aresta existir
    if (matriz.get(i).get(j)) {

      matriz.get(i).set(j, false);
      matriz.get(j).set(i, false);

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

    return matriz.get(i).get(j);
  }

  @Override
  public int grau(String vertice) {

    int i = indice(vertice);

    if (i == -1)
      return -1;

    int grau = 0;

    for (int j = 0; j < vertices.size(); j++) {
      if (matriz.get(i).get(j))
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

          boolean existeAresta = matriz.get(i).get(j);

          temAresta = true;

          if (!existeAresta)
            continue;

          String v1 = vertices.get(i);
          String v2 = vertices.get(j);

          if (v1.compareTo(v2) > 0) {
            String temp = v1;
            v1 = v2;
            v2 = temp;
          }

          arestas.add(
              "    \"" + v1 + "\" -- \"" + v2 + "\";");
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