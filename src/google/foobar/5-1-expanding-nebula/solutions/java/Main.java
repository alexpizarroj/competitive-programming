public class Main {
    public static void main(String[] args) {
        boolean[][] test1 = { 
            { true, false, true },
            { false, true, false },
            { true, false, true } 
        };
        boolean[][] test2 = {
            { true, false, true, false, false, true, true, true },
            { true, false, true, false, false, false, true, false },
            { true, true, true, false, false, false, true, false },
            { true, false, true, false, false, false, true, false },
            { true, false, true, false, false, true, true, true } 
        };
        boolean[][] test3 = {
            { true, true, false, true, false, true, false, true, true, false },
            { true, true, false, false, false, false, true, true, true, false },
            { true, true, false, false, false, false, false, false, false, true },
            { false, true, false, false, false, false, true, true, false, false }
        };

        System.out.println(Answer.answer(test1));
        System.out.println(Answer.answer(test2));
        System.out.println(Answer.answer(test3));
    }
}
