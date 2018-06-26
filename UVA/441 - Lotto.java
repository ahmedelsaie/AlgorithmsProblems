import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;


public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner (System.in);
        int n;
        ArrayList<gen> ans = new ArrayList<gen>();
        n = scanner.nextInt();
        gen inst;
        while(n != 0)
        {
            inst = new gen();
            inst.n = n;
            for(int counter = 0; counter < n; counter++)
            {
                inst.array2[counter] = scanner.nextInt();
            }
            ans.add(inst);
            n = scanner.nextInt();
        }

        for(int counter = 0; counter < ans.size(); counter++)
        {
            ans.get(counter).check();
            if(counter < ans.size() - 1)
                System.out.println();
        }
    }
}

class gen
{
    public int array2[] = new int[13];
    public int n = 0;
    private int temp[] = new int[6];

    void check()
    {
        for(int counter = 0; counter < n; counter++)
        {
            temp[0] = array2[counter];
            for(int counter2 = counter + 1; counter2 < n; counter2++)
            {
                temp[1] = array2[counter2];
                for(int counter3 = counter2 + 1; counter3 < n; counter3++)
                {
                    temp[2] = array2[counter3];
                    for(int counter4 = counter3 + 1; counter4 < n; counter4++)
                    {
                        temp[3] = array2[counter4];
                        for(int counter5 = counter4 + 1; counter5 < n; counter5++)
                        {
                            temp[4] = array2[counter5];
                            for(int counter6 = counter5 + 1; counter6 < n; counter6++)
                            {

                                temp[5] = array2[counter6];
                                System.out.println(temp[0] + " " + temp[1] + " " + temp[2] + " " + temp[3] + " " + temp[4] + " " + temp[5]);
                            }
                        }
                    }
                }
            }

        }
    }

}


