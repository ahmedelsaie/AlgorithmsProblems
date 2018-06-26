import java.util.Scanner;


public class Main {

    static char game[][]=new char [3][3];
    public static void main(String[] args) {
        Scanner scanner = new Scanner (System.in);
        String ind;
        for(int counter=0;counter<3;counter++)
        {
             ind= scanner.next();
             for(int counter2=0;counter2<3;counter2++)
             {
                 game[counter][counter2]=ind.charAt(counter2);
             }
        }
        ///////////////////////////////////////////
        int x=count('X');
        int o=count('0');
        int cx=check_completetion('X');
        int co=check_completetion('0');
        if(cx==-1 || co==-1)
        {
            System.out.println("illegal");
            return;
        }
        else
            if(cx>0 && co>0)
            {
                System.out.println("illegal");
                return;
            }
            else
                
            if(cx>0 && co==0)
            {
                if(x==o+1)
                {
                    System.out.println("the first player won");
                    return;
                }
                else
                {
                    System.out.println("illegal");
                    return;
                }
            }
            else
                if(cx==0 && co>0)
                {
                    if(x==o)
                    {
                        System.out.println("the second player won");
                        return;
                    }
                    else
                    {
                        System.out.println("illegal");
                        return;
                    }
                }
                else
                {
                    if(x==o+1 && x+o<9)
                    {
                        System.out.println("second");
                        return;
                    }
                    else
                        if(x==o && x+o<9)
                        {
                            System.out.println("first");
                            return;
                        }
                        else
                            if(x+o==9 && x==o+1)
                            {
                                System.out.println("draw");
                                return;
                            }
                            else
                            {
                                System.out.println("illegal");
                                return;
                            }
                }
        

    }
    
    
    static int check_completetion(char x)
    {
        int row=0;
        int col=0;
        int dig=0;
        int flag=0;
        //////////////////rows////////////////////
        for(int counter=0;counter<3;counter++)
        {
            flag=0;
            for(int counter2=0;counter2<3;counter2++)
            {
                if(game[counter][counter2]==x)
                    flag++;
            }
            if(flag==3)
                row++;
        }
        
        /////////////////////////////col///////////////
        for(int counter=0;counter<3;counter++)
        {
            flag=0;
            for(int counter2=0;counter2<3;counter2++)
            {
                if(game[counter2][counter]==x)
                    flag++;
            }
            if(flag==3)
                col++;
        }
        //////////////////diag////////////////////////////////
        if(game[0][0]==x && game[1][1]==x && game[2][2]==x)
            dig++;
        if(game[2][0]==x && game[1][1]==x && game[0][2]==x)
            dig++;
        ////////////////////////////////////////////////////////
        if(row>=2 || col>=2)
            return -1;
        else
            if(dig+row+col<=2)
                return dig+row+col;
            else
                return -1;
        
        
        
        
    }
    
    
    static int count(char x)
    {
        int flag=0;
        for(int counter=0;counter<3;counter++)
        {
            
            for(int counter2=0;counter2<3;counter2++)
            {
                if(game[counter][counter2]==x)
                    flag++;
            }
        }
        return flag;
    }
    

}