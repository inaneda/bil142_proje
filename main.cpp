#include <iostream>
#include <vector>
#include <cmath>
#include <random>

#define numberOfEvents 5

class Ship {

public:
int shipType{0};

Ship(Ship currentShip, int inputShipType){
    currentShip.shipType = inputShipType;

    currentShip.changeMultiplier(currentShip.shipType);
}

double damageMultiplier, fleeMultiplier;

int fuelEnough(Ship currentShip){  ///BUNU DAHA GENEL Bİ FONKSİYON YAPMAM LAZIM
    int isFuelEnough{1};
        if(currentShip.fuel < 2)
            isFuelEnough = 0;
return isFuelEnough;
}

int balanceEnough(Ship currentShip, int howMuchGold){ // BU CODE DUPLICATION OLDU
    int isBalanceEnough{1};
        if(currentShip.balance < howMuchGold)
            isBalanceEnough = 0;
return isBalanceEnough;
}

void changeMultiplier(int shipType) {

    switch (shipType) {
        case 1: // Fast
            currentDamageTaken = standardDamageTaken*1.5;
            currentFleeChance = standardFleeChance*1.5;
            std::cout << "You chose fast.\n";
            break;

        case 2: // Strong
            currentDamageTaken = standardDamageTaken*0.5;
            currentFleeChance = standardFleeChance*0.5;
            std::cout << "You chose strong.\n";
            break;
        case 3: // Normal
            std::cout << "You chose normal.\n";
            currentDamageTaken = standardDamageTaken;
            currentFleeChance = standardFleeChance;
            break;
        default:
            std::cout << "Undefined ship type.\n";
    }
}
    void changeStats(Ship currentShip, int whichStat, int howMuch) {
        switch(whichStat) {
            case 1: // Fuel
                currentShip.fuel += howMuch;
            case 2: // Health
                currentShip.health += howMuch;
            case 3: // Balance
                currentShip.balance += howMuch;
            default:
                std::cout << "Undefined stat.\n";
        }

    }

private:
int fuel{100}, health{100};
int balance{0};
double standardFleeChance{0.5};
double currentFleeChance{0};
double standardDamageTaken{30};
double currentDamageTaken{0};

};


class Event {

public:
    Event() : gen(std::random_device{}()) {}



void asteroidZone (Ship currentShip){
    for(int i = 0; i<3; i++){
        std::uniform_int_distribution<> fiftyFifty(0, 1);
        int damageOrNot = fiftyFifty(gen);

        if (damageOrNot == 1)
            currentShip.changeStats(currentShip, 2, -10);
        else
            continue;

    }
}


void abandonedPlanet (Ship currentShip){
    std::uniform_int_distribution<> fiftyFifty(0, 1);
    int goldOrNot = fiftyFifty(gen);

    if (goldOrNot == 1)
        currentShip.changeStats(currentShip, 3, 10);

    }


    void spacePirates (Ship currentShip){
        int playersDecision{0};
        int readyForNewEvent {0};
        while(readyForNewEvent == 0){
                std::cout << "\nWhat do you choose?\n1: Flee\n2: Attack\n3: Negotiate\n";
                std::cin >> playersDecision;
            switch (playersDecision) {

                case 1: // Flee
                    {
                        std::cout << "\nYou chose to flee.\n";
                        if(currentShip.fuelEnough(currentShip) == 0) {
                            std::cout << "\nInsufficient fuel to perform this action.\n";
                            break;
                            }
                    currentShip.changeStats(currentShip, 1, -33); //yakıt yeterli


                    std::uniform_int_distribution<> fleeRandomizer(0, 1); ///GÜNCEL RATE'E GÖRE RANDOMİZE ETMESİ LAZIM
                    int fleeOrNot = fleeRandomizer(gen);
                        if(fleeOrNot == 0) {
                            std::cout << "\nYou have successfully fled from the space pirates.\n";
                            readyForNewEvent = 1;

                        }
                        else{
                            std::cout << "\nHow unfortunate! Your flee attempt was unsuccessful.\nYou're still surrounded with space pirates.\n";
                            readyForNewEvent = 0;

                        }

                    }
                case 2: // Fight
                {
                    std::cout << "\nYou chose to attack.\n";
                    std::uniform_int_distribution<> fiftyFifty(0, 1);
                    int fightWonOrNot = fiftyFifty(gen);
                    if(fightWonOrNot == 1) {
                        std::cout
                                << "\nYou performed an outstanding attack and didn't take any damage. They were impressed.\nSpace pirates have fled.\n";
                        readyForNewEvent = 1;
                    }
                    else {
                        std::cout
                                << "\n Your attack wasn't enough to scare them.\nYou're still surrounded with space pirates";
                        readyForNewEvent = 0;
                    }

                }
                case 3:
                {
                    std::cout << "\nYou chose to negotiate.\n";
                    std::uniform_int_distribution<> oneThird(1, 3);
                    int requiredGold = (oneThird(gen))*10;
                    std::cout << "\nThey want" << requiredGold <<" gold from you.\n";
                    currentShip.balanceEnough(currentShip, requiredGold);

                    if(currentShip.balanceEnough(currentShip, requiredGold) == 0) {
                        std::cout << "\nYou don't have enough gold.\n";
                        readyForNewEvent = 1;
                        break;

                    }
                    else{
                        std::cout << "\nNegotiation successful.\n";
                        currentShip.changeStats(currentShip, 3, -requiredGold);
                        readyForNewEvent = 1;
                    }
                }
            }
        }
    }


private:
    std::mt19937 gen;

};

void eventHandler(Ship currentShip){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, 3);

    int whichEvent = dis(gen);

    switch (whichEvent) {  ///FONKSİYONA ULAŞAMADIM BURADA KALDIK 13.03.2024

        case 1: {

            currentShip.
        }

    }


}

int main() {
Ship ship1(ship1, 1);
Event event1;
event1.spacePirates(ship1);
//BURADA KALDIKG


    return 0;
}
