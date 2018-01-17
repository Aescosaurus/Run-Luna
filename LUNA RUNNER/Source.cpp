#include <iostream>
#include <fstream>
#include <string>

int main()
{
	int i = 0;
	while( true && !false )
	{
		std::fstream in( "LunaProjects/LunaProj" +
			std::to_string( i ) + "/src/Main.luna" );
		if( !in && i > 0 )
		{
			--i;
			std::string curFileName = "LunaProjects/LunaProj" +
				std::to_string( i ) + "/src/Main.luna";
			std::fstream runThis( curFileName );
			if( !runThis )
			{
				break;
			}
			std::cout << "Luna Project LunaProj" +
				std::to_string( i ) + " found!\n";

			std::ofstream runLuna( "RUN_LUNA.bat" );
			runLuna << "@echo off\n"
				"title Run Luna\n"
				"cd %1\n"
				"luna\n"
				"echo RUN_LUNA.bat run successfully!\n";
			runLuna.close();
			std::string command = "RUN_LUNA.bat LunaProjects/LunaProj" +
				std::to_string( i );
			system( command.c_str() );

			remove( "RUN_LUNA.bat" );

			break;
		}
		in.close();
		++i;
	}

	std::cout << "Exited loop!\n";
	std::cout << "Press <Enter> to exit.";
	std::cin.get();
	return 0;
}