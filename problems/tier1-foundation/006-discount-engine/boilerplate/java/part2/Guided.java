import java.util.*;

// Data class (given).
class CartItem {
    public String name;
    public double price;
    public int quantity;
    public String category;

    public CartItem(String name, double price, int quantity, String category) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
        this.category = category;
    }

    public CartItem(String name, double price, int quantity) {
        this(name, price, quantity, "");
    }
}

// HINT: introduce an abstraction so new variants don't change existing code.
public class Solution {
    // HINT: start from what this must return, then work backwards to the state it needs.
    public static double apply_percentage_discount(List<CartItem> cart, double percentage) {
        // TODO: write your solution
        return 0.0;
    }

    // HINT: start from what this must return, then work backwards to the state it needs.
    public static double apply_flat_discount(List<CartItem> cart, double amount) {
        // TODO: write your solution
        return 0.0;
    }

    // HINT: start from what this must return, then work backwards to the state it needs.
    public static double apply_bogo(List<CartItem> cart, int buyCount, int freeCount) {
        // TODO: write your solution
        return 0.0;
    }

}
