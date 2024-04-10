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
    // number of coffee types available
    int numberOfCoffeeTypes = 10;
    // water tank capacity in liters
    float waterTankCapacityLiters = 1.5f;
    // amount of coffee beans in grams
    int coffeeBeansGrams = 500;
    // current temperature in degrees Celsius
    float currentTemperatureCelsius = 90.0f;
    // days before servicing
    int daysBeforeServicing = 30;

    // 3 things it can do:
    // brew a cup of coffee
    void brewCoffee(int coffeeTypeIndex);

    // refill water
    void refillWater(float waterAmountLiters); // waterAmountLiters: Amount of water to refill.

    // select coffee type
    void selectCoffeeType(int coffeeTypeIndex);
};

struct SmartThermostat
{
    // current room temperature
    float currentRoomTemperature = 20.0f;
    // desired temperature setting
    float desiredTemperature = 22.0f;
    // energy consumption in kilowatt-hours
    float energyConsumptionKWh = 3.5f;
    // mode 'Heat', 'Cool, 'Auto'
    std::string mode = "Auto";
    // is wifi connected
    bool isWifiConnected = true;

    // 3 things it can do:
    // adjust room temperature
    void adjustTemperature(float newTemperature); // newTemperature: The new desired temperature.

    // switch between modes
    void switchMode(const std::string& newMode); // newMode: New mode to switch to.

    // send report of energy usage
    float sendEnergyUsageReport(); // Returns the total energy used.
};

struct LibraryAccount
{
    // number of books currently checked out
    int booksCheckedOut = 3;
    // total number of books allowed to borrow
    int totalBooksAllowed = 10;
    // fine amount due in dollars
    double fineAmountDue = 0.0;
    // account status 'active', 'suspended'
    std::string accountStatus = "active";
    // number of days until book return due
    int daysUntilReturnDue = 14;

    // 3 things it can do:
    // check out books
    void checkOutBooks(int numberOfBooks); // numberOfBooks: Number of books to check out.

    // pay fines
    void payFines(double amount); // amount: Amount of fine to pay.

    // renew borrowed books
    void renewBooks();
};

struct ExerciseBike
{
    // current speed in kilometers per hour
    float currentSpeedKmPerHour = 0.0f;
    // total distance covered in kilometers
    float totalDistanceKm = 0.0f;
    // resistance level
    int resistanceLevel = 1;
    // heart rate of the user
    int userHeartRate = 60;
    // number of calories burned
    double caloriesBurned = 0.0;

    // 3 things it can do:
    // increase or decrease resistance
    void adjustResistance(int newResistanceLevel); // newResistanceLevel: The new resistance level.

    // track distance and speed
    void trackDistanceAndSpeed(); // Updates the total distance and current speed.

    // monitor user's heart rate
    int monitorHeartRate(); // Returns the current heart rate of the user.
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

    // Function to import navigation settings from another source (e.g., a backup system)
    void importNavigationSettings(NavigationSystem backupNavigationSystem);

    // Function to perform a diagnostic check on the navigation system
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

    // Function to adjust thrust settings to match another engine
    void adjustToMatchOtherEngine(ThrustControl otherEngineThrustControl);

    // Function to initiate an emergency shutdown using thrust control parameters
    void initiateEmergencyShutdown(ThrustControl emergencyControlSettings);

    ThrustControl thrustControl;
};

struct Wings
{
    // wingspan in meters
    float wingspanMeters = 20.0f;
    // fuel capacity in liters
    float fuelCapacityLiters = 2000.0f;
    // number of flaps
    int numberOfFlaps = 4;
    // material type
    std::string materialType = "Composite";
    // elasticity in percent
    double elasticityPercent = 5.0;

    // 3 things it can do:
    // provide lift
    void provideLift(); // Generates lift to keep the airplane airborne.

    // control wing tilt
    void controlTilt(float angle); // angle: The angle to tilt the wings.

    // adjust for maneuvering and stability
    void adjustForManeuvering(); // Adjusts wing flaps for better maneuvering and stability.
};

struct LandingGear
{
    // number of wheels
    int numberOfWheels = 6;
    // maximum weight capacity
    float maximumWeightCapacity = 10000.0f;
    // retractable or fixed
    bool isRetractable = true;
    // brake effectiveness
    int brakeEffectiveness = 8; // Scale of 1-10
    // shock absorption level
    float shockAbsorptionLevel = 7.5f;

    // 3 things it can do:
    // deploy
    void deploy(); // Deploys the landing gear for landing.

    // retract
    void retract(); // Retracts the landing gear after takeoff.

    // brake
    void activateBrakes(); // Activates the brakes to slow down or stop the airplane.
};

struct Cabin
{
    // number of passenger seats
    int numberOfPassengerSeats = 150;
    // available legroom in inches
    float availableLegroomInches = 32.0f;
    // number of restrooms
    int numberOfRestrooms = 2;
    // onboard entertainment options
    std::string onboardEntertainmentOptions = "Movies, Music";
    // air filtration system quality
    int airFiltrationSystemQuality = 9; // Scale of 1-10

    // 3 things it can do:
    // adjust temperature
    void adjustTemperature(float newTemperature); // newTemperature: The new cabin temperature.

    // control cabin pressure
    void controlPressure(); // Maintains optimal cabin pressure.

    // monitor air quality
    void monitorAirQuality(); // Checks and regulates the quality of the air in the cabin.
};

struct Airplane
{
    // cockpit
    Cockpit cockpit;
    // engines
    Engine engine;
    // wings
    Wings wings;
    // landing gear
    LandingGear landingGear;
    // cabin
    Cabin cabin;

    // 3 things it can do:
    // take off
    void takeOff(); // Initiates the airplane's takeoff sequence.

    // land
    void land(); // Initiates the airplane's landing sequence.

    // navigate
    void navigate(const std::string& destination); // destination: The target destination to navigate to.
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
