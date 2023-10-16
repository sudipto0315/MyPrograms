import java.util.*;

class Student implements Comparable<Student> {
    String name;
    int roll;
    String birthyear;

    Student(String name, int roll, String birthyear) {
        this.name = name;
        this.roll = roll;
        this.birthyear = birthyear;
    }

    @Override
    public int compareTo(Student that) {
        return this.name.split(" ")[0].compareTo(that.name.split(" ")[0]);
    }

    public int compareByTitle(Student that) {
        return this.name.split(" ")[1].compareTo(that.name.split(" ")[1]);
    }

    public int compareByRoll(Student that) {
        if (this.roll > that.roll)
            return -1;
        else if (this.roll < that.roll)
            return 1;
        else
            return 0;
    }

    public int compareByBirthyear(Student that) {
        return this.birthyear.compareTo(that.birthyear);
    }

    @Override
    public String toString() {
        return name + "," + roll + "," + birthyear;
    }
}

public class ComparableExample {
    public static void main(String[] args) {

        String name;
        int roll;
        String birthyear;
        Scanner sc = new Scanner(System.in);

        ArrayList<Student> studentList = new ArrayList<Student>();
        for (int i = 0; i < 5; i++) {
            System.out.println("\nFor student- " + (i + 1) + ": ");
            System.out.print("Enter name: ");
            name = sc.nextLine();
            System.out.print("Enter roll: ");
            roll = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter birth year: ");
            birthyear = sc.nextLine();

            Student obj = new Student(name, roll, birthyear);
            studentList.add(obj);
        }

        // Collections.sort(studentList);
        Collections.sort(studentList,Student::compareTo);
        System.out.println("\nStudents sorted with respect to first name");
        for (Student x : studentList) {
            System.out.println(x);
        }

        Collections.sort(studentList,Student::compareByTitle);

        System.out.println("\nStudents sorted with respect to title");
        for (Student x : studentList) {
            System.out.println(x);
        }

        studentList.sort(Student::compareByRoll);
        System.out.println("\nStudents sorted with respect to roll number");
        for (Student x : studentList) {
            System.out.println(x);
        }

        studentList.sort(Student::compareByBirthyear);
        System.out.println("\nStudents sorted with respect to birth year");
        for (Student x : studentList) {
            System.out.println(x);
        }

        sc.close();
    }
}
