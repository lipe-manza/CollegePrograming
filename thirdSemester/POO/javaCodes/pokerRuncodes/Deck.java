import java.util.ArrayList;
import java.util.Arrays;

public class Deck {
    private Baralho baralho;
    private Cartas[] mao;
    private ArrayList<Cartas> descartes;

    public Deck(int seed) {
        this.baralho = new Baralho(seed);
        this.mao = new Cartas[5];
        this.descartes = new ArrayList<>();
        this.baralho.embaralhar();
    }

    public void preencher() {
        for (int i = 0; i < 5; i++) {
            this.mao[i] = this.baralho.comprar();
        }
    }

    public void trocar(int... posicoes) {
        Arrays.sort(posicoes);

        boolean[] trocado = new boolean[5];

        for (int pos : posicoes) {
            if (pos >= 1 && pos <= 5 && !trocado[pos - 1]) {
                this.descartes.add(this.mao[pos - 1]);
                this.mao[pos - 1] = this.baralho.comprar();
                trocado[pos - 1] = true;
            }
        }
    }

    public void finalizarRodada() {
        for (Cartas carta : this.mao) {
            this.baralho.adicionar(carta);
        }

        for (Cartas carta : this.descartes) {
            this.baralho.adicionar(carta);
        }

        this.descartes.clear();
        this.baralho.embaralhar();
    }

    public Cartas[] getCartas() {
        return this.mao;
    }

    @Override
    public String toString() {
        return """
                +-----+ +-----+ +-----+ +-----+ +-----+
                |     | |     | |     | |     | |     |
                | %-3s | | %-3s | | %-3s | | %-3s | | %-3s |
                |     | |     | |     | |     | |     |
                +-----+ +-----+ +-----+ +-----+ +-----+
                  (1)     (2)     (3)     (4)     (5)
                """.formatted(
                mao[0],
                mao[1],
                mao[2],
                mao[3],
                mao[4]);
    }
}
