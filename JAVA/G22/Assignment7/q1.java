import java.util.Scanner;

public class q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter numbers to add (space-separated): ");
        String input = scanner.nextLine().trim();
        scanner.close();

        String[] inputNumbers = input.split(" ");
        if (input.isEmpty()) {
            System.out.println("Error: No numbers to add");
        } else if (inputNumbers.length == 1) {
            System.out.println("Error: Add requires at least two numbers");
        } else {
            int sum = 0;
            try {
                for (String numStr : inputNumbers) {
                    int num = Integer.parseInt(numStr);
                    sum += num;
                }
                System.out.println("Addition result: " + sum);
            } catch (NumberFormatException e) {
                System.out.println("Error: Invalid number format");
            }
        }
    }
}

