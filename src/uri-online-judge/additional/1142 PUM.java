import java.io.*;
import java.util.*;


public class Main
{
    
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), cur = 1, i = 0;
        PrintWriter writer = new PrintWriter(
                    new BufferedWriter( new OutputStreamWriter(System.out) )
                );
        
        while ( i < n )
        {
            writer.println( (cur) + " " + (cur+1) + " " + (cur+2) + " PUM" );
            cur += 4;
            ++i;
        }       
        
        writer.close();
    }
    
}
