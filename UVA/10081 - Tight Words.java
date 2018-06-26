import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Arrays;
import java.util.Scanner;


public class Main
{
    static int k;
    static BigDecimal dp[][] = new BigDecimal[12][105];
    static boolean visited[][] = new boolean[12][105];

    public static BigDecimal fn(int last, int left)
    {
        if(last < 0 || last > k)
            return BigDecimal.valueOf(0);

        if(left == 0)
            return BigDecimal.valueOf(1);

        if(visited[last][left] == true)
            return dp[last][left];

        visited[last][left] = true;

        BigDecimal ret;
        ret = BigDecimal.valueOf(0);

        ret = ret.add(fn(last, left - 1));
        ret = ret.add(fn(last + 1, left - 1));
        ret = ret.add(fn(last - 1, left - 1));

        dp[last][left] = ret;

        return ret;
    }

    public static BigDecimal get(BigDecimal x, int n)
    {
        BigDecimal help;
        help = BigDecimal.valueOf(1);

        for(int i = 0; i < n; i++)
            help = help.multiply(BigDecimal.valueOf(k + 1));

        BigDecimal bg1;

        bg1 = new BigDecimal("1");

        x = x.divide(help, 100, RoundingMode.HALF_EVEN);
        x = x.multiply(BigDecimal.valueOf(100));
        x = x.divide(bg1, 5, RoundingMode.HALF_EVEN);
        return x;

    }


    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int x, y;
        BigDecimal ans;
        BigDecimal ans2;

        while (scan.hasNext())
        {

            y = scan.nextInt();
            x = scan.nextInt();
            k = y;

            ans = BigDecimal.valueOf(0);

            for (int i = 0; i < 12; i++)
                Arrays.fill(visited[i], false);

            for(int i = 0; i <= k; i++)
                ans = ans.add(fn(i, x - 1));
            ans2 = get(ans, x);


            System.out.println(ans2);
        }

    }


}



