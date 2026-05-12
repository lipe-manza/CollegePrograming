public class Verificador {

    private Cartas[] cartas;

    public int calcularPremio(int aposta, Cartas[] cartas) {
        this.cartas = cartas;

        if (isRoyalStraightFlush()) return aposta * 200;
        if (isStraightFlush())      return aposta * 100;
        if (isQuadra())             return aposta * 50;
        if (isFullHouse())          return aposta * 20;
        if (isFlush())              return aposta * 10;
        if (isStraight())           return aposta * 5;
        if (isTrinca())             return aposta * 2;
        if (isDoisPares())          return aposta;

        return 0;
    }

    private int[] contarValores() {
        int[] freq = new int[15];

        for (Cartas c : cartas) {
            freq[c.getValor()]++;
        }

        return freq;
    }

    private boolean mesmoNaipe() {
        Cartas.Naipe naipe = cartas[0].getNaipe();

        for (Cartas c : cartas) {
            if (c.getNaipe() != naipe) return false;
        }

        return true;
    }

    private boolean isFlush() {
        return mesmoNaipe() && !isStraight();
    }

    private boolean isStraight() {
        int[] freq = contarValores();

        int count = 0;

        for (int i = 2; i <= 14; i++) {
            if (freq[i] == 1) {
                count++;
                if (count == 5) return true;
            } else {
                count = 0;
            }
        }

        return false;
    }

    private boolean isTrinca() {
        int[] freq = contarValores();

        for (int f : freq) {
            if (f == 3) return true;
        }

        return false;
    }

    private boolean isQuadra() {
        int[] freq = contarValores();

        for (int f : freq) {
            if (f == 4) return true;
        }

        return false;
    }

    private boolean isDoisPares() {
        int[] freq = contarValores();
        int pares = 0;

        for (int f : freq) {
            if (f == 2) pares++;
        }

        return pares == 2;
    }

    private boolean isFullHouse() {
        int[] freq = contarValores();

        boolean trinca = false;
        boolean par = false;

        for (int f : freq) {
            if (f == 3) trinca = true;
            if (f == 2) par = true;
        }

        return trinca && par;
    }

    private boolean isStraightFlush() {
        return isStraight() && mesmoNaipe();
    }

    private boolean isRoyalStraightFlush() {
        int[] freq = contarValores();

        for (int i = 10; i <= 14; i++) {
            if (freq[i] != 1) return false;
        }

        return mesmoNaipe();
    }
}