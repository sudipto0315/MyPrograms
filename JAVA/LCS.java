import java.util.Arrays;

public class LCS {
    public static int lcs_recc(String str1, String str2, int n, int m) {
        int ans = 0;

        if (n == 0 || m == 0) {
            return 0;
        }

        if (str1.charAt(n - 1) == str2.charAt(m - 1)) {
            ans = 1 + lcs_recc(str1, str2, n - 1, m - 1);
        } else {
            int ans1 = lcs_recc(str1, str2, n - 1, m);
            int ans2 = lcs_recc(str1, str2, n, m - 1);

            ans += Math.max(ans1, ans2);
        }

        return ans;
    }

    public static int lcs_memo(String str1, String str2, int n, int m, int[][] dp) {
        if (n == 0 || m == 0) {
            return dp[n][m] = 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (str1.charAt(n - 1) == str2.charAt(m - 1)) {
            return dp[n][m] = 1 + lcs_memo(str1, str2, n - 1, m - 1, dp);
        } else {
            int ans1 = lcs_memo(str1, str2, n - 1, m, dp);
            int ans2 = lcs_memo(str1, str2, n, m - 1, dp);

            return dp[n][m] = Math.max(ans1, ans2);
        }
    }

    public static int lcs_tab(String str1, String str2) {
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
                } else {
                    int ans1 = dp[i - 1][j];
                    int ans2 = dp[i][j - 1];
                    dp[i][j] = Math.max(ans1, ans2);
                }
            }
        }

        for (int i = 0; i < dp.length; i++) {
            System.out.println(Arrays.toString(dp[i]));
        }

        return dp[n][m];
    }

    public static int lcs_tab_array(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int m = arr2.length;

        int[][] dp = new int[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr1[i - 1] == arr2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    int ans1 = dp[i - 1][j];
                    int ans2 = dp[i][j - 1];
                    dp[i][j] = Math.max(ans1, ans2);
                }
            }
        }
        return dp[n][m];
    }

    public static void main(String[] args) {
        String str1 = "abcbdab";
        String str2 = "bdcaba";

        int n = str1.length();
        int m = str2.length();

        int[][] dp = new int[n + 1][m + 1];

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = -1;
            }
        }

        System.out.println(lcs_recc(str1, str2, n, m));
        System.out.println(lcs_memo(str1, str2, n, m, dp));
        System.out.println(lcs_tab(str1, str2));
    }
}