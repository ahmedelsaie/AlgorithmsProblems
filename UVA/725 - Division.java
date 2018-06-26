import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner (System.in);
        int n;
        ArrayList<division> ans2 = new ArrayList<division>();
        division inst;

        n = scanner.nextInt();
        while(n != 0)
        {

            inst = new division(n);
            ans2.add(inst);
            n = scanner.nextInt();
        }

        for(int counter = 0; counter < ans2.size(); counter++)
        {
            ans2.get(counter).start();
        }


        for(int counter = 0; counter < ans2.size(); counter++)
        {
            inst = ans2.get(counter);
            if(inst.ans.size() == 0)
                System.out.println("There are no solutions for " + inst.getN() + ".");
            else
            {
                for(int counter2 = 0; counter2 < inst.ans.size(); counter2 += 2)
                    System.out.println(inst.ans.get(counter2 + 1) + " / " + inst.ans.get(counter2) + " = " + inst.getN() );
            }
            if(counter < ans2.size() - 1)
                System.out.println();

        }
    }

}

class division
{
    private int n, limit;
    private String temp;
    private String temp2;

    public ArrayList<String> ans = new ArrayList<String>();

    division(int n)
    {
        this.n = n;
        this.limit = 98765 / n;

    }

    public void start()
    {
        int no2;
        for(int counter = 1234; counter <= this.limit; counter++)
        {
            no2 = counter * this.n;

            if(check(counter, no2) == true )
            {
                ans.add(temp);
                ans.add(temp2);


            }
        }
    }

    boolean check(int x, int y)
    {
        String all;
        String zero;
        zero = "0";
        temp = Integer.toString(x);
        if(temp.length() < 5)
            temp = zero.concat(temp);

        temp2 = Integer.toString(y);
        if(temp2.length() < 5)
            temp2 = zero.concat(temp2);

        all = temp.concat(temp2);
        for(int counter = 0; counter < all.length(); counter++)
        {

            for(int counter2 = counter + 1; counter2 < all.length(); counter2++)
            {
                if(all.charAt(counter) == all.charAt(counter2))
                {

                    return false;
                }

            }
        }

        return true;
    }

    public int getN()
    {
        return this.n;
    }

}


