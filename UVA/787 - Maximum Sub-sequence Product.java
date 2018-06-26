import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main
{

    static int array[] = new int[110];
    static boolean visited[][] = new boolean[110][2];
    static BigInteger dp[][] = new BigInteger[110][2];
    static int n;

    static BigInteger fn(int x, int pos)
    {
        if (x == n)
            return BigInteger.valueOf(1);

        if (visited[x][pos])
            return dp[x][pos];

        visited[x][pos] = true;

        if (pos > 0)
        {
            int new_pos = pos;
            if (array[x] < 0)
                new_pos = 0;

            BigInteger choice1 = fn(x + 1, new_pos).multiply(
                                     BigInteger.valueOf(array[x]));
            BigInteger choice2 = BigInteger.valueOf(array[x]);
            return dp[x][pos] = max(choice1, choice2);

        }
        else
        {
            BigInteger choice1, choice2;
            if (array[x] < 0)
            {
                choice1 = fn(x + 1, 1).multiply(BigInteger.valueOf(array[x]));
                choice2 = BigInteger.valueOf(array[x]);
            }
            else
            {
                choice1 = fn(x + 1, pos).multiply(BigInteger.valueOf(array[x]));
                choice2 = BigInteger.valueOf(array[x]);
            }
            return dp[x][pos] = min(choice1, choice2);
        }

    }

    static BigInteger abs(BigInteger x)
    {
        if (x.compareTo(BigInteger.valueOf(0)) > 0)
            return x;
        else
            return x.multiply(BigInteger.valueOf(-1));
    }

    static BigInteger max(BigInteger x, BigInteger y)
    {
        if (x.compareTo(y) > 0)
            return x;
        else
            return y;
    }

    static BigInteger min(BigInteger x, BigInteger y)
    {
        if (x.compareTo(y) < 0)
            return x;
        else
            return y;
    }

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        BigInteger ans;
        while (scan.hasNext())
        {
            n = 0;
            while (true)
            {
                array[n] = scan.nextInt();
                if (array[n] == -999999)
                    break;
                n++;
            }
            for (int i = 0; i < 110; i++)
                Arrays.fill(visited[i], false);

            ans = fn(0, 1);

            for (int i = 0; i < n; i++)
                ans = ans.max(fn(i, 1));
            System.out.println(ans);
        }
    }
}
