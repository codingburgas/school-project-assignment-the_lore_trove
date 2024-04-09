#include <iostream>
#include "../../Library/GameManager.h"

int main() {
	GameManager* manager = GameManager::GetInstance();
	manager->Initizalize();
}