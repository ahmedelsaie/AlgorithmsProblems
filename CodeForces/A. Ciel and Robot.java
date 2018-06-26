import java.math.BigDecimal;
import java.util.*;


public class Main {

    
    



    public static void main(String[] args) {
        Scanner scanner = new Scanner (System.in);
        String array;
        BigDecimal x,y;
        Main test=new Main();
        line inst=test.new line();
        x= scanner.nextBigDecimal();
        y= scanner.nextBigDecimal();
        array=scanner.next();
        ArrayList<line> liness;
        liness=go(array);
        int i=checkpoint(x,y,liness);
        
     //System.out.println(i);
       //for(int counter=0;counter<liness.size();counter++)
    	  // System.out.println(liness.get(counter).c);
   
        
        if(ifclosedpath(liness)==1)
             if( firstpath(x,y,liness)==1)
                {System.out.println("Yes");
                return;
                }
                else
                {System.out.println("No");
                return;
                }
                
            
            
                if(firstpath(x,y,liness)==1)
                    {System.out.println("Yes");
                    return;
                    }
                else
                    if(checkpoint(x,y,liness)>=0)
                        {
                        if(check_range(i,x,liness)==1)
                        
                            System.out.println("Yes");  
                        else
                            System.out.println("No");
                        }
                    else
                System.out.println("No");
            
            
            
        
        
        
                
        
        
        
        
        
    

    }

    
    
    






static ArrayList<line> go(String array)
{
    int n=0;
   BigDecimal x=new BigDecimal(0);
   BigDecimal y=new BigDecimal(0);
    ArrayList<line> lines=new ArrayList<line>() ;
    Main test=new Main();
    line inst=test.new line();
    
    
    
  
      int l=array.length();
    
    
   
    
    while(n<l)
    {

        if(array.charAt(n)=='U')
        y=y.add(BigDecimal.valueOf(1));
        if(array.charAt(n)=='D')
        y=y.subtract(BigDecimal.valueOf(1));
        if(array.charAt(n)=='L')
        x=x.subtract(BigDecimal.valueOf(1));
        if(array.charAt(n)=='R')
        x=x.add(BigDecimal.valueOf(1));
        
        //System.out.println(x);
        inst=test.new line();
        inst.setX1(x);
        inst.setY1(y);
        lines.add(n,inst);
        
       n=n+1;
        
       
   }
    
        
        


    
    
  
    n=0;


    while(n<l)
    {

        if(array.charAt(n)=='U')
        y=y.add(BigDecimal.valueOf(1));
        if(array.charAt(n)=='D')
        y=y.subtract(BigDecimal.valueOf(1));
        if(array.charAt(n)=='L')
        x=x.subtract(BigDecimal.valueOf(1));
        if(array.charAt(n)=='R')
        x=x.add(BigDecimal.valueOf(1));
        
       
        
        inst=test.new line();
        inst=lines.get(n);
        
        inst.setX2(x);
        inst.setY2(y);
        
        lines.set(n, inst);
        

        n++;
       
    }
    
    
    
    for(int counter=0;counter<lines.size();counter++)
    {
         
        inst=test.new line();
        inst=lines.get(counter);
        inst.makeline();
        lines.set(counter, inst);
        
    }
    return lines;









}




    
static int firstpath(BigDecimal x,BigDecimal y,ArrayList <line> lines)
{
    Main test=new Main();
        line inst=test.new line();
        int l=lines.size();
        
    if(x.compareTo(BigDecimal.valueOf(0))==0 && y.compareTo(BigDecimal.valueOf(0))==0)
        return 1;
    else
    {

        for (int counter=0;counter<l;counter++)
        {
            
            inst=test.new line();
            inst=lines.get(counter);
            if(x.compareTo(inst.x1)==0 && y.compareTo(inst.y1)==0 )
            {
            	//System.out.println("ok");
            	return 1;
            }
            

        }
        return 0;
    }
    
    

}

                        
static int checkpoint(BigDecimal x,BigDecimal y,ArrayList<line> lines)
{
	BigDecimal r = new BigDecimal("1");
    Main test=new Main();
        line inst=test.new line();
    
    
    int flag=0;
    int counter;
    if(x.compareTo(BigDecimal.valueOf(0))==0 && y.compareTo(BigDecimal.valueOf(0))==0)
    return 0;

    else

    {




for(counter=0;counter<lines.size();counter++)
  {

        
    inst=test.new line();
    inst=lines.get(counter);
             if(inst.d=='v')
             {

                 if(x.compareTo(inst.c)==0 && check_rangey(counter,y,lines)==1)
                 {
                     flag++;
                   
                     //System.out.println("ok");
                     break;

                 }
             }
             else
                 if(inst.d=='h')
             {


                	if (y.compareTo(inst.c)==0)
                 {
                     flag++;
                     //System.out.println("ok");
                     break;

                 }
             }
             else

      {


      
        r=x;
        r=r.multiply(inst.deltay);
        r=r.divide(inst.deltax,6);
        inst.c=inst.deltay.multiply(inst.x1);
        inst.c=inst.c.divide(inst.deltax,6);
        inst.c=inst.y1.subtract(inst.c);
        r=r.add(inst.c);
        
        
        
        
 
        if(y.compareTo(r)==0)
        {

            flag++;
            break;


        }


      }

}
    if(flag>0)
    return counter;
    else
    return -1;
    }

}


static int ifclosedpath(ArrayList <line> lines)
{

    if(lines.get(0).x1.compareTo(lines.get(0).x2)==0 &&  lines.get(0).y1.compareTo(lines.get(0).y2)==0)
    return 1;
    else
        return 0;
}
    





public class line
{
    public BigDecimal x1,x2,y1,y2,m,c;
    public char d;
    public BigDecimal deltay=new BigDecimal("1");
    public BigDecimal deltax=new BigDecimal("1");
    public void setX1(BigDecimal x1) {
        this.x1 = x1;
    }

    public void setX2(BigDecimal x2) {
        this.x2 = x2;
    }

    public void setY1(BigDecimal y1) {
        this.y1 = y1;
    }


    public BigDecimal getX2() {
        return x2;
    }

    public BigDecimal getY2() {
        return y2;
    }

    public BigDecimal getY1() {
        return y1;
    }

    public void setY2(BigDecimal y2) {
        this.y2 = y2;
    }
    
    public BigDecimal getX1() {
        return x1;
    }

    void makeline()
    {
        
        if((this.x1.compareTo(this.x2))==0)
        {
            this.d='v';
            this.c=BigDecimal.valueOf(0);
            this.c=this.c.add(x1);
         
           //System.out.println("ok");
            
        }
        else
            if(this.y1.compareTo(this.y2)==0)
            {
            	 this.d='h';
                 this.c=BigDecimal.valueOf(0);
                 this.c=this.c.add(y1);
            }
            else
            {
                this.d='n';
                
                this.deltay=this.y2.subtract(this.y1);
                this.deltax=this.x2.subtract(this.x1);
                
                
                
              //  this.m=(this.y2-this.y1)/(this.x2-this.x1);
                
               // this.c=this.y1-(this.m*this.x1);
            
                
            }
        
    }
    
}

    
     
static int check_range(int n,BigDecimal x,ArrayList <line> lines)
    {
    Main test=new Main();
    line inst=test.new line();
    
    inst=lines.get(n);
        if(inst.x2.compareTo(BigDecimal.valueOf(0))>0)
        {
        	if(x.compareTo(inst.x2)>=0)
        	//if(x>=inst.x2)
            return 1;
            else
            return 0;
        }
        else
        {
        	if(inst.x2.compareTo(BigDecimal.valueOf(0))==-1)
            //if(inst.x2<0)
            {
        		if(x.compareTo(inst.x2)<=0)
        		//if(x<=inst.x2)
            return 1;
            else
            return 0;
            }
        }
        return 1;
    }








static int check_rangey(int n,BigDecimal y,ArrayList <line> lines)
  {
  Main test=new Main();
  line inst=test.new line();
  
  inst=lines.get(n);
      if(inst.y2.compareTo(BigDecimal.valueOf(0))>0)
      {
      	if(y.compareTo(inst.y2)>=0)
      	//if(y>=inst.y2)
          return 1;
          else
          return 0;
      }
      else
      {
      	if(inst.y2.compareTo(BigDecimal.valueOf(0))==-1)
          //if(inst.y2<0)
          {
      		if(y.compareTo(inst.y2)<=0)
      		//if(y<=inst.y2)
          return 1;
          else
          return 0;
          }
      }
      return 1;
  }































    
    
}