import java.util.ArrayList;
import java.util.Scanner;


public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner (System.in);
        rook inst;
        ArrayList<rook> ans = new ArrayList<rook>();
        int n;
        String input;

        n = scanner.nextInt();

        while(n != 0)
        {
            inst = new rook();
            inst.setNo(n);
            for(int counter = 0; counter < n; counter++)
            {
                input = scanner.next();
                inst.board(input);
            }
            ans.add(inst);
            n = scanner.nextInt();
        }

        for(int counter = 0; counter < ans.size(); counter++)
        {
            ans.get(counter).operator();
        }

        for(int counter = 0; counter < ans.size(); counter++)
        {
            System.out.println(ans.get(counter).getMax());
        }
    }

}

class rook
{
    private int m;    ///////16///////
    private int no;    ///////4/////
    private int n;     ////////power(2,n--)
    private int limit; ///////////16---poerwer 2-/////////
    private int max;

    public int getMax()
    {
        return max;
    }

    public void setNo(int no)
    {
        this.no = no;
    }

    int g = 0;
    char main[][] = new char[4][4];

    int array[][] = new int[16][65536];

    public void operator()
    {
        block();
        main_fill();
        check();
    }

    private boolean check_rows(int i)
    {
        int t;
        for(int counter = 0; counter < m; counter = counter + no)
        {
            t = 0;
            for(int counter2 = counter; counter2 < no + counter; counter2++)
            {
                if(array[counter2][i] == 1)
                {

                    if(t > 0)
                        return false;
                    else
                        t++;
                }
                if(array[counter2][i] == -1)
                    t = 0;
            }
        }
        return true;
    }

    private boolean check_cols(int i)
    {
        int t;
        for(int counter = 0; counter < no; counter++)
        {
            t = 0;
            for(int counter2 = counter; counter2 < m; counter2 += no)
            {
                if(array[counter2][i] == 1)
                {

                    if(t > 0)
                        return false;
                    else
                        t++;
                }
                if(array[counter2][i] == -1)
                    t = 0;
            }
        }
        return true;
    }

    private int count(int i)
    {
        int r = 0;
        for(int counter = 0; counter < m; counter++)
            if(array[counter][i] == 1)
                r++;
        return r;
    }

    private void check()
    {
        max = 0;
        int r;
        for(int counter = 0; counter < limit; counter++)
        {


            if(check_rows(counter) == true && check_cols(counter) == true)
            {
                r = count(counter);
                if(r > max)
                    max = r;
            }
        }
    }

    private void block()
    {
        n = no * no;
        m = n;
        for(int counter = 0; counter < no; counter++)
        {
            for(int counter2 = 0; counter2 < no; counter2++)
            {
                if(main[counter][counter2] == 'X')
                    n--;
            }
        }
        limit = (int) Math.pow(2, n);
    }

    public void board(String r)
    {
        for(int counter = 0; counter < no; counter++)
        {
            main[counter][g] = r.charAt(counter);
        }

        this.g++;
    }

    public void print()
    {
        for(int counter = 0; counter < limit; counter++)
        {
            for(int counter2 = 0; counter2 < no * no; counter2++)
                System.out.printf("%d ", array[counter2][counter]);
            System.out.printf("\n");
        }
    }

    private void main_fill()
    {
        int i = 0;
        int r = 0;
        for(int counter = 0; counter < no; counter++)
        {
            for(int counter2 = 0; counter2 < no; counter2++)
            {
                if(main[counter][counter2] == 'X')
                {
                    for(int counter3 = 0; counter3 < limit; counter3++)
                    {
                        array[i][counter3] = -1;
                    }

                    i++;
                }
                else
                {
                    fill(i, r);
                    i++;
                    r++;
                }
            }

        }
    }

    private void fill(int m, int r)
    {
        int i = -1;
        while(i < limit)
        {
            for(int counter = 0; counter < Math.pow(2, r); counter++)
            {
                i++;
                if(i >= limit)
                    break;

                array[m][i] = 0;

            }

            for(int counter = 0; counter < Math.pow(2, r); counter++)
            {
                i++;
                if(i >= limit)
                    break;

                array[m][i] = 1;
            }
        }
    }
}


