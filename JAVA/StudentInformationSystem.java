import java.util.Scanner;
import java.util.ArrayList;

class Student {
    static Scanner sc = new Scanner(System.in);
    int studentID;
    String studentName;
    int studentAge;
    String studentMajor;
    float studentGPA;
    static int totalStudentsEnrolled;

    Student() {
        studentID = 0;
        studentName = "";
        studentAge = 0;
        studentMajor = "";
        studentGPA = 0.0f;
        totalStudentsEnrolled++;
    }

    public void setDetails(int id, String name, int age, String major, float GPA) {
        studentID = id;
        studentName = name;
        studentAge = age;
        studentMajor = major;
        studentGPA = GPA;
    }

    public void getDetails(int id) {
        System.out.println("Student ID = " + id);
        System.out.println("Student Name = " + studentName);
        System.out.println("Student Age = " + studentAge);
        System.out.println("Student Major = " + studentMajor);
        System.out.println("Student GPA = " + studentGPA);
    }

    public void updateDetails(int id) {
        String name;
        int age;
        String major;
        float GPA;
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
        setDetails(id, name, age, major, GPA);
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

    public void decrementStudentCount(){
        totalStudentsEnrolled--;
    }

    public int getID(){
        return studentID;
    }
}

public class StudentInformationSystem {
    static Scanner sc = new Scanner(System.in);
    public static void studentCompare(int id1, int id2, ArrayList<Student> arr) {
        int i = 0;
        int j = 0;
        int flag1=0,flag2 =0;
        for (int k = 0; k < arr.size(); k++) {
            if (arr.get(k).getID()==id1){
                i=k;
                flag1 = 1;
            } else if (arr.get(k).getID()==id2){
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
            if (arr.get(i).getGPA(id1) > arr.get(j).getGPA(id2))
                arr.get(i).getDetails(id1);
            else if (arr.get(i).getGPA(id1) == arr.get(j).getGPA(id2)) {
                System.out.println("Both students have same GPA.");
            } else
                arr.get(j).getDetails(id2);
        }
    }
    public static void main(String[] args) {
        System.out.print("Enter the number of objects: ");
        int size = sc.nextInt();
        //Student[] stuObj = new Student[size];
        ArrayList<Student> stuObj = new ArrayList<Student>();
        int id, age;
        float GPA;
        String name, major;
        for (int i = 0; i < size; i++) {
            Student Obj = new Student();
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
            Obj.setDetails(id, name, age, major, GPA);
            stuObj.add(Obj);
        }
        char ans = 'Y';
        int ch;
        while (ans == 'Y' || ans == 'y') {
            System.out.println("\n");
            System.out.println("1.Set New Student Details");
            System.out.println("2.Remove Student");
            System.out.println("3.Update Student Details");
            System.out.println("4.Get Student Details");
            System.out.println("5.Update Student GPA");
            System.out.println("6.Get Total Students");
            System.out.println("7.Compare Students");
            System.out.println("8.Exit");
            System.out.print("Enter your choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    Student newObj = new Student();
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

                    newObj.setDetails(id, name, age, major, GPA);
                    stuObj.add(newObj);
                    break;
                case 2:
                    System.out.print("Enter the Student ID: ");
                    int id1 = sc.nextInt();
                    for (int i = 0; i < stuObj.size(); i++) {
                        if (stuObj.get(i).studentID == id1) {
                            stuObj.get(i).decrementStudentCount();
                            stuObj.remove(i);
                        }
                    }
                    break;
                case 3:
                    System.out.println("\nEnter the required Student ID: ");
                    int id2 = sc.nextInt();
                    for (int i = 0; i < stuObj.size(); i++) {
                        if (stuObj.get(i).studentID == id2) {
                            stuObj.get(i).updateDetails(id2);
                        }
                    }
                    System.out.println("Student Details Were Updated!");
                    break;
                case 4:
                    System.out.println("\nEnter the required Student ID: ");
                    int id3 = sc.nextInt();
                    for (int i = 0; i < stuObj.size(); i++) {
                        if (stuObj.get(i).studentID == id3) {
                            System.out.println("Student Details Are: ");
                            stuObj.get(i).getDetails(id3);
                        }
                    }
                    break;
                case 5:
                    System.out.println("\nEnter the required Student ID: ");
                    int id4 = sc.nextInt();
                    float newGPA = 0.0f;
                    for (int i = 0; i < stuObj.size(); i++) {
                        if (stuObj.get(i).studentID == id4) {
                            System.out.print("Enter the updated GPA: ");
                            newGPA = sc.nextFloat();
                            stuObj.get(i).updateGPA(id4, newGPA);
                        }
                    }
                    System.out.print("The Updated Student GPA Is: ");
                    for (int i = 0; i < stuObj.size(); i++) {
                        if (stuObj.get(i).studentID == id4) {
                            System.out.print(stuObj.get(i).getGPA(id4) + "\n");
                        }
                    }
                    break;
                case 6:
                    int totalStudents = Student.totalStudents();
                    System.out.println("Total No of Students Are: " + totalStudents);
                    break;
                case 7:
                    int id5;
                    int id6;
                    System.out.print("Enter the id of the first student: ");
                    id5= sc.nextInt();
                    System.out.print("Enter the id of the second student: ");
                    id6= sc.nextInt();
                    studentCompare(id5,id6,stuObj);
                    break;
                case 8:
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

