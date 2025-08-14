#include <bits/stdc++.h>
#include <string>

using namespace std;

// --------------------
// Abstraction Concept:
// --------------------
// Abstraction hides complex implementation details from the user 
// and exposes only the necessary functionality through an interface.
// Here, 'Car' is an abstract class that provides a blueprint for 
// any type of car, but doesn't define how the actions are performed.
// The derived class 'SportsCar' implements the specific behavior.
// --------------------

// Abstract Base Class (Interface for all cars)
class Car {
public:
    // Pure virtual functions - only the function signature is provided
    // These force derived classes to provide their own implementations.
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;

    // Virtual destructor for safe deletion through base class pointer
    virtual ~Car() {}
};

// Concrete Class (Implements the abstract interface)
class SportsCar : public Car {
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    // Constructor
    SportsCar(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0; // Neutral
    }

    // Implementation of abstract methods

    void startEngine() override {
        isEngineOn = true;
        cout << brand << " " << model << ": Engine starts with a roar!" << endl;
    }

    void shiftGear(int gear) override {
        if (!isEngineOn) {
            cout << brand << " " << model << ": Engine is off! Cannot shift gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << ": Shifted to gear " << currentGear << endl;
    }

    void accelerate() override {
        if (!isEngineOn) {
            cout << brand << " " << model << ": Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << ": Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake() override {
        if (currentSpeed > 0) {
            currentSpeed -= 10;
            if (currentSpeed < 0) currentSpeed = 0;
            cout << brand << " " << model << ": Braking, speed now " << currentSpeed << " km/h" << endl;
        } else {
            cout << brand << " " << model << ": Already stopped." << endl;
        }
    }

    void stopEngine() override {
        if (isEngineOn) {
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            cout << brand << " " << model << ": Engine stopped." << endl;
        } else {
            cout << brand << " " << model << ": Engine is already off." << endl;
        }
    }
};

// Main Method demonstrating abstraction
int main() {
    // Using abstraction:
    // We declare a pointer to the base class 'Car'
    // and assign it an object of 'SportsCar'.
    // This allows us to use the car's interface without knowing the details
    // of how a SportsCar works internally.
    Car* myCar = new SportsCar("Ford", "Mustang");

    // The user interacts with the object only via the abstract interface
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    // Clean up
    delete myCar;
    return 0;
}
