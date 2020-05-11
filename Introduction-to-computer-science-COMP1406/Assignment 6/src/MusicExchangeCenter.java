import javafx.util.Pair;

import java.util.*;


public class MusicExchangeCenter  {
    ArrayList<User> users = new ArrayList<>();  // arraylist of all registered users logged on or not


    public MusicExchangeCenter(){
        downloadedSongs = new ArrayList<Song>();
        royalties = new HashMap<String, Float>();
    }
    public ArrayList<User> onlineUsers(){ // returns the arraylist of users who are online
        ArrayList<User> onlineUsers = new ArrayList<User>();
        for(User u: users){
            if(u.isOnline() == true){
                onlineUsers.add(u);
            }
        }
        return onlineUsers;
    }

    public ArrayList<Song> allAvailableSongs() {
        ArrayList<Song> allAvailableSongs = new ArrayList<Song>();
        //ArrayList<User> Songs_from_logged_on_users
        for (User u: onlineUsers()) {
            allAvailableSongs.addAll(u.songList);// adding the song objects
        }
            return allAvailableSongs;
    }

    @Override
    public String toString() {
        return "Music Exchange Center ("+onlineUsers().size()+" users on-line, "+allAvailableSongs().size()+" songs available)";
    }
    public User userWithName(String s){ // it finds the user with the name and returns it
        for(User u: users){
            if(u.getUserName().equals(s)){
                return u;
            }
        }
        return null;
    }
    public void registerUser(User x){
        if(userWithName(x.getUserName())== null){
            users.add(x);
        }
    }

    public ArrayList<Song> availableSongsByArtist(String artist) {
        ArrayList<Song> availableSongsByArtist = new ArrayList<Song>();
        if(userWithName(artist)!=null){
            availableSongsByArtist.addAll(userWithName(artist).songList);
        }
        return  availableSongsByArtist;
    }
    public Song getSong(String title, String ownerName){
        for(User u: users){
            if(u.getUserName().equals(ownerName) && u.isOnline()){
                for(Song s: u.songList){ // going into the songs of users
                    if(s.getTitle().equals(title)){
                        downloadedSongs.add(s);
                        return s;
                    }
                }
            }
        }
        return null;
    }

    public HashMap<String, Float > royalties ;

    private ArrayList<Song> downloadedSongs;

    public ArrayList<Song> getDownloadedSongs() {
        return downloadedSongs;
    }

    public void displayRoyalties(){
        System.out.println(String.format("%-9s%-9s","Amount","Artist"));
        System.out.println("----------------");
        for(Song s: downloadedSongs){
            if(!royalties.containsKey(s.getArtist())){
                royalties.put(s.getArtist(),0.25f);
            }
            else{
                royalties.put(s.getArtist(),royalties.get(s.getArtist())+0.25f);
            }
        }

        for(String s:royalties.keySet()){
            System.out.println(String.format("$%1.2f    %-9s",royalties.get(s),s));
        }
    }


    public TreeSet<Song> uniqueDownloads(){
        return new TreeSet<>(getDownloadedSongs());
    }
    public ArrayList<Pair<Integer,Song>> songsByPopularity(){
        int download_count = 0;
        ArrayList<Pair<Integer,Song>> songsByPopularity = new ArrayList<Pair<Integer,Song>>();
        for(Song s: uniqueDownloads()){
            for(Song s2: downloadedSongs) {
                if (s.getTitle().equals(s2.getTitle())) {
                    download_count++;
                }
            }
            songsByPopularity.add(new Pair(download_count,s));
            download_count = 0;
        }
        Collections.sort(songsByPopularity, new Comparator<Pair<Integer, Song>>() {
            public int compare(Pair<Integer, Song> p1, Pair<Integer, Song> p2) {
                return p2.getKey()- p1.getKey();// PUT YOUR CODE IN HERE } });
            }});

        return songsByPopularity;
    }
}


