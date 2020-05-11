import java.util.Date;
public class PoliceDatabase {
    Vehicle[] vehicles; // Array of object for vehicles
    Driver[] drivers;// Array of object for Drivers
    Infraction[] infractions;// Array of object for vehicles
    int numVehicles = 0, numDrivers = 0, numInfractions = 0; // starting values or indexes of no of vehicles, drivers, infractions

    public static final int drivers_size = 2000; // maximum limits of drivers
    public static final int vehicles_size = 1000; // maximum limit of vehicles
    public static final int infractions_limit = 800; // maximum limit of infractions

    public PoliceDatabase() {
        drivers = new Driver[drivers_size]; // initializing the new drivers objects
        vehicles = new Vehicle[vehicles_size]; // initializing the new vehicles objects
        infractions = new Infraction[infractions_limit]; // initializing the new infractions objects
    }

    public void registerDriver(Driver aDriver) { // method to register driver
        drivers[numDrivers] = aDriver;
        numDrivers++;
    }

    public void registerVehicle(Vehicle aVehicle, String license) { // method to register vehicles with drivers
        vehicles[numVehicles] = aVehicle;
        vehicles[numVehicles].owner.license = license;
        for(int i =0;i<numDrivers;i++){ // goes to all the drivers with license no
            for(int j=0;j<numVehicles+1;j++){ // goes to all the vehicles and register with linking with driver
                if(vehicles[j].owner.license.equals(drivers[i].license)){
                    vehicles[j].owner = drivers[i];
                }
            }
        }
        ++numVehicles;

    }

    public void unregisterVehicle(String plate) { // method to unregister vehicle
        for (int i = 0; i < numVehicles; i++) {
            if (vehicles[i].plate.equals(plate)) {
                for (int j = i; j < numVehicles-1; j++) {
                    vehicles[j] = vehicles[j+1];
                    //vehicles[j].plate.equals(vehicles[j+1].plate);
                }
                --numVehicles;
            }
        }
    }

    public void reportStolen(String plate) { // method to report stolen vehicle
        for (int i = 0; i < numVehicles; i++) {
            if (vehicles[i].plate.equals(plate)) {
                vehicles[i].reportedStolen = true;
            }
        }
    }

    public void changeOwner(String plate, String license) { // method to change the owner
        for (int i = 0; i < numVehicles; i++) {
            if (vehicles[i].plate.equals(plate)) {
                vehicles[i].owner.license = license;
            }
            for(int j=0;j<numDrivers;j++){
                if(vehicles[i].owner.license.equals(drivers[j].license)){
                    vehicles[i].owner = drivers[j];
                }
            }
        }
    }
    public Infraction issueInfraction(String license, float amount, String description, Date date){ // issuing the infraction to the vehicles
        infractions[numInfractions] = new Infraction();
        for(int i=0;i<numDrivers;i++){
            if(drivers[i].license.equals(license)) {
                infractions[numInfractions].amount = amount;
                infractions[numInfractions].description = description;
                infractions[numInfractions].dateissued = date;
                infractions[numInfractions].driver = drivers[i];
            }
        }
        //++numInfractions;
        return infractions[numInfractions++] ;
    }
    public boolean hasOutstandingInfractions(Driver d){ // returning true or false  if the driver hasn't paid the infractions
        for(int i=0;i<numInfractions;i++)
            if(d.license.equals(infractions[i].driver.license))
                return infractions[i].outstanding;
        return false;
    }
    public boolean shouldStopVehicle(String plate){ // returns true or false to stop vehicle
        for(int i = 0;i<numVehicles;i++){
            if(vehicles[i].plate.equals(plate)){
                for(int j = 0; j < numDrivers; j++){
                    if(vehicles[i].reportedStolen || hasOutstandingInfractions(drivers[j])){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public void showInfractionsFor(String license){ // this program shows infractions for an individual
        int count = 0;
        for(int i=0;i<numInfractions;i++){
            if(infractions[i].driver.license.equals(license)){// comparing drivers license with given license
                System.out.println(infractions[i]);
                if(infractions[i].outstanding) {
                    count++;
                }
            }
        }
        System.out.println("Total outstanding infractions = " + count); // printing total no of outstanding infraction
    }
    public Driver[] cleanDrivers(){ // returning the drivers which don't have any infractions
        int i=0;
        while(i<numDrivers){
            int j = 0;
            while (j<numInfractions){
                if((drivers[i].license.equals(infractions[j].driver.license))) {
                    for (int k = i; k < numDrivers-1; k++)
                        drivers[k] = drivers[k + 1];
                    numDrivers--;
                    if(i>0){i--;}
                }
                j++;
            }
            i++;
        }
        Driver[] clean_drivers = new Driver[numDrivers]; //making new duplicate array with the same length except nulls
        for( i=0;i<numDrivers;i++){
            clean_drivers[i] = drivers[i];
        }
        return clean_drivers;
    }
    public void showInfractionReport(){ // the hard most method by making new duplicate array which contains
        int duplicate_value = numInfractions -1;// all the elements of infractions and changing it.
        Infraction[] duplicate = new Infraction[infractions.length];
        for(int i=0;i<numInfractions;i++){
            duplicate[i] = infractions[i];
            duplicate[i].driver = infractions[i].driver;
        }
        int flag = 0;
        for(int i=0; i<duplicate_value; i++){
            flag = 1;
            float amount_paid = 0;
            if(!(duplicate[i].outstanding)) {// condition for checking if the infraction amount is paid or outstanding
                amount_paid = duplicate[i].amount;
            }
            int j=1+i;
            while(j<duplicate_value){
                 if(duplicate[i].driver.license.equals(duplicate[j].driver.license)){
                    flag++;
                    if(!(duplicate[j].outstanding)) {
                        amount_paid += duplicate[j].amount;
                    }
                    for(int k = j; k<duplicate_value-1;k++)
                        duplicate[k] = duplicate[k+1];
                    duplicate_value--;
                    j--;
                }
                j++;
            } // printing the desired output
            System.out.println(String.format("%20s",duplicate[i].driver.name)+": "+flag+" infractions, Total Paid = $"+String.format("%6.2f",amount_paid));
        }
    }

    public static PoliceDatabase example() { // Register all drivers and their vehicles
        PoliceDatabase pdb = new PoliceDatabase();

        pdb.registerDriver(new Driver("L1567-34323-84980", "Matt Adore",
                "1323 Kenaston St.", "Gloucester", "ON"));
        pdb.registerDriver(new Driver("L0453-65433-87655", "Bob B. Pins",
                "32 Rideau Rd.", "Greely", "ON"));
        pdb.registerDriver(new Driver("L2333-45645-54354", "Stan Dupp",
                "1355 Louis Lane", "Gloucester", "ON"));
        pdb.registerDriver(new Driver("L1234-35489-99837", "Ben Dover",
                "2348 Walkley Rd.", "Ottawa", "ON"));
        pdb.registerDriver(new Driver("L8192-87498-27387", "Patty O'Lantern",
                "2338 Carling Ave.", "Nepean", "ON"));
        pdb.registerDriver(new Driver("L2325-45789-35647", "Ilene Dover",
                "287 Bank St.", "Ottawa", "ON"));
        pdb.registerDriver(new Driver("L1213-92475-03984", "Patty O'Furniture",
                "200 St. Laurant Blvd.", "Ottawa", "ON"));
        pdb.registerDriver(new Driver("L1948-87265-34782", "Jen Tull",
                "1654 Stonehenge Cres.", "Ottawa", "ON"));
        pdb.registerDriver(new Driver("L0678-67825-83940", "Jim Class",
                "98 Oak Blvd.", "Ottawa", "ON"));
        pdb.registerDriver(new Driver("L0122-43643-73286", "Mark Mywords",
                "3 Third St.", "Ottawa", "ON"));
        pdb.registerDriver(new Driver("L6987-34532-43334", "Bob Upandown",
                "434 Gatineau Way", "Hull", "QC"));
        pdb.registerDriver(new Driver("L3345-32390-23789", "Carrie Meehome",
                "123 Thurston Drive", "Kanata", "ON"));
        pdb.registerDriver(new Driver("L3545-45396-88983", "Sam Pull",
                "22 Colonel By Drive", "Ottawa", "ON"));
        pdb.registerDriver(new Driver("L1144-26783-58390", "Neil Down",
                "17 Murray St.", "Nepean", "ON"));
        pdb.registerDriver(new Driver("L5487-16576-38426", "Pete Reedish",
                "3445 Bronson Ave.", "Ottawa", "ON"));
        pdb.registerVehicle(new Vehicle("Honda", "Civic", 2015, "yellow", "W3EW4T"),
                "L0453-65433-87655");
        pdb.registerVehicle(new Vehicle("Pontiac", "Grand Prix", 2007, "dark green", "GO SENS"),
                "L0453-65433-87655");
        pdb.registerVehicle(new Vehicle("Mazda", "RX-8", 2004, "white", "OH YEAH"),
                "L2333-45645-54354");
        pdb.registerVehicle(new Vehicle("Nissan", "Altima", 2017, "bergundy", "Y6P9O7"),
                "L1234-35489-99837");
        pdb.registerVehicle(new Vehicle("Saturn", "Vue", 2002, "white", "9R6P2P"),
                "L2325-45789-35647");
        pdb.registerVehicle(new Vehicle("Honda", "Accord", 2018, "gray", "7U3H5E"),
                "L2325-45789-35647");
        pdb.registerVehicle(new Vehicle("Chrysler", "PT-Cruiser", 2006, "gold", "OLDIE"),
                "L2325-45789-35647");
        pdb.registerVehicle(new Vehicle("Nissan", "Cube", 2010, "white", "5Y6K8V"),
                "L1948-87265-34782");
        pdb.registerVehicle(new Vehicle("Porsche", "959", 1989, "silver", "CATCHME"),
                "L0678-67825-83940");
        pdb.registerVehicle(new Vehicle("Kia", "Soul", 2018, "red", "J8JG2Z"),
                "L0122-43643-73286");
        pdb.registerVehicle(new Vehicle("Porsche", "Cayenne", 2014, "black", "EXPNSV"),
                "L6987-34532-43334");
        pdb.registerVehicle(new Vehicle("Nissan", "Murano", 2010, "silver", "Q2WF6H"),
                "L3345-32390-23789");
        pdb.registerVehicle(new Vehicle("Honda", "Element", 2008, "black", "N7MB5C"),
                "L3545-45396-88983");
        pdb.registerVehicle(new Vehicle("Toyota", "RAV-4", 2010, "green", "R3W5Y7"),
                "L3545-45396-88983");
        pdb.registerVehicle(new Vehicle("Toyota", "Celica", 2006, "red", "FUNFUN"),
                "L5487-16576-38426");

        return pdb;
    }
}