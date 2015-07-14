import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

  public static void main(String[] args) {
    BufferedReader in = new BufferedReader(
      new InputStreamReader(System.in));
    OutputWriter out = new OutputWriter(System.out);
    while (true) {
      String line = null;
      try {
        line = in.readLine();
      } catch (IOException e) {
        // Let it go, let it go...
      }
      if (line == null) {
        break;
      }
      Solver ss = new Solver(in, out);
      ss.solve(line);  
    }
    out.close();
  }

}

class Solver {

  private BufferedReader in;
  private OutputWriter out;
  private static Keyboard[] kb;

  static {
    String qLayout = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    String qsLayout = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    String dLayout = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
    String dsLayout = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
    kb = new Keyboard[3];
    kb[0] = new Keyboard("asdfjkl;", qLayout, qsLayout);
    kb[1] = new Keyboard("fghj", qLayout, qsLayout);
    kb[2] = new Keyboard("ehtd", dLayout, dsLayout);
  }

  public Solver(BufferedReader _in, OutputWriter _out) {
    in = _in;
    out = _out;
  }

  public void solve(String line) {
    double[] ans = new double[kb.length];
    for(int i = 0; i < line.length(); i++) {
      if (line.charAt(i) == ' ' || line.charAt(i) == '\t') {
        continue;
      }
      for(int j = 0; j < kb.length; j++) {
        ans[j] += 2 * kb[j].getCharClosestDistance(line.charAt(i));
      }
    }

    for(int i = 0; i < ans.length; i++) {
      if (i > 0) {
        out.print(" ");
      }
      out.print(String.format("%.2f", ans[i]));
    }
    out.printLine();
  }

};

final class Keyboard {

  private String startingKeys, layout, shiftedLayout;

  public Keyboard(String myStartingKeys, String myLayout,
    String myShiftedLayout) {
    startingKeys = myStartingKeys;
    layout = myLayout;
    shiftedLayout = myShiftedLayout;
  }

  public double getCharClosestDistance(char c) {
    double res = 100000;
    int[] dst = getCharCoordinates(c);
    for(int i = 0; i < startingKeys.length(); i++) {
      int[] src = getCharCoordinates(startingKeys.charAt(i));
      double alt = Math.hypot(src[0] - dst[0], src[1] - dst[1]);
      if (alt < res) {
        res = alt;
      }
    }
    return res;
  }

  public int[] getCharCoordinates(char c) {
    int[] res = new int[2];
    int pos = layout.indexOf(c);
    if (pos == -1) {
      pos = shiftedLayout.indexOf(c);
    }

    if (pos < 13) {
      res[0] = pos;
      res[1] = 0;
    } else if (pos < 26) {
      res[0] = (pos - 13) + 1;
      res[1] = 1;
    } else if (pos < 37) {
      res[0] = (pos - 26) + 1;
      res[1] = 2;
    } else {
      res[0] = (pos - 37) + 1;
      res[1] = 3;
    }

    return res;
  }

}

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
