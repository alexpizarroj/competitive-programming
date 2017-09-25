import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    OutputWriter out = new OutputWriter(System.out);
    int n, test = 1;
    while ((n = in.readInt()) > 0) {
        Solver ss = new Solver(in, out);
        out.printLine(String.format("Case %d: %s", test++, ss.solve(n)));
    }
    out.close();
  }

}

class Solver {

  private InputReader in;
  private OutputWriter out;
  private static final Map<Integer, Character> code_to_char;

  static {
      Map<Integer, Character> aMap = new TreeMap<>();
      aMap.put(1, '0');
      aMap.put(17, '1');
      aMap.put(9, '2');
      aMap.put(24, '3');
      aMap.put(5, '4');
      aMap.put(20, '5');
      aMap.put(12, '6');
      aMap.put(3, '7');
      aMap.put(18, '8');
      aMap.put(16, '9');
      aMap.put(4, '-');
      aMap.put(6, 's');
      code_to_char = Collections.unmodifiableMap(aMap);
  }

  public Solver(InputReader _in, OutputWriter _out) {
    in = _in;
    out = _out;
  }

  public String solve(int n) {
    int[] v = IOUtils.readIntArray(in, n);
    if (n < 29 || n % 6 != 5 || normalize(v) == false)
      return "bad code";

    // Ensure reading from left to right, with a correct start
    if (getCharacter(getCode(v, 0)) != 's')
    {
      for(int i = 0; i < n / 2; i++) {
        int temp = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = temp;
      }
      if (getCharacter(getCode(v, 0)) != 's') {
        return "bad code";
      }
    }
    // Ensure there's a correct end
    if (getCharacter(getCode(v, n - 5)) != 's') {
      return "bad code";
    }

    // Input characters recognition
    int char_count = (n - 23) / 6;
    char[] res = new char[char_count];
    for(int i = 0; i < char_count; i++) {
      char c = getCharacter(getCode(v, (i+1)*6));
      if (c == 0 || c == 's') {
        return "bad code";
      }
      res[i] = c;
    }

    // Control code #1
    int given_C = getWeight(getCharacter(getCode(v, n - 17)));
    int current_C = 0;
    for(int i = char_count-1, p = 0; i >= 0; --i, p = (p+1)%10) {
      current_C += (p+1) * getWeight(res[i]);
    }
    current_C = current_C % 11;
    if (current_C != given_C) {
      return "bad C";
    }

    // Control code #2
    int given_K = getWeight(getCharacter(getCode(v, n - 11)));
    int current_K = current_C;
    for(int i = char_count-1, p = 1; i >= 0; --i, p = (p+1)%9) {
      current_K += (p+1) * getWeight(res[i]);
    }
    current_K = current_K % 11;
    if (current_K != given_K) {
      return "bad K";
    }

    return new String(res);
  }

  public int getCode(int[] v, int start) {
    // Code recovery
    int res = 0, m = 1;
    for(int i = 4; i >= 0; i--) {
      res += v[i + start] * m;
      m *= 2;
    }
    // Narrow white bar check
    if (start+5 < v.length && v[start+5] != 0) {
      return 0;
    }
    return res;
  }

  public char getCharacter(int code) {
    if (code_to_char.containsKey(code)) {
      return code_to_char.get(code);
    }
    return 0; // Not recognized
  }

  public int getWeight(char ch) {
    if (Character.isDigit(ch)) {
      return (ch - '0');
    } else if (ch == '-') {
      return 10;
    }
    return -1; // Not recognized
  }

  public boolean normalize(int[] v) {
    int[] alt = new int[v.length];
    int lowest = 201;
    for(int i = 0; i < v.length; i++) {
      lowest = Math.min(v[i], lowest);
    }

    double separator = lowest * 1.5;
    int highest = 0;
    lowest = 201;
    for(int i = 0; i < v.length; i++) {
      if (v[i] < separator) {
        alt[i] = 0;
        lowest = Math.min(lowest, 2*v[i]);
        highest = Math.max(highest, 2*v[i]);
      } else {
        alt[i] = 1;
        lowest = Math.min(lowest, v[i]);
        highest = Math.max(highest, v[i]);
      }
    }

    boolean good = (lowest >= 95.0 * highest / 105.0);
    if (good) {
      for(int i = 0; i < v.length; i++) {
        v[i] = alt[i];
      }
    }

    return good;
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
