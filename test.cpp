#include <iostream>
#include <cstring>

using namespace std;

namespace CAR_CONST
{
    enum
    {
        ID_LEN = 20,
        MAX_SPEED= 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

class Car
{
    private:
        char gamerID[CAR_CONST::ID_LEN];
        int fuelGauge;
        int curSpeed;

    public:
        void initMembers(char* ID, int fuel);
        void ShowCarState();
        void Accel();
        void Break();
};

void Car::initMembers(char* ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    cout << "ID: " << gamerID << endl;
    cout << "Speed: " << curSpeed << endl;
    cout << "Fuel: " << fuelGauge << endl << endl;
}

void Car::Accel()
{
    if (fuelGauge == 0)
        return;

    else
        fuelGauge -= CAR_CONST::FUEL_STEP;
    
    if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPEED)
    {
        curSpeed = CAR_CONST::MAX_SPEED;
        return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
    Car car;
    car.initMembers("run99", 100);
    car.Accel();
    car.Accel();
    car.Accel();
    car.ShowCarState();

    car.Break();
    car.ShowCarState();

    return 0;
}