

public class Game {

    private int[][] table;
    private int zeroI;
    private int zeroJ;

    public Game(int... numbers) {
        int size = (int) Math.sqrt(numbers.length);
        this.table = new int[size][size];

        int count = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                this.table[i][j] = numbers[count];
                if (numbers[count] == 0) {
                    this.zeroI = i;
                    this.zeroJ = j;
                }
                count++;
            }
        }
    }

    int getZeroI() {
        return this.zeroI;
    }

    int getZeroJ() {
        return this.zeroJ;
    }

    void upgradeZeroIJ(int i, int j) {
        this.zeroI = i;
        this.zeroJ = j;
    }

    int getTableSize() {
        return this.table.length;
    }

    void moveDown() {

        int i = getZeroI();
        int j = getZeroJ();

        if (i - 1 < 0) {
            return;
        }

        this.table[i][j] = this.table[i - 1][j];
        this.table[i - 1][j] = 0;

        upgradeZeroIJ(i - 1, j);

    }

    void moveUp() {

        int i = getZeroI();
        int j = getZeroJ();

        if (i + 1 >= getTableSize()) {
            return;
        }

        this.table[i][j] = this.table[i + 1][j];
        this.table[i + 1][j] = 0;

        upgradeZeroIJ(i + 1, j);

    }

    void moveRight() {

        int i = getZeroI();
        int j = getZeroJ();

        if (j - 1 < 0) {
            return;
        }

        this.table[i][j] = this.table[i][j - 1];
        this.table[i][j - 1] = 0;

        upgradeZeroIJ(i, j - 1);


    }

    void moveLeft() {

        int i = getZeroI();
        int j = getZeroJ();

        if (j + 1 >= getTableSize()) {
            return;
        }

        this.table[i][j] = this.table[i][j + 1];
        this.table[i][j + 1] = 0;

        upgradeZeroIJ(i, j + 1);
    }

    void printTable() {
        int size = getTableSize();
        String border = "+------".repeat(size) + "+";
        for (int i = 0; i < size; i++) {
            System.out.println(border);
            for (int j = 0; j < size; j++) {
                System.out.printf("|%4d  ", this.table[i][j]);
            }
            System.out.println("|");
        }
        System.out.println(border);
        System.out.println();
    }

    boolean isSolved() {
        int count = 0;
        for (int i = 0; i < getTableSize(); i++) {
            for (int j = 0; j < getTableSize(); j++) {
                if (count != this.table[i][j]) {
                    return false;
                }
                count++;
            }
        }
        return true;
    }

}
