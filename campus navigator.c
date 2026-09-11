#include <stdio.h>
#include <math.h>

int main() {
    // Location Coordinates (X, Y)
    int gateX = 0, gateY = 0;
    int libraryX = 4, libraryY = 3;
    int labX = 8, labY = 6;

    int startX, startY, endX, endY;
    int choice, transport, weather;
    double distance, speed, time;

    printf("===========================================\n");
    printf("        SMART CAMPUS GUIDE NAVIGATOR       \n");
    printf("===========================================\n");
    printf("Available Locations:\n");
    printf("1. Main Gate     (0, 0)\n");
    printf("2. Library       (4, 3)\n");
    printf("3. Computer Lab  (8, 6)\n");
    printf("-------------------------------------------\n");

    // Select Starting Point
    printf("Enter your CURRENT location (1-3): ");
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Error: Invalid selection. Program exiting.\n");
        return 1;
    }

    if (choice == 1) { startX = gateX; startY = gateY; }
    else if (choice == 2) { startX = libraryX; startY = libraryY; }
    else { startX = labX; startY = labY; }

    // Select Destination Point
    printf("Enter your DESTINATION (1-3): ");
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Error: Invalid selection. Program exiting.\n");
        return 1;
    }

    if (choice == 1) { endX = gateX; endY = gateY; }
    else if (choice == 2) { endX = libraryX; endY = libraryY; }
    else { endX = labX; endY = labY; }

    // Select Mode of Transport
    printf("\nChoose Mode of Transport:\n1. Walking (5 km/h)\n2. Biking (15 km/h)\nSelect (1-2): ");
    if (scanf("%d", &transport) != 1 || (transport != 1 && transport != 2)) {
        printf("Error: Invalid transport mode. Program exiting.\n");
        return 1;
    }

    // Select Weather Condition
    printf("Is it raining? (1 for Yes / 0 for No): ");
    if (scanf("%d", &weather) != 1 || (weather != 0 && weather != 1)) {
        printf("Error: Invalid weather option. Program exiting.\n");
        return 1;
    }

    // Calculate Distance using Distance Formula: sqrt((x2-x1)^2 + (y2-y1)^2)
    distance = sqrt(pow(endX - startX, 2) + pow(endY - startY, 2));

    // Determine Base Speed
    if (transport == 1) {
        speed = 5.0;  // Walking
    } else {
        speed = 15.0; // Biking
    }

    // Adjust Speed for Rain (30% reduction)
    if (weather == 1) {
        speed = speed * 0.7;
    }

    // Calculate Estimated Travel Time in Minutes
    time = (distance / speed) * 60;

    // Display Results
    printf("\n===========================================\n");
    printf("              NAVIGATION ROUTE             \n");
    printf("===========================================\n");
    printf("Total Distance : %.2f km\n", distance);
    printf("Estimated Time : %.1f minutes\n", time);
    printf("-------------------------------------------\n");
    printf("Smart Recommendation: ");

    if (weather == 1 && transport == 2) {
        printf("It is raining! Biking can be slippery. Please ride slow and wear a helmet.\n");
    } else if (weather == 1) {
        printf("It is raining! Consider taking covered walkways or carrying an umbrella.\n");
    } else if (distance == 0) {
        printf("You are already at your destination!\n");
    } else {
        printf("Weather conditions are ideal. Have a safe journey!\n");
    }
    printf("===========================================\n");

    return 0;
}
