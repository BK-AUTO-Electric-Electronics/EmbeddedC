#include <stdio.h>
#include "module_manager.h"
#include "function_handler.h"
#include "error_handler.h"
#include "bitmask_utils.h"

int main() {
    ModuleSystem myCar;
    init_system(&myCar);

    // BƯỚC 1: Add Module
    add_module(&myCar, 1, "Engine ECU", engine_control_logic);
    add_module(&myCar, 2, "ABS System", abs_control_logic);

    // Thiết lập Safe State với setjmp
    if (setjmp(safe_state_buffer) == 0) {
        printf("\n--- TIEN TRINH DIEU KHIEN --- \n");

        for (int i = 0; i < myCar.size; i++) {
            // BƯỚC 2: Get Module
            Module *current = &myCar.modules[i];
            printf("\nProcessing: %s\n", current->name);

            // BƯỚC 3: Turn ON
            current->control(current, 1);

            // BƯỚC 4: Check ERROR
            if (is_status_set(current->status, STATUS_ERROR)) {
                // BƯỚC 5: Warning
                printf("[WARNING] Critical Error at %s!\n", current->name);
                trigger_emergency_stop(current->name); // Gọi longjmp
            } else {
                printf("[OK] %s is running.\n", current->name);
            }
        }
    } else {
        printf("\n[SYSTEM] Safe Mode Activated due to error.\n");
    }

    // BƯỚC 6: Module List (Luôn chạy trước khi END)
    printf("\n--- FINAL MODULE LIST ---\n");
    for (int i = 0; i < myCar.size; i++) {
        printf("ID: %d | Name: %-15s | Status: 0x%02X\n", 
               myCar.modules[i].id, myCar.modules[i].name, myCar.modules[i].status);
    }

    cleanup_system(&myCar);
    printf("\n--- END PROGRAM ---\n");
    return 0;
}