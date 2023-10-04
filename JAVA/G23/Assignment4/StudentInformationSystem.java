import java.util.Scanner;

class Student {
    static Scanner sc = new Scanner(System.in);
    int studentID;
    String studentName;
    int studentAge;
    String studentMajor;
    float studentGPA;
    static int totalStudentsEnrolled;
    String studentAddress;

    Student() {
        studentID = 0;
        studentName = "";
        studentAge = 0;
        studentMajor = "";
        studentGPA = 0.0f;
        studentAddress = "";
        totalStudentsEnrolled++;
    }

    public void setDetails(int id, String name, int age, String major, float GPA, String address) {
        studentID = id;
        studentName = name;
        studentAge = age;
        studentMajor = major;
        studentGPA = GPA;
        studentAddress = address;
    }

    public void getDetails(int id) {
        System.out.println("Student ID = " + id);
        System.out.println("Student Name = " + studentName);
        System.out.println("Student Age = " + studentAge);
        System.out.println("Student Major = " + studentMajor);
        System.out.println("Student GPA = " + studentGPA);
        System.out.println("Student Address is = "+ studentAddress);
    }

    public void updateDetails(int id) {
        String name;
        int age;
        String major;
        float GPA;
        String address;
        System.out.print("Enter the updated Student ID: ");
        id = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter the updated Student Name: ");
        name = sc.nextLine();
        System.out.print("Enter the updated Student Age: ");
        age = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter the updated Student Major: ");
        major = sc.nextLine();
        System.out.print("Enter the updated Student GPA: ");
        GPA = sc.nextFloat();
        System.out.print("Enter the updated Student Address: ");
        address = sc.nextLine();
        setDetails(id, name, age, major, GPA,address);
    }

    public float getGPA(int id) {
        return studentGPA;
    }

    public void updateGPA(int id, float newGPA) {
        studentGPA = newGPA;
    }

    static int totalStudents() {
        return totalStudentsEnrolled;
    }

    public int getID(){
        return studentID;
    }
}

public class StudentInformationSystem {
    static Scanner sc = new Scanner(System.in);
    public static void studentCompare(int id1, int id2, Student[] arr) {
        int i = 0;
        int j = 0;
        int flag1=0,flag2 =0;
        for (int k = 0; k < arr.length; k++) {
            if (arr[k].getID()==id1){
                i=k;
                flag1 = 1;
            } else if (arr[k].getID()==id2){
                j=k;
                flag2 = 1;
            }
        }
        if (flag1 ==0 && flag2 ==0)
            System.out.println("Both IDs are invalid");
        else if (flag1==0)
            System.out.println("Invalid ID of student 1");
        else if (flag2 ==0)
            System.out.println("Invalid ID of student 2");
        else {
            System.out.println("Here are the details of the student with getter GPA:");
            if (arr[i].getGPA(id1) > arr[j].getGPA(id2))
                arr[i].getDetails(id1);
            else if (arr[i].getGPA(id1) == arr[j].getGPA(id2)) {
                System.out.println("Both students have same GPA.");
            } else
                arr[j].getDetails(id2);
        }
    }
    public static void main(String[] args) {
        System.out.print("Enter the number of objects: ");
        int size = sc.nextInt();
        Student[] stuObj = new Student[size];
        int id, age;
        float GPA;
        String name, major, address;
        for (int i = 0; i < size; i++) {
            stuObj[i] = new Student();
            System.out.println("\nFor student " + (i + 1) + ": ");
            System.out.print("Enter the Student ID: ");
            id = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter the Student Name: ");
            name = sc.nextLine();
            System.out.print("Enter the Student Age: ");
            age = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter the Student Major: ");
            major = sc.nextLine();
            System.out.print("Enter the Student GPA: ");
            GPA = sc.nextFloat();
            sc.nextLine();
            System.out.print("Enter the Student Address: ");
            address = sc.nextLine();
            stuObj[i].setDetails(id, name, age, major, GPA, address);
        }
        char ans = 'Y';
        int ch;
        while (ans == 'Y' || ans == 'y') {
            System.out.println("\n");
            System.out.println("1.Update Student Details");
            System.out.println("2.Get Student Details");
            System.out.println("3.Update Student GPA");
            System.out.println("4.Get Total Students");
            System.out.println("5.Compare Student");
            System.out.println("6.Exit");
            System.out.print("Enter your choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("\nEnter the required Student ID: ");
                    int id1 = sc.nextInt();
                    for (int i = 0; i < stuObj.length; i++) {
                        if (stuObj[i].studentID == id1) {
                            stuObj[i].updateDetails(id1);
                        }
                    }
                    System.out.println("Student Details Were Updated!");
                    break;
                case 2:
                    System.out.println("\nEnter the required Student ID: ");
                    int id2 = sc.nextInt();
                    for (int i = 0; i < stuObj.length; i++) {
                        if (stuObj[i].studentID == id2) {
                            System.out.println("Student Details Are: ");
                            stuObj[i].getDetails(id2);
                        }
                    }
                    break;
                case 3:
                    System.out.println("\nEnter the required Student ID: ");
                    int id3 = sc.nextInt();
                    float newGPA = 0.0f;
                    for (int i = 0; i < stuObj.length; i++) {
                        if (stuObj[i].studentID == id3) {
                            System.out.print("Enter the updated GPA: ");
                            newGPA = sc.nextFloat();
                            stuObj[i].updateGPA(id3, newGPA);
                        }
                    }
                    System.out.print("The Updated Student GPA Is: ");
                    for (int i = 0; i < stuObj.length; i++) {
                        if (stuObj[i].studentID == id3) {
                            System.out.print(stuObj[i].getGPA(id3) + "\n");
                        }
                    }
                    break;
                case 4:
                    int totalStudents = Student.totalStudents();
                    System.out.println("Total No of Students Are: " + totalStudents);
                    break;
                case 5:
                    int id4;
                    int id5;
                    System.out.print("Enter the id of the first student: ");
                    id4= sc.nextInt();
                    System.out.print("Enter the id of the second student: ");
                    id5= sc.nextInt();
                    studentCompare(id4,id5,stuObj);
                    break;
                case 6:
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
