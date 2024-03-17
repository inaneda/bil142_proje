//
// Created by stapi on 18.03.2024.
//

#ifndef UNTITLED1_EVENT_H
#define UNTITLED1_EVENT_H

class Event {
public:
    Event() : gen(std::random_device{}()) {}

    void asteroidZone(Ship &currentShip) {
        std::cout << "\n##Be careful! You're passing through an asteroid zone.##\n\n";
        for (int i = 0; i < 3; i++) {
            std::uniform_int_distribution<> fiftyFifty(0, 1);
            int damageOrNot = fiftyFifty(gen);

            if (damageOrNot == 1) {
                std::cout << "    Unlucky! An asteroid hit you and you took "
                          << standardAsteroidDamage * currentShip.currentDamageMultiplier
                          << " damage.\n";
                currentShip.changeStats(
                        currentShip, 2, -standardAsteroidDamage * currentShip.currentDamageMultiplier);
            } else
                std::cout << "    An asteroid was just about to hit you but "
                             "you dodged it. No damage was taken.\n";

        }
        std::cout << "\n##You passed through the asteroid zone.##\n";
    }

    void abandonedPlanet(Ship &currentShip, Event Event) {
        std::cout << "\n##You've encountered an abandoned planet.##\n";
        std::uniform_int_distribution<> fiftyFifty(0, 1);
        int goldOrNot = fiftyFifty(gen);

        if (goldOrNot == 1) {
            currentShip.changeStats(currentShip, 3, standardGoldFind);
            std::cout << "\n    You found " << standardGoldFind
                      << " gold while exploring on this planet.\n";
        } else {
            std::cout << "\n    You stumbled upon space pirates while exploring.\n    You didn't "
                         "find any gold and now you have to deal with them.\n";
            Event.spacePirates(currentShip);
        }
    }

    void spacePirates(Ship &currentShip) {
        std::cout << "\n##Oh crap! Space pirates have surrounded you.##\n";
        int playersDecision{0};
        int readyForNewEvent{0};
        while (readyForNewEvent == 0) {
            std::cout << "\n    What will you do?\n     1: Flee\n     2: "
                         "Attack\n     3: Negotiate\n\n";
            std::cin >> playersDecision;
            switch (playersDecision) {
                case 1:  // Flee
                {
                    std::cout << "\nYou chose to flee.\n";
                    if (currentShip.fuelEnough(currentShip) == 0) {
                        std::cout << "\nInsufficient fuel to perform this action.\n";
                        break;
                    }
                    currentShip.changeStats(currentShip, 1,
                                            -33);  // yakıt yeterli

                    std::uniform_int_distribution<> fleeRandomizer(0, 100);
                    int fleeOrNot = fleeRandomizer(gen);
                    currentShip.currentFleeChance *= 100;
                    if (fleeOrNot < currentShip.currentFleeChance) {
                        std::cout << "\nYou have successfully fled from the "
                                     "space pirates. You lost 33 fuel but it "
                                     "was worth it.\n";
                        readyForNewEvent = 1;

                    } else {
                        std::cout << "\nHow unfortunate! Your flee attempt was "
                                     "unsuccessful and you wasted 33 fuel.\nYou're "
                                     "still surrounded with space pirates.\n";
                        readyForNewEvent = 0;
                    }
                    break;
                }
                case 2:  // Attack
                {
                    std::cout << "\nYou chose to attack.\n";
                    std::uniform_int_distribution<> fiftyFifty(0, 1);
                    int fightWonOrNot = fiftyFifty(gen);
                    if (fightWonOrNot == 1) {
                        std::cout << "\nYou performed an outstanding attack "
                                     "and didn't take any damage. They were "
                                     "impressed.\nSpace pirates have fled.\n";
                        readyForNewEvent = 1;
                    } else {
                        std::cout << "\nYour attack wasn't enough to scare "
                                     "them. You took "
                                  << standardSpacePirateDamage * currentShip.currentDamageMultiplier
                                  << " damage.\nYou're still surrounded with "
                                     "space pirates";
                        readyForNewEvent = 0;
                        currentShip.changeStats(
                                currentShip, 2,
                                -standardSpacePirateDamage * currentShip.currentDamageMultiplier);
                    }
                    break;
                }
                case 3: {
                    std::cout << "\nYou chose to negotiate.\n";
                    std::uniform_int_distribution<> oneThird(1, 3);
                    int requiredGold = (oneThird(gen)) * 10;
                    std::cout << "\nThey want " << requiredGold << " gold from you.\n";
                    currentShip.balanceEnough(currentShip, requiredGold);

                    if (currentShip.balanceEnough(currentShip, requiredGold) == 0) {
                        std::cout << "\nYou don't have enough gold.\n";
                        readyForNewEvent = 0;
                        break;

                    } else {
                        std::cout << "\nNegotiation successful.\n";
                        currentShip.changeStats(currentShip, 3, -requiredGold);
                        readyForNewEvent = 1;
                    }
                    break;

                }
                default: {
                    std::cout << "\nThat is not something you can do, choose again.\n";
                }
            }
        }
    }

private:
    std::mt19937 gen;
};

#endif //UNTITLED1_EVENT_H
