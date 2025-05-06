#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool hasPriority(char vehicle) {
    return vehicle == 'P' || vehicle == 'A' || vehicle == 'V';
}

const char* getVehicleType(char vehicle) {
    switch (vehicle) {
        case 'C': return "Car";
        case 'B': return "Bus";
        case 'P': return "Police";
        case 'A': return "Ambulance";
        case 'V': return "VIP";
        default: return "Unknown";
    }
}

void controlGate(char vehicle, int count) {
    printf("\nVehicle #%d: %s\n", count, getVehicleType(vehicle));
    if (hasPriority(vehicle)) {
        printf("🚦 Priority: Opening gate...\n");
        sleep(2);
        printf("✅ Gate open for %s!\n", getVehicleType(vehicle));
    } else {
        printf("🚦 Standard: Waiting...\n");
        sleep(2);
        printf("🔴 Gate closed for %s.\n", getVehicleType(vehicle));
    }
}

int main() {
    char vehicle;
    int count = 0;

    printf("🌐 Smart Traffic System On\n");
    printf("\n=== Directions ===\n");
    printf("Enter a vehicle type to process it through the gate:\n");
    printf("  C: Car (Standard, gate stays closed)\n");
    printf("  B: Bus (Standard, gate stays closed)\n");
    printf("  P: Police (Priority, gate opens)\n");
    printf("  A: Ambulance (Priority, gate opens)\n");
    printf("  V: VIP (Priority, gate opens)\n");
    printf("  Q: Quit the system\n");
    printf("Invalid inputs will be rejected.\n");
    printf("=================\n");

    while (1) {
        printf("\nType (C=Car, B=Bus, P=Police, A=Ambulance, V=VIP, Q=Quit): ");
        scanf(" %c", &vehicle);
        count++;

        if (vehicle == 'Q') {
            printf("🛑 System Off. Processed: %d\n", count - 1);
            break;
        }

        if (vehicle != 'C' && vehicle != 'B' && vehicle != 'P' && vehicle != 'A' && vehicle != 'V') {
            printf("❌ Invalid type!\n");
            count--;
            continue;
        }

        controlGate(vehicle, count);
    }

    return 0;
}
