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
      out.printLine(ss.solve());
    }
    out.close();
  }

}

class Solver {

  private InputReader in;
  private OutputWriter out;

  public Solver(InputReader _in, OutputWriter _out) {
    in = _in;
    out = _out;
  }

  public String solve() {
    final double g = 9810;
    int l, d, h, v;
    l = in.readInt();
    d = in.readInt();
    h = in.readInt();
    v = in.readInt();
    double t = Math.sqrt(Double.valueOf(2 * h) / g);
    double p = v * t;

    if (d > 0) {
      if (p <= d - 500) {
        return "FLOOR";
      } else if (p <= d) {
        return "EDGE";
      }
    }

    if (l > 0) {
      if (p <= d + 500) {
        return "EDGE";
      } else if (p <= d + l - 500) {
        return "POOL";
      } else if (p <= l) {
        return "EDGE";
      }
    }

    if (p <= d + l + 500) {
      return "EDGE";
    }
    return "FLOOR";
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
