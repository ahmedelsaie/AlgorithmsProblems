import java.util.ArrayList;
import java.util.Scanner;
import java.math.BigInteger;

public class Main {

             static int nofzeros=0;
             static int nofninth=0;
             static int lk=0;
    public static void main(String[] args) {
        Scanner scanner = new Scanner (System.in);
        String input;
        input= scanner.next();
        lk=input.length();
        char main[];
        char main2[];
        main=input.toCharArray();
        main2=input.toCharArray();
        int traver[]={0,0,0,0,0,0,0,0,0,0};
        trav(traver, main);
     
        
        int max=0;
        int i=0;
  
        
     int array[];
     int no=0;
     array=iscontain_tenth(traver);
        no=array.length;
        Main test=new Main();
        /*for(int counter=0;counter<no;counter++)
        {
            System.out.println(array[counter]);
        }
        System.out.println("ok"); */
       
        if(no==0)
        {
            perm inst=test.new perm(lk,traver,traver);
            inst.setIt_containtenth(0);
            inst.operator();
            System.out.println(inst.getAns1());
            System.out.println(inst.getAns2());
       }
        else
        {
            ArrayList<perm> total=new ArrayList();
            perm inst=test.new perm(lk,traver,traver);
            for(int counter=0;counter<no;counter++)
            {
                inst=test.new perm(lk,traver,traver);
                inst.setIt_containtenth(1);
                inst.setChoice(array[counter]);
                inst.operator();
                total.add(inst);
            }
            int s=total.size();
            for(int counter=0;counter<s;counter++)
            {
                
                inst=total.get(counter);
                if(inst.getNeeded()>max)
                {
                    max=inst.getNeeded();
                    i=counter;
                }
            }
            System.out.println(total.get(i).getAns1());
            System.out.println(total.get(i).getAns2());
            
        }
        
      
    
            
}
   
    
    static void trav(int array[],char main[])
    {
        for(int counter=0;counter<lk;counter++)
        {
            switch(main[counter])
            {
                case '0':
                    array[0]++;
                    break;
                case '1':
                    array[1]++;
                    break;
                case '2':
                    array[2]++;
                    break;
                case '3':
                    array[3]++;
                    break;
                case '4':
                    array[4]++;
                    break;
                case '5':
                    array[5]++;
                    break;
                case '6':
                    array[6]++;
                    break;
                case '7':
                    array[7]++;
                    break;
                case '8':
                    array[8]++;
                    break;
                case '9':
                    array[9]++;
                    break;
                
            }
                
            
        }
        
    }
   

   static int [] iscontain_tenth(int trav[])
   {
       int no=0;
       int array[]=new int[5];
       for(int counter=9;counter>=5;counter--)
       {
           if(trav[counter]>0 && trav[10-counter]>0)
           {
              
               array[no]=counter;
               no++;
           }
       }
       int array2[]=new int[no];
       for(int counter=0;counter<no;counter++)
       {
           array2[counter]=array[counter];
       }
       return array2;
 
       
   }
   

   static int ctoi(char c)
    {
        String ref="0123456789";
        int counter;
        for(counter=0;counter<10;counter++)
        {
            if (ref.charAt(counter)==c)
            return counter;
        }
        return -1;

    }

   
   
    public class perm
    {
        private char main[];
        private char main2[];
        private String main3=new String("");
       
        private char ans1[];
        private char ans2[];
        private int it_containtenth;
        private int choice;
        private int needed;
        private int total=0;
        private int l;
        
        private int trav1[]=new int[10];
        private int trav2[]=new int [10];
        
       

       public char[] getAns1() {
           return ans1;
       }

       public char[] getAns2() {
           return ans2;
       }

       public int getNeeded() {
           return needed;
       }

       public void setIt_containtenth(int it_containtenth) {
           this.it_containtenth = it_containtenth;
       }

       public void setChoice(int choice) {
           this.choice = choice;
       }

  

    public perm(int lk,int t1[],int t2[]) {
           super();
           this.l=lk;
           ans1=new char[l];
           ans2=new char[l];
           for(int counter=0;counter<10;counter++)
           {
               this.trav1[counter]=t1[counter];
               this.trav2[counter]=t1[counter];
              // System.out.println(trav1[counter]);
           }
           
           
       }

        void operator()
        {
            
           this.check(trav1,trav2,this.it_containtenth);
           this.needed=total;
        }
        
  
           void check(int trav1[],int trav2[],int it_containtenth)
           {
               int i=l;
               i--;
               
               
               
               
       ////////////////////////////////////////////////////////////////////////
       //////////////////////////////////////////////////////////////
               if(trav1[0]>trav1[9] )
               {
                   
                   
                 //  System.out.println(l);
                   int m=trav1[0]-trav1[9];
                   for(int counter=0;counter<m;counter++)
                   {
                       start_zero(trav1,trav2, i);
                       total++;
                       i--;
                       l--;
                    //   System.out.println("ok");
                       
                   }
                  
                  
                  if(it_containtenth!=0)
                  
                      i=start_tenth(trav1,trav2,i);
               /*  System.out.println(main);
                   System.out.println(main2);
                   System.out.println(ans1);
                   System.out.println(ans2);
                   System.out.println(l);*/
                   i=start_ninth(trav1,trav2,i);
                  /* System.out.println("ok");
                   System.out.println(main);
                   System.out.println(main2);
                   System.out.println(ans1);
                   System.out.println(ans2);
                   System.out.println(l);*/
                       start_useless(trav1,trav2,i);
                        
                       
                  
                  
                   return;
               }
               //////////////////////////////////////////////////////////////////////
               //////////////////////////////////////////////////////////////////////
               if(trav1[0]==trav1[9] && trav1[9] >0 )
               {
                   if(it_containtenth!=0)
                   {
                       i=start_tenth(trav1,trav2,i);
                       i=start_ninth(trav1,trav2,i);
                          
                              start_useless(trav1,trav2,i);
                               
                               
                           
                       return;
                       
                   }
                   else
                   {
                       
                       
                       int m=trav1[0];
                       for(int counter=0;counter<m;counter++)
                       {
                           start_zero(trav1,trav2,i);
                           total++;
                           i--;    
                           l--;
                       }
                       i=start_ninth(trav1,trav2,i);
                          
                               start_useless(trav1,trav2,i);
                           
                           
                       return;
                   }
               }
               /////////////////////////////////////////////////////////////////////////////
               ////////////////////////////////////////////////////////////////////////////
               if(trav1[0]<trav1[9] && trav1[0] >0 )
               {
                   if(it_containtenth!=0)
                   {
                       
                       i=start_tenth(trav1,trav2,i);
                       i=start_ninth(trav1,trav2,i);
                          
                              start_useless(trav1,trav2,i);
                               
                           
                       return;
                       
                   }
                   else
                   {
                       int m=trav1[0];
                       for(int counter=0;counter<m;counter++)
                       {
                           start_zero(trav1,trav2,i);
                           total++;
                           i--;
                           l--;
                       }
                       i=start_ninth(trav1,trav2,i);
                         
                              start_useless(trav1,trav2,i);
                           
                       return;
                   }
                   
               }
               /////////////////////////////////////////////////////////////////
               ///////////////////////////////////////////////////////////////
               if(trav1[0]==0)
               {if(it_containtenth!=0)
                   i=start_tenth(trav1,trav2,i);
                   i=start_ninth(trav1,trav2,i);
                     
                           start_useless(trav1,trav2,i);
                       
                   return;
               }
               
               
               
               
               
               
               

           }

           
             void start_zero(int trav1[],int trav2[],int i)
            {
                ans1[i]='0';
                ans2[i]='0';
                trav1[0]--;
                trav2[0]--;
            }
           

             int start_tenth(int trav1[],int trav2[],int i)
            {
            /*   for(int counter=0;counter<9;counter++)
                 {
                   System.out.println(trav1[counter]);
                   System.out.println(trav2[counter]);
                 }*/
                 
                           total++;
                       
                           ans1[i]=itoc(choice);
                           ans2[i]=itoc(10-choice);
                           
                           trav1[choice]--;
                           trav2[10-choice]--;
                           l--;
                           
                       /*    for(int counter=0;counter<9;counter++)
                           {
                               System.out.println(trav1[counter]);
                               System.out.println(trav2[counter]);
                           }*/
                            return i-1 ;
                        }
                    
                
               
                
            
           
              int start_ninth(int trav1[],int trav2[],int i)
            {
                
             for(int counter=0;counter<10;counter++)
                {
                    
                    while(trav1[counter]>0 && trav2[9-counter]>0)
                    {
                        ans1[i]=itoc(counter);
                        ans2[i]=itoc(9-counter);
                        i--;
                        trav1[counter]--;
                        trav2[9-counter]--;
                        total++;
                   }
                    
                    
                    
                   
                }
              
                return i;
                
               
                
            }
            
              void start_useless(int trav1[],int trav2[],int i)
              {
                  int i_2=i;
                 
                /*  for(int counter=0;counter<10;counter++)
                  {
                      System.out.println(trav1[counter]);
                  }*/
                      
                  
                  while(i>=0)
                      {
                      for(int counter=0;counter<10;counter++)
                      {
                          while(trav1[counter]>0)
                          {
                              ans1[i]=itoc(counter);
                              i--;
                              trav1[counter]--;
                              
                              
                          }
                    
                      }
                      }
                  
                  while(i_2>=0)
                  {
                  for(int counter=0;counter<10;counter++)
                  {
                      while(trav2[counter]>0)
                      {
                          ans2[i_2]=itoc(counter);
                          i_2--;
                          trav2[counter]--;
                          
                          
                      }
                     
                  }
                  }
              
              
                   return;
                  
                 }
            
     
              int ctoi(char c)
              {
                   String ref="0123456789";
                   int counter;
                   for(counter=0;counter<10;counter++)
                   {
                       if (ref.charAt(counter)==c)
                       return counter;
                   }
                   
                   return -1;

               }

              char itoc(int i)
              {
                  String ref="0123456789";
                  return ref.charAt(i);
                  
              }
        
    
    
    }

}










