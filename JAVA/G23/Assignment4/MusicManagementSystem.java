import java.util.Scanner;
import java.util.ArrayList;

class Song {
    int songId;
    String songTitle;
    String artistName;
    String albumTitle;
    String genre;
    int durationInSeconds;
    int playCount;

    Song() {
        songId = 0;
        songTitle = "";
        artistName = "";
        albumTitle = "";
        genre = "";
        durationInSeconds = 0;
        playCount = 0;
    }

    public void setDetails(int id, String title, String name, String album, String genre, int duration) {
        songId = id;
        songTitle = title;
        artistName = name;
        albumTitle = album;
        this.genre = genre;
        durationInSeconds = duration;
    }

    public void getDetails(int id) {
        System.out.println("Id = " + id);
        System.out.println("Song title = " + songTitle);
        System.out.println("Artist name = " + artistName);
        System.out.println("Album name = " + albumTitle);
        System.out.println("Genre = " + genre);
        System.out.println("Duration in seconds = " + durationInSeconds);
    }

    public void play(int id) {
        System.out.println("Song played: " + songTitle);
    }

    static ArrayList<String> playlist = new ArrayList<String>();

    public void addToPlaylist(int id) {
        System.out.println("Song added to playlist: " + songTitle);
        playlist.add(songTitle);
        System.out.println();
        System.out.println("Songs in the playlist are: ");
        for (String iterator : playlist){
            int a = 1;
            System.out.println("Song "+a+": "+iterator);
            a++;
        }
    }

    public void removeFromPlaylist(int id) {
        System.out.println("Song removed from playlist: " + songTitle);
        playlist.remove(songTitle);
        System.out.println("Songs in the playlist are: ");
        for (String iterator : playlist){
            int a = 1;
            System.out.println("Song "+a+": "+iterator);
            a++;
        }
    }

    public int getSongId() {
        return songId;
    }
}

public class MusicManagementSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of objects: ");
        int n = sc.nextInt();

        ArrayList<Song> songList = new ArrayList<Song>();
        int id;
        String title, name, album, genre;
        int duration;

        for (int i = 0; i < n; i++) {
            Song obj = new Song();
            System.out.println("\nFor object " + (i + 1) + ": ");
            System.out.print("Enter the id: ");
            id = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter the song title: ");
            title = sc.nextLine();
            System.out.print("Enter the artist name: ");
            name = sc.nextLine();
            System.out.print("Enter the album name: ");
            album = sc.nextLine();
            System.out.print("Enter the genre: ");
            genre = sc.nextLine();
            System.out.print("Enter the duration: ");
            duration = sc.nextInt();
            obj.setDetails(id, title, name, album, genre, duration);
            songList.add(obj);

        }

        char ans = 'Y';
        int ch;
        while (ans == 'Y' || ans == 'y') {
            System.out.println("\n");
            System.out.println("1.Set details");
            System.out.println("2.Get details");
            System.out.println("3.Play");
            System.out.println("4.Add to playlist");
            System.out.println("5.Remove from playlist");
            System.out.println("6.Exit");
            System.out.print("Enter your choice: ");
            ch = sc.nextInt();

            switch (ch) {
                case 1:
                    Song object = new Song();
                    System.out.print("Enter the id: ");
                    id = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter the song title: ");
                    title = sc.nextLine();
                    System.out.print("Enter the artist name: ");
                    name = sc.nextLine();
                    System.out.print("Enter the album name: ");
                    album = sc.nextLine();
                    System.out.print("Enter the genre: ");
                    genre = sc.nextLine();
                    System.out.print("Enter the duration: ");
                    duration = sc.nextInt();

                    object.setDetails(id, title, name, album, genre, duration);
                    songList.add(object);
                    break;

                case 2:
                    System.out.println("\nEnter the required id: ");
                    int id1 = sc.nextInt();
                    for (int i = 0; i < songList.size(); i++) {
                        if (songList.get(i).getSongId() == id1) {
                            songList.get(i).getDetails(id1);
                        }
                    }
                    break;

                case 3:
                    System.out.println("Enter the required id: ");
                    int id2 = sc.nextInt();
                    for (int i = 0; i < songList.size(); i++) {
                        if (songList.get(i).getSongId() == id2) {
                            songList.get(i).play(id2);
                        }
                    }
                    break;

                case 4:
                    System.out.println("Enter the required id: ");
                    int id3 = sc.nextInt();
                    for (int i = 0; i < songList.size(); i++) {
                        if (songList.get(i).getSongId() == id3) {
                            songList.get(i).addToPlaylist(id3);
                        }
                    }
                    break;

                case 5:
                    System.out.println("Enter the required id: ");
                    int id4 = sc.nextInt();
                    for (int i = 0; i < songList.size(); i++) {
                        if (songList.get(i).getSongId() == id4) {
                            songList.get(i).removeFromPlaylist(id4);
                        }
                    }
                    break;

                case 6:
                    System.out.println("Exit from system");
                    break;

                default:
                    System.out.println("Invalid choice, try again");
            }
            System.out.print("Do you want to continue(y/n)? ");
            ans = sc.next().charAt(0);
        }

        sc.close();
    }
}