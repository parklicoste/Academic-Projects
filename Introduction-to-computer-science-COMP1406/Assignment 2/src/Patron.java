public class Patron {
    int age;
    String movie_ticket_name;
    double movie_cost;
    Ticket ticket; // object(it contains theatre a or theatre b)
    public Patron (int saal){
        age = saal;
    }
    public Patron(String movie,double price){
        movie_ticket_name = movie;
        movie_cost = price;
        //this.ticket.theatre.moviePlaying.earnings = price;
        //this.ticket.theatre.moviePlaying.title = movie;
    }

}
