#include "declarations.h"

#define MARKET_HALL_BAGIETKA_CENA 4.50
#define MARKET_HALL_BAGIETKA_PUNKTY 22
#define MARKET_HALL_JABLKO_CENA 2.00
#define MARKET_HALL_JABLKO_PUNKTY 5
#define MARKET_HALL_GRUSZKA_CENA 2.00
#define MARKET_HALL_GRUSZKA_PUNKTY 5
#define MARKET_HALL_BANAN_CENA 2.00
#define MARKET_HALL_BANAN_PUNKTY 7
#define MARKET_HALL_WODA_CENA 1.50
#define MARKET_HALL_WODA_PUNKTY 6

void handle_market_hall() {
    while (true) {
        int random_item = get_random_int_to_percent() % 5 + 1;
        string item_name;
        double item_price;
        int item_points;

        if (random_item == 1) {
            item_name = "Bagietka";
            item_price = MARKET_HALL_BAGIETKA_CENA;
            item_points = MARKET_HALL_BAGIETKA_PUNKTY;
        } else if (random_item == 2) {
            item_name = "Jabłko";
            item_price = MARKET_HALL_JABLKO_CENA;
            item_points = MARKET_HALL_JABLKO_PUNKTY;
        } else if (random_item == 3) {
            item_name = "Gruszka";
            item_price = MARKET_HALL_GRUSZKA_CENA;
            item_points = MARKET_HALL_GRUSZKA_PUNKTY;
        } else if (random_item == 4) {
            item_name = "Banan";
            item_price = MARKET_HALL_BANAN_CENA;
            item_points = MARKET_HALL_BANAN_PUNKTY;
        } else {
            item_name = "Woda";
            item_price = MARKET_HALL_WODA_CENA;
            item_points = MARKET_HALL_WODA_PUNKTY;
        }

        set_console_color(0x0D, 0);
        println("Nowa oferta");
        set_console_color(6, 0);
        println(item_name);
        set_console_color(7, 0);
        printf("Cena: %.2f\n", item_price);
        printf("Punkty najedzenia: %d punktów\n", item_points);
        println("  1 - Kup");
        println("  2 - Odrzuć");
        println("  3 - Wyjdź");

        string readed = read("> ", 2);
        if (readed == "1") {
            if (item_price > money) {
                set_console_color(4, 0);
                println("Nie stać cię na taki wydatek, ale wolisz się zadłużyć.");
                set_console_color(7, 0);
            }
            remove_money(item_price);
            hunger -= item_points;
            set_console_color(2, 0);
            println("Zakupiono pomyślnie!");
            set_console_color(7, 0);
            continue;
        } else if (readed == "2") {
            continue;
        } else if (readed == "3") {
            break;
        }
    }
}