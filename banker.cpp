#include <iostream>

using namespace std;

int main() {
    int NUM_PROCESSES = 5;
    int NUM_RESOURCES = 3;
    
    // Number of resources of each type are allocated to each process
    int allocated[NUM_PROCESSES][NUM_RESOURCES] = {
        {0,1,0}, 
        {2,0,0},
        {3,0,2}, 
        {2,1,1},
        {0,0,2}
    };
    
    // How many resource each process may request at most
    int max[NUM_PROCESSES][NUM_RESOURCES] = {
        {7,5,3}, 
        {3,2,2},
        {9,0,2}, 
        {2,2,2},
        {4,3,3}
    };
    
    // Number of available resources of each type
    int available[NUM_RESOURCES] = {3,3,2};
    
    // How many resources each process still needs
    int need[NUM_PROCESSES][NUM_RESOURCES] = {0};
    
    // Currently working on
    bool finish[NUM_PROCESSES] = {false};
    
    // Creates the array for the safe sequence and its location pointer
    int safe_sequence[NUM_PROCESSES];
    int ss_loc = 0;
    
    // Sets need as a copy of max - allocated
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        for (int j = 0; j < NUM_RESOURCES; ++j) {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
    
    //// Safety Algorithm
    for (int k = 0; k < NUM_PROCESSES; ++k) {
        bool found = false;
        for (int i = 0; i < NUM_PROCESSES; ++i) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < NUM_RESOURCES; ++j) {
                    if (available[j] < need[i][j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    // Allocate resources to process i
                    for (int j = 0; j < NUM_RESOURCES; ++j) {
                        available[j] += allocated[i][j];
                    }
                    // Process is finnished 
                    finish[i] = true;
                    // Update safe seq
                    safe_sequence[ss_loc] = i;
                    ss_loc += 1;
                    found = true;
                }
            }
        }
        // If no process is found in this iteration, break to avoid infinite loop
        if (!found) break;
    }
    
    // Check if all processes finished
    bool safe = true;
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        if (!finish[i]) {
            safe = false;
            break;
        }
    }
    
    // Print safe sequence or "Not safe"
    if (safe) {
        cout << "Safe sequence: ";
        for (int i = 0; i < NUM_PROCESSES; ++i) {
            cout << "p" << safe_sequence[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "Not safe";
    }
    
    return 0;
}
