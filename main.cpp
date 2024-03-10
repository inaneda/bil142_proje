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
}

double damageMultiplier, fleeMultiplier;

int fuelEnough(Ship currentShip){
   int isFuelEnough{1};
    if(currentShip.fuel < 2)
        isFuelEnough = 0;
    return isFuelEnough;
}

void changeMultiplier(int shipType) {

    switch (shipType) {
        case 1: // Fast
            damageMultiplier *= 1.5;
            fleeMultiplier *= 1.5;
            break;

        case 2: // Strong
            damageMultiplier *= 0.5;
            fleeMultiplier *= 0.5;
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
        while(1){
                std::cout << "\nWhat do you choose?\n1: Flee\n2: Attack\n3: Negotiate\n";
                std::cin >> playersDecision;
            switch (playersDecision) {

                case 1:
                    {
                        if(currentShip.fuelEnough(currentShip) == 0) {
                            std::cout << "\nInsufficient fuel to perform this action.\n";
                            break;
                            }
                    currentShip.changeStats(currentShip, 1, -33);
            double fleeChance{0.5};
                    currentShip.changeMultiplier(currentShip.shipType);




                    }


            }



        }



    }


private:
    std::mt19937 gen;

};




int main() {
Ship ship1(ship1, 1);
Event event1;
event1.spacePirates(ship1);
//BURADA KALDIKG




    return 0;
}
