public class Test {
    public static void main(String[] args) {
        int[][] testInputs = {
            {1, 3, 5, 7, 9},
            {100000},
            {1, 2, 3, 4, 5, 6},
            {10, 20, 30, 40, 50},
            {99999, 100000}
        };

        int[] sizes = {5, 1, 6, 5, 2};
        int[] keysToSearch = {7, 99999, 10, 25, 100000};
        boolean[] expectedResults = {true, false, false, false, true};

        for (int i = 0; i < testInputs.length; i++) {
            Solution.Node head = Solution.buildLinkedList(testInputs[i], sizes[i]);
            boolean result = Solution.searchKey(sizes[i], head, keysToSearch[i]);

            System.out.println("\n-----------------------------");
            System.out.println("Test Case " + (i + 1));
            System.out.print("Linked List: {");
            for (int j = 0; j < sizes[i]; j++) {
                System.out.print(testInputs[i][j]);
                if (j < sizes[i] - 1) System.out.print(", ");
            }
            System.out.println("}");

            System.out.println("Key to Search: " + keysToSearch[i]);
            System.out.println("Expected: " + expectedResults[i]);
            System.out.println("Your Output: " + result);
            System.out.println("Test Case: " + (result == expectedResults[i] ? "✅ Passed" : "❌ Failed"));
        }
    }
}
