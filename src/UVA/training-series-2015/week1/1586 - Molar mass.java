import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    OutputWriter out = new OutputWriter(System.out);

    Solver.atomic_weight = new int[256];
    Solver.atomic_weight['C'] = 12010;
    Solver.atomic_weight['H'] =  1008;
    Solver.atomic_weight['O'] = 16000;
    Solver.atomic_weight['N'] = 14010;

    int tc = in.readInt();
    for(int i = 0; i < tc; i++) {
      Solver ss = new Solver(in, out);
      out.printLine(ss.solve());
    }

    out.close();
  }

}

class Solver {

  public static int[] atomic_weight;
  private InputReader in;
  private OutputWriter out;

  public Solver(InputReader _in, OutputWriter _out) {
    in = _in;
    out = _out;
  }

  public String solve() {
    String s = in.readString();
    int sum = 0, n = s.length();

    char comp = 'C';
    int count = 0;
    boolean second_digit = false;

    for(int i = 0; i <= n; i++) {
      if (i == n || Character.isLetter(s.charAt(i))) {
        sum += atomic_weight[comp] * count;
        if (i < n) {
          comp = s.charAt(i);
        }
        count = 1;
        second_digit = false;
      } else {
        if (!second_digit) {
          count = s.charAt(i) - '0';
          second_digit = true;
        } else {
          count = 10 * count + (s.charAt(i) - '0');
        }
      }
    }

    return String.format("%d.%03d", sum / 1000, sum % 1000);
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
