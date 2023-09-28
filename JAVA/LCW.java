import java.util.Arrays;
public class LCW {
    private static int lcs_recc(String str1, String str2, int m, int n, int maxLength) {
        // Base case: if either string is empty, return 0
        if (m == 0 || n == 0) {
            return maxLength;
        }

        // If the last characters of both strings match
        if (str1.charAt(m - 1) == str2.charAt(n - 1)) {
            maxLength = lcs_recc(str1, str2, m - 1, n - 1, maxLength + 1);
        }

        // Recursively compute lengths by excluding the last character of either string
        maxLength = Math.max(maxLength, Math.max(
                lcs_recc(str1, str2, m - 1, n, 0),
                lcs_recc(str1, str2, m, n - 1, 0)));

        return maxLength;
    }

    public static int lcs_memo(String str1, String str2, int n, int m, int maxLength, int[][] dp) {
        if (n == 0 || m == 0) {
            return dp[n][m] = maxLength;

        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (str1.charAt(n - 1) == str2.charAt(m - 1)) {
            maxLength = lcs_memo(str1, str2, n - 1, m - 1, maxLength + 1, dp);
            dp[n][m] = maxLength;
        } else {
            maxLength = Math.max(maxLength, Math.max(
                    lcs_memo(str1, str2, n - 1, m, maxLength, dp),
                    lcs_memo(str1, str2, n, m - 1, maxLength, dp)));
            dp[n][m] = maxLength;
        }

        return dp[n][m] = maxLength;
    }

    public static int lcs_tab(String str1, String str2) {
        int maxLength = 0;

        int n = str1.length();
        int m = str2.length();

        int[][] dp = new int[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxLength = Math.max(maxLength, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < dp.length; i ++) {
            System.out.println(Arrays.toString(dp[i]));
        }
        return maxLength;
    }

    public static void main(String[] args) {
        String str1 = "bisect";
        String str2 = "secret";

        int n = str1.length();
        int m = str2.length();

        int[][] dp = new int[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = -1;
            }
        }

        System.out.println(lcs_recc(str1, str2, n, m, 0));
        System.out.println(lcs_memo(str1, str2, n, m, 0, dp));
        System.out.println(lcs_tab(str1, str2));
    }
}