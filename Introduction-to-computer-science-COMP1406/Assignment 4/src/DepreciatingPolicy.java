public class DepreciatingPolicy extends Policy {
    private float rate;
    public DepreciatingPolicy(float x,float y){
        super(x);
        rate = y;
    }

    public float getRate() {
        return rate;
    }

    @Override
    public String toString() {
        return "Depreciating"+super.toString()+String.format(" rate: %1.1f",rate*100)+"%";
    }
    public boolean isExpired() {
        return amount == 0;
    }
    public void depreciate(){
        amount -= (amount* rate);
    }

    public float handleClaim(){
        float initial_amount = amount;
        depreciate();
        return initial_amount;
    }
}
