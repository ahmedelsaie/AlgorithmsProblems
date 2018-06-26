import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner (System.in);
        int n;
        fun inst;
        ArrayList<fun> ans = new ArrayList<fun>();
        n = scanner.nextInt();
        while(n != 0)
        {
            inst = new fun(n);
            ans.add(inst);
            n = scanner.nextInt();
        }

        for(int counter = 0; counter < ans.size(); counter++)
        {
            ans.get(counter).operator();
        }

        for(int counter = 0; counter < ans.size(); counter++)
        {
            System.out.println(ans.get(counter).answer);
        }
    }
}

class fun
{
    private int n;
    public int answer = 0;

    public fun(int n)
    {
        super();
        this.n = n;
    }

    public void operator()
    {
        for(int counter = 1; counter < this.n + 1; counter++)
        {
            if(turn_off(counter) == true)
            {
                this.answer = counter;
                break;
            }
        }
    }

    private boolean turn_off(int i)
    {
        int array[] = new int[this.n + 1];
        for(int counter = 1; counter < this.n + 1; counter++)
            array[counter] = counter;
        int real = 0;
        int trav = 1;
        int turned_off = 0;


        while(turned_off < this.n - 1)
        {
            if(array[trav] != -1)
            {
                if( real % i == 0)
                {
                    if(array[trav] == 13)
                        return false;
                    else
                    {

                        array[trav] = -1;
                        turned_off++;
                    }
                }
                real++;
            }
            if(trav == this.n)
                trav = 1;
            else
                trav++;
        }

        return true;
    }
}

