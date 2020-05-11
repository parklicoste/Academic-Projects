public class Driver {

    String license,name,street,city,province;
    public Driver(String lics ,String nam,String st,String ct,String prov){
        license = lics;
        name = nam;
        street =st;
        city = ct;
        province = prov;
    }

    public Driver(){
        this(" "," "," "," "," ");
    }

    @Override
    public String toString() {
        return "#" + this.license + " " + this.name + " living at " + this.street + ", " + this.city + ", " + this.province;
    }
}
