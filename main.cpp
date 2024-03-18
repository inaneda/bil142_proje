#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#define numberOfEvents 5
#define standardAsteroidDamage 10
#define standardSpacePirateDamage 30
#define standardGoldFind 10

#include "Ship.h"
#include "Event.h"




void eventHandler(Ship &currentShip) {
    static int numberOfEventsLeft = numberOfEvents;
    static int currentEventNumber{1};
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, 3);

    int whichEvent = dis(gen);

    Event event;

    std::this_thread::sleep_for(std::chrono::milliseconds(7000));
    std::cout << "\n\n\n\n\nYOU HAVE " << numberOfEventsLeft
              << " RANDOM EVENT(S) LEFT TO ENCOUNTER\n\nRANDOM EVENT " << currentEventNumber
              << ":\n";  // for readability
    --numberOfEventsLeft;
    ++currentEventNumber;
    switch (whichEvent) {       //whichEvent kesinlikle 1, 2 ya da 3 tam sayısına eşit, default statement'a gerek yok.
        case 1: {
            event.spacePirates(currentShip);
            break;
        }
        case 2: {
            event.abandonedPlanet(currentShip, event);
            break;
        }
        case 3: {
            event.asteroidZone(currentShip);
            break;

        }
    }
    currentShip.displayStats(currentShip);
}

int main() {
    std::cout << "\nCOSMIC VOYAGER\n";
    std::cout << " In this game, you embark on an interstellar journey facing "
                 "cosmic challenges.\n"
                 " Customize your ship's traits for speed, strength, or "
                 "balance. Navigate asteroid zones, explore\n"
                 " abandoned planets, and confront space pirates. Choose "
                 "wisely between fleeing, fighting, or\n"
                 " negotiating. Every decision shapes your voyage's outcome.\n";

    int shipType;
    std::cout << "\nChoose ship type to start your voyage:\n 1: Fast\n 2: Strong\n 3: Normal\n\n";
    std::cin >> shipType;
    Ship ship1(ship1, shipType);

    for (int i = 0; i < numberOfEvents && ship1.shipStatus(ship1) == 0; i++) {
        eventHandler(ship1);
    }

    ship1.printFinalScore(ship1);

    return 0;
}
