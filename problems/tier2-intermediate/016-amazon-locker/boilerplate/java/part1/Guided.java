import java.util.*;

// Data class (given).
class LockerOp {
    public String kind;
    public String s1;
    public String s2;
    public int i1;
    public int i2;

    public LockerOp(String kind, String s1, String s2, int i1, int i2) {
        this.kind = kind;
        this.s1 = s1;
        this.s2 = s2;
        this.i1 = i1;
        this.i2 = i2;
    }

    public LockerOp(String kind) {
        this(kind, "", "", 0, 0);
    }
}

// HINT: introduce an abstraction so new variants don't change existing code.
public class Solution {
    // HINT: start from what this must return, then work backwards to the state it needs.
    public static List<String> locker_simulate(List<LockerOp> ops) {
        // TODO: write your solution
        return null;
    }

}
