import java.util.Scanner;

class Book {
    static Scanner sc = new Scanner(System.in);
    int bookId;
    String bookTitle;
    int yearOfPublication;
    String authorName;
    String publisherName;
    int numberOfAvailableCopies;
    int totalCopies;

    Book() {
        bookId = 0;
        bookTitle = "";
        yearOfPublication = 0;
        authorName = "";
        publisherName = "";
        numberOfAvailableCopies = 0;
    }

    Book(int totalCopies) {
        this.totalCopies = totalCopies;
    }

    public void setDetails(int id, String title, int year, String author, String publisher, int count) {
        bookId = id;
        bookTitle = title;
        yearOfPublication = year;
        authorName = author;
        publisherName = publisher;
        numberOfAvailableCopies = count;
    }

    public void updateDetails() {
        int id, year, count;
        String title, author, publisher;
        System.out.println("Enter the Updated Book ID: ");
        id = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter the Updated Title of the Book: ");
        title = sc.nextLine();
        System.out.println("Enter the Updated Publishing Year: ");
        year = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter the Updated Author of the Book: ");
        author = sc.nextLine();
        System.out.println("Enter the Updated Publisher of the Book: ");
        publisher = sc.nextLine();
        System.out.println("Enter the Updated No of Copies Already Issued: ");
        count = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter the Updated Total No of copies of the book: ");
        totalCopies = sc.nextInt();
        sc.nextLine();
        if (count < totalCopies) {
            setDetails(id, title, year, author, publisher, count);
        } else
            System.out.println("Total Copies Exceded!!");
    }

    public void getDetails(int id) {
        System.out.println("ID =" + bookId);
        System.out.println("Book Title = " + bookTitle);
        System.out.println("Year of Publication = " + yearOfPublication);
        System.out.println("Author Name = " + authorName);
        System.out.println("Publisher Name = " + publisherName);
        System.out.println("Number of Available Copies = " + numberOfAvailableCopies);
        System.out.println("Total Copies = " + totalCopies);
    }

    public void issue(int id) {
        if (numberOfAvailableCopies != 0)
            numberOfAvailableCopies--;
        else
            System.out.println("No books available");
    }

    public void Return(int id) {
        numberOfAvailableCopies++;
    }
}

public class LibraryManagementSystem {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter the number of objects: ");
        int size = sc.nextInt();
        Book[] objects = new Book[size];
        int id, year, count = 0;
        String title, author, publisher = "";
        for (int i = 0; i < objects.length; i++) {
            int totCopies;
            System.out.println("\nFor Book " + (i + 1) + ": ");
            objects[i] = new Book();
            System.out.println("Enter the Book ID: ");
            id = sc.nextInt();
            sc.nextLine();
            System.out.println("Enter the Title of the Book: ");
            title = sc.nextLine();
            System.out.println("Enter the Publishing Year: ");
            year = sc.nextInt();
            sc.nextLine();
            System.out.println("Enter the Author of the Book: ");
            author = sc.nextLine();
            System.out.println("Enter the Publisher of the Book: ");
            publisher = sc.nextLine();
            System.out.println("Enter the total copies of the book: ");
            totCopies = sc.nextInt();
            sc.nextLine();
            objects[i] = new Book(totCopies);
            count = totCopies;
            objects[i].setDetails(id, title, year, author, publisher, count);
        }
        System.out.print("\n");
        char ans = 'Y';
        int ch;
        while (ans == 'Y' || ans == 'y') {
            System.out.println("\n");
            System.out.println("1.Set Book Details");
            System.out.println("2.Get Book Details");
            System.out.println("3.Issue Book");
            System.out.println("4.Return Book");
            System.out.println("5.Exit");
            System.out.print("Enter your choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("\nEnter the required Book ID: ");
                    int id1 = sc.nextInt();
                    for(int i=0; i < objects.length ;i++){
                        if(objects[i].bookId == id1){
                            objects[i].updateDetails();
                        }
                    }
                    System.out.println("Book Details Were Updated!");
                    break;
                case 2:
                    System.out.println("\nEnter the required Book ID: ");
                    int id2 = sc.nextInt();
                    for(int i=0; i < objects.length ;i++){
                        if(objects[i].bookId == id2){
                            objects[i].getDetails(id2);
                        }
                    }
                    System.out.println("Book Details Were Updated!");
                    break;
                case 3:
                    System.out.println("Enter the id you want?");
                    int id3 = sc.nextInt();
                    for (int i = 0; i < 5; i++) {
                        if (id3 == objects[i].bookId) {
                            objects[i].issue(id3);
                            break;
                        }
                    }
                    System.out.println("Book Issued !!");
                    break;
                    case 4:
                    System.out.println("Enter the id you want?");
                    int id4 = sc.nextInt();
                    for (int i = 0; i < 5; i++) {
                        if (id4 == objects[i].bookId) {
                            objects[i].Return(id4);;
                            break;
                        }
                    }
                    System.out.println("Book Returned !!");
                    break;
                case 5:
                    System.out.println("Exit from system");
                    break;
                default:
                    System.out.println("Invalid choice, try again");
            }
            System.out.print("Do you want to continue(y/n)? ");
            ans = sc.next().charAt(0);
    }
}
}
