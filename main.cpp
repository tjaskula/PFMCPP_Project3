/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

struct CoffeeMachine
{
    int numberOfCoffeeTypes = 10;
    float waterTankCapacityLiters = 1.5f;
    int coffeeBeansGrams = 500;
    float currentTemperatureCelsius = 90.0f;
    int daysBeforeServicing = 30;

    CoffeeMachine();

    void brewCoffee(int coffeeTypeIndex);
    void refillWater(float waterAmountLiters);
    void selectCoffeeType(int coffeeTypeIndex);
};

struct SmartThermostat
{
    float currentRoomTemperature = 20.0f;
    float desiredTemperature = 22.0f;
    float energyConsumptionKWh = 3.5f;
    std::string mode = "Auto";
    bool isWifiConnected = true;

    SmartThermostat();

    void adjustTemperature(float newTemperature);
    void switchMode(const std::string& newMode);
    float sendEnergyUsageReport();
};

struct LibraryAccount
{
    int booksCheckedOut = 3;
    int totalBooksAllowed = 10;
    double fineAmountDue = 0.0;
    std::string accountStatus = "active";
    int daysUntilReturnDue = 14;

    LibraryAccount();

    void checkOutBooks(int numberOfBooks);
    void payFines(double amount);
    void renewBooks();
};

struct ExerciseBike
{
    float currentSpeedKmPerHour = 0.0f;
    float totalDistanceKm = 0.0f;
    int resistanceLevel = 1;
    int userHeartRate = 60;
    double caloriesBurned = 0.0;

    ExerciseBike();

    void adjustResistance(int newResistanceLevel);
    void trackDistanceAndSpeed();
    int monitorHeartRate();
};

struct Cockpit
{
    int numberOfControlPanels = 4;
    std::string autopilotSystemType = "Advanced";
    bool visibilityThroughWindshield = true;
    int numberOfSeats = 2;
    int amountOfEmergencyEquipment = 5;

    struct NavigationSystem
    {
        float gpsLatitude = 0.0f;
        float gpsLongitude = 0.0f;
        bool hasAutoPilotCapability = true;
        std::string currentFlightPlan = "N/A";
        float altitude = 10000.0f;

        NavigationSystem();

        void updateFlightPlan(const std::string& newFlightPlan);
        void changeAltitude(float newAltitude);
        void activateAutoPilot();
    };

    Cockpit();

    void navigateAirplane();
    void communicateWithATC(const std::string& message);
    void monitorSystems();
    void importNavigationSettings(NavigationSystem backupNavigationSystem);
    void performDiagnosticOnSystem(NavigationSystem systemToCheck);

    NavigationSystem navigationSystem;
};

struct Engine
{
    float thrustPowerKiloNewtons = 100.0f;
    float fuelConsumptionPerHour = 50.0f;
    std::string engineType = "Jet";
    float operatingTemperatureRange = 150.0f;
    int currentRPM = 2000;

    struct ThrustControl
    {
        float maxThrustKiloNewtons = 120.0f;
        float currentThrustKiloNewtons = 100.0f;
        bool isAfterburnerActive = false;
        int thrustEfficiencyPercentage = 90;
        float fuelFlowRate = 0.0f;

        ThrustControl();

        void increaseThrust(float amount);
        void activateAfterburner();
        void decreaseThrust(float amount);
    };

    Engine();

    void propelAirplane();
    void adjustThrust(float newThrustLevel);
    void startEngine();
    void adjustToMatchOtherEngine(ThrustControl otherEngineThrustControl);
    void initiateEmergencyShutdown(ThrustControl emergencyControlSettings);

    ThrustControl thrustControl;
};

struct Wings
{
    float wingspanMeters = 20.0f;
    float fuelCapacityLiters = 2000.0f;
    int numberOfFlaps = 4;
    std::string materialType = "Composite";
    double elasticityPercent = 5.0;

    Wings();

    void provideLift();
    void controlTilt(float angle);
    void adjustForManeuvering();
};

struct LandingGear
{
    int numberOfWheels = 6;
    float maximumWeightCapacity = 10000.0f;
    bool isRetractable = true;
    int brakeEffectiveness = 8;
    float shockAbsorptionLevel = 7.5f;

    LandingGear();

    void deploy();
    void retract();
    void activateBrakes();
};

struct Cabin
{
    int numberOfPassengerSeats = 150;
    float availableLegroomInches = 32.0f;
    int numberOfRestrooms = 2;
    std::string onboardEntertainmentOptions = "Movies, Music";
    int airFiltrationSystemQuality = 9;

    Cabin();

    void adjustTemperature(float newTemperature);
    void controlPressure();
    void monitorAirQuality();
};

struct Airplane
{
    Cockpit cockpit;
    Engine engine;
    Wings wings;
    LandingGear landingGear;
    Cabin cabin;

    Airplane();

    void takeOff();
    void land();
    void navigate(const std::string& destination); 
};

// Implementations for CoffeeMachine
CoffeeMachine::CoffeeMachine() : numberOfCoffeeTypes(10), waterTankCapacityLiters(1.5f), 
                  coffeeBeansGrams(500), currentTemperatureCelsius(90.0f), 
                  daysBeforeServicing(30)
{
    std::cout << "Constructing CoffeeMachine" << std::endl;
}

void CoffeeMachine::brewCoffee(int coffeeTypeIndex)
{
    std::cout << "Brewing coffee type " << coffeeTypeIndex << std::endl;
}

void CoffeeMachine::refillWater(float waterAmountLiters)
{
    waterTankCapacityLiters += waterAmountLiters;
    std::cout << "Refilled water tank. Current capacity: " << waterTankCapacityLiters << " liters" << std::endl;
}

void CoffeeMachine::selectCoffeeType(int coffeeTypeIndex)
{
    std::cout << "Selected coffee type " << coffeeTypeIndex << std::endl;
}

// Implementations for SmartThermostat
SmartThermostat::SmartThermostat() : currentRoomTemperature(20.0f), desiredTemperature(22.0f),
                    energyConsumptionKWh(3.5f), mode("Auto"), isWifiConnected(true)
{
    std::cout << "Constructing SmartThermostat" << std::endl;
}

void SmartThermostat::adjustTemperature(float newTemperature)
{
    desiredTemperature = newTemperature;
    std::cout << "Adjusted desired temperature to " << newTemperature << std::endl;
}

void SmartThermostat::switchMode(const std::string& newMode)
{
    mode = newMode;
    std::cout << "Switched mode to " << newMode << std::endl;
}

float SmartThermostat::sendEnergyUsageReport()
{
    std::cout << "Sending energy usage report. Total consumption: " << energyConsumptionKWh << " kWh" << std::endl;
    return energyConsumptionKWh;
}

// Implementations for LibraryAccount
LibraryAccount::LibraryAccount() : booksCheckedOut(3), totalBooksAllowed(10), 
                   fineAmountDue(0.0), accountStatus("active"), 
                   daysUntilReturnDue(14)
{
    std::cout << "Constructing LibraryAccount" << std::endl;
}

void LibraryAccount::checkOutBooks(int numberOfBooks)
{
    booksCheckedOut += numberOfBooks;
    std::cout << "Checked out " << numberOfBooks << " books" << std::endl;
}

void LibraryAccount::payFines(double amount)
{
    fineAmountDue -= amount;
    std::cout << "Paid fine. Remaining fine amount: $" << fineAmountDue << std::endl;
}

void LibraryAccount::renewBooks()
{
    std::cout << "Books renewed. No fines due" << std::endl;
}

// Implementations for ExerciseBike
ExerciseBike::ExerciseBike() : currentSpeedKmPerHour(0.0f), totalDistanceKm(0.0f), 
                 resistanceLevel(1), userHeartRate(60), caloriesBurned(0.0)
{
    std::cout << "Constructing ExerciseBike" << std::endl;
}

void ExerciseBike::adjustResistance(int newResistanceLevel)
{
    resistanceLevel = newResistanceLevel;
    std::cout << "Adjusted resistance to level " << newResistanceLevel << std::endl;
}

void ExerciseBike::trackDistanceAndSpeed()
{
    std::cout << "Tracking distance and speed. Current speed: " << currentSpeedKmPerHour << " km/h" << std::endl;
}

int ExerciseBike::monitorHeartRate()
{
    std::cout << "Monitoring heart rate: " << userHeartRate << " BPM" << std::endl;
    return userHeartRate;
}

// Implementations for Cockpit
Cockpit::Cockpit() : numberOfControlPanels(4), autopilotSystemType("Advanced"), 
            visibilityThroughWindshield(true), numberOfSeats(2), 
            amountOfEmergencyEquipment(5)
{
    std::cout << "Constructing Cockpit" << std::endl;
}

void Cockpit::navigateAirplane()
{
    std::cout << "Navigating airplane" << std::endl;
}

void Cockpit::communicateWithATC(const std::string& message)
{
    std::cout << "Communicating with ATC: " << message << std::endl;
}

void Cockpit::monitorSystems()
{
    std::cout << "Monitoring airplane systems" << std::endl;
}

void Cockpit::importNavigationSettings(Cockpit::NavigationSystem backupNavigationSystem)
{
    navigationSystem = backupNavigationSystem;
    std::cout << "Imported navigation settings from backup" << std::endl;
}

void Cockpit::performDiagnosticOnSystem(Cockpit::NavigationSystem systemToCheck)
{
    std::cout << "Performing diagnostic check on navigation system." << std::endl;

    const float epsilon = 0.001f;

    // Example diagnostics
    if (std::abs(navigationSystem.altitude - systemToCheck.altitude) < epsilon)
    {
        std::cout << "Altitude discrepancy detected. Current: " << navigationSystem.altitude
                  << ", Checked: " << systemToCheck.altitude << std::endl;
    }

    if (navigationSystem.hasAutoPilotCapability != systemToCheck.hasAutoPilotCapability)
    {
        std::cout << "Autopilot capability mismatch. Current: "
                  << (navigationSystem.hasAutoPilotCapability ? "Enabled" : "Disabled")
                  << ", Checked: " << (systemToCheck.hasAutoPilotCapability ? "Enabled" : "Disabled") << std::endl;
    }
}

Cockpit::NavigationSystem::NavigationSystem() : gpsLatitude(0.0f), gpsLongitude(0.0f), 
                     hasAutoPilotCapability(true), currentFlightPlan("N/A"), 
                     altitude(10000.0f)
{
    std::cout << "Constructing NavigationSystem" << std::endl;
}

void Cockpit::NavigationSystem::updateFlightPlan(const std::string& newFlightPlan)
{
    currentFlightPlan = newFlightPlan;
    std::cout << "Updated flight plan to " << newFlightPlan << std::endl;
}

void Cockpit::NavigationSystem::changeAltitude(float newAltitude)
{
    altitude = newAltitude;
    std::cout << "Changed altitude to " << newAltitude << std::endl;
}

void Cockpit::NavigationSystem::activateAutoPilot()
{
    hasAutoPilotCapability = true;
    std::cout << "Autopilot activated" << std::endl;
}

// Implementations for Engine
Engine::Engine() : thrustPowerKiloNewtons(100.0f), fuelConsumptionPerHour(50.0f), 
           engineType("Jet"), operatingTemperatureRange(150.0f), 
           currentRPM(2000)
{
    std::cout << "Constructing Engine" << std::endl;
}

void Engine::propelAirplane() {
    std::cout << "Propelling airplane" << std::endl;
}

void Engine::adjustThrust(float newThrustLevel)
{
    thrustPowerKiloNewtons = newThrustLevel;
    std::cout << "Adjusted thrust to " << newThrustLevel << " kilonewtons" << std::endl;
}

void Engine::startEngine()
{
    std::cout << "Engine started" << std::endl;
}

void Engine::adjustToMatchOtherEngine(Engine::ThrustControl otherEngineThrustControl)
{
    thrustControl = otherEngineThrustControl;
    std::cout << "Adjusted to match other engine's thrust control settings" << std::endl;
}

void Engine::initiateEmergencyShutdown(Engine::ThrustControl emergencyControlSettings)
{
    thrustControl = emergencyControlSettings;
    std::cout << "Initiating emergency shutdown" << std::endl;
}

Engine::ThrustControl::ThrustControl() : maxThrustKiloNewtons(120.0f), currentThrustKiloNewtons(100.0f), 
                  isAfterburnerActive(false), thrustEfficiencyPercentage(90), 
                  fuelFlowRate(0.0f)
{
    std::cout << "Constructing ThrustControl" << std::endl;
}

void Engine::ThrustControl::increaseThrust(float amount)
{
    currentThrustKiloNewtons += amount;
    std::cout << "Increased thrust by " << amount << std::endl;
}

void Engine::ThrustControl::activateAfterburner()
{
    isAfterburnerActive = true;
    std::cout << "Afterburner activated" << std::endl;
}

void Engine::ThrustControl::decreaseThrust(float amount)
{
    currentThrustKiloNewtons -= amount;
    std::cout << "Decreased thrust by " << amount << std::endl;
}

// Implementations for Wings
Wings::Wings() : wingspanMeters(20.0f), fuelCapacityLiters(2000.0f), 
          numberOfFlaps(4), materialType("Composite"), 
          elasticityPercent(5.0)
{
    std::cout << "Constructing Wings" << std::endl;
}

void Wings::provideLift()
{
    std::cout << "Wings providing lift with wingspan of " << wingspanMeters << " meters." << std::endl;
}

void Wings::controlTilt(float angle)
{
    std::cout << "Tilting wings to " << angle << " degrees for better maneuverability." << std::endl;
}

void Wings::adjustForManeuvering()
{
    std::cout << "Adjusting wing flaps and elasticity by " << elasticityPercent << "% for improved stability." << std::endl;
}

// Implementations for LandingGear
LandingGear::LandingGear() : numberOfWheels(6), maximumWeightCapacity(10000.0f), 
                isRetractable(true), brakeEffectiveness(8), 
                shockAbsorptionLevel(7.5f)
{
    std::cout << "Constructing LandingGear" << std::endl;
}

void LandingGear::deploy()
{
    std::cout << "Deploying " << numberOfWheels << " wheels of landing gear." << std::endl;
}

void LandingGear::retract()
{
    std::cout << "Retracting landing gear. Gear is " << (isRetractable ? "" : "not ") << "retractable." << std::endl;
}

void LandingGear::activateBrakes()
{
    std::cout << "Activating brakes with effectiveness level of " << brakeEffectiveness << " out of 10." << std::endl;
}

// Implementations for Cabin
Cabin::Cabin() : numberOfPassengerSeats(150), availableLegroomInches(32.0f), 
          numberOfRestrooms(2), onboardEntertainmentOptions("Movies, Music"), 
          airFiltrationSystemQuality(9)
{
    std::cout << "Constructing Cabin" << std::endl;
}

void Cabin::adjustTemperature(float newTemperature)
{
    std::cout << "Adjusting cabin temperature from " << availableLegroomInches << " inches legroom space to " << newTemperature << "°C." << std::endl;
}

void Cabin::controlPressure()
{
    std::cout << "Controlling cabin pressure for " << numberOfPassengerSeats << " seats." << std::endl;
}

void Cabin::monitorAirQuality()
{
    std::cout << "Monitoring air quality. Filtration system quality: " << airFiltrationSystemQuality << "/10." << std::endl;
}

// Implementations for Airplane
Airplane::Airplane()
{
    std::cout << "Constructing Airplane" << std::endl;
}

void Airplane::takeOff()
{
    std::cout << "Airplane taking off. Cockpit and engines are ready." << std::endl;
    cockpit.navigateAirplane();
    engine.propelAirplane();
}

void Airplane::land()
{
    std::cout << "Airplane landing. Deploying landing gear." << std::endl;
    landingGear.deploy();
}

void Airplane::navigate(const std::string& destination)
{
    std::cout << "Airplane navigating to " << destination << ". Autopilot: " << cockpit.autopilotSystemType << "." << std::endl;
    cockpit.navigateAirplane();
}



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
