#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/lab5.hpp"

#include <string>
#include <vector>

using namespace std;

TEST_CASE("CircularLinkedList basic operations", "[circular]") {
    CircularLinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);

    REQUIRE(list.getCurrent() == 1);
    list.step();
    REQUIRE(list.getCurrent() == 2);
    list.step();
    REQUIRE(list.getCurrent() == 3);
    list.step();
    REQUIRE(list.getCurrent() == 1);
}

TEST_CASE("Monopoly board order", "[monopoly]") {
    CircularLinkedList<string> board;
    vector<string> spaces = {
        "Go",
        "Mediterranean Avenue",
        "Community Chest",
        "Baltic Avenue",
        "Income Tax",
        "Reading Railroad",
        "Oriental Avenue",
        "Chance",
        "Vermont Avenue",
        "Connecticut Avenue",
        "Jail (Just Visiting)",
        "St. Charles Place",
        "Electric Company",
        "States Avenue",
        "Virginia Avenue",
        "Pennsylvania Railroad",
        "St. James Place",
        "Community Chest",
        "Tennessee Avenue",
        "New York Avenue",
        "Free Parking",
        "Kentucky Avenue",
        "Chance",
        "Indiana Avenue",
        "Illinois Avenue",
        "B&O Railroad",
        "Atlantic Avenue",
        "Ventnor Avenue",
        "Water Works",
        "Marvin Gardens",
        "Go to Jail",
        "Pacific Avenue",
        "North Carolina Avenue",
        "Community Chest",
        "Pennsylvania Avenue",
        "Short Line Railroad",
        "Chance",
        "Park Place",
        "Luxury Tax",
        "Boardwalk"
    };

    for (auto& s : spaces) board.append(s);

    for (auto& s : spaces) {
        REQUIRE(board.getCurrent() == s);
        board.step();
    }
}

TEST_CASE("Roll dice and move", "roll") {
    CircularLinkedList<int> board;
    for (int i = 1; i <= 10; i++) board.append(i);

    int start = board.getCurrent();
    int roll = board.rollAndMove();
    REQUIRE(roll >= 2);
    REQUIRE(roll <= 12);
    REQUIRE(board.getCurrent() >= 1);
    REQUIRE(board.getCurrent() <= 10);
}

TEST_CASE("Benchmark stepping with Catch2", "benchmark") {
    CircularLinkedList<int> list;
    for (int i = 0; i < 10000; i++) list.append(i);

    BENCHMARK("Stepping through list") {
        list.step();
    };
}

