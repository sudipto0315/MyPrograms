import java.util.*;

class Book {
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

    void setDetails() {
        bookId = 0;
        bookTitle = "";
        yearOfPublication = 0;
        authorName = "";
        publisherName = "";
        numberOfAvailableCopies = 0;
    }

    void setDetails(int id, String title, int year, String author, String publisher, int count) {
        bookId = id;
        bookTitle = title;
        yearOfPublication = year;
        authorName = author;
        publisherName = publisher;
        numberOfAvailableCopies = count;
    }

    void getDetails(int id) {
        System.out.println("The ID of the book is " + bookId);
        System.out.println("The title of the book is " + bookTitle);
        System.out.println("The year of publication of the book is " + yearOfPublication);
        System.out.println("The author name of the book is " + authorName);
        System.out.println("The publisher name of the book is " + publisherName);
        System.out.println("The number of available copies of the book is " + numberOfAvailableCopies);
        System.out.println("The number of total copies of the book is " + totalCopies);
    }

    void issue(int id) {
        if (numberOfAvailableCopies != 0)
            numberOfAvailableCopies--;
        else
            System.out.println("No books available");
    }

    void Return(int id) {
        numberOfAvailableCopies++;
    }
}

public class prg1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Book objarrBook[] = new Book[5];
        for (int i = 0; i < 5; i++) {
            int totCopies;
            System.out.println("Enter the total copies of book " + (i + 1));
            totCopies = sc.nextInt();
            objarrBook[i] = new Book(totCopies);
            int id, year, count = 0;
            String title, author, publisher = "";
            System.out.println("Enter the initial details of the book " + (i + 1));
            System.out.println("Enter the id of the book");
            id = sc.nextInt();
            System.out.println("Enter the publishing year of the book");
            year = sc.nextInt();
            count = totCopies;
            sc.nextLine();
            System.out.println("Enter the title of the book");
            title = sc.nextLine();
            System.out.println("Enter the author of the book");
            author = sc.nextLine();
            System.out.println("Enter the publisher of the book");
            publisher = sc.nextLine();
            objarrBook[i].setDetails(id, title, year, author, publisher, count);
        }
        int choice = 0;
        do {
            System.out.println("Enter your choice:\n1)Set Details\n2)Get Details\n3)Issue\n4)Return\n5)Exit");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("Enter the id you want?");
                    int ID = sc.nextInt();
                    for (int i = 0; i < 5; i++) {
                        if (ID == objarrBook[i].bookId) {
                            System.out.println("Enter the id of the book");
                            int Id = sc.nextInt();
                            System.out.println("Enter the publishing year of the book");
                            int Year = sc.nextInt();
                            System.out.println("Enter the count of the book");
                            int Count = sc.nextInt();
                            sc.nextLine();
                            System.out.println("Enter the title of the book");
                            String Title = sc.nextLine();
                            System.out.println("Enter the author of the book");
                            String Author = sc.nextLine();
                            System.out.println("Enter the publisher of the book");
                            String Publisher = sc.nextLine();
                            objarrBook[i].setDetails(Id, Title, Year, Author, Publisher, Count);
                            break;
                        }
                    }
                    break;
                case 2:
                    System.out.println("Enter the id you want?");
                    ID = sc.nextInt();
                    for (int i = 0; i < 5; i++) {
                        if (ID == objarrBook[i].bookId) {
                            objarrBook[i].getDetails(ID);
                            break;
                        }
                    }
                    break;
                case 3:
                    System.out.println("Enter the id you want?");
                    ID = sc.nextInt();
                    for (int i = 0; i < 5; i++) {
                        if (ID == objarrBook[i].bookId) {
                            objarrBook[i].issue(ID);
                            break;
                        }
                    }
                    break;
                case 4:
                    System.out.println("Enter the id you want?");
                    ID = sc.nextInt();
                    for (int i = 0; i < 5; i++) {
                        if (ID == objarrBook[i].bookId) {
                            objarrBook[i].Return(ID);
                            break;
                        }
                    }
                    break;
                case 5:
                    System.out.println("Thank you!!!");
                default:
                    System.out.println("Invalid input");
            }
        } while (choice != 5);
        sc.close();
    }
}