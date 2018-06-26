import java.util.ArrayList;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		int array[]=new int[5];
		int k,l,m,n,d;
		Scanner scanner = new Scanner (System.in);
		 k= scanner.nextInt();
	     l= scanner.nextInt();
	     m= scanner.nextInt();
	     n= scanner.nextInt();
	     d= scanner.nextInt();
	     array[0]=k;
	     array[1]=l;
	     array[2]=m;
	     array[3]=n;
	      int r[];
	 
	    
	 bsort(array);
	 r=repet(array);
	 int s=r.length;
	     
/*	 for(int counter=0;counter<s;counter++)
     {
		 System.out.println(r[counter]);
     }
	     */
	    	 System.out.println(total(r,d,s));
	     
	     
	     

	}
	
	
	static int total(int array[],int d,int s)
	{
		int t=0;
		
		if(array[s-1]==1)
			return d;
		else
		{
			
			 //System.out.println(t);
			for(int counter=s-1;counter>=0;counter--)
		     {
				//System.out.println(array[counter]);
				for(int n=array[counter];n<=d;n=n+array[counter])
			     {
					
					if(check(array[counter],array,n,counter)==1)
					t=t+1;
					
					//	System.out.println(n);
						
					
				 }
				
				
		     }
			return t;
			
			
			
			
		}
		
	}
	
	static int check(int i,int array[],int d,int count)
	{
		int s=array.length;
		for(int counter=0;counter<s;counter++)
	     {
			if(d%array[counter]==0 && array[counter]!=i && counter>count)
				return 0;
			
	     }
		return 1;
		
		
	}
	
	
	static int [] repet(int array[])
	{
		int s=4;
		   for(int counter=0;counter<s;counter++)
		     {
		    	 for(int counter2=counter+1;counter2<s;counter2++)
		    	 {
		    		 if((array[counter])%(array[counter2])==0 && (array[counter2])!=1)
		    			 {
		    			 for(int counter3=counter;counter3<s;counter3++)
		    		     array[counter3]=array[counter3+1];
		    		     
		    			  s--;
		    			 }
		    	 }
		     }
		   
		   for(int counter=0;counter<s;counter++)
		     {
			   if(array[counter]==array[counter+1])
			   {
				   for(int counter2=counter+1;counter<s;counter++)
				   {
					   array[counter2]=array[counter2+1];
				   }
				   s--;
			   }
		     }
		   
		   
		   int r[]=new int [s];
		   
		   for(int counter=0;counter<s;counter++)
		     {
			   r[counter]=array[counter];
		     }
		   return r;
		
	}
	

	static void bsort(int array[])
{
		int swap;
		 for(int counter=0;counter<3;counter++)
	     {
	    	 for(int counter2=0;counter2<3;counter2++)
	    	 {
	    		 if(array[counter2]<array[counter2+1])
	    		 {
	    			 swap=array[counter2];
	    			 array[counter2]=array[counter2+1];
	    			 array[counter2+1]=swap;
	    		}
	    	 }
	     }
	     
	}

}
