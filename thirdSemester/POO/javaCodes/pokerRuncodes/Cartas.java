public class Cartas {
    public enum Naipe {
        PAUS("♣"),
        COPAS("♥"),
        ESPADAS("♠"),
        OUROS("♦");

        private final String simbolo;

        Naipe(String simbolo) {
            this.simbolo = simbolo;
        }

        public String getSimbolo() {
            return simbolo;
        }
    }

    private int valor;
    private Naipe naipe;

    public Cartas(int valor, Naipe naipe) {
        this.valor = valor;
        this.naipe = naipe;
    }

    public int getValor() {
        return valor;
    }

    public Naipe getNaipe() {
        return naipe;
    }

    public String toString() {
        String valorStr;

        if (this.valor == 11) {
            valorStr = "J";
        } else if (this.valor == 12) {
            valorStr = "Q";
        } else if (this.valor == 13) {
            valorStr = "K";
        } else if (this.valor == 14) {
            valorStr = "A";
        } else {
            valorStr = Integer.toString(this.valor);
        }

        return valorStr + (valor == 10 ?"" + this.naipe.getSimbolo():" " + this.naipe.getSimbolo());
    }
}