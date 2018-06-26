import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner (System.in);
        String input;

        recycle inst = new recycle();
        ArrayList<recycle> ans = new ArrayList<recycle>();
        input = scanner.next();

        while(input.charAt(0) != '#')
        {
            inst = new recycle();
            while(input.charAt(0) != 'e')
            {
                inst.add(input);
                input = scanner.next();
            }
            ans.add(inst);
            input = scanner.next();
        }

        for(int counter = 0; counter < ans.size(); counter++)
        {
            inst = ans.get(counter);
            inst.check();
        }

        for(int counter = 0; counter < ans.size(); counter++)
        {
            inst = ans.get(counter);
            System.out.println(inst.getPerfect());
        }
    }
}

class recycle
{
    public int n = 0;
    private int perfect = 0;
    private int replacements = Integer.MAX_VALUE;
    private char block[][] = new char[100][5];

    public void print()
    {
        for(int counter = 0; counter < n; counter++)
        {
            System.out.println(block[counter][0] + " " + block[counter][1] + " " + block[counter][2] + " " + block[counter][3] + " " + block[counter][4] );
        }
        System.out.println(perfect);
    }

    void add(String temp)
    {
        String city[] = new String[5];
        String d;
        city = temp.split(",");
        for(int counter = 0; counter < 5; counter++)
        {
            d = city[counter];
            switch (d.charAt(0))
            {
            case 'r':
                block[n][0] = d.charAt(2);
                break;
            case 'o':
                block[n][1] = d.charAt(2);
                break;
            case 'y':
                block[n][2] = d.charAt(2);
                break;
            case 'g':
                block[n][3] = d.charAt(2);
                break;
            case 'b':
                block[n][4] = d.charAt(2);
                break;
            }
        }
        this.n++;
    }

    void check()
    {
        int r = 0;
        for(int counter = 0; counter < n; counter++)
        {
            r = 0;
            for(int counter2 = 0; counter2 < n; counter2++)
            {
                for(int counter3 = 0; counter3 < 5; counter3++)
                {
                    if(block[counter][counter3] != block[counter2][counter3])
                        r++;
                }
                if(r > replacements)
                    break;
            }

            if(r < replacements)
            {
                replacements = r;
                perfect = counter;
            }
        }
    }

    public int getPerfect()
    {
        return perfect + 1;
    }
}

