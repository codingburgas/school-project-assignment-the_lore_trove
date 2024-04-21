#include <iostream>
#include "../Library/Manager.h"

int main() {

    Manager* manager = Manager::GetInstance();

    manager->Initizalize();

    while (!manager->ShouldWindowClose())
    {
        manager->Update();
    }

    CloseWindow();
}