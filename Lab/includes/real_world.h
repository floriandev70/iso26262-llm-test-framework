//
// Created by Florian Carstens on 16.04.24.
//

#ifndef REAL_WORLD_H
#define REAL_WORLD_H
//Nasa check abort
bool check_abort(bool, bool, bool);
//Automotive MCU State Machine
int autom_MCU_state_machine(int);
// State definitions for State Machine
#define OFF         0
#define RUN         2
#define STARTUP     3
#define GO_SLEEP    4
#define SLEEP       5
#define WAKEUP      6
#define SHUTDOWN    7
#define CURRENT_STATE 8
// Global variable to maintain the current state of the MCU state machine
static int g_current_state = OFF;

#endif //REAL_WORLD_H
