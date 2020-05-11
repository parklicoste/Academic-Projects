public class CompanyClient extends Client {
    public CompanyClient(String str){ // making a constructor takes a single string argument
        super(str);
    }

    @Override
    public float makeClaim(int polNum) {
        Policy policy_obj = getPolicy(polNum);//getting the policy object from policy number
        if(!(policy_obj==null|| getPolicy(polNum).isExpired() )){ // checking if object is not null and not expired
            return policy_obj.handleClaim();// calling the handle claim function which sends the initial float amount
        }
        return 0;// if no policy is found with given no then return 0
    }
}
