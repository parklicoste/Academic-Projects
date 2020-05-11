public class Vehicle {

    String make, model, color, plate;
    Driver owner = new Driver();
    boolean reportedStolen;
    int year;
    public Vehicle(String mk, String mod, int yr, String col, String plt) {
        make = mk;
        model = mod;
        year = yr;
        color = col;
        plate = plt;
    }

    public Vehicle() {
        this(" "," ",0," "," ");
        //v = new Vehicle("Ford", "Mustang", 2004, "blue", "P@rkL!co$te");
    }

    public String toString() {
        return "A " + this.color + " " + this.year + " " + this.make + " " + this.model + " with plate " + this.plate;
    }
}
