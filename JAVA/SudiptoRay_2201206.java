import java.util.ArrayList;
import java.util.Scanner;

// import java.util.Scanner;
class User {
    String Name;
    int dateOfBirth;
    String Address;
    int PAN;

    public User() {
        Name = "";
        dateOfBirth = 0;
        Address = "";
        PAN = 0;
    }
}

class SuperUser extends User {
    int SuperUserID;
    int password;
    int dateOfJoining;
    float salary;
    ArrayList<String> permissibleOperations;

    public SuperUser() {
        SuperUserID = 0;
        password = 0;
        dateOfJoining = 0;
        salary = 0.0f;
        permissibleOperations = new ArrayList<>();
    }

    // Method to add a new stock item
    public void addNewStock(ArrayList<Item> stock, Item newItem) {
        stock.add(newItem);
    }

    // Method to delete stock item by item code
    public void deleteStock(ArrayList<Item> stock, int itemCode) {
        // Iterate through the stock to find the item with the given itemCode
        for (Item item : stock) {
            if (item.itemCode == itemCode) {
                // Check if available quantity is zero before deleting
                if (item.AvailableQty == 0) {
                    stock.remove(item);
                    System.out.println("Item with item code " + itemCode + " deleted.");
                } else {
                    System.out.println("Item with item code " + itemCode
                            + " cannot be deleted as available quantity is not zero.");
                }
                return;
            }
        }
        System.out.println("Item with item code " + itemCode + " not found.");
    }

    // Method to modify stock item by item code
    public void modifyStock(ArrayList<Item> stock, int itemCode, float newPrice, int newAvailableQty) {
        // Iterate through the stock to find the item with the given itemCode
        for (Item item : stock) {
            if (item.itemCode == itemCode) {
                // Update the item's details
                item.price = newPrice;
                item.AvailableQty = newAvailableQty;
                System.out.println("Item with item code " + itemCode + " modified.");
                return;
            }
        }
        System.out.println("Item with item code " + itemCode + " not found.");
    }
}

class NormalUser extends User {
    int userID;
    int dateOfJoining;
    float salary;
    int dutyHourPerDay;

    public NormalUser() {
        userID = 0;
        dateOfJoining = 0;
        salary = 0.0f;
        dutyHourPerDay = 0;
    }

    // Method to sell an item
    public void sellItem(ArrayList<Item> stock, ArrayList<Sell> sales, int itemCode, int quantity, int dateOfSell) {
        // Find the item in stock
        for (Item item : stock) {
            if (item.itemCode == itemCode) {
                if (item.AvailableQty >= quantity) {
                    // Create a new sell record
                    Sell sell = new Sell(dateOfSell, itemCode, quantity, item.price);
                    sales.add(sell);
                    // Update available quantity in stock
                    item.AvailableQty -= quantity;
                    System.out.println("Item with item code " + itemCode + " sold.");
                } else {
                    System.out.println("Not enough quantity available for item with item code " + itemCode + ".");
                }
                return;
            }
        }
        System.out.println("Item with item code " + itemCode + " not found.");
    }

    // Method to return an item
    public void returnItem(ArrayList<Item> stock, ArrayList<Return> returns, int itemCode, int quantity,
            int dateOfReturn) {
        // Find the item in stock
        for (Item item : stock) {
            if (item.itemCode == itemCode) {
                if (!(item instanceof Consumables)) { // Check if it's not a food item
                    // Create a new return record
                    Return returnRecord = new Return(dateOfReturn, itemCode, quantity, item.price * quantity);
                    returns.add(returnRecord);
                    // Update available quantity in stock
                    item.AvailableQty += quantity;
                    System.out.println("Item with item code " + itemCode + " returned.");
                } else {
                    System.out.println("Food item with item code " + itemCode + " cannot be returned.");
                }
                return;
            }
        }
        System.out.println("Item with item code " + itemCode + " not found.");
    }

    // Method to display stock by item code
    public void displayStock(ArrayList<Item> stock, int itemCode) {
        for (Item item : stock) {
            if (item.itemCode == itemCode) {
                System.out.println("Item Code: " + item.itemCode);
                System.out.println("Price: " + item.price);
                System.out.println("Available Quantity: " + item.AvailableQty);
                return;
            }
        }
        System.out.println("Item with item code " + itemCode + " not found in stock.");
    }

    // Method to display items which are going to be Expired
    // public void displayToBeExpiredItems(ArrayList<Sell>
    // sales,ArrayList<Consumables> consumabl, int m){
    // for(Sell item : ToBeExpired){
    // if(item.dateOfSell + m >= item.dateOfExpiry){

    // }
    // }
    // }

    // Method to display sold items within a date range
    public void displaySell(ArrayList<Sell> sales, int startDate, int endDate) {
        for (Sell sell : sales) {
            if (sell.dateOfSell >= startDate && sell.dateOfSell <= endDate) {
                System.out.println("Date of Sell: " + sell.dateOfSell);
                System.out.println("Item Code: " + sell.itemCode);
                System.out.println("Quantity Sold: " + sell.quantity);
                System.out.println("Total Amount: " + sell.totalAmount);
            }
        }
    }
}

class Item {
    int itemCode;
    float price;
    int AvailableQty;

    public Item() {
        itemCode = 0;
        price = 0.0f;
        AvailableQty = 0;
    }

    public Item(int itemCode, float price, int AvailableQty) {
        this.itemCode = itemCode;
        this.price = price;
        this.AvailableQty = AvailableQty;
    }
}

class Consumables extends Item {
    int dateOfExpiry;

    public Consumables() {
        dateOfExpiry = 0;
    }

    public Consumables(int itemCode, float price, int AvailableQty, int dateOfExpiry) {
        super(itemCode, price, AvailableQty);
        this.dateOfExpiry = dateOfExpiry;
    }
}

class NonConsumables extends Item {
    int returnCount;

    public NonConsumables() {
        returnCount = 0;
    }

    public NonConsumables(int itemCode, float price, int AvailableQty, int returnCount) {
        super(itemCode, price, AvailableQty);
        this.returnCount = returnCount;
    }
}

class Sell {
    int dateOfSell;
    int itemCode;
    int quantity;
    float totalAmount;

    public Sell() {
        dateOfSell = 0;
        itemCode = 0;
        quantity = 0;
        totalAmount = 0.0f;
    }

    public Sell(int dateOfSell, int itemCode, int quantity, float pricePerUnit) {
        this.dateOfSell = dateOfSell;
        this.itemCode = itemCode;
        this.quantity = quantity;
        this.totalAmount = quantity * pricePerUnit;
    }
}

class Return {
    int dateOfReturn;
    int itemCode;
    int quantity;
    float returnAmount;

    public Return() {
        dateOfReturn = 0;
        itemCode = 0;
        quantity = 0;
        returnAmount = 0.0f;
    }

    public Return(int dateOfReturn, int itemCode, int quantity, float pricePerUnit) {
        this.dateOfReturn = dateOfReturn;
        this.itemCode = itemCode;
        this.quantity = quantity;
        this.returnAmount = quantity * pricePerUnit;
    }
}

public class SudiptoRay_2201206 {
    static Scanner sc = new Scanner(System.in);
    static SuperUser superUser;
    static ArrayList<NormalUser> normalUsers = new ArrayList<>();

    public static void main(String[] args) {
        char ans = 'Y';
        int ch;

        while (ans == 'Y' || ans == 'y') {
            System.out.println("\nMain Menu:");
            System.out.println("1. Setup");
            System.out.println("2. SuperUser mode");
            System.out.println("3. NormalUser User mode");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            ch = sc.nextInt();

            switch (ch) {
                case 1:
                    setup();
                    break;

                case 2:
                    superUserMode();
                    break;

                case 3:
                    normalUserMode();
                    break;

                case 4:
                    ans = 'N';
                    break;

                default:
                    System.out.println("Invalid choice. Please select a valid option.");
            }
        }
    }

    public static void setup() {
        System.out.println("Setting up the system...");

        // Create a SuperUser
        superUser = new SuperUser();
        superUser.Name = "SuperUser";
        superUser.SuperUserID = 1; // Assuming SuperUserID is always 1
        superUser.password = 12345; // Set a password for the SuperUser

        // Create NormalUsers
        int numNormalUsers = 2; // Change this as needed
        for (int i = 0; i < numNormalUsers; i++) {
            NormalUser normalUser = new NormalUser();
            normalUser.userID = i + 1; // UserID starts from 1
            normalUsers.add(normalUser);
        }

        System.out.println("System setup completed.");
    }

    public static void superUserMode() {
        System.out.println("\nSuperUser Mode");
        System.out.print("Enter SuperUser password: ");
        int password = sc.nextInt();

        if (superUser.password == password) {
            char ans = 'Y';

            while (ans == 'Y' || ans == 'y') {
                // SuperUser operations here
                System.out.println("SuperUser operations go here...");
                // Implement SuperUser operations as needed

                System.out.print("Do you want to perform another SuperUser operation (Y/N)? ");
                ans = sc.next().charAt(0);
            }
        } else {
            System.out.println("Invalid password. Access denied.");
        }
    }

    public static void normalUserMode() {
        System.out.println("\nNormalUser Mode");

        System.out.print("Enter User ID: ");
        int userID = sc.nextInt();
        NormalUser currentUser = findNormalUserByID(userID);

        if (currentUser != null) {
            char ans = 'Y';

            while (ans == 'Y' || ans == 'y') {
                // NormalUser operations here
                System.out.println("NormalUser operations go here...");
                // Implement NormalUser operations as needed

                System.out.print("Do you want to perform another NormalUser operation (Y/N)? ");
                ans = sc.next().charAt(0);
            }
        } else {
            System.out.println("User with ID " + userID + " not found.");
        }
    }

    public static NormalUser findNormalUserByID(int userID) {
        for (NormalUser user : normalUsers) {
            if (user.userID == userID) {
                return user;
            }
        }
        return null;
    }
}