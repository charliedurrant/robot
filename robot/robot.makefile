# Compiler flags...
CPP_COMPILER = g++
C_COMPILER = gcc

# Include paths...
Debug_Win32_Include_Path=
Release_Win32_Include_Path=

# Library paths...
Debug_Win32_Library_Path=
Release_Win32_Library_Path=

# Additional libraries...
Debug_Win32_Libraries=-Wl,--start-group -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf  -Wl,--end-group
Release_Win32_Libraries=-Wl,--start-group -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf  -Wl,--end-group

# Preprocessor definitions...
Debug_Win32_Preprocessor_Definitions=-D GCC_BUILD 
Release_Win32_Preprocessor_Definitions=-D GCC_BUILD 

# Implictly linked object files...
Debug_Win32_Implicitly_Linked_Objects=
Release_Win32_Implicitly_Linked_Objects=

# Compiler flags...
Debug_Win32_Compiler_Flags=-O0 -g 
Release_Win32_Compiler_Flags=-O2 

# Builds all configurations for this project...
.PHONY: build_all_configurations
build_all_configurations: Debug_Win32 Release_Win32 

# Builds the Debug_Win32 configuration...
.PHONY: Debug_Win32
Debug_Win32: create_folders D:/Projects/robot/code/robot/robot/gccDebug/StdAfx.h.gch D:/Projects/robot/code/robot/robot/gccDebug/EventHndler.o D:/Projects/robot/code/robot/robot/gccDebug/Main.o D:/Projects/robot/code/robot/robot/gccDebug/MyGame.o D:/Projects/robot/code/robot/robot/gccDebug/RobotProgram.o D:/Projects/robot/code/robot/robot/gccDebug/Settings.o D:/Projects/robot/code/robot/robot/gccDebug/Theme.o D:/Projects/robot/code/robot/robot/gccDebug/ErrorState.o D:/Projects/robot/code/robot/robot/gccDebug/MenuState.o D:/Projects/robot/code/robot/robot/gccDebug/PlayState.o D:/Projects/robot/code/robot/robot/gccDebug/BaseGameTheme.o D:/Projects/robot/code/robot/robot/gccDebug/Color.o D:/Projects/robot/code/robot/robot/gccDebug/FontManager.o D:/Projects/robot/code/robot/robot/gccDebug/FontManagerFont.o D:/Projects/robot/code/robot/robot/gccDebug/Game.o D:/Projects/robot/code/robot/robot/gccDebug/Exception.o D:/Projects/robot/code/robot/robot/gccDebug/Functions.o D:/Projects/robot/code/robot/robot/gccDebug/GameFont.o D:/Projects/robot/code/robot/robot/gccDebug/GameObjects.o D:/Projects/robot/code/robot/robot/gccDebug/InputHandler.o D:/Projects/robot/code/robot/robot/gccDebug/MouseData.o D:/Projects/robot/code/robot/robot/gccDebug/GameObject.o D:/Projects/robot/code/robot/robot/gccDebug/ImageManager.o D:/Projects/robot/code/robot/robot/gccDebug/Image.o D:/Projects/robot/code/robot/robot/gccDebug/SettingsBase.o D:/Projects/robot/code/robot/robot/gccDebug/StdAfx.o D:/Projects/robot/code/robot/robot/gccDebug/ThemeObjectImage.o D:/Projects/robot/code/robot/robot/gccDebug/SplitPath.o D:/Projects/robot/code/robot/robot/gccDebug/State.o D:/Projects/robot/code/robot/robot/gccDebug/StateManager.o D:/Projects/robot/code/robot/robot/gccDebug/ThemeObject.o D:/Projects/robot/code/robot/robot/gccDebug/Types.o D:/Projects/robot/code/robot/robot/gccDebug/Vector2D.o D:/Projects/robot/code/robot/robot/gccDebug/Window.o D:/Projects/robot/code/robot/robot/gccDebug/format.o D:/Projects/robot/code/robot/robot/gccDebug/tinystr.o D:/Projects/robot/code/robot/robot/gccDebug/tinyxml.o D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlerror.o D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlparser.o D:/Projects/robot/code/robot/robot/gccDebug/BoardSquare.o D:/Projects/robot/code/robot/robot/gccDebug/Board.o D:/Projects/robot/code/robot/robot/gccDebug/Buttn.o D:/Projects/robot/code/robot/robot/gccDebug/ButtonBar.o D:/Projects/robot/code/robot/robot/gccDebug/CommandBar.o D:/Projects/robot/code/robot/robot/gccDebug/CommandBarButton.o D:/Projects/robot/code/robot/robot/gccDebug/DebugInfo.o D:/Projects/robot/code/robot/robot/gccDebug/Labl.o D:/Projects/robot/code/robot/robot/gccDebug/MenuItem.o D:/Projects/robot/code/robot/robot/gccDebug/Robot.o D:/Projects/robot/code/robot/robot/gccDebug/BoardRotationArrow.o D:/Projects/robot/code/robot/robot/gccDebug/StandardBackground.o D:/Projects/robot/code/robot/robot/gccDebug/Level.o D:/Projects/robot/code/robot/robot/gccDebug/LevelPack.o D:/Projects/robot/code/robot/robot/gccDebug/LevelPacks.o D:/Projects/robot/code/robot/robot/gccDebug/LevelSquare.o 
	g++ D:/Projects/robot/code/robot/robot/gccDebug/EventHndler.o D:/Projects/robot/code/robot/robot/gccDebug/Main.o D:/Projects/robot/code/robot/robot/gccDebug/MyGame.o D:/Projects/robot/code/robot/robot/gccDebug/RobotProgram.o D:/Projects/robot/code/robot/robot/gccDebug/Settings.o D:/Projects/robot/code/robot/robot/gccDebug/Theme.o D:/Projects/robot/code/robot/robot/gccDebug/ErrorState.o D:/Projects/robot/code/robot/robot/gccDebug/MenuState.o D:/Projects/robot/code/robot/robot/gccDebug/PlayState.o D:/Projects/robot/code/robot/robot/gccDebug/BaseGameTheme.o D:/Projects/robot/code/robot/robot/gccDebug/Color.o D:/Projects/robot/code/robot/robot/gccDebug/FontManager.o D:/Projects/robot/code/robot/robot/gccDebug/FontManagerFont.o D:/Projects/robot/code/robot/robot/gccDebug/Game.o D:/Projects/robot/code/robot/robot/gccDebug/Exception.o D:/Projects/robot/code/robot/robot/gccDebug/Functions.o D:/Projects/robot/code/robot/robot/gccDebug/GameFont.o D:/Projects/robot/code/robot/robot/gccDebug/GameObjects.o D:/Projects/robot/code/robot/robot/gccDebug/InputHandler.o D:/Projects/robot/code/robot/robot/gccDebug/MouseData.o D:/Projects/robot/code/robot/robot/gccDebug/GameObject.o D:/Projects/robot/code/robot/robot/gccDebug/ImageManager.o D:/Projects/robot/code/robot/robot/gccDebug/Image.o D:/Projects/robot/code/robot/robot/gccDebug/SettingsBase.o D:/Projects/robot/code/robot/robot/gccDebug/StdAfx.o D:/Projects/robot/code/robot/robot/gccDebug/ThemeObjectImage.o D:/Projects/robot/code/robot/robot/gccDebug/SplitPath.o D:/Projects/robot/code/robot/robot/gccDebug/State.o D:/Projects/robot/code/robot/robot/gccDebug/StateManager.o D:/Projects/robot/code/robot/robot/gccDebug/ThemeObject.o D:/Projects/robot/code/robot/robot/gccDebug/Types.o D:/Projects/robot/code/robot/robot/gccDebug/Vector2D.o D:/Projects/robot/code/robot/robot/gccDebug/Window.o D:/Projects/robot/code/robot/robot/gccDebug/format.o D:/Projects/robot/code/robot/robot/gccDebug/tinystr.o D:/Projects/robot/code/robot/robot/gccDebug/tinyxml.o D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlerror.o D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlparser.o D:/Projects/robot/code/robot/robot/gccDebug/BoardSquare.o D:/Projects/robot/code/robot/robot/gccDebug/Board.o D:/Projects/robot/code/robot/robot/gccDebug/Buttn.o D:/Projects/robot/code/robot/robot/gccDebug/ButtonBar.o D:/Projects/robot/code/robot/robot/gccDebug/CommandBar.o D:/Projects/robot/code/robot/robot/gccDebug/CommandBarButton.o D:/Projects/robot/code/robot/robot/gccDebug/DebugInfo.o D:/Projects/robot/code/robot/robot/gccDebug/Labl.o D:/Projects/robot/code/robot/robot/gccDebug/MenuItem.o D:/Projects/robot/code/robot/robot/gccDebug/Robot.o D:/Projects/robot/code/robot/robot/gccDebug/BoardRotationArrow.o D:/Projects/robot/code/robot/robot/gccDebug/StandardBackground.o D:/Projects/robot/code/robot/robot/gccDebug/Level.o D:/Projects/robot/code/robot/robot/gccDebug/LevelPack.o D:/Projects/robot/code/robot/robot/gccDebug/LevelPacks.o D:/Projects/robot/code/robot/robot/gccDebug/LevelSquare.o  $(Debug_Win32_Library_Path) $(Debug_Win32_Libraries) -Wl,-rpath,./ -o D:/Projects/robot/code/robot/gccDebug/robot.exe

# Compiles file StdAfx.h as the precompiled header StdAfx.h.gch for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/StdAfx.d
D:/Projects/robot/code/robot/robot/gccDebug/StdAfx.h.gch: StdAfx.h
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c StdAfx.h $(Debug_Win32_Include_Path) -o StdAfx.h.gch

# Compiles file EventHndler.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/EventHndler.d
D:/Projects/robot/code/robot/robot/gccDebug/EventHndler.o: EventHndler.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c EventHndler.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/EventHndler.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM EventHndler.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/EventHndler.d

# Compiles file Main.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Main.d
D:/Projects/robot/code/robot/robot/gccDebug/Main.o: Main.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Main.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Main.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Main.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Main.d

# Compiles file MyGame.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/MyGame.d
D:/Projects/robot/code/robot/robot/gccDebug/MyGame.o: MyGame.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c MyGame.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/MyGame.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM MyGame.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/MyGame.d

# Compiles file RobotProgram.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/RobotProgram.d
D:/Projects/robot/code/robot/robot/gccDebug/RobotProgram.o: RobotProgram.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c RobotProgram.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/RobotProgram.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM RobotProgram.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/RobotProgram.d

# Compiles file Settings.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Settings.d
D:/Projects/robot/code/robot/robot/gccDebug/Settings.o: Settings.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Settings.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Settings.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Settings.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Settings.d

# Compiles file Theme.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Theme.d
D:/Projects/robot/code/robot/robot/gccDebug/Theme.o: Theme.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Theme.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Theme.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Theme.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Theme.d

# Compiles file ErrorState.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/ErrorState.d
D:/Projects/robot/code/robot/robot/gccDebug/ErrorState.o: ErrorState.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c ErrorState.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/ErrorState.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM ErrorState.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/ErrorState.d

# Compiles file MenuState.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/MenuState.d
D:/Projects/robot/code/robot/robot/gccDebug/MenuState.o: MenuState.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c MenuState.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/MenuState.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM MenuState.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/MenuState.d

# Compiles file PlayState.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/PlayState.d
D:/Projects/robot/code/robot/robot/gccDebug/PlayState.o: PlayState.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c PlayState.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/PlayState.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM PlayState.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/PlayState.d

# Compiles file BaseGameTheme.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/BaseGameTheme.d
D:/Projects/robot/code/robot/robot/gccDebug/BaseGameTheme.o: BaseGameTheme.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c BaseGameTheme.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/BaseGameTheme.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM BaseGameTheme.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/BaseGameTheme.d

# Compiles file Color.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Color.d
D:/Projects/robot/code/robot/robot/gccDebug/Color.o: Color.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Color.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Color.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Color.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Color.d

# Compiles file FontManager.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/FontManager.d
D:/Projects/robot/code/robot/robot/gccDebug/FontManager.o: FontManager.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c FontManager.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/FontManager.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM FontManager.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/FontManager.d

# Compiles file FontManagerFont.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/FontManagerFont.d
D:/Projects/robot/code/robot/robot/gccDebug/FontManagerFont.o: FontManagerFont.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c FontManagerFont.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/FontManagerFont.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM FontManagerFont.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/FontManagerFont.d

# Compiles file Game.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Game.d
D:/Projects/robot/code/robot/robot/gccDebug/Game.o: Game.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Game.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Game.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Game.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Game.d

# Compiles file Exception.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Exception.d
D:/Projects/robot/code/robot/robot/gccDebug/Exception.o: Exception.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Exception.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Exception.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Exception.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Exception.d

# Compiles file Functions.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Functions.d
D:/Projects/robot/code/robot/robot/gccDebug/Functions.o: Functions.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Functions.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Functions.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Functions.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Functions.d

# Compiles file GameFont.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/GameFont.d
D:/Projects/robot/code/robot/robot/gccDebug/GameFont.o: GameFont.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c GameFont.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/GameFont.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM GameFont.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/GameFont.d

# Compiles file GameObjects.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/GameObjects.d
D:/Projects/robot/code/robot/robot/gccDebug/GameObjects.o: GameObjects.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c GameObjects.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/GameObjects.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM GameObjects.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/GameObjects.d

# Compiles file InputHandler.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/InputHandler.d
D:/Projects/robot/code/robot/robot/gccDebug/InputHandler.o: InputHandler.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c InputHandler.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/InputHandler.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM InputHandler.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/InputHandler.d

# Compiles file MouseData.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/MouseData.d
D:/Projects/robot/code/robot/robot/gccDebug/MouseData.o: MouseData.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c MouseData.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/MouseData.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM MouseData.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/MouseData.d

# Compiles file GameObject.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/GameObject.d
D:/Projects/robot/code/robot/robot/gccDebug/GameObject.o: GameObject.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c GameObject.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/GameObject.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM GameObject.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/GameObject.d

# Compiles file ImageManager.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/ImageManager.d
D:/Projects/robot/code/robot/robot/gccDebug/ImageManager.o: ImageManager.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c ImageManager.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/ImageManager.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM ImageManager.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/ImageManager.d

# Compiles file Image.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Image.d
D:/Projects/robot/code/robot/robot/gccDebug/Image.o: Image.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Image.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Image.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Image.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Image.d

# Compiles file SettingsBase.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/SettingsBase.d
D:/Projects/robot/code/robot/robot/gccDebug/SettingsBase.o: SettingsBase.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c SettingsBase.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/SettingsBase.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM SettingsBase.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/SettingsBase.d

# Compiles file StdAfx.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/StdAfx.d
D:/Projects/robot/code/robot/robot/gccDebug/StdAfx.o: StdAfx.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c StdAfx.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/StdAfx.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM StdAfx.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/StdAfx.d

# Compiles file ThemeObjectImage.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/ThemeObjectImage.d
D:/Projects/robot/code/robot/robot/gccDebug/ThemeObjectImage.o: ThemeObjectImage.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c ThemeObjectImage.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/ThemeObjectImage.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM ThemeObjectImage.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/ThemeObjectImage.d

# Compiles file SplitPath.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/SplitPath.d
D:/Projects/robot/code/robot/robot/gccDebug/SplitPath.o: SplitPath.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c SplitPath.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/SplitPath.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM SplitPath.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/SplitPath.d

# Compiles file State.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/State.d
D:/Projects/robot/code/robot/robot/gccDebug/State.o: State.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c State.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/State.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM State.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/State.d

# Compiles file StateManager.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/StateManager.d
D:/Projects/robot/code/robot/robot/gccDebug/StateManager.o: StateManager.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c StateManager.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/StateManager.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM StateManager.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/StateManager.d

# Compiles file ThemeObject.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/ThemeObject.d
D:/Projects/robot/code/robot/robot/gccDebug/ThemeObject.o: ThemeObject.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c ThemeObject.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/ThemeObject.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM ThemeObject.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/ThemeObject.d

# Compiles file Types.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Types.d
D:/Projects/robot/code/robot/robot/gccDebug/Types.o: Types.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Types.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Types.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Types.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Types.d

# Compiles file Vector2D.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Vector2D.d
D:/Projects/robot/code/robot/robot/gccDebug/Vector2D.o: Vector2D.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Vector2D.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Vector2D.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Vector2D.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Vector2D.d

# Compiles file Window.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Window.d
D:/Projects/robot/code/robot/robot/gccDebug/Window.o: Window.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Window.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Window.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Window.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Window.d

# Compiles file format.cc for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/format.d
D:/Projects/robot/code/robot/robot/gccDebug/format.o: format.cc
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c format.cc $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/format.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM format.cc $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/format.d

# Compiles file tinystr.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/tinystr.d
D:/Projects/robot/code/robot/robot/gccDebug/tinystr.o: tinystr.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c tinystr.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/tinystr.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM tinystr.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/tinystr.d

# Compiles file tinyxml.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/tinyxml.d
D:/Projects/robot/code/robot/robot/gccDebug/tinyxml.o: tinyxml.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c tinyxml.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/tinyxml.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM tinyxml.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/tinyxml.d

# Compiles file tinyxmlerror.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlerror.d
D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlerror.o: tinyxmlerror.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c tinyxmlerror.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlerror.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM tinyxmlerror.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlerror.d

# Compiles file tinyxmlparser.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlparser.d
D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlparser.o: tinyxmlparser.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c tinyxmlparser.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlparser.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM tinyxmlparser.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/tinyxmlparser.d

# Compiles file BoardSquare.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/BoardSquare.d
D:/Projects/robot/code/robot/robot/gccDebug/BoardSquare.o: BoardSquare.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c BoardSquare.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/BoardSquare.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM BoardSquare.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/BoardSquare.d

# Compiles file Board.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Board.d
D:/Projects/robot/code/robot/robot/gccDebug/Board.o: Board.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Board.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Board.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Board.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Board.d

# Compiles file Buttn.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Buttn.d
D:/Projects/robot/code/robot/robot/gccDebug/Buttn.o: Buttn.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Buttn.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Buttn.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Buttn.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Buttn.d

# Compiles file ButtonBar.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/ButtonBar.d
D:/Projects/robot/code/robot/robot/gccDebug/ButtonBar.o: ButtonBar.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c ButtonBar.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/ButtonBar.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM ButtonBar.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/ButtonBar.d

# Compiles file CommandBar.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/CommandBar.d
D:/Projects/robot/code/robot/robot/gccDebug/CommandBar.o: CommandBar.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c CommandBar.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/CommandBar.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM CommandBar.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/CommandBar.d

# Compiles file CommandBarButton.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/CommandBarButton.d
D:/Projects/robot/code/robot/robot/gccDebug/CommandBarButton.o: CommandBarButton.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c CommandBarButton.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/CommandBarButton.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM CommandBarButton.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/CommandBarButton.d

# Compiles file DebugInfo.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/DebugInfo.d
D:/Projects/robot/code/robot/robot/gccDebug/DebugInfo.o: DebugInfo.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c DebugInfo.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/DebugInfo.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM DebugInfo.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/DebugInfo.d

# Compiles file Labl.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Labl.d
D:/Projects/robot/code/robot/robot/gccDebug/Labl.o: Labl.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Labl.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Labl.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Labl.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Labl.d

# Compiles file MenuItem.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/MenuItem.d
D:/Projects/robot/code/robot/robot/gccDebug/MenuItem.o: MenuItem.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c MenuItem.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/MenuItem.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM MenuItem.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/MenuItem.d

# Compiles file Robot.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Robot.d
D:/Projects/robot/code/robot/robot/gccDebug/Robot.o: Robot.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Robot.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Robot.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Robot.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Robot.d

# Compiles file BoardRotationArrow.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/BoardRotationArrow.d
D:/Projects/robot/code/robot/robot/gccDebug/BoardRotationArrow.o: BoardRotationArrow.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c BoardRotationArrow.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/BoardRotationArrow.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM BoardRotationArrow.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/BoardRotationArrow.d

# Compiles file StandardBackground.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/StandardBackground.d
D:/Projects/robot/code/robot/robot/gccDebug/StandardBackground.o: StandardBackground.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c StandardBackground.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/StandardBackground.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM StandardBackground.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/StandardBackground.d

# Compiles file Level.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/Level.d
D:/Projects/robot/code/robot/robot/gccDebug/Level.o: Level.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c Level.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/Level.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM Level.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/Level.d

# Compiles file LevelPack.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/LevelPack.d
D:/Projects/robot/code/robot/robot/gccDebug/LevelPack.o: LevelPack.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c LevelPack.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/LevelPack.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM LevelPack.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/LevelPack.d

# Compiles file LevelPacks.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/LevelPacks.d
D:/Projects/robot/code/robot/robot/gccDebug/LevelPacks.o: LevelPacks.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c LevelPacks.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/LevelPacks.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM LevelPacks.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/LevelPacks.d

# Compiles file LevelSquare.cpp for the Debug_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccDebug/LevelSquare.d
D:/Projects/robot/code/robot/robot/gccDebug/LevelSquare.o: LevelSquare.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c LevelSquare.cpp $(Debug_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccDebug/LevelSquare.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM LevelSquare.cpp $(Debug_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccDebug/LevelSquare.d

# Builds the Release_Win32 configuration...
.PHONY: Release_Win32
Release_Win32: create_folders D:/Projects/robot/code/robot/robot/gccRelease/StdAfx.h.gch D:/Projects/robot/code/robot/robot/gccRelease/EventHndler.o D:/Projects/robot/code/robot/robot/gccRelease/Main.o D:/Projects/robot/code/robot/robot/gccRelease/MyGame.o D:/Projects/robot/code/robot/robot/gccRelease/RobotProgram.o D:/Projects/robot/code/robot/robot/gccRelease/Settings.o D:/Projects/robot/code/robot/robot/gccRelease/Theme.o D:/Projects/robot/code/robot/robot/gccRelease/ErrorState.o D:/Projects/robot/code/robot/robot/gccRelease/MenuState.o D:/Projects/robot/code/robot/robot/gccRelease/PlayState.o D:/Projects/robot/code/robot/robot/gccRelease/BaseGameTheme.o D:/Projects/robot/code/robot/robot/gccRelease/Color.o D:/Projects/robot/code/robot/robot/gccRelease/FontManager.o D:/Projects/robot/code/robot/robot/gccRelease/FontManagerFont.o D:/Projects/robot/code/robot/robot/gccRelease/Game.o D:/Projects/robot/code/robot/robot/gccRelease/Exception.o D:/Projects/robot/code/robot/robot/gccRelease/Functions.o D:/Projects/robot/code/robot/robot/gccRelease/GameFont.o D:/Projects/robot/code/robot/robot/gccRelease/GameObjects.o D:/Projects/robot/code/robot/robot/gccRelease/InputHandler.o D:/Projects/robot/code/robot/robot/gccRelease/MouseData.o D:/Projects/robot/code/robot/robot/gccRelease/GameObject.o D:/Projects/robot/code/robot/robot/gccRelease/ImageManager.o D:/Projects/robot/code/robot/robot/gccRelease/Image.o D:/Projects/robot/code/robot/robot/gccRelease/SettingsBase.o D:/Projects/robot/code/robot/robot/gccRelease/StdAfx.o D:/Projects/robot/code/robot/robot/gccRelease/ThemeObjectImage.o D:/Projects/robot/code/robot/robot/gccRelease/SplitPath.o D:/Projects/robot/code/robot/robot/gccRelease/State.o D:/Projects/robot/code/robot/robot/gccRelease/StateManager.o D:/Projects/robot/code/robot/robot/gccRelease/ThemeObject.o D:/Projects/robot/code/robot/robot/gccRelease/Types.o D:/Projects/robot/code/robot/robot/gccRelease/Vector2D.o D:/Projects/robot/code/robot/robot/gccRelease/Window.o D:/Projects/robot/code/robot/robot/gccRelease/format.o D:/Projects/robot/code/robot/robot/gccRelease/tinystr.o D:/Projects/robot/code/robot/robot/gccRelease/tinyxml.o D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlerror.o D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlparser.o D:/Projects/robot/code/robot/robot/gccRelease/BoardSquare.o D:/Projects/robot/code/robot/robot/gccRelease/Board.o D:/Projects/robot/code/robot/robot/gccRelease/Buttn.o D:/Projects/robot/code/robot/robot/gccRelease/ButtonBar.o D:/Projects/robot/code/robot/robot/gccRelease/CommandBar.o D:/Projects/robot/code/robot/robot/gccRelease/CommandBarButton.o D:/Projects/robot/code/robot/robot/gccRelease/DebugInfo.o D:/Projects/robot/code/robot/robot/gccRelease/Labl.o D:/Projects/robot/code/robot/robot/gccRelease/MenuItem.o D:/Projects/robot/code/robot/robot/gccRelease/Robot.o D:/Projects/robot/code/robot/robot/gccRelease/BoardRotationArrow.o D:/Projects/robot/code/robot/robot/gccRelease/StandardBackground.o D:/Projects/robot/code/robot/robot/gccRelease/Level.o D:/Projects/robot/code/robot/robot/gccRelease/LevelPack.o D:/Projects/robot/code/robot/robot/gccRelease/LevelPacks.o D:/Projects/robot/code/robot/robot/gccRelease/LevelSquare.o 
	g++ D:/Projects/robot/code/robot/robot/gccRelease/EventHndler.o D:/Projects/robot/code/robot/robot/gccRelease/Main.o D:/Projects/robot/code/robot/robot/gccRelease/MyGame.o D:/Projects/robot/code/robot/robot/gccRelease/RobotProgram.o D:/Projects/robot/code/robot/robot/gccRelease/Settings.o D:/Projects/robot/code/robot/robot/gccRelease/Theme.o D:/Projects/robot/code/robot/robot/gccRelease/ErrorState.o D:/Projects/robot/code/robot/robot/gccRelease/MenuState.o D:/Projects/robot/code/robot/robot/gccRelease/PlayState.o D:/Projects/robot/code/robot/robot/gccRelease/BaseGameTheme.o D:/Projects/robot/code/robot/robot/gccRelease/Color.o D:/Projects/robot/code/robot/robot/gccRelease/FontManager.o D:/Projects/robot/code/robot/robot/gccRelease/FontManagerFont.o D:/Projects/robot/code/robot/robot/gccRelease/Game.o D:/Projects/robot/code/robot/robot/gccRelease/Exception.o D:/Projects/robot/code/robot/robot/gccRelease/Functions.o D:/Projects/robot/code/robot/robot/gccRelease/GameFont.o D:/Projects/robot/code/robot/robot/gccRelease/GameObjects.o D:/Projects/robot/code/robot/robot/gccRelease/InputHandler.o D:/Projects/robot/code/robot/robot/gccRelease/MouseData.o D:/Projects/robot/code/robot/robot/gccRelease/GameObject.o D:/Projects/robot/code/robot/robot/gccRelease/ImageManager.o D:/Projects/robot/code/robot/robot/gccRelease/Image.o D:/Projects/robot/code/robot/robot/gccRelease/SettingsBase.o D:/Projects/robot/code/robot/robot/gccRelease/StdAfx.o D:/Projects/robot/code/robot/robot/gccRelease/ThemeObjectImage.o D:/Projects/robot/code/robot/robot/gccRelease/SplitPath.o D:/Projects/robot/code/robot/robot/gccRelease/State.o D:/Projects/robot/code/robot/robot/gccRelease/StateManager.o D:/Projects/robot/code/robot/robot/gccRelease/ThemeObject.o D:/Projects/robot/code/robot/robot/gccRelease/Types.o D:/Projects/robot/code/robot/robot/gccRelease/Vector2D.o D:/Projects/robot/code/robot/robot/gccRelease/Window.o D:/Projects/robot/code/robot/robot/gccRelease/format.o D:/Projects/robot/code/robot/robot/gccRelease/tinystr.o D:/Projects/robot/code/robot/robot/gccRelease/tinyxml.o D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlerror.o D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlparser.o D:/Projects/robot/code/robot/robot/gccRelease/BoardSquare.o D:/Projects/robot/code/robot/robot/gccRelease/Board.o D:/Projects/robot/code/robot/robot/gccRelease/Buttn.o D:/Projects/robot/code/robot/robot/gccRelease/ButtonBar.o D:/Projects/robot/code/robot/robot/gccRelease/CommandBar.o D:/Projects/robot/code/robot/robot/gccRelease/CommandBarButton.o D:/Projects/robot/code/robot/robot/gccRelease/DebugInfo.o D:/Projects/robot/code/robot/robot/gccRelease/Labl.o D:/Projects/robot/code/robot/robot/gccRelease/MenuItem.o D:/Projects/robot/code/robot/robot/gccRelease/Robot.o D:/Projects/robot/code/robot/robot/gccRelease/BoardRotationArrow.o D:/Projects/robot/code/robot/robot/gccRelease/StandardBackground.o D:/Projects/robot/code/robot/robot/gccRelease/Level.o D:/Projects/robot/code/robot/robot/gccRelease/LevelPack.o D:/Projects/robot/code/robot/robot/gccRelease/LevelPacks.o D:/Projects/robot/code/robot/robot/gccRelease/LevelSquare.o  $(Release_Win32_Library_Path) $(Release_Win32_Libraries) -Wl,-rpath,./ -o D:/Projects/robot/code/robot/gccRelease/robot.exe

# Compiles file StdAfx.h as the precompiled header StdAfx.h.gch for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/StdAfx.d
D:/Projects/robot/code/robot/robot/gccRelease/StdAfx.h.gch: StdAfx.h
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c StdAfx.h $(Release_Win32_Include_Path) -o StdAfx.h.gch

# Compiles file EventHndler.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/EventHndler.d
D:/Projects/robot/code/robot/robot/gccRelease/EventHndler.o: EventHndler.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c EventHndler.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/EventHndler.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM EventHndler.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/EventHndler.d

# Compiles file Main.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Main.d
D:/Projects/robot/code/robot/robot/gccRelease/Main.o: Main.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Main.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Main.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Main.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Main.d

# Compiles file MyGame.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/MyGame.d
D:/Projects/robot/code/robot/robot/gccRelease/MyGame.o: MyGame.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c MyGame.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/MyGame.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM MyGame.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/MyGame.d

# Compiles file RobotProgram.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/RobotProgram.d
D:/Projects/robot/code/robot/robot/gccRelease/RobotProgram.o: RobotProgram.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c RobotProgram.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/RobotProgram.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM RobotProgram.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/RobotProgram.d

# Compiles file Settings.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Settings.d
D:/Projects/robot/code/robot/robot/gccRelease/Settings.o: Settings.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Settings.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Settings.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Settings.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Settings.d

# Compiles file Theme.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Theme.d
D:/Projects/robot/code/robot/robot/gccRelease/Theme.o: Theme.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Theme.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Theme.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Theme.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Theme.d

# Compiles file ErrorState.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/ErrorState.d
D:/Projects/robot/code/robot/robot/gccRelease/ErrorState.o: ErrorState.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c ErrorState.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/ErrorState.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM ErrorState.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/ErrorState.d

# Compiles file MenuState.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/MenuState.d
D:/Projects/robot/code/robot/robot/gccRelease/MenuState.o: MenuState.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c MenuState.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/MenuState.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM MenuState.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/MenuState.d

# Compiles file PlayState.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/PlayState.d
D:/Projects/robot/code/robot/robot/gccRelease/PlayState.o: PlayState.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c PlayState.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/PlayState.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM PlayState.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/PlayState.d

# Compiles file BaseGameTheme.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/BaseGameTheme.d
D:/Projects/robot/code/robot/robot/gccRelease/BaseGameTheme.o: BaseGameTheme.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c BaseGameTheme.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/BaseGameTheme.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM BaseGameTheme.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/BaseGameTheme.d

# Compiles file Color.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Color.d
D:/Projects/robot/code/robot/robot/gccRelease/Color.o: Color.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Color.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Color.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Color.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Color.d

# Compiles file FontManager.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/FontManager.d
D:/Projects/robot/code/robot/robot/gccRelease/FontManager.o: FontManager.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c FontManager.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/FontManager.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM FontManager.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/FontManager.d

# Compiles file FontManagerFont.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/FontManagerFont.d
D:/Projects/robot/code/robot/robot/gccRelease/FontManagerFont.o: FontManagerFont.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c FontManagerFont.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/FontManagerFont.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM FontManagerFont.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/FontManagerFont.d

# Compiles file Game.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Game.d
D:/Projects/robot/code/robot/robot/gccRelease/Game.o: Game.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Game.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Game.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Game.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Game.d

# Compiles file Exception.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Exception.d
D:/Projects/robot/code/robot/robot/gccRelease/Exception.o: Exception.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Exception.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Exception.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Exception.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Exception.d

# Compiles file Functions.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Functions.d
D:/Projects/robot/code/robot/robot/gccRelease/Functions.o: Functions.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Functions.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Functions.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Functions.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Functions.d

# Compiles file GameFont.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/GameFont.d
D:/Projects/robot/code/robot/robot/gccRelease/GameFont.o: GameFont.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c GameFont.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/GameFont.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM GameFont.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/GameFont.d

# Compiles file GameObjects.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/GameObjects.d
D:/Projects/robot/code/robot/robot/gccRelease/GameObjects.o: GameObjects.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c GameObjects.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/GameObjects.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM GameObjects.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/GameObjects.d

# Compiles file InputHandler.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/InputHandler.d
D:/Projects/robot/code/robot/robot/gccRelease/InputHandler.o: InputHandler.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c InputHandler.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/InputHandler.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM InputHandler.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/InputHandler.d

# Compiles file MouseData.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/MouseData.d
D:/Projects/robot/code/robot/robot/gccRelease/MouseData.o: MouseData.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c MouseData.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/MouseData.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM MouseData.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/MouseData.d

# Compiles file GameObject.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/GameObject.d
D:/Projects/robot/code/robot/robot/gccRelease/GameObject.o: GameObject.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c GameObject.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/GameObject.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM GameObject.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/GameObject.d

# Compiles file ImageManager.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/ImageManager.d
D:/Projects/robot/code/robot/robot/gccRelease/ImageManager.o: ImageManager.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c ImageManager.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/ImageManager.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM ImageManager.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/ImageManager.d

# Compiles file Image.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Image.d
D:/Projects/robot/code/robot/robot/gccRelease/Image.o: Image.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Image.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Image.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Image.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Image.d

# Compiles file SettingsBase.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/SettingsBase.d
D:/Projects/robot/code/robot/robot/gccRelease/SettingsBase.o: SettingsBase.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c SettingsBase.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/SettingsBase.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM SettingsBase.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/SettingsBase.d

# Compiles file StdAfx.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/StdAfx.d
D:/Projects/robot/code/robot/robot/gccRelease/StdAfx.o: StdAfx.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c StdAfx.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/StdAfx.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM StdAfx.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/StdAfx.d

# Compiles file ThemeObjectImage.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/ThemeObjectImage.d
D:/Projects/robot/code/robot/robot/gccRelease/ThemeObjectImage.o: ThemeObjectImage.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c ThemeObjectImage.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/ThemeObjectImage.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM ThemeObjectImage.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/ThemeObjectImage.d

# Compiles file SplitPath.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/SplitPath.d
D:/Projects/robot/code/robot/robot/gccRelease/SplitPath.o: SplitPath.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c SplitPath.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/SplitPath.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM SplitPath.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/SplitPath.d

# Compiles file State.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/State.d
D:/Projects/robot/code/robot/robot/gccRelease/State.o: State.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c State.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/State.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM State.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/State.d

# Compiles file StateManager.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/StateManager.d
D:/Projects/robot/code/robot/robot/gccRelease/StateManager.o: StateManager.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c StateManager.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/StateManager.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM StateManager.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/StateManager.d

# Compiles file ThemeObject.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/ThemeObject.d
D:/Projects/robot/code/robot/robot/gccRelease/ThemeObject.o: ThemeObject.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c ThemeObject.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/ThemeObject.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM ThemeObject.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/ThemeObject.d

# Compiles file Types.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Types.d
D:/Projects/robot/code/robot/robot/gccRelease/Types.o: Types.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Types.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Types.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Types.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Types.d

# Compiles file Vector2D.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Vector2D.d
D:/Projects/robot/code/robot/robot/gccRelease/Vector2D.o: Vector2D.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Vector2D.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Vector2D.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Vector2D.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Vector2D.d

# Compiles file Window.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Window.d
D:/Projects/robot/code/robot/robot/gccRelease/Window.o: Window.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Window.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Window.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Window.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Window.d

# Compiles file format.cc for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/format.d
D:/Projects/robot/code/robot/robot/gccRelease/format.o: format.cc
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c format.cc $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/format.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM format.cc $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/format.d

# Compiles file tinystr.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/tinystr.d
D:/Projects/robot/code/robot/robot/gccRelease/tinystr.o: tinystr.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c tinystr.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/tinystr.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM tinystr.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/tinystr.d

# Compiles file tinyxml.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/tinyxml.d
D:/Projects/robot/code/robot/robot/gccRelease/tinyxml.o: tinyxml.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c tinyxml.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/tinyxml.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM tinyxml.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/tinyxml.d

# Compiles file tinyxmlerror.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlerror.d
D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlerror.o: tinyxmlerror.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c tinyxmlerror.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlerror.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM tinyxmlerror.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlerror.d

# Compiles file tinyxmlparser.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlparser.d
D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlparser.o: tinyxmlparser.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c tinyxmlparser.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlparser.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM tinyxmlparser.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/tinyxmlparser.d

# Compiles file BoardSquare.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/BoardSquare.d
D:/Projects/robot/code/robot/robot/gccRelease/BoardSquare.o: BoardSquare.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c BoardSquare.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/BoardSquare.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM BoardSquare.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/BoardSquare.d

# Compiles file Board.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Board.d
D:/Projects/robot/code/robot/robot/gccRelease/Board.o: Board.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Board.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Board.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Board.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Board.d

# Compiles file Buttn.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Buttn.d
D:/Projects/robot/code/robot/robot/gccRelease/Buttn.o: Buttn.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Buttn.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Buttn.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Buttn.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Buttn.d

# Compiles file ButtonBar.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/ButtonBar.d
D:/Projects/robot/code/robot/robot/gccRelease/ButtonBar.o: ButtonBar.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c ButtonBar.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/ButtonBar.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM ButtonBar.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/ButtonBar.d

# Compiles file CommandBar.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/CommandBar.d
D:/Projects/robot/code/robot/robot/gccRelease/CommandBar.o: CommandBar.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c CommandBar.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/CommandBar.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM CommandBar.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/CommandBar.d

# Compiles file CommandBarButton.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/CommandBarButton.d
D:/Projects/robot/code/robot/robot/gccRelease/CommandBarButton.o: CommandBarButton.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c CommandBarButton.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/CommandBarButton.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM CommandBarButton.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/CommandBarButton.d

# Compiles file DebugInfo.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/DebugInfo.d
D:/Projects/robot/code/robot/robot/gccRelease/DebugInfo.o: DebugInfo.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c DebugInfo.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/DebugInfo.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM DebugInfo.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/DebugInfo.d

# Compiles file Labl.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Labl.d
D:/Projects/robot/code/robot/robot/gccRelease/Labl.o: Labl.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Labl.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Labl.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Labl.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Labl.d

# Compiles file MenuItem.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/MenuItem.d
D:/Projects/robot/code/robot/robot/gccRelease/MenuItem.o: MenuItem.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c MenuItem.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/MenuItem.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM MenuItem.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/MenuItem.d

# Compiles file Robot.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Robot.d
D:/Projects/robot/code/robot/robot/gccRelease/Robot.o: Robot.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Robot.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Robot.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Robot.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Robot.d

# Compiles file BoardRotationArrow.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/BoardRotationArrow.d
D:/Projects/robot/code/robot/robot/gccRelease/BoardRotationArrow.o: BoardRotationArrow.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c BoardRotationArrow.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/BoardRotationArrow.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM BoardRotationArrow.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/BoardRotationArrow.d

# Compiles file StandardBackground.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/StandardBackground.d
D:/Projects/robot/code/robot/robot/gccRelease/StandardBackground.o: StandardBackground.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c StandardBackground.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/StandardBackground.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM StandardBackground.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/StandardBackground.d

# Compiles file Level.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/Level.d
D:/Projects/robot/code/robot/robot/gccRelease/Level.o: Level.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c Level.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/Level.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM Level.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/Level.d

# Compiles file LevelPack.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/LevelPack.d
D:/Projects/robot/code/robot/robot/gccRelease/LevelPack.o: LevelPack.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c LevelPack.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/LevelPack.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM LevelPack.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/LevelPack.d

# Compiles file LevelPacks.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/LevelPacks.d
D:/Projects/robot/code/robot/robot/gccRelease/LevelPacks.o: LevelPacks.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c LevelPacks.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/LevelPacks.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM LevelPacks.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/LevelPacks.d

# Compiles file LevelSquare.cpp for the Release_Win32 configuration...
-include D:/Projects/robot/code/robot/robot/gccRelease/LevelSquare.d
D:/Projects/robot/code/robot/robot/gccRelease/LevelSquare.o: LevelSquare.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c LevelSquare.cpp $(Release_Win32_Include_Path) -o D:/Projects/robot/code/robot/robot/gccRelease/LevelSquare.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM LevelSquare.cpp $(Release_Win32_Include_Path) > D:/Projects/robot/code/robot/robot/gccRelease/LevelSquare.d

# Creates the intermediate and output folders for each configuration...
.PHONY: create_folders
create_folders:
	mkdir -p D:/Projects/robot/code/robot/robot/gccDebug/source
	mkdir -p D:/Projects/robot/code/robot/gccDebug
	mkdir -p D:/Projects/robot/code/robot/robot/gccRelease/source
	mkdir -p D:/Projects/robot/code/robot/gccRelease

# Cleans intermediate and output files (objects, libraries, executables)...
.PHONY: clean
clean:
	rm -f D:/Projects/robot/code/robot/robot/gccDebug/*.o
	rm -f D:/Projects/robot/code/robot/robot/gccDebug/*.d
	rm -f D:/Projects/robot/code/robot/gccDebug/*.a
	rm -f D:/Projects/robot/code/robot/gccDebug/*.so
	rm -f D:/Projects/robot/code/robot/gccDebug/*.dll
	rm -f D:/Projects/robot/code/robot/gccDebug/*.exe
	rm -f D:/Projects/robot/code/robot/robot/gccRelease/*.o
	rm -f D:/Projects/robot/code/robot/robot/gccRelease/*.d
	rm -f D:/Projects/robot/code/robot/gccRelease/*.a
	rm -f D:/Projects/robot/code/robot/gccRelease/*.so
	rm -f D:/Projects/robot/code/robot/gccRelease/*.dll
	rm -f D:/Projects/robot/code/robot/gccRelease/*.exe

