#include "../include/Utils.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <limits>

void limparTela() {
    std::cout << "\033[2J\033[H";
}

void digitarTexto(const std::string& texto, int delayMs) {
    for(char c : texto) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}

void esperarEnter() {
    std::cout << "\nPressione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
