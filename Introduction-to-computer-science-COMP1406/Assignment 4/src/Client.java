import java.util.*;
public abstract class Client {
    private static final int MAX_POLICIES_PER_CLIENT = 10;
    private static int NEXT_CLIENT_ID = 1;
    private String name;
    private int id;
    protected Policy[] policies;
    protected int numPolicies;
    public Client(String n) {
        name = n;
        id = NEXT_CLIENT_ID++;
        policies = new Policy[MAX_POLICIES_PER_CLIENT];
        numPolicies = 0;
    }
    public String getName() { return name; }
    public int getId() { return id; }
    public Policy[] getPolicies() { return policies; }
    public int getNumPolicies() { return numPolicies; }
    public String toString() {
        String naam = this.getClass().getName();
        return naam + String.format("Client: %06d amount: %s", id, name);
    }
    public float totalCoverage(){
        float total = 0;
        for(int i=0 ; i<numPolicies;i++){
            total += policies[i].getAmount();
        }
        return total;
    }
    public Policy addPolicy(Policy p){
        if (numPolicies<MAX_POLICIES_PER_CLIENT){
            policies[numPolicies]=p;
            numPolicies++;
            return p;
        }
        return null;
    }
    public void openPolicyFor(float amt){
        Policy newPolicy = new Policy(amt);
        addPolicy(newPolicy);
    }
    public void openPolicyFor(float amt,float rt){
        DepreciatingPolicy newDepPolicy = new DepreciatingPolicy(amt,rt);
        addPolicy(newDepPolicy);
    }
    public void openPolicyFor(float amt,Date expire){
        ExpiringPolicy newExpPolicy = new ExpiringPolicy(amt,expire);
        addPolicy(newExpPolicy);
    }
    public Policy getPolicy(int polNum){
        for(int i=0; i<numPolicies;i++ ){
            if(polNum == policies[i].getPolicyNumber()){
                return policies[i];
            }
        }
        return null;
    }
    public boolean cancelPolicy(int polNum){ //method for cancelling policy
        for(int i=0; i<numPolicies;i++ ){ // loop for going into total policies
            if(polNum == policies[i].getPolicyNumber()){//checking if the policy no matches one of the policy no
                for(int j=i;j<numPolicies-1;j++){//second loop for the overriding the next array(which goes from i to second last array)
                    policies[j] = policies[j+1];//copying the next array into the first one
                }
                numPolicies--;// if we found the policy no then remove from array and decreasing the length of array by one
                return true;// return true
            }
        }
        return false;// otherwise returning false
    }
    public abstract float makeClaim(int polNum);
}