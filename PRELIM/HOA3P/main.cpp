#include "playlist.h"

int main(){

    Playlist music;

    music.insertSong("Passenger Seat");
    music.insertSong("Dammed");
    music.insertSong("Summer Crush");
    music.insertSong("You");

    music.playAll();

    std::cout << std::endl;

    music.nextSong("Summer Crush");
    music.previousSong("Dammed");

    std::cout << std::endl;

    music.deleteSong("You");

    std::cout << std::endl;

    music.playAll();

    return 0;
} 