public class BoxOffice {
    Theatre theatreA, theatreB;//2 theatre objects theatre a and theatre b which both has movies
    double previous_earnings;
    Movie previous_movie;
    public BoxOffice(int a, int b) {
        theatreA = new Theatre(a);//5 justice league
        theatreB = new Theatre(b);// 5 geostorm
    }

    public void openMovie(String s, Theatre t) { // opens the movie in theatre A na theatre B
        if (t == theatreA) {
            int duplicate_capacity = theatreA.capacity;
            theatreA = new Theatre(s, duplicate_capacity);
        }
        else {
            int duplicate_capacity = theatreB.capacity;
            theatreB = new Theatre(s, duplicate_capacity);
        }
    }

    public void sellTicket(Patron p , String st) {
        if (st.equals(theatreA.moviePlaying.title)) { // Theatre A opens Justice league and Despicable Me 3
            if (!(theatreA.capacity == theatreA.seatsSold)) {
                p.movie_ticket_name = st;
                theatreA.seatsSold += 1;
                if (p.age < 12) {
                    p.movie_cost = 6.25;
                    theatreA.moviePlaying.earnings += 6.25;
                }
                else if (p.age >= 65) {
                    p.movie_cost = 5.75;
                    theatreA.moviePlaying.earnings += 5.25;
                }
                else {
                    p.movie_cost = 12.5;
                    theatreA.moviePlaying.earnings += 12.5;
                }
            }
            else { //no capacity left for Justice League or Despicable Me 3
                System.out.println("Movie is sold out");
            }

        }
        else if (st.equals(theatreB.moviePlaying.title)) { //Theatre B opens Geostorm
            if (!(theatreB.seatsSold == theatreB.capacity)) {
                theatreB.seatsSold += 1;
                p.movie_ticket_name = st;
                if (p.age < 12) {
                    p.movie_cost = 6.25;
                    theatreB.moviePlaying.earnings += 6.25;
                }
                else if (p.age >= 65) {
                    p.movie_cost = 5.25;
                    theatreB.moviePlaying.earnings += 5.75;
                }
                else {
                    p.movie_cost = 12.5;
                    theatreB.moviePlaying.earnings += 12.5;
                }
            }
            else {  //no capacity left for Geostorm
                System.out.println("Movie is sold out");
            }
        } else {  // if movie name does not matches
            System.out.println("Movie is not currently playing");
        }
    }
    public void returnTicket(Patron pt) { // if patron is returning ticket
        if ((pt.movie_ticket_name).equals(theatreA.moviePlaying.title)&& pt.movie_cost!=0) {
            if (pt.age < 12) {
                theatreA.moviePlaying.earnings -= pt.movie_cost;
                pt.movie_cost = 0;
            }
            else if (pt.age >= 65) {
                theatreA.moviePlaying.earnings -= pt.movie_cost;
                pt.movie_cost = 0;
            }
            else {
                theatreA.moviePlaying.earnings -= pt.movie_cost;
                pt.movie_cost = 0;
            }
            theatreA.seatsSold -= 1;
        }
        else if ((pt.movie_ticket_name).equals(theatreB.moviePlaying.title) && pt.movie_cost !=0) {
            if (pt.age < 12) {
                theatreB.moviePlaying.earnings -= pt.movie_cost;
                pt.movie_cost = 0;
            }
            else if (pt.age >= 65) {
                theatreB.moviePlaying.earnings -= pt.movie_cost;
                pt.movie_cost = 0;
            }
            else {
                theatreB.moviePlaying.earnings -= pt.movie_cost;
                pt.movie_cost = 0;
            }
            theatreB.seatsSold -= 1;
        }
        else { //if patron is returning again
            System.out.println("Patron does not have a ticket");
        }
    }

    public Movie bestMovie(){ // returns the best movie which has maximum earnings
        if((theatreA.moviePlaying.title).equals("Justice League")){
             previous_movie = theatreA.moviePlaying;
             previous_earnings = theatreA.moviePlaying.earnings;
        }
        if (theatreA.moviePlaying.earnings > theatreB.moviePlaying.earnings) {
            if(previous_earnings>=theatreA.moviePlaying.earnings) {
                return previous_movie;
            }
            else {
                return theatreA.moviePlaying;
            }
        }
        else {
            return theatreB.moviePlaying;
        }
    }
}
