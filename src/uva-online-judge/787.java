import java.math.*;
import java.util.*;

public class Main
{
    static BigInteger[] seq = new BigInteger[105];
    final static String cstEOS = "-999999";
    
    public static BigInteger getBest(BigInteger[] seq, int n)
    {
        BigInteger best = new BigInteger(cstEOS);
        BigInteger running, untilFirstNeg, fromLastNeg;
        int nR, nUFN, nFLN;
        
        running = new BigInteger("1");
        untilFirstNeg = new BigInteger("1");
        fromLastNeg = null;
        nR = 0; nUFN = 0; nFLN = 0;
        
        for(int i = 0; i < n; ++i)
        {
            int cmpResult = seq[i].compareTo(BigInteger.ZERO);
            if( cmpResult != 0 )
            {
                running = running.multiply( seq[i] );
                ++nR;
                if ( cmpResult > 0 )
                {
                    if ( fromLastNeg == null )
                    {
                        untilFirstNeg = untilFirstNeg.multiply( seq[i] );
                        ++nUFN;
                    }
                    else
                    {
                        fromLastNeg = fromLastNeg.multiply( seq[i] );
                        ++nFLN;
                    }
                }
                else
                {
                    if ( fromLastNeg == null ) 
                    {
                        untilFirstNeg = untilFirstNeg.multiply( seq[i] );
                        ++nUFN;
                    }
                    fromLastNeg = new BigInteger( seq[i].toString() );
                    nFLN = 1;
                }
            }
            else
            {
                // update: best vs. running
                if ( nR > 0 && best.compareTo(running) < 0 ) 
                {
                    best = running;
                }
                // update if: odd amount of negative numbers -> (-) running
                if ( running.compareTo(BigInteger.ZERO) < 0 )
                {
                    if ( nR != nFLN ) 
                    {
                        BigInteger leftSide = running.divide(fromLastNeg);
                        if ( best.compareTo(leftSide) < 0 )
                        {
                            best = leftSide;
                        }
                    }
                    if ( nR != nUFN ) 
                    {
                        BigInteger rightSide = running.divide(untilFirstNeg);
                        if ( best.compareTo(rightSide) < 0 )
                        {
                            best = rightSide;
                        }
                    }
                }
                // update: best vs. zero
                if ( best.compareTo(BigInteger.ZERO) < 0 ) 
                {
                    best = BigInteger.ZERO;
                }
                    
                running = new BigInteger("1");
                untilFirstNeg = new BigInteger("1");
                fromLastNeg = null;
                nR = 0; nUFN = 0; nFLN = 0;
            }
        }
        
        // update: best vs. running
        if ( nR > 0 && best.compareTo(running) < 0 ) 
        {
            best = running;
        }
        // update if: odd amount of negative numbers -> (-) running
        if ( running.compareTo(BigInteger.ZERO) < 0 )
        {
            if ( nR != nFLN ) 
            {
                BigInteger leftSide = running.divide(fromLastNeg);
                if ( best.compareTo(leftSide) < 0 )
                {
                    best = leftSide;
                }
            }
            if ( nR != nUFN ) 
            {
                BigInteger rightSide = running.divide(untilFirstNeg);
                if ( best.compareTo(rightSide) < 0 )
                {
                    best = rightSide;
                }
            }
        }
        
        return best;
    }
    
    public static void main(String[] args)
    {
        String value; int top = 0;
        
        Scanner in = new Scanner(System.in);
        while ( in.hasNext() )
        {
            value = in.next();
            if ( value.equals(cstEOS) )
            {
                System.out.println( getBest(seq, top) );
                top = 0;
            }
            else
            {
                seq[top++] = new BigInteger(value);
            }
        }
    }
    
}
