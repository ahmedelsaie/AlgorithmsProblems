import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner (System.in);
        double x1;
        double x2;
        double x3;
        double y1;
        double y2;
        double y3;
        circle inst;
        ArrayList<circle> ans = new ArrayList<circle>();

        while(scanner.hasNext())
        {
            x1 = scanner.nextDouble();
            y1 = scanner.nextDouble();
            x2 = scanner.nextDouble();
            y2 = scanner.nextDouble();
            x3 = scanner.nextDouble();
            y3 = scanner.nextDouble();
            inst = new circle(x1, y1, x2, y2, x3, y3);
            ans.add(inst);
        }

        for(int counter = 0; counter < ans.size(); counter++)
        {
            ans.get(counter).operator();
            System.out.printf("%.2f", 2 * ans.get(counter).r * 3.141592653589793);

            System.out.println();
        }
    }
}

class circle
{
    double x1;
    double x2;
    double x3;
    double y1;
    double y2;
    double y3;

    String line1_m;
    String line2_m;

    String linef1_m;
    String linef2_m;

    double xf1;
    double yf1;
    double xf2;
    double yf2;
    double cf1;
    double cf2;

    double rx;
    double ry;
    double r;


    public circle(double x1, double y1, double x2, double y2, double x3,
                  double y3)
    {
        super();
        this.x1 = x1;
        this.x2 = x2;
        this.x3 = x3;
        this.y1 = y1;
        this.y2 = y2;
        this.y3 = y3;
    }

    public void operator()
    {
        line1_m = get_m(x1, y1, x2, y2);
        linef1_m = get_mf(line1_m);

        xf1 = (x2 + x1) / 2;

        yf1 = (y2 + y1) / 2;

        cf1 = get_cf(linef1_m, xf1, yf1);


        line2_m = get_m(x2, y2, x3, y3);
        linef2_m = get_mf(line2_m);
        //System.out.println(linef2_m);
        xf2 = (x2 + x3) / 2;
        yf2 = (y2 + y3) / 2;
        cf2 = get_cf(linef2_m, xf2, yf2);
        getr();
        calc_r();

    }

    private String get_m(double x1, double y1, double x2, double y2)
    {
        if(x1 == x2)
            return "i";
        else if(y1 == y2)
        {
            return"0";
        }
        else
            return String.valueOf((y2 - y1) / (x2 - x1));
    }

    private String get_mf(String x)
    {
        if(x == "0")
            return "i";
        else if(x == "i")
            return"0";
        else
        {
            double t;
            t = -1 / Double.valueOf(x);
            return String.valueOf(t);
        }

    }

    private double get_cf(String c, double x, double y)
    {
        if(c == "0")
        {
            return y;
        }
        else if(c == "i")
        {
            return x;
        }
        else
        {
            double i = Double.valueOf(c) * x;
            return (y - i);
        }
    }

    private void getr()
    {
        if(linef1_m == "0" && linef2_m == "i")
        {
            rx = xf2;
            ry = yf1;
            return;
        }

        if(linef1_m == "i" && linef2_m == "0")
        {
            rx = xf1;
            ry = yf2;
            return;
        }

        if(linef1_m == "i")
        {
            rx = xf1;
            ry = Double.valueOf(linef2_m) * rx + cf2;
            return;
        }

        if(linef2_m == "i")
        {

            rx = xf2;
            ry = Double.valueOf(linef1_m) * rx + cf1;
            return;
        }

        if(linef1_m == "0")
        {
            ry = yf1;
            rx = (ry - cf2) / Double.valueOf(linef2_m);
            return;
        }

        if(linef2_m == "0")
        {
            ry = yf2;
            rx = (ry - cf1) / Double.valueOf(linef1_m);
            return;
        }

        rx = (cf2 - cf1) / (Double.valueOf(linef1_m) - Double.valueOf(linef2_m));
        ry = rx * Double.valueOf(linef1_m) + cf1;
    }

    private void calc_r()
    {
        Double x = this.x1 - rx;
        x = Math.pow(x, 2);

        Double y = this.y1 - ry;
        y = Math.pow(y, 2);

        x = x + y;
        x = Math.sqrt(x);
        r = x;
    }

    public void print()
    {
        double i = Math.pow(rx, 2);
        i = i + Math.pow(ry, 2);
        i = i - Math.pow(r, 2);

        if(rx < 0)
            System.out.printf("(x + %.3f)", Math.abs(rx));
        else
            System.out.printf("(x - %.3f)", Math.abs(rx));

        System.out.printf("^2 + ");

        if(ry < 0)
            System.out.printf("(y + %.3f)", Math.abs(ry));
        else
            System.out.printf("(y - %.3f)", Math.abs(ry));

        System.out.printf("^2");
        System.out.printf(" = %.3f^2\n", r);

        System.out.printf("x^2 + y^2");

        if(rx < 0)
            System.out.printf(" + %.3fx", Math.abs(2 * rx));
        else if(rx > 0)
            System.out.printf(" - %.3fx", Math.abs(2 * rx));

        if(ry < 0)
            System.out.printf(" + %.3fy", Math.abs(2 * ry));
        else if(ry > 0)
            System.out.printf(" - %.3fy", Math.abs(2 * ry));

        if(i > 0)
            System.out.printf(" + %.3f", Math.abs(i));

        else
            System.out.printf(" - %.3f", Math.abs(i));

        System.out.printf(" = 0");
    }
}
