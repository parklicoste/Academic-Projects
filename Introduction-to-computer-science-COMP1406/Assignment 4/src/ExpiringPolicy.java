import java.text.SimpleDateFormat;
import java.util.*;
import java.util.Date;

public class ExpiringPolicy extends Policy {
    private Date expiryDate;
    Date today = new Date();

    public ExpiringPolicy(float x , Date d){
        super(x);
        expiryDate = d;
    }

    public Date getExpiryDate() {
        return expiryDate;
    }

    public ExpiringPolicy(float pri_amt) {
        super(pri_amt);
        GregorianCalendar aCalendar = new GregorianCalendar();
        aCalendar.add(Calendar.YEAR,1);
        expiryDate = aCalendar.getTime();

    }

    @Override
    public String toString() {
        if (expiryDate.before(today)) {
            return "Expiring" + super.toString() + " expired on: " + new SimpleDateFormat("MMMM dd,yyyy (hh:mma)").format(expiryDate);
        }
        else {
            return "Expiring" + super.toString() + " expires: " + new SimpleDateFormat("MMMM dd,yyyy (hh:mma)").format(expiryDate);
        }
    }
    public boolean isExpired(){
        if (expiryDate.after(today)){
            return false;
        }
        return true;
    }
    public float handleClaim(){
        if(!(isExpired()))//if the policy isn't expired then return the amount
            return amount;
        else {
            return 0; // otherwise return 0
        }
    }
}
