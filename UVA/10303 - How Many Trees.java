import java.math.BigInteger;
import java.util.Scanner;


public class Main
{

    public static BigInteger[] dp = new BigInteger[1005];
    public static boolean[] visited = new boolean[1005];

    public static BigInteger fn(int leaf)
    {
        if(leaf <= 1)
            return BigInteger.ONE;

        if(visited[leaf] == true)
            return dp[leaf];
        visited[leaf] = true;
        dp[leaf] = BigInteger.ZERO;

        for(int i = 0; i < leaf; i++)
            dp[leaf] = dp[leaf].add(fn(i).multiply(fn(leaf - i - 1)));

        return dp[leaf];

    }

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        while(scan.hasNext())
        {
            int x = scan.nextInt();
            System.out.println(fn(x));
        }


    }

}
