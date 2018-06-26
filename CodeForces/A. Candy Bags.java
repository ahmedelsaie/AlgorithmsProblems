import java.util.Scanner;


public class Main {

	
	public static void main(String[] args) {
		Scanner scanner = new Scanner (System.in);
		int n;
		n=scanner.nextInt();
		int s=n*n;
		int m=1;
		for(int counter=0;counter<n;counter++ )
		{
			for(int counter2=0;counter2<n/2;counter2++ )
			{
				System.out.printf("%d %d ",m,s);
				s--;
				m++;
				
			}
			System.out.printf("\n");
		}

	}

}
