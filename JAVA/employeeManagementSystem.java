import java.util.ArrayList;
import java.util.Scanner;

class Employee {
    static Scanner sc = new Scanner(System.in);
    int employeeID;
    String employeeName;
    double employeeSalary;
    static int totalEmployeeCreated;

    Employee() {
        employeeID = 0;
        employeeName = "";
        employeeSalary = 0.0;
        totalEmployeeCreated++;
    }

    public void setDetails(int id, String name, double salary) {
        employeeID = id;
        employeeName = name;
        employeeSalary = salary;
    }

    public void getDetails(int id) {
        System.out.println("Employee ID = " + id);
        System.out.println("Employee Name = " + employeeName);
        System.out.println("Employee Age = " + employeeSalary);
    }

    public void updateDetails(int id) {
        String name;
        double salary;
        System.out.print("Enter the updated Employee ID: ");
        id = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter the updated Employee Name: ");
        name = sc.nextLine();
        System.out.print("Enter the updated Employee Salary: ");
        salary = sc.nextDouble();
        sc.nextLine();
        setDetails(id, name, salary);
    }

    public double getSalary(int id) {
        return employeeSalary;
    }

    public void updatedSalary(int id, double newSalary) {
        employeeSalary = newSalary;
    }

    public boolean removeEmployee(int id1) {
        totalEmployeeCreated--;
        return true;
    }

    static int totalEmployees() {
        return totalEmployeeCreated;
    }

    public int getID() {
        return employeeID;
    }
}

public class employeeManagementSystem {
    static Scanner sc = new Scanner(System.in);

    public static void employeeCompare(int id1, int id2, ArrayList<Employee> arr) {
        int i = 0;
        int j = 0;
        int flag1 = 0, flag2 = 0;
        for (int k = 0; k < arr.size(); k++) {
            if (arr.get(k).getID() == id1) {
                i = k;
                flag1 = 1;
            } else if (arr.get(k).getID() == id2) {
                j = k;
                flag2 = 1;
            }
        }
        if (flag1 == 0 && flag2 == 0)
            System.out.println("Both IDs are invalid");
        else if (flag1 == 0)
            System.out.println("Invalid ID of Employee 1");
        else if (flag2 == 0)
            System.out.println("Invalid ID of Employee 2");
        else {
            System.out.println("Here are the details of the Employee with getter Salary:");
            if (arr.get(i).getSalary(id1) > arr.get(j).getSalary(id2))
                arr.get(i).getDetails(id1);
            else if (arr.get(i).getSalary(id1) == arr.get(j).getSalary(id2)) {
                System.out.println("Both Employees have same Salary.");
            } else
                arr.get(j).getDetails(id2);
        }
    }

    public static void displayEmployeeSort(ArrayList<Employee> employee) {
        if (employee.isEmpty()) {
            System.out.println("No employees to display.");
            return;
        }

        // Bubble sort employees by salary in ascending order
        for (int i = 0; i < employee.size() - 1; i++) {
            for (int j = 0; j < employee.size() - i - 1; j++) {
                if (employee.get(j).employeeSalary > employee.get(j + 1).employeeSalary) {
                    // Swap employees at index j and j + 1
                    Employee temp = employee.get(j); // here temp is a local variable of the type Employee
                    employee.set(j, employee.get(j + 1));
                    employee.set(j + 1, temp);

                    // employees.set(index, element) is a method used to replace or update
                    // the element at the specified index within a List'.
                }
            }
        }

        System.out.println("Employees sorted by salary (lowest to highest):");
        for (Employee itarator : employee) {
            System.out.println("Employee ID: " + itarator.employeeID);
            System.out.println("Employee Name: " + itarator.employeeName);
            System.out.println("Employee Salary: " + itarator.employeeSalary);
            System.out.println("-----------------------------");
        }
    }

    public static void main(String[] args) {
        System.out.print("Enter the number of objects: ");
        int size = sc.nextInt();
        ArrayList<Employee> employeeObj = new ArrayList<Employee>();
        int id;
        double salary;
        String name;
        for (int i = 0; i < size; i++) {
            Employee Obj = new Employee();
            System.out.println("\nFor Employee " + (i + 1) + ": ");
            System.out.print("Enter the Employee ID: ");
            id = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter the Employee Name: ");
            name = sc.nextLine();
            System.out.print("Enter the Employee Salary: ");
            salary = sc.nextDouble();
            Obj.setDetails(id, name, salary);
            employeeObj.add(Obj);
        }
        char ans = 'Y';
        int ch;
        while (ans == 'Y' || ans == 'y') {
            System.out.println("\n");
            System.out.println("1.Set New Employee Details");
            System.out.println("2.Remove Employee");
            System.out.println("3.Update Employee Details");
            System.out.println("4.Get Employee Details");
            System.out.println("5.Update Employee Salary");
            System.out.println("6.Get Total Employees");
            System.out.println("7.Compare Employees");
            System.out.println("8.Sort");
            System.out.println("9.Exit");
            System.out.print("Enter your choice: ");
            System.out.print("\n");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    Employee newObj = new Employee();
                    System.out.print("Enter the Employee ID: ");
                    id = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter the Employee Name: ");
                    name = sc.nextLine();
                    System.out.print("Enter the Employee Salary: ");
                    salary = sc.nextDouble();

                    newObj.setDetails(id, name, salary);
                    employeeObj.add(newObj);
                    break;
                case 2:
                    System.out.print("Enter the Employee ID: ");
                    int id1 = sc.nextInt();
                    for (int i = 0; i < employeeObj.size(); i++) {
                        if (employeeObj.get(i).employeeID == id1 && employeeObj.get(i).removeEmployee(id1)) {
                            employeeObj.remove(i);
                        }
                    }
                    System.out.println("Removed Employee...");
                    break;
                case 3:
                    System.out.println("\nEnter the required Employee ID: ");
                    int id2 = sc.nextInt();
                    for (int i = 0; i < employeeObj.size(); i++) {
                        if (employeeObj.get(i).employeeID == id2) {
                            employeeObj.get(i).updateDetails(id2);
                        }
                    }
                    System.out.println("Employee Details Were Updated!");
                    break;
                case 4:
                    System.out.println("\nEnter the required Employee ID: ");
                    int id3 = sc.nextInt();
                    for (int i = 0; i < employeeObj.size(); i++) {
                        if (employeeObj.get(i).employeeID == id3) {
                            System.out.println("Employee Details Are: ");
                            employeeObj.get(i).getDetails(id3);
                        }
                    }
                    break;
                case 5:
                    System.out.println("\nEnter the required Employee ID: ");
                    int id4 = sc.nextInt();
                    double newSalary = 0.0;
                    for (int i = 0; i < employeeObj.size(); i++) {
                        if (employeeObj.get(i).employeeID == id4) {
                            System.out.print("Enter the updated Salary: ");
                            newSalary = sc.nextDouble();
                            employeeObj.get(i).updatedSalary(id4, newSalary);
                        }
                    }
                    System.out.print("The Updated Employee Salary Is: ");
                    for (int i = 0; i < employeeObj.size(); i++) {
                        if (employeeObj.get(i).employeeID == id4) {
                            System.out.print(employeeObj.get(i).getSalary(id4) + "\n");
                        }
                    }
                    break;
                case 6:
                    int totalEmployees = Employee.totalEmployees();
                    System.out.println("Total No of Employees Are: " + totalEmployees);
                    break;
                case 7:
                    int id5;
                    int id6;
                    System.out.print("Enter the id of the first Employee: ");
                    id5 = sc.nextInt();
                    System.out.print("Enter the id of the second Employee: ");
                    id6 = sc.nextInt();
                    employeeCompare(id5, id6, employeeObj);
                    break;
                case 8:
                    displayEmployeeSort(employeeObj);
                    break;
                case 9:
                    System.out.println("Exiting from the system");
                    break;
                default:
                    System.out.println("Invalid choice, try again");
            }
            System.out.print("Do you want to continue(y/n)? ");
            ans = sc.next().charAt(0);
        }
    }
}
