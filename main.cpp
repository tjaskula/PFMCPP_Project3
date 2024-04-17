/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

struct CoffeeMachine {
    int numberOfCoffeeTypes;
    float waterTankCapacityLiters;
    int coffeeBeansGrams;
    float currentTemperatureCelsius;
    int daysBeforeServicing;

    CoffeeMachine() 
    : numberOfCoffeeTypes(10), waterTankCapacityLiters(1.5f), 
      coffeeBeansGrams(500), currentTemperatureCelsius(90.0f), 
      daysBeforeServicing(30) {
        std::cout << "Constructing CoffeeMachine\n";
    }

    void brewCoffee(int coffeeTypeIndex) {
        std::cout << "Brewing coffee type " << coffeeTypeIndex << ", available types: " << numberOfCoffeeTypes << "\n";
    }

    void refillWater(float waterAmountLiters) {
        waterTankCapacityLiters += waterAmountLiters;
        std::cout << "Refilled water tank. Current capacity: " << waterTankCapacityLiters << " liters\n";
    }

    void selectCoffeeType(int coffeeTypeIndex) {
        std::cout << "Selected coffee type " << coffeeTypeIndex << "\n";
    }
};

struct SmartThermostat {
    float currentRoomTemperature {20.0f};
    float desiredTemperature;
    float energyConsumptionKWh {3.5f};
    std::string mode {"Auto"};
    bool isWifiConnected;

    SmartThermostat(float initDesiredTemperature = 22.0f, bool initWifiConnected = true)
    : desiredTemperature(initDesiredTemperature), isWifiConnected(initWifiConnected) {
        std::cout << "Constructing SmartThermostat\n";
    }

    void adjustTemperature(float newTemperature) {
        desiredTemperature = newTemperature;
        std::cout << "Adjusted desired temperature to " << newTemperature << "\n";
    }

    void switchMode(const std::string& newMode) {
        mode = newMode;
        std::cout << "Switched mode to " << newMode << "\n";
    }

    float sendEnergyUsageReport() {
        std::cout << "Sending energy usage report. Total consumption: " << energyConsumptionKWh << " kWh\n";
        return energyConsumptionKWh;
    }
};

struct LibraryAccount {
    int booksCheckedOut {0};
    int totalBooksAllowed;
    double fineAmountDue {0.0};
    std::string accountStatus {"active"};
    int daysUntilReturnDue;

    LibraryAccount(int allowed = 10, int daysUntilDue = 14)
    : totalBooksAllowed(allowed), daysUntilReturnDue(daysUntilDue) {
        std::cout << "Constructing LibraryAccount\n";
    }

    void checkOutBooks(int numberOfBooks) {
        booksCheckedOut += numberOfBooks;
        std::cout << "Checked out " << numberOfBooks << " books. Total checked out: " << booksCheckedOut << "\n";
    }

    void payFines(double amount) {
        fineAmountDue -= amount;
        std::cout << "Paid fine. Remaining fine amount: $" << fineAmountDue << "\n";
    }

    void renewBooks() {
        std::cout << "Books renewed. No fines due\n";
    }
};

struct ExerciseBike {
    float currentSpeedKmPerHour {0.0f};
    float totalDistanceKm {0.0f};
    int resistanceLevel {1};
    int userHeartRate {60};
    double caloriesBurned {0.0};

    ExerciseBike() {
        std::cout << "Constructing ExerciseBike\n";
    }

    void adjustResistance(int newResistanceLevel) {
        resistanceLevel = newResistanceLevel;
        std::cout << "Adjusted resistance to level " << newResistanceLevel << "\n";
    }

    void trackDistanceAndSpeed() {
        std::cout << "Tracking distance and speed. Current speed: " << currentSpeedKmPerHour << " km/h\n";
    }

    int monitorHeartRate() {
        std::cout << "Monitoring heart rate: " << userHeartRate << " BPM\n";
        return userHeartRate;
    }
};

struct Cockpit {
    int numberOfControlPanels {4};
    std::string autopilotSystemType {"Advanced"};
    bool visibilityThroughWindshield {true};
    int numberOfSeats {2};
    int amountOfEmergencyEquipment {5};

    struct NavigationSystem {
        float gpsLatitude {0.0f};
        float gpsLongitude {0.0f};
        bool hasAutoPilotCapability {true};
        std::string currentFlightPlan {"N/A"};
        float altitude {10000.0f};

        NavigationSystem() {
            std::cout << "Constructing NavigationSystem\n";
        }

        void updateFlightPlan(const std::string& newFlightPlan) {
            currentFlightPlan = newFlightPlan;
            std::cout << "Updated flight plan to " << newFlightPlan << "\n";
        }

        void changeAltitude(float newAltitude) {
            altitude = newAltitude;
            std::cout << "Changed altitude to " << newAltitude << "\n";
        }

        void activateAutoPilot() {
            hasAutoPilotCapability = true;
            std::cout << "Autopilot activated\n";
        }
    };

    Cockpit() {
        std::cout << "Constructing Cockpit\n";
    }

    void navigateAirplane() {
        std::cout << "Navigating airplane with autopilot system type: " << autopilotSystemType << "\n";
    }

    void communicateWithATC(const std::string& message) {
        std::cout << "Communicating with ATC: " << message << "\n";
    }

    void monitorSystems() {
        std::cout << "Monitoring airplane systems\n";
    }

    void importNavigationSettings(NavigationSystem backupNavigationSystem) {
        navigationSystem = backupNavigationSystem;
        std::cout << "Imported navigation settings from backup\n";
    }

    void performDiagnosticOnSystem(NavigationSystem systemToCheck) {
        std::cout << "Performing diagnostic check on navigation system.\n";
        const float epsilon = 0.001f;
        if (std::abs(navigationSystem.altitude - systemToCheck.altitude) > epsilon) {
            std::cout << "Altitude discrepancy detected. Current: " << navigationSystem.altitude
                      << ", Checked: " << systemToCheck.altitude << "\n";
        }
        if (navigationSystem.hasAutoPilotCapability != systemToCheck.hasAutoPilotCapability) {
            std::cout << "Autopilot capability mismatch. Current: "
                      << (navigationSystem.hasAutoPilotCapability ? "Enabled" : "Disabled")
                      << ", Checked: " << (systemToCheck.hasAutoPilotCapability ? "Enabled" : "Disabled") << "\n";
        }
    }

    NavigationSystem navigationSystem;
};

struct Engine {
    float thrustPowerKiloNewtons {100.0f};
    float fuelConsumptionPerHour;
    std::string engineType {"Jet"};
    float operatingTemperatureRange {150.0f};
    int currentRPM;

    Engine(float fuelRate = 50.0f, int rpm = 2000)
    : fuelConsumptionPerHour(fuelRate), currentRPM(rpm) {
        std::cout << "Constructing Engine\n";
    }

    void propelAirplane() {
        std::cout << "Propelling airplane with engine type: " << engineType << "\n";
    }

    void adjustThrust(float newThrustLevel) {
        thrustPowerKiloNewtons = newThrustLevel;
        std::cout << "Adjusted thrust to " << newThrustLevel << " kilonewtons\n";
    }

    void startEngine() {
        std::cout << "Engine started\n";
    }
};


struct Wings {
    float wingspanMeters {20.0f};
    float fuelCapacityLiters {2000.0f};
    int numberOfFlaps {4};
    std::string materialType {"Composite"};
    double elasticityPercent {5.0};

    Wings() {
        std::cout << "Constructing Wings\n";
    }

    void provideLift() {
        std::cout << "Wings providing lift with wingspan of " << wingspanMeters << " meters\n";
    }

    void controlTilt(float angle) {
        std::cout << "Tilting wings to " << angle << " degrees for better maneuverability\n";
    }

    void adjustForManeuvering() {
        std::cout << "Adjusting wing flaps and elasticity by " << elasticityPercent << "% for improved stability\n";
    }
};

struct LandingGear {
    int numberOfWheels {6};
    float maximumWeightCapacity {10000.0f};
    bool isRetractable {true};
    int brakeEffectiveness {8};
    float shockAbsorptionLevel {7.5f};

    LandingGear() {
        std::cout << "Constructing LandingGear\n";
    }

    void deploy() {
        std::cout << "Deploying " << numberOfWheels << " wheels of landing gear\n";
    }

    void retract() {
        std::cout << "Retracting landing gear. Gear is " << (isRetractable ? "retractable" : "not retractable") << "\n";
    }

    void activateBrakes() {
        std::cout << "Activating brakes with effectiveness level of " << brakeEffectiveness << " out of 10\n";
    }
};

struct Cabin {
    int numberOfPassengerSeats {150};
    float availableLegroomInches {32.0f};
    int numberOfRestrooms {2};
    std::string onboardEntertainmentOptions {"Movies, Music"};
    int airFiltrationSystemQuality {9};

    Cabin() {
        std::cout << "Constructing Cabin\n";
    }

    void adjustTemperature(float newTemperature) {
        std::cout << "Adjusting cabin temperature from " << availableLegroomInches << " inches legroom space to " << newTemperature << "°C\n";
    }

    void controlPressure() {
        std::cout << "Controlling cabin pressure for " << numberOfPassengerSeats << " seats\n";
    }

    void monitorAirQuality() {
        std::cout << "Monitoring air quality. Filtration system quality: " << airFiltrationSystemQuality << "/10\n";
    }
};

struct Airplane {
    Cockpit cockpit;
    Engine engine;
    Wings wings;
    LandingGear landingGear;
    Cabin cabin;

    Airplane() {
        std::cout << "Constructing Airplane\n";
    }

    void takeOff() {
        std::cout << "Airplane taking off. Cockpit and engines are ready\n";
        cockpit.navigateAirplane();
        engine.propelAirplane();
    }

    void land() {
        std::cout << "Airplane landing. Deploying landing gear\n";
        landingGear.deploy();
    }

    void navigate(const std::string& destination) {
        std::cout << "Airplane navigating to " << destination << ". Autopilot: " << cockpit.autopilotSystemType << "\n";
        cockpit.navigateAirplane();
    }
};

int main()
{
    Example::main(); //do not delete this line
    //add your code here:

    CoffeeMachine coffeeMachine1, coffeeMachine2;
    SmartThermostat thermostat1, thermostat2;
    LibraryAccount libraryAccount1, libraryAccount2;
    ExerciseBike bike1, bike2;
    Cockpit cockpit1, cockpit2;
    Engine engine1, engine2;
    Wings wings1, wings2;
    LandingGear gear1, gear2;
    Cabin cabin1, cabin2;
    Airplane airplane1, airplane2;

    // Call member functions
    coffeeMachine1.brewCoffee(1);
    coffeeMachine1.refillWater(0.5);
    coffeeMachine1.selectCoffeeType(2);

    thermostat1.adjustTemperature(25.0f);
    thermostat1.switchMode("Heat");
    thermostat2.sendEnergyUsageReport();

    libraryAccount1.checkOutBooks(5);
    libraryAccount1.payFines(20.0);
    libraryAccount2.renewBooks();

    bike1.adjustResistance(3);
    bike1.trackDistanceAndSpeed();
    bike2.monitorHeartRate();

    cockpit1.navigateAirplane();
    cockpit1.communicateWithATC("Ascending to 15000 feet.");
    cockpit2.monitorSystems();

    engine1.propelAirplane();
    engine1.adjustThrust(110.0f);
    engine2.startEngine();

    wings1.provideLift();
    wings1.controlTilt(15.0f);
    wings2.adjustForManeuvering();

    gear1.deploy();
    gear1.retract();
    gear2.activateBrakes();

    cabin1.adjustTemperature(22.0f);
    cabin1.controlPressure();
    cabin2.monitorAirQuality();

    airplane1.takeOff();
    airplane1.land();
    airplane2.navigate("New York");

    // Display some values
    std::cout << "Coffee machine current water level: " << coffeeMachine1.waterTankCapacityLiters << " liters" << std::endl;
    std::cout << "Thermostat current temperature: " << thermostat1.currentRoomTemperature << " degrees Celsius" << std::endl;
    std::cout << "Library account books checked out: " << libraryAccount1.booksCheckedOut << std::endl;
    std::cout << "Exercise bike current speed: " << bike1.currentSpeedKmPerHour << " km/h" << std::endl;
    std::cout << "Cockpit current altitude: " << cockpit1.navigationSystem.altitude << " feet" << std::endl;
    std::cout << "Engine current RPM: " << engine1.currentRPM << std::endl;
    std::cout << "Wings current wingspan: " << wings1.wingspanMeters << " meters" << std::endl;
    std::cout << "Landing gear number of wheels: " << gear1.numberOfWheels << std::endl;
    std::cout << "Cabin number of seats: " << cabin1.numberOfPassengerSeats << std::endl;
    std::cout << "Airplane taking off with cockpit system type: " << airplane1.cockpit.autopilotSystemType << std::endl;

 
    std::cout << "good to go!" << std::endl;
}
