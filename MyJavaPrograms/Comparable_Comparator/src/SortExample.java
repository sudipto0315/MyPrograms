import java.util.ArrayList;
import java.util.Collections;
// java.lang has comparable
// java.util has comparator
// public class SortExample{
//     public static void main(String[] args) {
//         ArrayList<Integer> marks = new ArrayList<>();
//         marks.add(12);
//         marks.add(34);
//         marks.add(6);
//         System.out.println(marks);
//         Collections.sort(marks);
//         System.out.println(marks);
//     }
// }

//now implementing comaparable and Comparator
public class SortExample {
    public static void main(String[] args) {
        ArrayList<Emp> emps = new ArrayList<>();
        emps.add(new Emp("Sudipto", "789", 12));
        emps.add(new Emp("Arnab", "456", 11));
        emps.add(new Emp("Sreejita", "123", 10));
        System.out.println(emps);
//        comparable
//        Collections.sort(emps);
//        System.out.println(emps);

//        comparator
        ArrayList<Emp> emps1 = new ArrayList<>(emps);
//        Collections.sort(emps1, new IdComparator());
        Collections.sort(emps1, new NameComparator());
        System.out.println(emps1);

    }
}