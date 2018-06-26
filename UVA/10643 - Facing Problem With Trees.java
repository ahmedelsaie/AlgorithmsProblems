import java.math.BigInteger;
import java.util.Scanner;


public class Main
{

    static BigInteger dp[][] = new BigInteger [505][2];
    static BigInteger dp2[] = new BigInteger[505];

    static boolean v[][] = new boolean [505][2];
    static boolean v2[] = new boolean[505];

    public static void main(String[] args)
    {

        Scanner scanner = new Scanner(System.in);
        int tc = scanner.nextInt();
        int cases = 1;

        while(tc-- > 0)
        {
            int x = scanner.nextInt();
            System.out.println("Case " + cases++ + ": " + fn(x, 1));
        }

    }

    static BigInteger fn(int left, int edge)
    {
        if(left < 0)
            return BigInteger.ZERO;

        if(left == 0)
        {
            if(edge == 1)
                return BigInteger.ONE;
            return BigInteger.ZERO;
        }

        if(v[left][edge] == true)
            return dp[left][edge];

        v[left][edge] = true;
        BigInteger ret = BigInteger.ZERO;
        int new_left = left - 1;

        int new_edge = 0;

        if(edge == 0)
            new_edge = 1;

        for(int i = 0; i <= new_left; i++)
            ret = ret.add(fn(i, new_edge).multiply(fn2(new_left - i)));

        dp[left][edge] = ret;
        return ret;
    }

    static BigInteger fn2(int left)
    {
        if(left == 1)
            return BigInteger.ZERO;

        if(left == 0)
            return BigInteger.ONE;


        if(v2[left] == true)
            return dp2[left];

        BigInteger ret = BigInteger.ZERO;
        v2[left] = true;

        int new_left = left - 2;
        for(int i = 0; i <= new_left; i++)
            ret = ret.add(fn2(i).multiply(fn2(new_left - i)));

        dp2[left] = ret;
        return ret;
    }

}
