#include "pch.h"

#include "CtlTypes.h"
#include "User-Bridge.h"
#include "Kernel-Tests.h"

void RunTests() {
    BeeperTest tBeeper(L"Beeper");
    IoplTest tIopl(L"IOPL");
    VirtualMemoryTest tVirtualMemory(L"VirtualMemory");
    MdlTest tMdl(L"Mdl");
    PhysicalMemoryTest tPhysicalMemory(L"PhysicalMemory");
    ProcessesTest tProcesses(L"Processes");
}

int main() {
    KbLoader::KbUnload();
    if (KbLoader::KbLoad(L"C:\\Temp\\Kernel-Bridge\\Kernel-Bridge.sys")) {
        RunTests();
        KbLoader::KbUnload();
    } else {
        std::wcout << L"Unable to load driver!" << std::endl;
    }

    std::wcout << L"Press any key to exit..." << std::endl;
    std::cin.get();
}