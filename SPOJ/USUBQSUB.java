import java.io.*;
import java.util.*;

public class BeautifulMind {
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        OutputWriter out = new OutputWriter(System.out);
        int n = in.readInt(), m = in.readInt();

        RangedFenwickTree2D f = new RangedFenwickTree2D(n + 1, n + 1);
        for (int i = 0; i < m; i++) {
            int kind, x1, y1, x2, y2;
            kind = in.readInt();
            x1 = in.readInt();
            y1 = in.readInt();
            x2 = in.readInt();
            y2 = in.readInt();
            if (kind == 1) {
                out.printLine(f.query(x1, y1, x2, y2));
            } else {
                int k = in.readInt();
                f.update(x1, y1, x2, y2, k);
            }
        }        
        out.close();
    }
    
}

class RangedFenwickTree {
    
    private final long[] data_mul;
    private final long[] data_add;
    private final int n;
    
    public RangedFenwickTree(int _n)
    {
        n = _n;
        data_mul = new long[n];
        data_add = new long[n];
        Arrays.fill(data_mul, 0);
        Arrays.fill(data_add, 0);
    }
    
    public long query(int x) {
        long mul = 0, add = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            mul += data_mul[i];
            add += data_add[i];
        }
        return mul * x + add;
    }
    
    public long query(int x, int y) {
        return query(y) - query(x - 1);
    }
    
    public void update(int x, int y, long delta) {
        internalUpdate(x, delta, -delta * (x - 1));
        if (y + 1 < n) {
            internalUpdate(y + 1, -delta, delta * y);
        }
    }
    
    private void internalUpdate(int x, long mul, long add) {
        for(int i = x; i < n; i = (i | (i + 1))) {
            data_mul[i] += mul;
            data_add[i] += add;
        }
    }

}

class RangedFenwickTree2D {
    
    private final RangedFenwickTree[] data_mul;
    private final RangedFenwickTree[] data_add;
    private final int m, n;
    
    public RangedFenwickTree2D(int _m, int _n)
    {
        m = _m;
        n = _n;
        data_mul = new RangedFenwickTree[m];
        data_add = new RangedFenwickTree[m];
        for(int i = 0; i < m; i++) {
            data_mul[i] = new RangedFenwickTree(n);
            data_add[i] = new RangedFenwickTree(n);
        }
    }
    
    public long query(int x, int y) {
        long mul = 0, add = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            mul += data_mul[i].query(y);
            add += data_add[i].query(y);
        }
        return mul * x + add;
    }
    
    public long query(int x1, int y1, int x2, int y2) {
        long result = query(x2, y2);
        if (x1 > 0)
          result -= query(x1 - 1, y2);
        if (y1 > 0)
          result -= query(x2, y1 - 1);
        if (x1 > 0 && y1 > 0)
          result += query(x1 - 1, y1 - 1);
        return result;
    }
    
    public void update(int x1, int y1, int x2, int y2, long delta) {
        for(int i = x1; i < m; i |= i + 1)
        {
          data_mul[i].update(y1, y2, delta);
          data_add[i].update(y1, y2, -delta * (x1 - 1));
        }
        for(int i = x2 + 1; i < m; i |= i + 1)
        {
          data_mul[i].update(y1, y2, -delta);
          data_add[i].update(y1, y2, delta * x2);
        }
    }

}

class InputReader {

    private InputStream stream;

    private byte[] buf = new byte[1024];

    private int curChar;

    private int numChars;

    private SpaceCharFilter filter;

    public InputReader(InputStream stream) {

        this.stream = stream;

    }

    public int read() {

        if (numChars == -1) {
            throw new InputMismatchException();
        }

        if (curChar >= numChars) {

            curChar = 0;

            try {

                numChars = stream.read(buf);

            } catch (IOException e) {

                throw new InputMismatchException();

            }

            if (numChars <= 0) {
                return -1;
            }

        }

        return buf[curChar++];

    }

    public int readInt() {

        int c = read();

        while (isSpaceChar(c)) {
            c = read();
        }

        int sgn = 1;

        if (c == '-') {

            sgn = -1;

            c = read();

        }

        int res = 0;

        do {

            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }

            res *= 10;

            res += c - '0';

            c = read();

        } while (!isSpaceChar(c));

        return res * sgn;

    }

    public String readString() {

        int c = read();

        while (isSpaceChar(c)) {
            c = read();
        }

        StringBuilder res = new StringBuilder();

        do {

            res.appendCodePoint(c);

            c = read();

        } while (!isSpaceChar(c));

        return res.toString();

    }

    public boolean isSpaceChar(int c) {

        if (filter != null) {
            return filter.isSpaceChar(c);
        }

        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;

    }

    public String next() {

        return readString();

    }

    public interface SpaceCharFilter {

        public boolean isSpaceChar(int ch);

    }

}

class OutputWriter {

    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {

        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));

    }

    public OutputWriter(Writer writer) {

        this.writer = new PrintWriter(writer);

    }

    public void print(Object... objects) {

        for (int i = 0; i < objects.length; i++) {

            if (i != 0) {
                writer.print(' ');
            }

            writer.print(objects[i]);

        }

    }

    public void printLine(Object... objects) {

        print(objects);

        writer.println();

    }

    public void close() {

        writer.close();

    }

    public void flush() {

        writer.flush();

    }

}

class IOUtils {

    public static int[] readIntArray(InputReader in, int size) {

        int[] array = new int[size];

        for (int i = 0; i < size; i++) {
            array[i] = in.readInt();
        }

        return array;

    }

}
