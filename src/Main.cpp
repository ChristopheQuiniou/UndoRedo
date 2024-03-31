#include <iostream>
#include "command/Command.h"
#include "input handler/InputHandler.h"
#include "entity/Entity.h"
#include "entity/player/Player.h"

#define MAX_COMMANDS_SAVED 10

int main() {
	std::cout << "Undo redo project!" << std::endl;
	
	//Initialize the game
	Command* cmd = nullptr;
	Entity* player = new Player();
	
	Command** commands = new Command*[MAX_COMMANDS_SAVED];
	int currentCommandIndex = 0;
	InputHandler inputHandler = InputHandler(player);

	for(int i = 0; i < MAX_COMMANDS_SAVED; i++)
	{
		commands[i] = nullptr;
	}


	//Main loop
	while (true)
	{
		cmd = inputHandler.handleInput();

		//Check if we need to undo
		if (currentCommandIndex != 0 && ((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState('Z') & 0x8000)))
		{
			commands[currentCommandIndex - 1]->undo();
			currentCommandIndex--;
		}

		//If we have a new command, execute it and save it
		if (cmd != nullptr)
		{
			//If we have reached the maximum number of commands saved, delete the oldest one
			if (currentCommandIndex == MAX_COMMANDS_SAVED)
			{
				delete commands[0];
				for (int i = 0; i < MAX_COMMANDS_SAVED - 1; i++)
				{
					commands[i] = commands[i + 1];
				}
				currentCommandIndex--;
			}

			commands[currentCommandIndex] = cmd;
			currentCommandIndex++;

			cmd->execute();
		}

		//Render game
		player->render();

		//Sleep for a bit
		Sleep(300);
	}


	//Cleanup
	for (int i = 0; i < MAX_COMMANDS_SAVED; i++)
	{
		if (commands[i] != nullptr)
		{
			delete commands[i];
		}
	}
	delete player;

	return 0;
}
