public class IndividualClient extends Client {
    public IndividualClient(String str) { // making a constructor takes a single string argument
        super(str); // calling the constructor of super class that takes the string as parameter
    }

    public float makeClaim(int polNum) {//implementing the abstract method of client
        Policy policy_obj = getPolicy(polNum);// checking if policy no matches any one of the policy no
        if (policy_obj == null) {
            return 0;// if not found then return 0
        }
        else if (policy_obj instanceof DepreciatingPolicy) {//checking if instance of Depreciating Policy
            DepreciatingPolicy casting_into_DP = ((DepreciatingPolicy) policy_obj);// casting the policy object into Depreciating policy
            casting_into_DP.depreciate();// Depreciating the policy
            return casting_into_DP.amount;//Depreciate policy should return the amount of policy(amount after depreciating)
        }
        else if (policy_obj instanceof ExpiringPolicy) {//checking if instance of Expiring Policy
            ExpiringPolicy casting_into_EP = ((ExpiringPolicy) policy_obj);
            if (casting_into_EP.isExpired()) {//need to check if it is Expired if it is then return 0
                return 0; //if it is Expired if it is then return 0
            }
            else { // if not Expired then return amount
                return casting_into_EP.amount;
            }
        }
        else {
            cancelPolicy(polNum);// regular policy only 1 claim is made then cancel it
            return policy_obj.amount;
        }
    }
}