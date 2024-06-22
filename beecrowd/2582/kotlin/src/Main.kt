import java.util.*;

fun main(args: Array<String>){
    val sc = Scanner(System.`in`);

    val songs = mapOf(0 to "PROXYCITY", 1 to "P.Y.N.G",2 to "DNSUEY!", 3 to "SERVERS", 4 to "HOST!", 5 to "CRIPTONIZE", 6 to "OFFLINE DAY", 7 to "SALT",8 to "ANSWER!", 9 to "RAR?"
    ,10 to "WIFI ANTENNAS"
    );

    val a = sc.nextInt();
    val b = sc.nextInt();

    val c = a +b;
    val song = songs[c];
    println(song);
}