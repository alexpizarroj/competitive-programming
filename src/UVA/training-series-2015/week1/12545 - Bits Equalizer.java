import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    OutputWriter out = new OutputWriter(System.out);
    int tc = in.readInt();
    for(int i = 0; i < tc; i++) {
      Solver ss = new Solver(in, out);
      out.printLine(String.format("Case %d: %d", i + 1, ss.solve()));
    }
    out.close();
  }

}

class Solver {

  private InputReader in;
  private OutputWriter out;
  private final static int inf = 1000000007;

  public Solver(InputReader _in, OutputWriter _out) {
    in = _in;
    out = _out;
  }

  public int solve() {
    String s = in.readString();
    String t = in.readString();
    int n = s.length();
    
    int z, zz, o, oo, zeros, ones;
    z = zz = o = oo = zeros = ones = 0;
    for(int i = 0; i < n; i++) {
      if (t.charAt(i) == s.charAt(i)) {
        continue;
      }
      if (t.charAt(i) == '0') {
        zeros += 1;
        if (s.charAt(i) == '1') {
          o += 1;
        } else {
          zz += 1;
        }
      } else {
        ones += 1;
        if (s.charAt(i) == '0') {
          z += 1;
        } else {
          oo += 1;
        }
      }
    }
    
    int ans = inf;
    for(int i = 0; i <= z; i++) {
      if (ones - i >= 0) {
        ans = Math.min(ans, i+getMin(z - i, zz, o, oo, zeros, ones - i));
      }
    }
    return (ans == inf ? -1 : ans);
  }

  public int getMin(int z, int zz, int o, int oo, int zeros, int ones) {
    if (z > zeros || o > ones)
      return inf;
    if (zeros + ones == 0)
      return 0;

    /**
     * z <= zeros,        o <= ones
     * (o + zz) == zeros, (z + oo) = ones
     */
    int ans = 0;
    if (o > 0) {
      if (z > 0) {
        int taken = Math.min(o, z);
        o -= taken;
        z -= taken;
        zeros -= taken;
        ones -= taken;
        ans += taken;
      }
      if (o > 0) {
        int swapping = o;
        o = 0;
        zz += swapping;
        oo -= swapping;
        ones -= swapping;
        ans += swapping;
      }
    }

    ans += zz + z + oo;
    return ans;
  }

};

// ==================================================================

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
