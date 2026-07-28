import java.util.*;

// Data class (given).
class TwitterOp {
    public String kind;
    public int i1;
    public int i2;

    public TwitterOp(String kind, int i1, int i2) {
        this.kind = kind;
        this.i1 = i1;
        this.i2 = i2;
    }

    public TwitterOp(String kind) {
        this(kind, 0, 0);
    }
}

// HINT: introduce an abstraction so new variants don't change existing code.
public class Solution {
    // HINT: start from what this must return, then work backwards to the state it needs.
    public static List<String> twitter_simulate(List<TwitterOp> ops) {
        // TODO: write your solution
        return null;
    }

}
