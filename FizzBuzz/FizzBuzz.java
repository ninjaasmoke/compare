public class FizzBuzz {
    public static void main(String[] args) {
        StringBuilder output = new StringBuilder(9000000);
        for (int i = 1; i <= 10000000; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                output.append("FizzBuzz\n");
            } else if (i % 3 == 0) {
                output.append("Fizz\n");
            } else if (i % 5 == 0) {
                output.append("Buzz\n");
            } else {
                output.append(i).append('\n');
            }
        }
        System.out.print(output);
    }
}
