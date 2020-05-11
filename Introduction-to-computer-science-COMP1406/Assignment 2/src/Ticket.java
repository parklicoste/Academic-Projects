public class Ticket {
    Theatre theatre ;
    public Ticket (Theatre t){
        theatre = t;
    }
    public Ticket(String movie,double cost){
        this.theatre.moviePlaying.title = movie;
        this.theatre.moviePlaying.earnings = cost;
    }
}
