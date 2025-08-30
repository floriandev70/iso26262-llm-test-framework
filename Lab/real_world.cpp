#include "includes/real_world.h"

#include <cstdint>

/***********************************************************************************************************************
 * Check abort, taken from the MC/DC program example by Lorraine E. Prokop, PhD, NASA technical Fellow for Software.
 * (Prokop, Lorraine E., 2023)
 * Function: bool check_abort(bool off_course, bool abort_commanded, bool valid_abort_command);
 * Requirements: This function checks, whether the abort criteria is met and returns the result.
 **********************************************************************************************************************/
bool check_abort(bool off_course, bool abort_commanded, bool valid_abort_command) {
    bool result = false;
    if (off_course || (abort_commanded && valid_abort_command)) {
        result = true; // initiate abort sequence
    }
    else {
        result = false; // don't abort, keep flying
    }
    return result;
}

/* C code for a simple status machine used in automotive microcontrollers.

Requirements:
- Function Name: int autom_MCU_state_machine(int requested_state)
- Implements a status machine for a microcontroller (MCU).
- States: {Current_State, On, startup, Run, go_sleep, Sleep, wakeup, shutdown, Off}
- External state transitions:
  {(Off,Run,startup), (Run,Sleep,go_sleep), (Sleep,Run,wakeup), (Run,Off,shutdown)}
- Internal state transitions managed by the state machine:
  {(startup,Run), (shutdown,Off), (wakeup,Run), (go_sleep,Sleep)}
- Each state represented by a positive integer value.
- Return -1 if a state transition is not possible.
- Returning 'Current_State' outputs the integer number of the current state.
*/

int autom_MCU_state_machine(int requested_state) {
    // Returning the current state when requested
    if (requested_state == CURRENT_STATE) {
        return g_current_state;
    }

    int new_state = g_current_state;

    // Processing external state transitions
    switch (g_current_state) {
        case OFF:
            if (requested_state == RUN){
                new_state = STARTUP;
            }
            else {
                return -1;
            }
            break;

        case RUN:
            if (requested_state == SLEEP) {
                new_state = GO_SLEEP;
            }
            else if (requested_state == OFF) {
                new_state = SHUTDOWN;
            }
            else {
                return -1;
            }
            break;

        case SLEEP:
            if (requested_state == RUN) {
                new_state = WAKEUP;
            }
            else {
                return -1;
            }
            break;
    }

    // Processing internal state transitions
    switch (new_state) {
        case STARTUP:
            g_current_state = RUN;
            break;
        case SHUTDOWN:
            g_current_state = OFF;
            break;
        case WAKEUP:
            g_current_state = RUN;
            break;
        case GO_SLEEP:
            g_current_state = SLEEP;
            break;
    }

    return g_current_state;
}

