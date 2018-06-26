import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;


public class Main
{
    static BigInteger[] dp = new BigInteger[300];
    static BigInteger[][] dp2 = new BigInteger[300][300];
    static int sub[] = new int[300];
    static int comple[] = new int[300];
    static int array[] = new int[300];
    static BigInteger desired;
    static boolean check[] = new boolean[300];

    static int l_sub, l_comple;
    static int length;

    static BigInteger fac(int x)
    {
        if(x < 0)
            x = 1;
        if(x == 1)
            return BigInteger.valueOf(1);

        if(dp[x].compareTo(BigInteger.valueOf(-1)) != 0)
            return dp[x];

        return dp[x] = BigInteger.valueOf(x).multiply(fac(x - 1));
    }

    static BigInteger calc(int x, int y)
    {
        if(y <= 0)
            y = 1;
        if(x <= 0)
            x = 1;
        if(dp2[x][y].compareTo(BigInteger.valueOf(-1)) != 0)
            return dp2[x][y];

        return dp2[x][y] = fac(x).divide(fac(y));
    }

    static void fill()
    {
        for(int i = 0; i < l_sub; i++)
            check[sub[i]] = false;

        int j = 0;
        int i = 1;
        while(j < l_comple)
        {
            if(check[i])
            {
                comple[j] = i;
                j++;
            }
            i++;
        }
        return ;
    }

    static void print()
    {
        for(int i = 0; i < length; i++)
        {
            if(i > 0)
                System.out.print(" ");
            System.out.print(array[i]);
        }
        return ;
    }

    static void fn(BigInteger accum, int sub_i, int taken)
    {
        if(taken == length)
        {
            print();
            return ;
        }

        boolean flag = true;
        BigInteger help;
        int i = 0;
        while(true)
        {
            if(!check[comple[i]])
            {
                i++;
                continue;
            }

            if(i >= l_comple)
            {
                array[taken] = sub[sub_i];
                fn(accum, sub_i + 1, taken + 1);
                return;
            }


            if(sub[sub_i] < comple[i] && flag && sub_i < l_sub)
            {
                flag = false;
                help = calc(length - taken - 1, l_sub - sub_i - 1);
                if(desired.compareTo(accum.add(help)) <= 0)
                {
                    array[taken] = sub[sub_i];
                    fn(accum, sub_i + 1, taken + 1);
                    return ;
                }
                else
                    accum = accum.add(help);
            }
            else
            {
                help = calc(length - taken - 1, l_sub - sub_i);
                if(desired.compareTo(accum.add(help)) <= 0)
                {
                    array[taken] = comple[i];
                    check[comple[i]] = false;
                    fn(accum, sub_i, taken + 1);
                    return;
                }
                else
                {
                    accum = accum.add(help);
                    i++;
                }
            }

        }
    }


    public static void main(String[] args)
    {
        Scanner scanner = new Scanner (System.in);
        Arrays.fill(dp, BigInteger.valueOf(-1));

        for(int i = 0; i < 300; i++)
            Arrays.fill(dp2[i], BigInteger.valueOf(-1));

        while(scanner.hasNext())
        {
            length = scanner.nextInt();
            l_sub = scanner.nextInt();
            desired = scanner.nextBigInteger();

            l_comple = length - l_sub;
            for(int i = 0; i < l_sub; i++)
                sub[i] = scanner.nextInt();

            Arrays.fill(check, true);
            fill();
            Arrays.fill(check, true);

            fn(BigInteger.valueOf(0), 0, 0);

            System.out.println();
        }
    }

}
