public class Emp implements Comparable<Emp>{
    private String name;
    private String phone;
    private int empID;

    @Override
    public int compareTo(Emp o) {
        return empID-o.empID;
    }

    public Emp(String name, String phone, int empID){
        this.name = name;
        this.phone = phone; 
        this.empID = empID;
    }

    public String getName(){
        return name;
    }

    public String getPhone(){
        return phone;
    }

    public int getEmpID(){
        return empID;
    }

    @Override
    public String toString() {
        return "Emp{" +
                "name='" + name + '\'' +
                ", phone='" + phone + '\'' +
                ", empID=" + empID +
                '}';
    }
}

