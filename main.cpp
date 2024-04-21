/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()




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
    int numberOfCoffeeTypes;
    float waterTankCapacityLiters;
    int coffeeBeansGrams;
    float currentTemperatureCelsius;
    int daysBeforeServicing;

    CoffeeMachine() 
    : numberOfCoffeeTypes(10), waterTankCapacityLiters(1.5f), 
      coffeeBeansGrams(500), currentTemperatureCelsius(90.0f), 
      daysBeforeServicing(30)
    {
        std::cout << "Constructing CoffeeMachine\n";
    }

    void brewCoffee(int coffeeTypeIndex)
    {
        std::cout << "Brewing coffee type " << coffeeTypeIndex << ", available types: " << numberOfCoffeeTypes << "\n";
    }

    void refillWater(float waterAmountLiters)
    {
        waterTankCapacityLiters += waterAmountLiters;
        std::cout << "Refilled water tank. Current capacity: " << waterTankCapacityLiters << " liters\n";
    }

    void selectCoffeeType(int coffeeTypeIndex)
    {
        std::cout << "Selected coffee type " << coffeeTypeIndex << "\n";
    }

    void performCleaningCycle()
    {
        while (currentTemperatureCelsius > 30.0f)
        {
            std::cout << "Cooling down for cleaning. Current temperature: " << currentTemperatureCelsius << "°C\n";
            currentTemperatureCelsius -= 5.0f; // Cooling down
            if (currentTemperatureCelsius <= 30.0f)
            {
                std::cout << "Temperature cool enough for cleaning.\n";
                break;
            }
        }
    }
};

struct SmartThermostat
{
    float currentRoomTemperature {20.0f};
    float desiredTemperature;
    float energyConsumptionKWh {3.5f};
    std::string mode {"Auto"};
    bool isWifiConnected;

    SmartThermostat(float initDesiredTemperature = 22.0f, bool initWifiConnected = true)
    : desiredTemperature(initDesiredTemperature), isWifiConnected(initWifiConnected)
    {
        std::cout << "Constructing SmartThermostat\n";
    }

    void adjustTemperature(float newTemperature) 
    {
        desiredTemperature = newTemperature;
        std::cout << "Adjusted desired temperature to " << newTemperature << "\n";
    }

    void switchMode(const std::string& newMode)
    {
        mode = newMode;
        std::cout << "Switched mode to " << newMode << "\n";
    }

    float sendEnergyUsageReport()
    {
        std::cout << "Sending energy usage report. Total consumption: " << energyConsumptionKWh << " kWh\n";
        return energyConsumptionKWh;
    }

    void simulateDayPassing()
    {
        for (int day = 1; day <= 7; ++day)
        {
            currentRoomTemperature += 0.5f; // simulate temperature rise
            std::cout << "Day " << day << ": Room temperature is now " << currentRoomTemperature << "°C\n";
            if (currentRoomTemperature >= desiredTemperature)
            {
                std::cout << "Desired temperature reached or exceeded.\n";
                break;
            }
        }
    }
};

struct LibraryAccount
{
    int booksCheckedOut {0};
    int totalBooksAllowed;
    double fineAmountDue {0.0};
    std::string accountStatus {"active"};
    int daysUntilReturnDue;

    LibraryAccount(int allowed = 10, int daysUntilDue = 14)
    : totalBooksAllowed(allowed), daysUntilReturnDue(daysUntilDue)
    {
        std::cout << "Constructing LibraryAccount\n";
    }

    void checkOutBooks(int numberOfBooks)
    {
        booksCheckedOut += numberOfBooks;
        std::cout << "Checked out " << numberOfBooks << " books. Total checked out: " << booksCheckedOut << "\n";
    }

    void payFines(double amount)
    {
        fineAmountDue -= amount;
        std::cout << "Paid fine. Remaining fine amount: $" << fineAmountDue << "\n";
    }

    void renewBooks()
    {
        std::cout << "Books renewed. No fines due\n";
    }

    void simulateBookCheckouts()
    {
        int days = 0;
        while (booksCheckedOut < totalBooksAllowed)
        {
            ++booksCheckedOut;
            ++days;
            std::cout << "Checked out one more book, total: " << booksCheckedOut << "\n";
            if (booksCheckedOut == totalBooksAllowed)
            {
                std::cout << "Reached max books allowed after " << days << " days.\n";
                break;
            }
        }
    }
};

struct ExerciseBike
{
    float currentSpeedKmPerHour {0.0f};
    float totalDistanceKm {0.0f};
    int resistanceLevel {1};
    int userHeartRate {60};
    double caloriesBurned {0.0};

    ExerciseBike()
    {
        std::cout << "Constructing ExerciseBike\n";
    }

    void adjustResistance(int newResistanceLevel)
    {
        resistanceLevel = newResistanceLevel;
        std::cout << "Adjusted resistance to level " << newResistanceLevel << "\n";
    }

    void trackDistanceAndSpeed()
    {
        std::cout << "Tracking distance and speed. Current speed: " << currentSpeedKmPerHour << " km/h\n";
    }

    int monitorHeartRate()
    {
        std::cout << "Monitoring heart rate: " << userHeartRate << " BPM\n";
        return userHeartRate;
    }

    void simulateExerciseSession(int minutes)
    {
        for (int minute = 0; minute < minutes; ++minute)
        {
            currentSpeedKmPerHour += 1.0f; // increase speed
            totalDistanceKm += currentSpeedKmPerHour / 60; // convert speed to distance per minute
            std::cout << "Minute " << minute + 1 << ": Speed " << currentSpeedKmPerHour << " km/h, Total Distance: " << totalDistanceKm << " km\n";
        }
    }
};

struct Cockpit
{
    int numberOfControlPanels {4};
    std::string autopilotSystemType {"Advanced"};
    bool visibilityThroughWindshield {true};
    int numberOfSeats {2};
    int amountOfEmergencyEquipment {5};

    struct NavigationSystem
    {
        float gpsLatitude {0.0f};
        float gpsLongitude {0.0f};
        bool hasAutoPilotCapability {true};
        std::string currentFlightPlan {"N/A"};
        float altitude {10000.0f};

        NavigationSystem()
        {
            std::cout << "Constructing NavigationSystem\n";
        }

        void updateFlightPlan(const std::string& newFlightPlan)
        {
            currentFlightPlan = newFlightPlan;
            std::cout << "Updated flight plan to " << newFlightPlan << "\n";
        }

        void changeAltitude(float newAltitude)
        {
            altitude = newAltitude;
            std::cout << "Changed altitude to " << newAltitude << "\n";
        }

        void activateAutoPilot()
        {
            hasAutoPilotCapability = true;
            std::cout << "Autopilot activated\n";
        }

        void autoCorrectCourse(float targetLatitude, float targetLongitude)
        {
            std::cout << "Starting auto-correction for course...\n";
            // Define thresholds for corrections
            const float threshold = 0.1f;
            while (std::abs(gpsLatitude - targetLatitude) > threshold || std::abs(gpsLongitude - targetLongitude) > threshold)
            {
                // Correct latitude
                if (gpsLatitude < targetLatitude)
                {
                    gpsLatitude += 0.05f;
                }
                else if (gpsLatitude > targetLatitude)
                {
                    gpsLatitude -= 0.05f;
                }

                // Correct longitude
                if (gpsLongitude < targetLongitude)
                {
                    gpsLongitude += 0.05f;
                }
                else if (gpsLongitude > targetLongitude)
                {
                    gpsLongitude -= 0.05f;
                }

                // Report current coordinates
                std::cout << "Correcting to Latitude: " << gpsLatitude << ", Longitude: " << gpsLongitude << "\n";

                // Check if within thresholds to break the loop early
                if (std::abs(gpsLatitude - targetLatitude) <= threshold && std::abs(gpsLongitude - targetLongitude) <= threshold) {
                    std::cout << "Course corrected to within acceptable thresholds.\n";
                    break;
                }
            }
        }

    };

    Cockpit()
    {
        std::cout << "Constructing Cockpit\n";
    }

    void navigateAirplane()
    {
        std::cout << "Navigating airplane with autopilot system type: " << autopilotSystemType << "\n";
    }

    void communicateWithATC(const std::string& message)
    {
        std::cout << "Communicating with ATC: " << message << "\n";
    }

    void monitorSystems()
    {
        std::cout << "Monitoring airplane systems\n";
    }

    void importNavigationSettings(NavigationSystem backupNavigationSystem)
    {
        navigationSystem = backupNavigationSystem;
        std::cout << "Imported navigation settings from backup\n";
    }

    void performDiagnosticOnSystem(NavigationSystem systemToCheck)
    {
        std::cout << "Performing diagnostic check on navigation system.\n";
        const float epsilon = 0.001f;
        if (std::abs(navigationSystem.altitude - systemToCheck.altitude) > epsilon)
        {
            std::cout << "Altitude discrepancy detected. Current: " << navigationSystem.altitude
                      << ", Checked: " << systemToCheck.altitude << "\n";
        }
        if (navigationSystem.hasAutoPilotCapability != systemToCheck.hasAutoPilotCapability)
        {
            std::cout << "Autopilot capability mismatch. Current: "
                      << (navigationSystem.hasAutoPilotCapability ? "Enabled" : "Disabled")
                      << ", Checked: " << (systemToCheck.hasAutoPilotCapability ? "Enabled" : "Disabled") << "\n";
        }
    }

    void simulateFlight(int hours)
    {
        for (int hour = 1; hour <= hours; ++hour)
        {
            navigationSystem.changeAltitude(navigationSystem.altitude + 500.0f);
            std::cout << "Hour " << hour << ": Altitude adjusted to " << navigationSystem.altitude << " feet.\n";
            if (navigationSystem.altitude >= 15000.0f)
            {
                std::cout << "Cruising altitude reached.\n";
                break;
            }
        }
    }


    NavigationSystem navigationSystem;
};

struct Engine
{
    float thrustPowerKiloNewtons {100.0f};
    float fuelConsumptionPerHour;
    std::string engineType {"Jet"};
    float operatingTemperatureRange {150.0f};
    int currentRPM;

    Engine(float fuelRate = 50.0f, int rpm = 2000)
    : fuelConsumptionPerHour(fuelRate), currentRPM(rpm)
    {
        std::cout << "Constructing Engine\n";
    }

    void propelAirplane()
    {
        std::cout << "Propelling airplane with engine type: " << engineType << "\n";
    }

    void adjustThrust(float newThrustLevel)
    {
        thrustPowerKiloNewtons = newThrustLevel;
        std::cout << "Adjusted thrust to " << newThrustLevel << " kilonewtons\n";
    }

    void startEngine()
    {
        std::cout << "Engine started\n";
    }

    void simulateEngineWarmUp()
    {
        while (operatingTemperatureRange < 200.0f)
        {
            operatingTemperatureRange += 5.0f; // Warm up the engine
            std::cout << "Warming up. Current operating temperature: " << operatingTemperatureRange << "°C\n";
            if (operatingTemperatureRange >= 200.0f)
            {
                std::cout << "Optimal operating temperature reached.\n";
                break;
            }
        }
    }
};


struct Wings
{
    float wingspanMeters {20.0f};
    float fuelCapacityLiters {2000.0f};
    int numberOfFlaps {4};
    std::string materialType {"Composite"};
    double elasticityPercent {5.0};

    Wings()
    {
        std::cout << "Constructing Wings\n";
    }

    void provideLift()
    {
        std::cout << "Wings providing lift with wingspan of " << wingspanMeters << " meters\n";
    }

    void controlTilt(float angle)
    {
        std::cout << "Tilting wings to " << angle << " degrees for better maneuverability\n";
    }

    void adjustForManeuvering()
    {
        std::cout << "Adjusting wing flaps and elasticity by " << elasticityPercent << "% for improved stability\n";
    }

    void adjustFlapsForTakeoff()
    {
        for (int position = 1; position <= numberOfFlaps; ++position)
        {
            std::cout << "Flap " << position << " adjusted for takeoff.\n";
            if (position == numberOfFlaps) {
                std::cout << "All flaps are set for takeoff.\n";
                break;
            }
        }
    }
};

struct LandingGear
{
    int numberOfWheels {6};
    float maximumWeightCapacity {10000.0f};
    bool isRetractable {true};
    int brakeEffectiveness {8};
    float shockAbsorptionLevel {7.5f};

    LandingGear()
    {
        std::cout << "Constructing LandingGear\n";
    }

    void deploy()
    {
        std::cout << "Deploying " << numberOfWheels << " wheels of landing gear\n";
    }

    void retract()
    {
        std::cout << "Retracting landing gear. Gear is " << (isRetractable ? "retractable" : "not retractable") << "\n";
    }

    void activateBrakes()
    {
        std::cout << "Activating brakes with effectiveness level of " << brakeEffectiveness << " out of 10\n";
    }

    void testLandingGearCycles()
    {
        int cycles = 3; // Number of test cycles
        for (int cycle = 1; cycle <= cycles; ++cycle)
        {
            deploy();
            retract();
            std::cout << "Cycle " << cycle << " completed.\n";
        }
    }
};

struct Cabin
{
    int numberOfPassengerSeats {150};
    float availableLegroomInches {32.0f};
    int numberOfRestrooms {2};
    std::string onboardEntertainmentOptions {"Movies, Music"};
    int airFiltrationSystemQuality {9};

    Cabin()
    {
        std::cout << "Constructing Cabin\n";
    }

    void adjustTemperature(float newTemperature)
    {
        std::cout << "Adjusting cabin temperature from " << availableLegroomInches << " inches legroom space to " << newTemperature << "°C\n";
    }

    void controlPressure()
    {
        std::cout << "Controlling cabin pressure for " << numberOfPassengerSeats << " seats\n";
    }

    void monitorAirQuality()
    {
        std::cout << "Monitoring air quality. Filtration system quality: " << airFiltrationSystemQuality << "/10\n";
    }

    void simulatePassengerBoarding()
    {
        int passengersBoarded = 0;
        while (passengersBoarded < numberOfPassengerSeats)
        {
            ++passengersBoarded;
            std::cout << "Passenger " << passengersBoarded << " boarded.\n";
            if (passengersBoarded == numberOfPassengerSeats)
            {
                std::cout << "All passengers are boarded.\n";
                break;
            }
        }
    }
};

struct Airplane
{
    Cockpit cockpit;
    Engine engine;
    Wings wings;
    LandingGear landingGear;
    Cabin cabin;

    Airplane()
    {
        std::cout << "Constructing Airplane\n";
    }

    void takeOff()
    {
        std::cout << "Airplane taking off. Cockpit and engines are ready\n";
        cockpit.navigateAirplane();
        engine.propelAirplane();
    }

    void land()
    {
        std::cout << "Airplane landing. Deploying landing gear\n";
        landingGear.deploy();
    }

    void navigate(const std::string& destination)
    {
        std::cout << "Airplane navigating to " << destination << ". Autopilot: " << cockpit.autopilotSystemType << "\n";
        cockpit.navigateAirplane();
    }

    void simulateFlightPreparation()
    {
        std::cout << "Starting flight preparation...\n";
        int tasksCompleted = 0;
        while (tasksCompleted < 5)
        { // Assuming 5 tasks for preparation
            ++tasksCompleted;
            std::cout << "Task " << tasksCompleted << " completed.\n";
            if (tasksCompleted == 5)
            {
                std::cout << "Flight preparation is complete. Ready for takeoff.\n";
                break;
            }
        }
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
    coffeeMachine1.performCleaningCycle();

    thermostat1.adjustTemperature(25.0f);
    thermostat1.switchMode("Heat");
    thermostat2.sendEnergyUsageReport();
    thermostat2.simulateDayPassing();

    libraryAccount1.checkOutBooks(5);
    libraryAccount1.payFines(20.0);
    libraryAccount2.renewBooks();
    libraryAccount2.simulateBookCheckouts();

    bike1.adjustResistance(3);
    bike1.trackDistanceAndSpeed();
    bike2.monitorHeartRate();
    bike2.simulateExerciseSession(30);

    cockpit1.navigateAirplane();
    cockpit1.communicateWithATC("Ascending to 15000 feet.");
    cockpit2.monitorSystems();
    cockpit2.simulateFlight(5);

    engine1.propelAirplane();
    engine1.adjustThrust(110.0f);
    engine2.startEngine();
    engine2.simulateEngineWarmUp();

    wings1.provideLift();
    wings1.controlTilt(15.0f);
    wings2.adjustForManeuvering();
    wings2.adjustFlapsForTakeoff();

    gear1.deploy();
    gear1.retract();
    gear2.activateBrakes();
    gear2.testLandingGearCycles();

    cabin1.adjustTemperature(22.0f);
    cabin1.controlPressure();
    cabin2.monitorAirQuality();
    cabin2.simulatePassengerBoarding();

    airplane1.takeOff();
    airplane1.land();
    airplane2.navigate("New York");
    airplane2.simulateFlightPreparation();
    airplane2.cockpit.navigationSystem.autoCorrectCourse(45.0f, 12.0f);

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
