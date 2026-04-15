import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        try (Scanner scanner = new Scanner(System.in)) {

            String linha = scanner.nextLine();
            String[] partes = linha.split(" ");

            int[] nums = new int[partes.length];

            for (int i = 0; i < partes.length; i++) {
                nums[i] = Integer.parseInt(partes[i]);
            }

            Game table = new Game(nums);
            table.printTable();

            if (scanner.hasNextLine()) {
                linha = scanner.nextLine().trim();

                for (char c : linha.toCharArray()) {
                    switch (c) {
                        case 'u' -> table.moveUp();
                        case 'd' -> table.moveDown();
                        case 'l' -> table.moveLeft();
                        case 'r' -> table.moveRight();
                        default -> System.out.println("Comando invalido: " + c);
                    }

                    table.printTable();
                }
            }

            System.out.println("Posicao final: " + table.isSolved());
        }
    }
}
