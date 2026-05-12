import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class Baralho {

    private List<Cartas> baralho;
    private Random random;

    public Baralho(int seed) {
        baralho = new ArrayList<>();
        random = new Random(seed);

        for (Cartas.Naipe naipe : Cartas.Naipe.values()) {
            for (int valor = 2; valor <= 14; valor++) {
                baralho.add(new Cartas(valor, naipe));
            }
        }

        embaralhar();
    }

    public void embaralhar() {
        Collections.shuffle(baralho, random);
    }

    public Cartas comprar() {
        return baralho.remove(0);
    }

    public void adicionar(Cartas carta) {
        baralho.add(carta);
    }
}
