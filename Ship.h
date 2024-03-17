//
// Created by stapi on 18.03.2024.
//

#ifndef UNTITLED1_SHIP_H
#define UNTITLED1_SHIP_H

class Ship {
public:
    double currentDamageMultiplier{0};
    double currentFleeChance{0};

    int shipType{0};

    Ship(Ship &currentShip, int inputShipType) {
        currentShip.shipType = inputShipType;

        currentShip.changeMultiplier(currentShip, currentShip.shipType);
        std::cout << "Your ship's flee chance is set to " << currentShip.currentFleeChance * 100
                  << "% and your damage \nmultiplier rate is set to "
                  << 100 * currentShip.currentDamageMultiplier
                  << "% for any kind of damage dealt to your ship.\n"
                     "Your voyage will start in seconds...\n";
    }


    void printFinalScore(Ship currentship) {
        double finalScore = currentship.fuel * 5 + currentship.health * 10 + currentship.balance * 10;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "\n\nGAME OVER!\nYour cosmic voyage ends here.\nYour "
                     "final score is: "
                  << finalScore
                  << "\nThank you for playing!\n\nCOSMIC VOYAGER\nAn indie game made by Korhan "
                     "Karaman and Eda Inan.";
    }

    int shipStatus(Ship currentShip) {
        int areWeDead{0};
        if (currentShip.fuel < 1 || currentShip.health < 1) areWeDead = 1;

        return areWeDead;
    }

    void displayStats(Ship currentShip) {
        std::cout << "\n#Your ship's current stats are:\n#Fuel: " << currentShip.fuel
                  << "\n#Balance: " << currentShip.balance << "\n#Health: " << currentShip.health
                  << "\n";
    }

    int fuelEnough(Ship currentShip) {
        int isFuelEnough{1};
        if (currentShip.fuel < 2) isFuelEnough = 0;
        return isFuelEnough;
    }

    int balanceEnough(Ship currentShip, int howMuchGold) {
        int isBalanceEnough{1};
        if (currentShip.balance < howMuchGold) isBalanceEnough = 0;
        return isBalanceEnough;
    }

    void changeMultiplier(Ship &currentShip, int inputShipType) {
        switch (inputShipType) {
            case 1:  // Fast
                currentShip.currentDamageMultiplier = 1.5;
                currentShip.currentFleeChance = standardFleeChance * 1.5;
                std::cout << "You chose fast.\n";
                break;

            case 2:  // Strong
                currentShip.currentDamageMultiplier = 0.5;
                currentShip.currentFleeChance = standardFleeChance * 0.5;
                std::cout << "You chose strong.\n";
                break;
            case 3:  // Normal
                std::cout << "You chose normal.\n";
                currentShip.currentDamageMultiplier = 1;
                currentShip.currentFleeChance = standardFleeChance;
                break;
            default:
                std::cout << "Undefined ship type. But we will provide a normal ship for you.\n";
                currentShip.currentDamageMultiplier = 1;
                currentShip.currentFleeChance = standardFleeChance;
        }
    }
    void changeStats(Ship &currentShip, int whichStat, double howMuch) {
        switch (whichStat) {
            case 1: {  // Fuel
                currentShip.fuel += howMuch;
                break;
            }
            case 2: {  // Health
                currentShip.health += howMuch;
                break;
            }
            case 3: {  // Balance
                currentShip.balance += howMuch;
                break;
            }
            default:
                std::cout << "Undefined stat.\n";
        }

        if (currentShip.shipStatus(currentShip) == 1) {
            currentShip.displayStats(currentShip);
            currentShip.printFinalScore(currentShip);
            exit(0);
        }
    }

private:
    double fuel{100}, health{100};
    double balance{0};
    double standardFleeChance{0.5};
};



#endif //UNTITLED1_SHIP_H
