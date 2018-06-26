import java.math.BigInteger;
import java.util.Scanner;


public class Main
{
    public static BigInteger ans[] = new BigInteger[1005];

    public static void fn()
    {
        BigInteger last_xy = BigInteger.ONE;
        BigInteger last_yx = BigInteger.ZERO;
        BigInteger last_xx = BigInteger.ZERO;
        BigInteger last_yy = BigInteger.ZERO;

        BigInteger xy, yx, xx, yy;
        for(int i = 1; i <= 1000; i++)
        {
            ans[i] = last_xx;
            xy = BigInteger.ZERO;
            yx = BigInteger.ZERO;
            xx = BigInteger.ZERO;
            yy = BigInteger.ZERO;

            xx = xx.add(last_xy);
            yx = yx.add(last_xy);

            yy = yy.add(last_yx);
            xy = xy.add(last_yx);

            yx = yx.add(last_xx);
            xy = xy.add(last_xx);

            yx = yx.add(last_yy);
            xy = xy.add(last_yy);

            xy = xy.add(BigInteger.ONE);
            last_xy = xy;
            last_yx = yx;
            last_xx = xx;
            last_yy = yy;
        }
    }

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        fn();
        int x = 0;

        while(scan.hasNext())
        {
            x = scan.nextInt();
            System.out.println(ans[x]);
        }
    }

}
