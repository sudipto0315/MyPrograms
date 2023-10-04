import java.util.ArrayList;
import java.util.Scanner;

class User {
    int UserID;
    String name;
    int dateOfBirth;
    String Address;
    int PAN;

    public User() {
        UserID = 0;
        name = "";
        dateOfBirth = 0;
        Address = "";
        PAN = 0;
    }
}

class Admin extends User {
    int dateOfJoining;
    float salary;
    ArrayList<String> permissibleOperations;

    public Admin() {
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
                    System.out.println("Item with item code " + itemCode + " cannot be deleted as available quantity is not zero.");
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

class General extends User {
    int dateOfJoining;
    float salary;
    int dutyHourPerDay;

    public General() {
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
                if (!(item instanceof FoodItem)) { // Check if it's not a food item
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

class FoodItem extends Item {
    int dateOfExpiry;

    public FoodItem() {
        dateOfExpiry = 0;
    }

    public FoodItem(int itemCode, float price, int AvailableQty, int dateOfExpiry) {
        super(itemCode, price, AvailableQty);
        this.dateOfExpiry = dateOfExpiry;
    }
}

class NonFoodItem extends Item {
    int returnCount;

    public NonFoodItem() {
        returnCount = 0;
    }

    public NonFoodItem(int itemCode, float price, int AvailableQty, int returnCount) {
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

public class midSem2022 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Application User Manojit");

        // Initialize stock, sales, and returns ArrayLists
        ArrayList<Item> stock = new ArrayList<>();
        ArrayList<Sell> sales = new ArrayList<>();
        ArrayList<Return> returns = new ArrayList<>();

        // Create Admin and General instances
        Admin admin = new Admin();
        General general = new General();

        while (true) {
            System.out.println("Select user type (Admin/General/Exit): ");
            String userType = scanner.nextLine();

            if (userType.equalsIgnoreCase("Admin")) {
                // Admin operations
                System.out.println("Select operation (addNewStock/deleteStock/modifyStock/Exit): ");
                String operation = scanner.nextLine();

                if (operation.equalsIgnoreCase("addNewStock")) {
                    System.out.print("Enter item code: ");
                    int itemCode = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline
                    System.out.print("Enter price: ");
                    float price = scanner.nextFloat();
                    scanner.nextLine(); // Consume the newline
                    System.out.print("Enter available quantity: ");
                    int availableQty = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline

                    Item newItem = new Item(itemCode, price, availableQty);
                    admin.addNewStock(stock, newItem);
                    System.out.println("Item added to stock.");
                } else if (operation.equalsIgnoreCase("deleteStock")) {
                    System.out.print("Enter item code to delete: ");
                    int itemCode = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline
                    admin.deleteStock(stock, itemCode);
                } else if (operation.equalsIgnoreCase("modifyStock")) {
                    System.out.print("Enter item code to modify: ");
                    int itemCode = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline
                    System.out.print("Enter new price: ");
                    float newPrice = scanner.nextFloat();
                    scanner.nextLine(); // Consume the newline
                    System.out.print("Enter new available quantity: ");
                    int newAvailableQty = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline

                    admin.modifyStock(stock, itemCode, newPrice, newAvailableQty);
                } else if (operation.equalsIgnoreCase("Exit")) {
                    break;
                }
            } else if (userType.equalsIgnoreCase("General")) {
                // General operations
                System.out.println("Select operation (sellItem/returnItem/displayStock/displaySell/Exit): ");
                String operation = scanner.nextLine();

                if (operation.equalsIgnoreCase("sellItem")) {
                    System.out.print("Enter item code to sell: ");
                    int itemCode = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline
                    System.out.print("Enter quantity to sell: ");
                    int quantity = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline
                    System.out.print("Enter date of sell: ");
                    int dateOfSell = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline

                    general.sellItem(stock, sales, itemCode, quantity, dateOfSell);
                } else if (operation.equalsIgnoreCase("returnItem")) {
                    System.out.print("Enter item code to return: ");
                    int itemCode = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline
                    System.out.print("Enter quantity to return: ");
                    int quantity = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline
                    System.out.print("Enter date of return: ");
                    int dateOfReturn = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline

                    general.returnItem(stock, returns, itemCode, quantity, dateOfReturn);
                } else if (operation.equalsIgnoreCase("displayStock")) {
                    System.out.print("Enter item code to display: ");
                    int itemCode = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline
                    general.displayStock(stock, itemCode);
                } else if (operation.equalsIgnoreCase("displaySell")) {
                    System.out.print("Enter start date: ");
                    int startDate = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline
                    System.out.print("Enter end date: ");
                    int endDate = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline

                    general.displaySell(sales, startDate, endDate);
                } else if (operation.equalsIgnoreCase("Exit")) {
                    break;
                }
            } else if (userType.equalsIgnoreCase("Exit")) {
                break;
            } else {
                System.out.println("Invalid user type. Please enter 'Admin', 'General', or 'Exit'.");
            }
        }

        scanner.close();
    }
}
