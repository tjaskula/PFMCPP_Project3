 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    void run(int howFast, bool startWithLeftFoot);

    struct Foot
    {
        void stepForward();
        int stepSize();
    };

    Foot leftFoot;
    Foot rightFoot;
};

void Person::Foot::stepForward()
{
    std::cout << "stepForward\n";
}

int Person::Foot::stepSize()
{
    return 2;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    int numberOfSteps = howFast * 2; // Assuming the number of steps is proportional to how fast they run

    if(startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTraveled += (leftFoot.stepSize() + rightFoot.stepSize()) * numberOfSteps;
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

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

        void updateFlightPlan(const std::string& newFlightPlan);
        void changeAltitude(float newAltitude);
        void activateAutoPilot();
    };

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

        void increaseThrust(float amount);
        void activateAfterburner();
        void decreaseThrust(float amount);
    };

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

    void takeOff();
    void land();
    void navigate(const std::string& destination); 
};

// Implementations for CoffeeMachine
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

// Implementations for Wings, LandingGear, Cabin, and Airplane would follow a similar pattern.


int main()
{
    std::cout << "good to go!" << std::endl;
}
