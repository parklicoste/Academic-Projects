public class Theatre {
    Movie moviePlaying;//movie object
    int capacity, seatsSold;//capacity seat sold
    public Theatre(int jagah){
        capacity = jagah;
    }
    public Theatre(String mov, int duplicate_capacity){
        moviePlaying = new Movie(mov);
        capacity = duplicate_capacity;
    }
    public boolean isFull() {
        if (capacity - seatsSold == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}
