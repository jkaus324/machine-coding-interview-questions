import java.util.*;

// Data class (given).
class PaymentMethod {
    public String name;
    public double cashbackRate;
    public double transactionFee;
    public int usageCount;
    public boolean easyRefundEligible;

    public PaymentMethod(String name, double cashbackRate, double transactionFee, int usageCount, boolean easyRefundEligible) {
        this.name = name;
        this.cashbackRate = cashbackRate;
        this.transactionFee = transactionFee;
        this.usageCount = usageCount;
        this.easyRefundEligible = easyRefundEligible;
    }

    public PaymentMethod(String name, double cashbackRate, double transactionFee, int usageCount) {
        this(name, cashbackRate, transactionFee, usageCount, false);
    }
}

// HINT: introduce an abstraction so new variants don't change existing code.
public class Solution {
    // HINT: start from what this must return, then work backwards to the state it needs.
    public static List<PaymentMethod> rank_by_rewards(List<PaymentMethod> methods) {
        // TODO: write your solution
        return methods;
    }

    // HINT: start from what this must return, then work backwards to the state it needs.
    public static List<PaymentMethod> rank_by_low_fee(List<PaymentMethod> methods) {
        // TODO: write your solution
        return methods;
    }

    // HINT: start from what this must return, then work backwards to the state it needs.
    public static List<PaymentMethod> rank_by_trust(List<PaymentMethod> methods) {
        // TODO: write your solution
        return methods;
    }

}
