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
Debug_Win32: create_folders d:/Projects/robot/source/robot/gccDebug/stdafx.h.gch d:/Projects/robot/source/robot/gccDebug/main.o d:/Projects/robot/source/robot/gccDebug/my_game.o d:/Projects/robot/source/robot/gccDebug/robot_program.o d:/Projects/robot/source/robot/gccDebug/settings.o d:/Projects/robot/source/robot/gccDebug/theme.o d:/Projects/robot/source/robot/gccDebug/base_game_theme.o d:/Projects/robot/source/robot/gccDebug/color.o d:/Projects/robot/source/robot/gccDebug/font_manager.o d:/Projects/robot/source/robot/gccDebug/font_manager_font.o d:/Projects/robot/source/robot/gccDebug/game.o d:/Projects/robot/source/robot/gccDebug/exception.o d:/Projects/robot/source/robot/gccDebug/functions.o d:/Projects/robot/source/robot/gccDebug/game_font.o d:/Projects/robot/source/robot/gccDebug/game_objects.o d:/Projects/robot/source/robot/gccDebug/input_handler.o d:/Projects/robot/source/robot/gccDebug/mouse_data.o d:/Projects/robot/source/robot/gccDebug/game_object.o d:/Projects/robot/source/robot/gccDebug/image_manager.o d:/Projects/robot/source/robot/gccDebug/image.o d:/Projects/robot/source/robot/gccDebug/settings_base.o d:/Projects/robot/source/robot/gccDebug/stdafx.o d:/Projects/robot/source/robot/gccDebug/theme_object_image.o d:/Projects/robot/source/robot/gccDebug/split_path.o d:/Projects/robot/source/robot/gccDebug/state.o d:/Projects/robot/source/robot/gccDebug/state_manager.o d:/Projects/robot/source/robot/gccDebug/theme_object.o d:/Projects/robot/source/robot/gccDebug/types.o d:/Projects/robot/source/robot/gccDebug/vector_2d.o d:/Projects/robot/source/robot/gccDebug/window.o d:/Projects/robot/source/robot/gccDebug/format.o d:/Projects/robot/source/robot/gccDebug/tinystr.o d:/Projects/robot/source/robot/gccDebug/tinyxml.o d:/Projects/robot/source/robot/gccDebug/tinyxmlerror.o d:/Projects/robot/source/robot/gccDebug/tinyxmlparser.o d:/Projects/robot/source/robot/gccDebug/level.o d:/Projects/robot/source/robot/gccDebug/level_pack.o d:/Projects/robot/source/robot/gccDebug/level_packs.o d:/Projects/robot/source/robot/gccDebug/level_square.o d:/Projects/robot/source/robot/gccDebug/board_square.o d:/Projects/robot/source/robot/gccDebug/board.o d:/Projects/robot/source/robot/gccDebug/button.o d:/Projects/robot/source/robot/gccDebug/button_bar.o d:/Projects/robot/source/robot/gccDebug/command_bar.o d:/Projects/robot/source/robot/gccDebug/command_bar_button.o d:/Projects/robot/source/robot/gccDebug/head_up_display.o d:/Projects/robot/source/robot/gccDebug/label.o d:/Projects/robot/source/robot/gccDebug/menu_item.o d:/Projects/robot/source/robot/gccDebug/robot.o d:/Projects/robot/source/robot/gccDebug/board_rotation_arrow.o d:/Projects/robot/source/robot/gccDebug/standard_background.o d:/Projects/robot/source/robot/gccDebug/error_state.o d:/Projects/robot/source/robot/gccDebug/menu_state.o d:/Projects/robot/source/robot/gccDebug/play_state.o 
	g++ d:/Projects/robot/source/robot/gccDebug/main.o d:/Projects/robot/source/robot/gccDebug/my_game.o d:/Projects/robot/source/robot/gccDebug/robot_program.o d:/Projects/robot/source/robot/gccDebug/settings.o d:/Projects/robot/source/robot/gccDebug/theme.o d:/Projects/robot/source/robot/gccDebug/base_game_theme.o d:/Projects/robot/source/robot/gccDebug/color.o d:/Projects/robot/source/robot/gccDebug/font_manager.o d:/Projects/robot/source/robot/gccDebug/font_manager_font.o d:/Projects/robot/source/robot/gccDebug/game.o d:/Projects/robot/source/robot/gccDebug/exception.o d:/Projects/robot/source/robot/gccDebug/functions.o d:/Projects/robot/source/robot/gccDebug/game_font.o d:/Projects/robot/source/robot/gccDebug/game_objects.o d:/Projects/robot/source/robot/gccDebug/input_handler.o d:/Projects/robot/source/robot/gccDebug/mouse_data.o d:/Projects/robot/source/robot/gccDebug/game_object.o d:/Projects/robot/source/robot/gccDebug/image_manager.o d:/Projects/robot/source/robot/gccDebug/image.o d:/Projects/robot/source/robot/gccDebug/settings_base.o d:/Projects/robot/source/robot/gccDebug/stdafx.o d:/Projects/robot/source/robot/gccDebug/theme_object_image.o d:/Projects/robot/source/robot/gccDebug/split_path.o d:/Projects/robot/source/robot/gccDebug/state.o d:/Projects/robot/source/robot/gccDebug/state_manager.o d:/Projects/robot/source/robot/gccDebug/theme_object.o d:/Projects/robot/source/robot/gccDebug/types.o d:/Projects/robot/source/robot/gccDebug/vector_2d.o d:/Projects/robot/source/robot/gccDebug/window.o d:/Projects/robot/source/robot/gccDebug/format.o d:/Projects/robot/source/robot/gccDebug/tinystr.o d:/Projects/robot/source/robot/gccDebug/tinyxml.o d:/Projects/robot/source/robot/gccDebug/tinyxmlerror.o d:/Projects/robot/source/robot/gccDebug/tinyxmlparser.o d:/Projects/robot/source/robot/gccDebug/level.o d:/Projects/robot/source/robot/gccDebug/level_pack.o d:/Projects/robot/source/robot/gccDebug/level_packs.o d:/Projects/robot/source/robot/gccDebug/level_square.o d:/Projects/robot/source/robot/gccDebug/board_square.o d:/Projects/robot/source/robot/gccDebug/board.o d:/Projects/robot/source/robot/gccDebug/button.o d:/Projects/robot/source/robot/gccDebug/button_bar.o d:/Projects/robot/source/robot/gccDebug/command_bar.o d:/Projects/robot/source/robot/gccDebug/command_bar_button.o d:/Projects/robot/source/robot/gccDebug/head_up_display.o d:/Projects/robot/source/robot/gccDebug/label.o d:/Projects/robot/source/robot/gccDebug/menu_item.o d:/Projects/robot/source/robot/gccDebug/robot.o d:/Projects/robot/source/robot/gccDebug/board_rotation_arrow.o d:/Projects/robot/source/robot/gccDebug/standard_background.o d:/Projects/robot/source/robot/gccDebug/error_state.o d:/Projects/robot/source/robot/gccDebug/menu_state.o d:/Projects/robot/source/robot/gccDebug/play_state.o  $(Debug_Win32_Library_Path) $(Debug_Win32_Libraries) -Wl,-rpath,./ -o d:/Projects/robot/source/gccDebug/robot.exe

# Compiles file stdafx.h as the precompiled header stdafx.h.gch for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/stdafx.d
d:/Projects/robot/source/robot/gccDebug/stdafx.h.gch: stdafx.h
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c stdafx.h $(Debug_Win32_Include_Path) -o stdafx.h.gch

# Compiles file main.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/main.d
d:/Projects/robot/source/robot/gccDebug/main.o: main.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c main.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/main.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM main.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/main.d

# Compiles file my_game.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/my_game.d
d:/Projects/robot/source/robot/gccDebug/my_game.o: my_game.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c my_game.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/my_game.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM my_game.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/my_game.d

# Compiles file robot_program.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/robot_program.d
d:/Projects/robot/source/robot/gccDebug/robot_program.o: robot_program.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c robot_program.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/robot_program.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM robot_program.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/robot_program.d

# Compiles file settings.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/settings.d
d:/Projects/robot/source/robot/gccDebug/settings.o: settings.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c settings.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/settings.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM settings.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/settings.d

# Compiles file theme.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/theme.d
d:/Projects/robot/source/robot/gccDebug/theme.o: theme.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c theme.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/theme.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM theme.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/theme.d

# Compiles file base_game_theme.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/base_game_theme.d
d:/Projects/robot/source/robot/gccDebug/base_game_theme.o: base_game_theme.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c base_game_theme.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/base_game_theme.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM base_game_theme.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/base_game_theme.d

# Compiles file color.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/color.d
d:/Projects/robot/source/robot/gccDebug/color.o: color.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c color.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/color.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM color.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/color.d

# Compiles file font_manager.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/font_manager.d
d:/Projects/robot/source/robot/gccDebug/font_manager.o: font_manager.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c font_manager.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/font_manager.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM font_manager.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/font_manager.d

# Compiles file font_manager_font.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/font_manager_font.d
d:/Projects/robot/source/robot/gccDebug/font_manager_font.o: font_manager_font.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c font_manager_font.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/font_manager_font.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM font_manager_font.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/font_manager_font.d

# Compiles file game.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/game.d
d:/Projects/robot/source/robot/gccDebug/game.o: game.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c game.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/game.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM game.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/game.d

# Compiles file exception.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/exception.d
d:/Projects/robot/source/robot/gccDebug/exception.o: exception.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c exception.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/exception.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM exception.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/exception.d

# Compiles file functions.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/functions.d
d:/Projects/robot/source/robot/gccDebug/functions.o: functions.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c functions.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/functions.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM functions.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/functions.d

# Compiles file game_font.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/game_font.d
d:/Projects/robot/source/robot/gccDebug/game_font.o: game_font.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c game_font.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/game_font.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM game_font.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/game_font.d

# Compiles file game_objects.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/game_objects.d
d:/Projects/robot/source/robot/gccDebug/game_objects.o: game_objects.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c game_objects.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/game_objects.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM game_objects.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/game_objects.d

# Compiles file input_handler.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/input_handler.d
d:/Projects/robot/source/robot/gccDebug/input_handler.o: input_handler.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c input_handler.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/input_handler.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM input_handler.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/input_handler.d

# Compiles file mouse_data.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/mouse_data.d
d:/Projects/robot/source/robot/gccDebug/mouse_data.o: mouse_data.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c mouse_data.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/mouse_data.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM mouse_data.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/mouse_data.d

# Compiles file game_object.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/game_object.d
d:/Projects/robot/source/robot/gccDebug/game_object.o: game_object.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c game_object.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/game_object.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM game_object.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/game_object.d

# Compiles file image_manager.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/image_manager.d
d:/Projects/robot/source/robot/gccDebug/image_manager.o: image_manager.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c image_manager.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/image_manager.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM image_manager.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/image_manager.d

# Compiles file image.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/image.d
d:/Projects/robot/source/robot/gccDebug/image.o: image.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c image.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/image.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM image.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/image.d

# Compiles file settings_base.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/settings_base.d
d:/Projects/robot/source/robot/gccDebug/settings_base.o: settings_base.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c settings_base.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/settings_base.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM settings_base.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/settings_base.d

# Compiles file stdafx.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/stdafx.d
d:/Projects/robot/source/robot/gccDebug/stdafx.o: stdafx.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c stdafx.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/stdafx.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM stdafx.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/stdafx.d

# Compiles file theme_object_image.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/theme_object_image.d
d:/Projects/robot/source/robot/gccDebug/theme_object_image.o: theme_object_image.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c theme_object_image.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/theme_object_image.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM theme_object_image.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/theme_object_image.d

# Compiles file split_path.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/split_path.d
d:/Projects/robot/source/robot/gccDebug/split_path.o: split_path.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c split_path.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/split_path.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM split_path.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/split_path.d

# Compiles file state.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/state.d
d:/Projects/robot/source/robot/gccDebug/state.o: state.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c state.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/state.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM state.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/state.d

# Compiles file state_manager.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/state_manager.d
d:/Projects/robot/source/robot/gccDebug/state_manager.o: state_manager.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c state_manager.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/state_manager.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM state_manager.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/state_manager.d

# Compiles file theme_object.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/theme_object.d
d:/Projects/robot/source/robot/gccDebug/theme_object.o: theme_object.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c theme_object.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/theme_object.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM theme_object.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/theme_object.d

# Compiles file types.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/types.d
d:/Projects/robot/source/robot/gccDebug/types.o: types.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c types.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/types.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM types.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/types.d

# Compiles file vector_2d.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/vector_2d.d
d:/Projects/robot/source/robot/gccDebug/vector_2d.o: vector_2d.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c vector_2d.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/vector_2d.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM vector_2d.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/vector_2d.d

# Compiles file window.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/window.d
d:/Projects/robot/source/robot/gccDebug/window.o: window.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c window.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/window.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM window.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/window.d

# Compiles file format.cc for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/format.d
d:/Projects/robot/source/robot/gccDebug/format.o: format.cc
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c format.cc $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/format.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM format.cc $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/format.d

# Compiles file tinystr.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/tinystr.d
d:/Projects/robot/source/robot/gccDebug/tinystr.o: tinystr.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c tinystr.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/tinystr.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM tinystr.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/tinystr.d

# Compiles file tinyxml.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/tinyxml.d
d:/Projects/robot/source/robot/gccDebug/tinyxml.o: tinyxml.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c tinyxml.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/tinyxml.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM tinyxml.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/tinyxml.d

# Compiles file tinyxmlerror.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/tinyxmlerror.d
d:/Projects/robot/source/robot/gccDebug/tinyxmlerror.o: tinyxmlerror.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c tinyxmlerror.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/tinyxmlerror.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM tinyxmlerror.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/tinyxmlerror.d

# Compiles file tinyxmlparser.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/tinyxmlparser.d
d:/Projects/robot/source/robot/gccDebug/tinyxmlparser.o: tinyxmlparser.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c tinyxmlparser.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/tinyxmlparser.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM tinyxmlparser.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/tinyxmlparser.d

# Compiles file level.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/level.d
d:/Projects/robot/source/robot/gccDebug/level.o: level.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c level.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/level.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM level.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/level.d

# Compiles file level_pack.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/level_pack.d
d:/Projects/robot/source/robot/gccDebug/level_pack.o: level_pack.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c level_pack.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/level_pack.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM level_pack.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/level_pack.d

# Compiles file level_packs.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/level_packs.d
d:/Projects/robot/source/robot/gccDebug/level_packs.o: level_packs.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c level_packs.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/level_packs.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM level_packs.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/level_packs.d

# Compiles file level_square.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/level_square.d
d:/Projects/robot/source/robot/gccDebug/level_square.o: level_square.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c level_square.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/level_square.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM level_square.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/level_square.d

# Compiles file board_square.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/board_square.d
d:/Projects/robot/source/robot/gccDebug/board_square.o: board_square.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c board_square.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/board_square.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM board_square.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/board_square.d

# Compiles file board.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/board.d
d:/Projects/robot/source/robot/gccDebug/board.o: board.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c board.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/board.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM board.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/board.d

# Compiles file button.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/button.d
d:/Projects/robot/source/robot/gccDebug/button.o: button.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c button.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/button.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM button.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/button.d

# Compiles file button_bar.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/button_bar.d
d:/Projects/robot/source/robot/gccDebug/button_bar.o: button_bar.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c button_bar.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/button_bar.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM button_bar.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/button_bar.d

# Compiles file command_bar.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/command_bar.d
d:/Projects/robot/source/robot/gccDebug/command_bar.o: command_bar.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c command_bar.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/command_bar.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM command_bar.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/command_bar.d

# Compiles file command_bar_button.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/command_bar_button.d
d:/Projects/robot/source/robot/gccDebug/command_bar_button.o: command_bar_button.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c command_bar_button.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/command_bar_button.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM command_bar_button.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/command_bar_button.d

# Compiles file head_up_display.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/head_up_display.d
d:/Projects/robot/source/robot/gccDebug/head_up_display.o: head_up_display.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c head_up_display.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/head_up_display.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM head_up_display.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/head_up_display.d

# Compiles file label.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/label.d
d:/Projects/robot/source/robot/gccDebug/label.o: label.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c label.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/label.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM label.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/label.d

# Compiles file menu_item.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/menu_item.d
d:/Projects/robot/source/robot/gccDebug/menu_item.o: menu_item.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c menu_item.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/menu_item.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM menu_item.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/menu_item.d

# Compiles file robot.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/robot.d
d:/Projects/robot/source/robot/gccDebug/robot.o: robot.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c robot.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/robot.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM robot.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/robot.d

# Compiles file board_rotation_arrow.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/board_rotation_arrow.d
d:/Projects/robot/source/robot/gccDebug/board_rotation_arrow.o: board_rotation_arrow.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c board_rotation_arrow.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/board_rotation_arrow.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM board_rotation_arrow.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/board_rotation_arrow.d

# Compiles file standard_background.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/standard_background.d
d:/Projects/robot/source/robot/gccDebug/standard_background.o: standard_background.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c standard_background.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/standard_background.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM standard_background.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/standard_background.d

# Compiles file error_state.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/error_state.d
d:/Projects/robot/source/robot/gccDebug/error_state.o: error_state.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c error_state.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/error_state.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM error_state.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/error_state.d

# Compiles file menu_state.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/menu_state.d
d:/Projects/robot/source/robot/gccDebug/menu_state.o: menu_state.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c menu_state.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/menu_state.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM menu_state.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/menu_state.d

# Compiles file play_state.cpp for the Debug_Win32 configuration...
-include d:/Projects/robot/source/robot/gccDebug/play_state.d
d:/Projects/robot/source/robot/gccDebug/play_state.o: play_state.cpp
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -c play_state.cpp $(Debug_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccDebug/play_state.o
	$(CPP_COMPILER) $(Debug_Win32_Preprocessor_Definitions) $(Debug_Win32_Compiler_Flags) -MM play_state.cpp $(Debug_Win32_Include_Path) > d:/Projects/robot/source/robot/gccDebug/play_state.d

# Builds the Release_Win32 configuration...
.PHONY: Release_Win32
Release_Win32: create_folders d:/Projects/robot/source/robot/gccRelease/stdafx.h.gch d:/Projects/robot/source/robot/gccRelease/main.o d:/Projects/robot/source/robot/gccRelease/my_game.o d:/Projects/robot/source/robot/gccRelease/robot_program.o d:/Projects/robot/source/robot/gccRelease/settings.o d:/Projects/robot/source/robot/gccRelease/theme.o d:/Projects/robot/source/robot/gccRelease/base_game_theme.o d:/Projects/robot/source/robot/gccRelease/color.o d:/Projects/robot/source/robot/gccRelease/font_manager.o d:/Projects/robot/source/robot/gccRelease/font_manager_font.o d:/Projects/robot/source/robot/gccRelease/game.o d:/Projects/robot/source/robot/gccRelease/exception.o d:/Projects/robot/source/robot/gccRelease/functions.o d:/Projects/robot/source/robot/gccRelease/game_font.o d:/Projects/robot/source/robot/gccRelease/game_objects.o d:/Projects/robot/source/robot/gccRelease/input_handler.o d:/Projects/robot/source/robot/gccRelease/mouse_data.o d:/Projects/robot/source/robot/gccRelease/game_object.o d:/Projects/robot/source/robot/gccRelease/image_manager.o d:/Projects/robot/source/robot/gccRelease/image.o d:/Projects/robot/source/robot/gccRelease/settings_base.o d:/Projects/robot/source/robot/gccRelease/stdafx.o d:/Projects/robot/source/robot/gccRelease/theme_object_image.o d:/Projects/robot/source/robot/gccRelease/split_path.o d:/Projects/robot/source/robot/gccRelease/state.o d:/Projects/robot/source/robot/gccRelease/state_manager.o d:/Projects/robot/source/robot/gccRelease/theme_object.o d:/Projects/robot/source/robot/gccRelease/types.o d:/Projects/robot/source/robot/gccRelease/vector_2d.o d:/Projects/robot/source/robot/gccRelease/window.o d:/Projects/robot/source/robot/gccRelease/format.o d:/Projects/robot/source/robot/gccRelease/tinystr.o d:/Projects/robot/source/robot/gccRelease/tinyxml.o d:/Projects/robot/source/robot/gccRelease/tinyxmlerror.o d:/Projects/robot/source/robot/gccRelease/tinyxmlparser.o d:/Projects/robot/source/robot/gccRelease/level.o d:/Projects/robot/source/robot/gccRelease/level_pack.o d:/Projects/robot/source/robot/gccRelease/level_packs.o d:/Projects/robot/source/robot/gccRelease/level_square.o d:/Projects/robot/source/robot/gccRelease/board_square.o d:/Projects/robot/source/robot/gccRelease/board.o d:/Projects/robot/source/robot/gccRelease/button.o d:/Projects/robot/source/robot/gccRelease/button_bar.o d:/Projects/robot/source/robot/gccRelease/command_bar.o d:/Projects/robot/source/robot/gccRelease/command_bar_button.o d:/Projects/robot/source/robot/gccRelease/head_up_display.o d:/Projects/robot/source/robot/gccRelease/label.o d:/Projects/robot/source/robot/gccRelease/menu_item.o d:/Projects/robot/source/robot/gccRelease/robot.o d:/Projects/robot/source/robot/gccRelease/board_rotation_arrow.o d:/Projects/robot/source/robot/gccRelease/standard_background.o d:/Projects/robot/source/robot/gccRelease/error_state.o d:/Projects/robot/source/robot/gccRelease/menu_state.o d:/Projects/robot/source/robot/gccRelease/play_state.o 
	g++ d:/Projects/robot/source/robot/gccRelease/main.o d:/Projects/robot/source/robot/gccRelease/my_game.o d:/Projects/robot/source/robot/gccRelease/robot_program.o d:/Projects/robot/source/robot/gccRelease/settings.o d:/Projects/robot/source/robot/gccRelease/theme.o d:/Projects/robot/source/robot/gccRelease/base_game_theme.o d:/Projects/robot/source/robot/gccRelease/color.o d:/Projects/robot/source/robot/gccRelease/font_manager.o d:/Projects/robot/source/robot/gccRelease/font_manager_font.o d:/Projects/robot/source/robot/gccRelease/game.o d:/Projects/robot/source/robot/gccRelease/exception.o d:/Projects/robot/source/robot/gccRelease/functions.o d:/Projects/robot/source/robot/gccRelease/game_font.o d:/Projects/robot/source/robot/gccRelease/game_objects.o d:/Projects/robot/source/robot/gccRelease/input_handler.o d:/Projects/robot/source/robot/gccRelease/mouse_data.o d:/Projects/robot/source/robot/gccRelease/game_object.o d:/Projects/robot/source/robot/gccRelease/image_manager.o d:/Projects/robot/source/robot/gccRelease/image.o d:/Projects/robot/source/robot/gccRelease/settings_base.o d:/Projects/robot/source/robot/gccRelease/stdafx.o d:/Projects/robot/source/robot/gccRelease/theme_object_image.o d:/Projects/robot/source/robot/gccRelease/split_path.o d:/Projects/robot/source/robot/gccRelease/state.o d:/Projects/robot/source/robot/gccRelease/state_manager.o d:/Projects/robot/source/robot/gccRelease/theme_object.o d:/Projects/robot/source/robot/gccRelease/types.o d:/Projects/robot/source/robot/gccRelease/vector_2d.o d:/Projects/robot/source/robot/gccRelease/window.o d:/Projects/robot/source/robot/gccRelease/format.o d:/Projects/robot/source/robot/gccRelease/tinystr.o d:/Projects/robot/source/robot/gccRelease/tinyxml.o d:/Projects/robot/source/robot/gccRelease/tinyxmlerror.o d:/Projects/robot/source/robot/gccRelease/tinyxmlparser.o d:/Projects/robot/source/robot/gccRelease/level.o d:/Projects/robot/source/robot/gccRelease/level_pack.o d:/Projects/robot/source/robot/gccRelease/level_packs.o d:/Projects/robot/source/robot/gccRelease/level_square.o d:/Projects/robot/source/robot/gccRelease/board_square.o d:/Projects/robot/source/robot/gccRelease/board.o d:/Projects/robot/source/robot/gccRelease/button.o d:/Projects/robot/source/robot/gccRelease/button_bar.o d:/Projects/robot/source/robot/gccRelease/command_bar.o d:/Projects/robot/source/robot/gccRelease/command_bar_button.o d:/Projects/robot/source/robot/gccRelease/head_up_display.o d:/Projects/robot/source/robot/gccRelease/label.o d:/Projects/robot/source/robot/gccRelease/menu_item.o d:/Projects/robot/source/robot/gccRelease/robot.o d:/Projects/robot/source/robot/gccRelease/board_rotation_arrow.o d:/Projects/robot/source/robot/gccRelease/standard_background.o d:/Projects/robot/source/robot/gccRelease/error_state.o d:/Projects/robot/source/robot/gccRelease/menu_state.o d:/Projects/robot/source/robot/gccRelease/play_state.o  $(Release_Win32_Library_Path) $(Release_Win32_Libraries) -Wl,-rpath,./ -o d:/Projects/robot/source/gccRelease/robot.exe

# Compiles file stdafx.h as the precompiled header stdafx.h.gch for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/stdafx.d
d:/Projects/robot/source/robot/gccRelease/stdafx.h.gch: stdafx.h
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c stdafx.h $(Release_Win32_Include_Path) -o stdafx.h.gch

# Compiles file main.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/main.d
d:/Projects/robot/source/robot/gccRelease/main.o: main.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c main.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/main.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM main.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/main.d

# Compiles file my_game.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/my_game.d
d:/Projects/robot/source/robot/gccRelease/my_game.o: my_game.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c my_game.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/my_game.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM my_game.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/my_game.d

# Compiles file robot_program.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/robot_program.d
d:/Projects/robot/source/robot/gccRelease/robot_program.o: robot_program.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c robot_program.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/robot_program.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM robot_program.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/robot_program.d

# Compiles file settings.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/settings.d
d:/Projects/robot/source/robot/gccRelease/settings.o: settings.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c settings.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/settings.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM settings.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/settings.d

# Compiles file theme.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/theme.d
d:/Projects/robot/source/robot/gccRelease/theme.o: theme.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c theme.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/theme.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM theme.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/theme.d

# Compiles file base_game_theme.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/base_game_theme.d
d:/Projects/robot/source/robot/gccRelease/base_game_theme.o: base_game_theme.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c base_game_theme.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/base_game_theme.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM base_game_theme.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/base_game_theme.d

# Compiles file color.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/color.d
d:/Projects/robot/source/robot/gccRelease/color.o: color.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c color.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/color.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM color.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/color.d

# Compiles file font_manager.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/font_manager.d
d:/Projects/robot/source/robot/gccRelease/font_manager.o: font_manager.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c font_manager.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/font_manager.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM font_manager.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/font_manager.d

# Compiles file font_manager_font.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/font_manager_font.d
d:/Projects/robot/source/robot/gccRelease/font_manager_font.o: font_manager_font.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c font_manager_font.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/font_manager_font.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM font_manager_font.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/font_manager_font.d

# Compiles file game.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/game.d
d:/Projects/robot/source/robot/gccRelease/game.o: game.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c game.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/game.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM game.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/game.d

# Compiles file exception.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/exception.d
d:/Projects/robot/source/robot/gccRelease/exception.o: exception.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c exception.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/exception.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM exception.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/exception.d

# Compiles file functions.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/functions.d
d:/Projects/robot/source/robot/gccRelease/functions.o: functions.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c functions.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/functions.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM functions.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/functions.d

# Compiles file game_font.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/game_font.d
d:/Projects/robot/source/robot/gccRelease/game_font.o: game_font.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c game_font.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/game_font.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM game_font.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/game_font.d

# Compiles file game_objects.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/game_objects.d
d:/Projects/robot/source/robot/gccRelease/game_objects.o: game_objects.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c game_objects.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/game_objects.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM game_objects.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/game_objects.d

# Compiles file input_handler.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/input_handler.d
d:/Projects/robot/source/robot/gccRelease/input_handler.o: input_handler.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c input_handler.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/input_handler.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM input_handler.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/input_handler.d

# Compiles file mouse_data.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/mouse_data.d
d:/Projects/robot/source/robot/gccRelease/mouse_data.o: mouse_data.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c mouse_data.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/mouse_data.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM mouse_data.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/mouse_data.d

# Compiles file game_object.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/game_object.d
d:/Projects/robot/source/robot/gccRelease/game_object.o: game_object.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c game_object.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/game_object.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM game_object.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/game_object.d

# Compiles file image_manager.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/image_manager.d
d:/Projects/robot/source/robot/gccRelease/image_manager.o: image_manager.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c image_manager.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/image_manager.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM image_manager.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/image_manager.d

# Compiles file image.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/image.d
d:/Projects/robot/source/robot/gccRelease/image.o: image.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c image.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/image.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM image.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/image.d

# Compiles file settings_base.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/settings_base.d
d:/Projects/robot/source/robot/gccRelease/settings_base.o: settings_base.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c settings_base.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/settings_base.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM settings_base.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/settings_base.d

# Compiles file stdafx.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/stdafx.d
d:/Projects/robot/source/robot/gccRelease/stdafx.o: stdafx.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c stdafx.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/stdafx.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM stdafx.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/stdafx.d

# Compiles file theme_object_image.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/theme_object_image.d
d:/Projects/robot/source/robot/gccRelease/theme_object_image.o: theme_object_image.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c theme_object_image.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/theme_object_image.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM theme_object_image.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/theme_object_image.d

# Compiles file split_path.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/split_path.d
d:/Projects/robot/source/robot/gccRelease/split_path.o: split_path.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c split_path.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/split_path.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM split_path.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/split_path.d

# Compiles file state.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/state.d
d:/Projects/robot/source/robot/gccRelease/state.o: state.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c state.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/state.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM state.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/state.d

# Compiles file state_manager.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/state_manager.d
d:/Projects/robot/source/robot/gccRelease/state_manager.o: state_manager.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c state_manager.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/state_manager.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM state_manager.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/state_manager.d

# Compiles file theme_object.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/theme_object.d
d:/Projects/robot/source/robot/gccRelease/theme_object.o: theme_object.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c theme_object.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/theme_object.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM theme_object.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/theme_object.d

# Compiles file types.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/types.d
d:/Projects/robot/source/robot/gccRelease/types.o: types.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c types.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/types.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM types.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/types.d

# Compiles file vector_2d.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/vector_2d.d
d:/Projects/robot/source/robot/gccRelease/vector_2d.o: vector_2d.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c vector_2d.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/vector_2d.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM vector_2d.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/vector_2d.d

# Compiles file window.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/window.d
d:/Projects/robot/source/robot/gccRelease/window.o: window.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c window.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/window.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM window.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/window.d

# Compiles file format.cc for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/format.d
d:/Projects/robot/source/robot/gccRelease/format.o: format.cc
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c format.cc $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/format.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM format.cc $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/format.d

# Compiles file tinystr.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/tinystr.d
d:/Projects/robot/source/robot/gccRelease/tinystr.o: tinystr.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c tinystr.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/tinystr.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM tinystr.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/tinystr.d

# Compiles file tinyxml.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/tinyxml.d
d:/Projects/robot/source/robot/gccRelease/tinyxml.o: tinyxml.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c tinyxml.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/tinyxml.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM tinyxml.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/tinyxml.d

# Compiles file tinyxmlerror.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/tinyxmlerror.d
d:/Projects/robot/source/robot/gccRelease/tinyxmlerror.o: tinyxmlerror.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c tinyxmlerror.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/tinyxmlerror.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM tinyxmlerror.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/tinyxmlerror.d

# Compiles file tinyxmlparser.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/tinyxmlparser.d
d:/Projects/robot/source/robot/gccRelease/tinyxmlparser.o: tinyxmlparser.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c tinyxmlparser.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/tinyxmlparser.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM tinyxmlparser.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/tinyxmlparser.d

# Compiles file level.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/level.d
d:/Projects/robot/source/robot/gccRelease/level.o: level.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c level.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/level.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM level.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/level.d

# Compiles file level_pack.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/level_pack.d
d:/Projects/robot/source/robot/gccRelease/level_pack.o: level_pack.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c level_pack.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/level_pack.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM level_pack.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/level_pack.d

# Compiles file level_packs.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/level_packs.d
d:/Projects/robot/source/robot/gccRelease/level_packs.o: level_packs.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c level_packs.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/level_packs.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM level_packs.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/level_packs.d

# Compiles file level_square.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/level_square.d
d:/Projects/robot/source/robot/gccRelease/level_square.o: level_square.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c level_square.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/level_square.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM level_square.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/level_square.d

# Compiles file board_square.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/board_square.d
d:/Projects/robot/source/robot/gccRelease/board_square.o: board_square.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c board_square.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/board_square.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM board_square.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/board_square.d

# Compiles file board.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/board.d
d:/Projects/robot/source/robot/gccRelease/board.o: board.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c board.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/board.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM board.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/board.d

# Compiles file button.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/button.d
d:/Projects/robot/source/robot/gccRelease/button.o: button.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c button.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/button.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM button.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/button.d

# Compiles file button_bar.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/button_bar.d
d:/Projects/robot/source/robot/gccRelease/button_bar.o: button_bar.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c button_bar.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/button_bar.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM button_bar.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/button_bar.d

# Compiles file command_bar.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/command_bar.d
d:/Projects/robot/source/robot/gccRelease/command_bar.o: command_bar.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c command_bar.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/command_bar.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM command_bar.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/command_bar.d

# Compiles file command_bar_button.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/command_bar_button.d
d:/Projects/robot/source/robot/gccRelease/command_bar_button.o: command_bar_button.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c command_bar_button.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/command_bar_button.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM command_bar_button.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/command_bar_button.d

# Compiles file head_up_display.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/head_up_display.d
d:/Projects/robot/source/robot/gccRelease/head_up_display.o: head_up_display.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c head_up_display.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/head_up_display.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM head_up_display.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/head_up_display.d

# Compiles file label.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/label.d
d:/Projects/robot/source/robot/gccRelease/label.o: label.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c label.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/label.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM label.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/label.d

# Compiles file menu_item.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/menu_item.d
d:/Projects/robot/source/robot/gccRelease/menu_item.o: menu_item.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c menu_item.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/menu_item.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM menu_item.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/menu_item.d

# Compiles file robot.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/robot.d
d:/Projects/robot/source/robot/gccRelease/robot.o: robot.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c robot.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/robot.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM robot.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/robot.d

# Compiles file board_rotation_arrow.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/board_rotation_arrow.d
d:/Projects/robot/source/robot/gccRelease/board_rotation_arrow.o: board_rotation_arrow.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c board_rotation_arrow.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/board_rotation_arrow.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM board_rotation_arrow.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/board_rotation_arrow.d

# Compiles file standard_background.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/standard_background.d
d:/Projects/robot/source/robot/gccRelease/standard_background.o: standard_background.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c standard_background.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/standard_background.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM standard_background.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/standard_background.d

# Compiles file error_state.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/error_state.d
d:/Projects/robot/source/robot/gccRelease/error_state.o: error_state.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c error_state.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/error_state.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM error_state.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/error_state.d

# Compiles file menu_state.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/menu_state.d
d:/Projects/robot/source/robot/gccRelease/menu_state.o: menu_state.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c menu_state.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/menu_state.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM menu_state.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/menu_state.d

# Compiles file play_state.cpp for the Release_Win32 configuration...
-include d:/Projects/robot/source/robot/gccRelease/play_state.d
d:/Projects/robot/source/robot/gccRelease/play_state.o: play_state.cpp
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -c play_state.cpp $(Release_Win32_Include_Path) -o d:/Projects/robot/source/robot/gccRelease/play_state.o
	$(CPP_COMPILER) $(Release_Win32_Preprocessor_Definitions) $(Release_Win32_Compiler_Flags) -MM play_state.cpp $(Release_Win32_Include_Path) > d:/Projects/robot/source/robot/gccRelease/play_state.d

# Creates the intermediate and output folders for each configuration...
.PHONY: create_folders
create_folders:
	mkdir -p d:/Projects/robot/source/robot/gccDebug/source
	mkdir -p d:/Projects/robot/source/gccDebug
	mkdir -p d:/Projects/robot/source/robot/gccRelease/source
	mkdir -p d:/Projects/robot/source/gccRelease

# Cleans intermediate and output files (objects, libraries, executables)...
.PHONY: clean
clean:
	rm -f d:/Projects/robot/source/robot/gccDebug/*.o
	rm -f d:/Projects/robot/source/robot/gccDebug/*.d
	rm -f d:/Projects/robot/source/gccDebug/*.a
	rm -f d:/Projects/robot/source/gccDebug/*.so
	rm -f d:/Projects/robot/source/gccDebug/*.dll
	rm -f d:/Projects/robot/source/gccDebug/*.exe
	rm -f d:/Projects/robot/source/robot/gccRelease/*.o
	rm -f d:/Projects/robot/source/robot/gccRelease/*.d
	rm -f d:/Projects/robot/source/gccRelease/*.a
	rm -f d:/Projects/robot/source/gccRelease/*.so
	rm -f d:/Projects/robot/source/gccRelease/*.dll
	rm -f d:/Projects/robot/source/gccRelease/*.exe

