import java.util.Scanner;

class Account {
    static Scanner sc = new Scanner(System.in);
    int accountNumber;
    String accountType;
    String serviceBranchIFSC;
    float availableBalance;
    int customerID;
    String customerName;
    static int totalAccountCreated;

    Account() {
        accountNumber = 0;
        accountType = " ";
        serviceBranchIFSC = " ";
        availableBalance = 0.0f;
        customerID = 0;
        customerName = " ";
        totalAccountCreated++;
    }

    public void setDetails(int an, String at, String sb, float ab, int cid, String cn) {
        accountNumber = an;
        accountType = at;
        serviceBranchIFSC = sb;
        availableBalance = ab;
        customerID = cid;
        customerName = cn;
    }

    public void getDetails(int an) {
        System.out.println("\nDetails: ");
        System.out.println("Account number: " + accountNumber);
        System.out.println("Account type: " + accountType);
        System.out.println("Service branch: " + serviceBranchIFSC);
        System.out.println("Available balance: " + availableBalance);
        System.out.println("Customer ID: " + customerID);
        System.out.println("Customer name: " + customerName);
    }

    void updateDetails(int an) {
        int newAccountNumber;
        String newAccountType;
        String newServiceBranchIFSC;
        float newAvailableBalance;
        int newCustomerID;
        String newCustomerName;
        System.out.print("Enter the new account number: ");
        newAccountNumber = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter new account type: ");
        newAccountType = sc.nextLine();
        System.out.print("Enter the new service branch: ");
        newServiceBranchIFSC = sc.nextLine();
        System.out.print("Enter the new available balance: ");
        newAvailableBalance = sc.nextFloat();
        sc.nextLine();
        System.out.print("Enter the new customer ID: ");
        newCustomerID = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter the new customer name: ");
        newCustomerName = sc.nextLine();
        setDetails(newAccountNumber, newAccountType, newServiceBranchIFSC, newAvailableBalance, newCustomerID,
                newCustomerName);
    }

    void deposit(int an, float amt) {
        availableBalance += amt;
        System.out.println("Amount deposited: " + amt);
        System.out.println("New available balance: " + availableBalance);
    }

    void withdraw(int an, float amt) {
        availableBalance -= amt;
        System.out.println("Amount withdrawn: " + amt);
        System.out.println("New available balance: " + availableBalance);
    }

    static int totalAccounts() {
        return totalAccountCreated;
    }

    int getAccountNumber() {
        return accountNumber;
    }
}

class SavingsAccount extends Account {
    float interestRate;

    SavingsAccount() {
        interestRate = 0.0f;
    }

    public void setInterestRate(float rate) {
        interestRate = rate;
    }

    public void addInterest() {
        float interest = availableBalance * (interestRate / 100);
        availableBalance += interest;
        System.out.println("Interest added: " + interest);
        System.out.println("New available balance: " + availableBalance);
    }
}

class CheckingAccount extends Account {
    float overdraftLimit;

    CheckingAccount() {
        overdraftLimit = 0.0f;
    }

    public void setOverdraftLimit(float limit) {
        overdraftLimit = limit;
    }

    @Override
    void withdraw(int an, float amt) {
        if (availableBalance - amt < overdraftLimit) {
            System.out.println("Withdrawal exceeds overdraft limit.");
        } else {
            availableBalance -= amt;
            System.out.println("Amount withdrawn: " + amt);
            System.out.println("New available balance: " + availableBalance);
        }
    }
}

public class q2 {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter the number of accounts: ");
        int n = sc.nextInt();
        Account[] objects = new Account[n];
        int accnum, cID;
        String acctype, cname, sbIFSC;
        float avB, interestRate, overdraftLimit;

        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for Account " + (i + 1) + ":");
            System.out.print("Enter the account number: ");
            accnum = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter account type (Savings/Checking): ");
            acctype = sc.nextLine();
            System.out.print("Enter the service branch: ");
            sbIFSC = sc.nextLine();
            System.out.print("Enter the available balance: ");
            avB = sc.nextFloat();
            sc.nextLine();
            System.out.print("Enter customer ID: ");
            cID = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter the customer name: ");
            cname = sc.nextLine();

            if ("Savings".equalsIgnoreCase(acctype)) {
                SavingsAccount savingsAccount = new SavingsAccount();
                savingsAccount.setDetails(accnum, acctype, sbIFSC, avB, cID, cname);
                System.out.print("Enter the interest rate: ");
                interestRate = sc.nextFloat();
                savingsAccount.setInterestRate(interestRate);
                objects[i] = savingsAccount;
            } else if ("Checking".equalsIgnoreCase(acctype)) {
                CheckingAccount checkingAccount = new CheckingAccount();
                checkingAccount.setDetails(accnum, acctype, sbIFSC, avB, cID, cname);
                System.out.print("Enter the overdraft limit: ");
                overdraftLimit = sc.nextFloat();
                checkingAccount.setOverdraftLimit(overdraftLimit);
                objects[i] = checkingAccount;
            } else {
                System.out.println("Invalid account type. Please enter 'Savings' or 'Checking'.");
                i--; // Decrement i to re-enter details for this account.
            }
            System.out.print("\n");
        }

        char ans = 'y';
        while (ans == 'y' || ans == 'Y') {
            System.out.print("\n");
            System.out.println("1. Update details");
            System.out.println("2. Get details");
            System.out.println("3. Deposit");
            System.out.println("4. Withdraw");
            System.out.println("5. Calculate and add interest (Savings)");
            System.out.println("6. Total accounts created");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");
            int ch = sc.nextInt();

            switch (ch) {
                case 1:
                    System.out.print("Enter the required account number: ");
                    int id2 = sc.nextInt();
                    for (int i = 0; i < objects.length; i++) {
                        if (objects[i].getAccountNumber() == id2) {
                            objects[i].updateDetails(id2);
                        }
                    }
                    System.out.println("Account Details Were Updated!");
                    break;

                case 2:
                    System.out.print("Enter the required account number: ");
                    int id1 = sc.nextInt();
                    for (int i = 0; i < objects.length; i++) {
                        if (objects[i].getAccountNumber() == id1) {
                            objects[i].getDetails(id1);
                        }
                    }
                    break;

                case 3:
                    System.out.print("Enter the required account number: ");
                    int id4 = sc.nextInt();
                    System.out.println("Enter amount to be deposited: ");
                    float amt_d = sc.nextFloat();
                    for (int i = 0; i < objects.length; i++) {
                        if (objects[i].getAccountNumber() == id4) {
                            objects[i].deposit(id4, amt_d);
                        }
                    }
                    break;

                case 4:
                    System.out.print("Enter the required account number: ");
                    int id5 = sc.nextInt();
                    System.out.println("Enter amount to be withdrawn: ");
                    float amt_w = sc.nextFloat();
                    for (int i = 0; i < objects.length; i++) {
                        if (objects[i].getAccountNumber() == id5) {
                            objects[i].withdraw(id5, amt_w);
                        }
                    }
                    break;

                case 5:
                    System.out.print("Enter the account number for interest calculation (Savings only): ");
                    int id6 = sc.nextInt();
                    for (int i = 0; i < objects.length; i++) {
                        if (objects[i] instanceof SavingsAccount && objects[i].getAccountNumber() == id6) {
                            SavingsAccount savingsAccount = (SavingsAccount) objects[i];
                            savingsAccount.addInterest();
                        }
                    }
                    break;

                case 6:
                    int totalAccounts = Account.totalAccounts();
                    System.out.println("Total number of accounts: " + totalAccounts);
                    break;

                case 7:
                    System.out.println("Exiting the system");
                    System.exit(0);
                    break;

                default:
                    System.out.println("Invalid choice");
            }
            System.out.print("Do you want to continue? (y/n): ");
            ans = sc.next().charAt(0);
        }
    }
}