#ifndef LOADLIB_H
#define LOADLIB_H

#include <iostream>

// Определяем условную компиляцию для разных ОС
<<<<<<< HEAD

#include <dlfcn.h> // Для Linux используем dlfcn.h
=======
#include <windows.h>
>>>>>>> no-linux

class LoadLib {
public:
    LoadLib(const char* libName);
    ~LoadLib();

    template<typename FuncType>
    FuncType loadFunction(const char* funcName);

private:

<<<<<<< HEAD
        void* hLib;      // Тип для Linux
=======
    HINSTANCE hLib;  // Тип для Windows
>>>>>>> no-linux

};

template<typename FuncType>
FuncType LoadLib::loadFunction(const char* funcName) {
    if (!hLib) return nullptr;

<<<<<<< HEAD

        // Загрузка функции для Linux
        FuncType func = reinterpret_cast<FuncType>(dlsym(hLib, funcName));
=======
        // Загрузка функции для Windows
        FuncType func = reinterpret_cast<FuncType>(GetProcAddress(hLib, funcName));
>>>>>>> no-linux


    if (!func) {
        std::cerr << "Cannot load function: " << funcName << std::endl;
    }
    return func;
}

#endif // LOADLIB_H
