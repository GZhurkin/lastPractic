#include <iostream>
#include <stdexcept>

<<<<<<< HEAD

#include <dlfcn.h>
=======
#include <windows.h>
>>>>>>> no-linux

class LoadLib {
public:
    LoadLib(const char* libName);
    ~LoadLib();

    void* getFunction(const char* funcName);

private:
    void* hLib = nullptr;
};

LoadLib::LoadLib(const char* libName) {
<<<<<<< HEAD

        // Загрузка библиотеки для Linux
        hLib = dlopen(libName, RTLD_LAZY);
        if (!hLib) {
            std::cerr << "Cannot load library: " << libName << " - " << dlerror() << std::endl;
=======
        // Загрузка библиотеки для Windows
        hLib = LoadLibraryA(libName);
        if (!hLib) {
            std::cerr << "Cannot load library: " << libName << " - Error Code: " << GetLastError() << std::endl;
>>>>>>> no-linux
            throw std::runtime_error("Failed to load library");
        }
}

LoadLib::~LoadLib() {
    if (hLib) {
<<<<<<< HEAD

        // Выгрузка библиотеки для Linux
        dlclose(hLib);
=======
            // Выгрузка библиотеки для Windows
            FreeLibrary(static_cast<HMODULE>(hLib));
>>>>>>> no-linux

    }
}

void* LoadLib::getFunction(const char* funcName) {
    if (!hLib) {
        throw std::runtime_error("Library is not loaded");
    }

<<<<<<< HEAD

        // Получение адреса функции для Linux
        void* func = dlsym(hLib, funcName);
        if (!func) {
            std::cerr << "Cannot load function: " << funcName << " - " << dlerror() << std::endl;
            return nullptr;
        }
        return func;
}
=======
        // Получение адреса функции для Windows
        FARPROC func = GetProcAddress(static_cast<HMODULE>(hLib), funcName);
        if (!func) {
            std::cerr << "Cannot load function: " << funcName << " - Error Code: " << GetLastError() << std::endl;
            return nullptr;
        }
        return reinterpret_cast<void*>(func);
}
>>>>>>> no-linux
