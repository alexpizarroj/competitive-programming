import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    OutputWriter out = new OutputWriter(System.out);
    int test = 1;
    while (true) {
      try
      {
        String s = in.next();
        Solver ss = new Solver(in, out);
        String line = String.format("Case %d: %d", test++, ss.solve());
        out.printLine(line);
      } catch (InputMismatchException e) {
        break;
      }
    }
    out.close();
  }

}

class Solver {

  private InputReader in;
  private OutputWriter out;
  private static int[] energy;

  static {
    energy = new int[10];
    energy[0] = 6;
    energy[1] = 2;
    energy[2] = 5;
    energy[3] = 5;
    energy[4] = 4;
    energy[5] = 5;
    energy[6] = 6;
    energy[7] = 3;
    energy[8] = 7;
    energy[9] = 6;
  }

  public Solver(InputReader _in, OutputWriter _out) {
    in = _in;
    out = _out;
  }

  public int solve() {
    int last = getTime(in.next()), current, ans = 0;
    int[] score = new int[2];
    while (true)
    {
      String kind = in.next();
      current = getTime(in.next());

      int used_power = (current - last);
      used_power *= getPower(score[0]) + getPower(score[1]);
      ans += used_power;
      last = current;

      if (kind.charAt(0) == 'S') {
        int team = (in.next().compareTo("home") == 0 ? 0 : 1);
        int points = in.readInt();
        score[team] += points;
      } else {
        break;
      }
    }
    return ans;
  }

  public int getTime(String s) {
    String[] time = s.split(":");
    int res = 0;
    res += Integer.parseInt(time[0]) * 3600;
    res += Integer.parseInt(time[1]) * 60;
    res += Integer.parseInt(time[2]);
    return res;
  }

  public int getPower(int x) {
    int res = 0;
    do {
      int number = x % 10;
      res += energy[number];
      x /= 10;
    } while (x > 0);
    return res;
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
