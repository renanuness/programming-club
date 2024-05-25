import java.util.Scanner

fun main(args: Array<String>) {
    val sc = Scanner(System.`in`);
    var n:Int;

    val a = sc.nextInt();
    do {
        n = sc.nextInt();
    }while(n <= 0);

    val limit = n+a-1;
    var sum:Int = 0;
    for (i in a..limit) {
        sum += i;
    }

    println(sum);
}