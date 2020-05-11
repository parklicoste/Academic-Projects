import java.util.Date;
public class Infraction {
    float amount;
    String description;
    Date dateissued;
    boolean outstanding = true;
    Driver driver = new Driver();
    public Infraction(float amt,String des, Date d){
        amount = amt;
        description = des;
        dateissued = d;
    }
    public Infraction(){
        this(0," ",null);
    }

    @Override
    public String toString() {
        if(!outstanding){
        return "$ " + String.format("%.2f", amount) + " Infraction on " + String.format("%tc",dateissued) + "[PAID IN FULL]";
        }
        else{return "$ " + String.format("%.2f", amount) + " Infraction on " + String.format("%tc",dateissued) + "[OUTSTANDING]";
        }
    }
    public void pay(){
        outstanding = false;
    }
}
