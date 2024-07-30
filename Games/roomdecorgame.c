#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define constants for maximum string lengths
#define MAX_ROOM_DESCRIPTION_LENGTH 1000
#define MAX_COMMAND_LENGTH 100

// Define a structure for rooms
typedef struct Room {
    char description[MAX_ROOM_DESCRIPTION_LENGTH];
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

// Function prototypes
Room* createRoom(const char* description);
void describeRoom(Room* room);
void freeRoom(Room* room);

int main() {
    // Create rooms
    Room* startRoom = createRoom("You are in a dark room. You can see a faint light to the north.");
    Room* northRoom = createRoom("You are in a brightly lit room. There is a door to the south.");
    Room* southRoom = createRoom("You are in a dimly lit room. There is a door to the north.");

    // Connect rooms
    startRoom->north = northRoom;
    northRoom->south = startRoom;
    northRoom->north = southRoom;
    southRoom->north = northRoom;

    // Start the game in the initial room
    Room* currentRoom = startRoom;

    // Main game loop
    char command[MAX_COMMAND_LENGTH];
    while (true) {
        // Describe current room
        describeRoom(currentRoom);

        // Prompt for user input
        printf("Enter a command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove trailing newline

        // Process command
        if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strcmp(command, "north") == 0 && currentRoom->north != NULL) {
            currentRoom = currentRoom->north;
        } else if (strcmp(command, "south") == 0 && currentRoom->south != NULL) {
            currentRoom = currentRoom->south;
        } else if (strcmp(command, "east") == 0 && currentRoom->east != NULL) {
            currentRoom = currentRoom->east;
        } else if (strcmp(command, "west") == 0 && currentRoom->west != NULL) {
            currentRoom = currentRoom->west;
        } else {
            printf("Invalid command. Try 'north', 'south', 'east', 'west', or 'quit'.\n");
        }
    }

    // Free memory
    freeRoom(startRoom);
    freeRoom(northRoom);
    freeRoom(southRoom);

    return 0;
}

// Function to create a room
Room* createRoom(const char* description) {
    Room* room = (Room*)malloc(sizeof(Room));
    if (room != NULL) {
        strncpy(room->description, description, MAX_ROOM_DESCRIPTION_LENGTH - 1);
        room->description[MAX_ROOM_DESCRIPTION_LENGTH - 1] = '\0';
        room->north = NULL;
        room->south = NULL;
        room->east = NULL;
        room->west = NULL;
    }
    return room;
}

// Function to describe a room
void describeRoom(Room* room) {
    printf("------------------------------\n");
    printf("%s\n", room->description);
    printf("------------------------------\n");
}

// Function to free memory allocated for a room
void freeRoom(Room* room) {
    free(room);
}
