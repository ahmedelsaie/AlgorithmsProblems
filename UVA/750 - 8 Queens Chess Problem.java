import java.util.ArrayList;
import java.util.Scanner;


public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner (System.in);
        int no, r, c;
        no = scanner.nextInt();
        Main test = new Main();
        ArrayList<chess> ans = new ArrayList();

        for(int counter = 0; counter < no; counter++)
        {
            r = scanner.nextInt();
            c = scanner.nextInt();
            chess inst = test.new chess(r, c);
            ans.add(inst);
        }

        for(int counter = 0; counter < no; counter++)
        {
            System.out.println("SOLN       COLUMN");
            System.out.println(" #      1 2 3 4 5 6 7 8");
            System.out.println();

            ans.get(counter).nqueens(1);
            if(counter < no - 1)
                System.out.println();
        }
    }

    public class chess
    {
        int x[] = new int[9];
        int r, c;
        int all = 0;
        ArrayList<String> ans = new ArrayList();
        String last;

        public chess(int r, int c)
        {
            super();
            this.r = r;
            this.c = c;

        }

        boolean check_position(int row, int col)
        {
            for(int counter = 1; counter <= col - 1; counter++)
            {
                if(x[counter] == row || Math.abs(x[counter] - row) == Math.abs(counter - col))
                    return false;
            }
            return true;
        }

        void nqueens(int col)
        {
            for(int counter = 1; counter <= 8; counter++)

                if(check_position(counter, col) == true)

                {
                    x[col] = counter;
                    if(col == 8 && x[c] == r)
                    {
                        all++;
                        System.out.printf("%2d      ", all);
                        for(int counter2 = 1; counter2 <= 8; counter2++)
                        {
                            System.out.printf("%d", x[counter2]);
                            if(counter2 < 8)
                                System.out.printf(" ");
                        }
                        System.out.printf("\n");
                    }
                    else
                        nqueens(col + 1);
                }
        }

        void print()
        {
            for(int counter = 0; counter < ans.size(); counter++)
            {
                System.out.println(ans.get(counter));
            }
        }
    }
}


