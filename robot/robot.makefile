# Compiler flags...
CPP_COMPILER = g++
C_COMPILER = gcc

# Include paths...
Debug_Include_Path=-I"./" -I"~/include" -I"/usr/include" -I"/usr/local/include/SDL2" 
Release_Include_Path=-I"./" -I"~/include" -I"/usr/include" -I"/usr/local/include/SDL2" 

# Library paths...
Debug_Library_Path=-L"./" -L"./lib" -L"~/lib" -L"/lib" -L"/usr/lib" -L"/usr/local/lib" -L"/usr/lib/arm-linux-gnueabihf" 
Release_Library_Path=-L"./" -L"./lib" -L"~/lib" -L"/lib" -L"/usr/lib" -L"/usr/local/lib" -L"/usr/lib/arm-linux-gnueabihf" 

# Additional libraries...
Debug_Libraries=-Wl,--start-group -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf  -Wl,--end-group
Release_Libraries=-Wl,--start-group -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf  -Wl,--end-group

# Preprocessor definitions...
Debug_Preprocessor_Definitions=-D GCC_BUILD 
Release_Preprocessor_Definitions=-D GCC_BUILD 

# Implictly linked object files...
Debug_Implicitly_Linked_Objects=
Release_Implicitly_Linked_Objects=

# Compiler flags...
Debug_Compiler_Flags=-O0 -g -std=c++11 
Release_Compiler_Flags=-O2 -std=c++11 

# Builds all configurations for this project...
.PHONY: build_all_configurations
build_all_configurations: Debug Release 

# Builds the Debug configuration...
.PHONY: Debug
Debug: create_folders gccDebug/stdafx.h.gch gccDebug/main.o gccDebug/menu_play_state.o gccDebug/my_game.o gccDebug/robot_program.o gccDebug/settings.o gccDebug/theme.o gccDebug/base_game_theme.o gccDebug/color.o gccDebug/font_manager.o gccDebug/font_manager_font.o gccDebug/game.o gccDebug/exception.o gccDebug/functions.o gccDebug/game_font.o gccDebug/game_objects.o gccDebug/input_handler.o gccDebug/mouse_data.o gccDebug/game_object.o gccDebug/image_manager.o gccDebug/image.o gccDebug/settings_base.o gccDebug/stdafx.o gccDebug/theme_object_image.o gccDebug/split_path.o gccDebug/state.o gccDebug/state_manager.o gccDebug/theme_object.o gccDebug/types.o gccDebug/vector_2d.o gccDebug/window.o gccDebug/format.o gccDebug/tinystr.o gccDebug/tinyxml.o gccDebug/tinyxmlerror.o gccDebug/tinyxmlparser.o gccDebug/level.o gccDebug/level_pack.o gccDebug/level_packs.o gccDebug/level_square.o gccDebug/board_square.o gccDebug/board.o gccDebug/button.o gccDebug/button_bar.o gccDebug/command_bar.o gccDebug/command_bar_button.o gccDebug/head_up_display.o gccDebug/label.o gccDebug/menu_item.o gccDebug/robot.o gccDebug/board_rotation_arrow.o gccDebug/standard_background.o gccDebug/error_state.o gccDebug/menu_state.o gccDebug/play_state.o 
	g++ gccDebug/main.o gccDebug/menu_play_state.o gccDebug/my_game.o gccDebug/robot_program.o gccDebug/settings.o gccDebug/theme.o gccDebug/base_game_theme.o gccDebug/color.o gccDebug/font_manager.o gccDebug/font_manager_font.o gccDebug/game.o gccDebug/exception.o gccDebug/functions.o gccDebug/game_font.o gccDebug/game_objects.o gccDebug/input_handler.o gccDebug/mouse_data.o gccDebug/game_object.o gccDebug/image_manager.o gccDebug/image.o gccDebug/settings_base.o gccDebug/stdafx.o gccDebug/theme_object_image.o gccDebug/split_path.o gccDebug/state.o gccDebug/state_manager.o gccDebug/theme_object.o gccDebug/types.o gccDebug/vector_2d.o gccDebug/window.o gccDebug/format.o gccDebug/tinystr.o gccDebug/tinyxml.o gccDebug/tinyxmlerror.o gccDebug/tinyxmlparser.o gccDebug/level.o gccDebug/level_pack.o gccDebug/level_packs.o gccDebug/level_square.o gccDebug/board_square.o gccDebug/board.o gccDebug/button.o gccDebug/button_bar.o gccDebug/command_bar.o gccDebug/command_bar_button.o gccDebug/head_up_display.o gccDebug/label.o gccDebug/menu_item.o gccDebug/robot.o gccDebug/board_rotation_arrow.o gccDebug/standard_background.o gccDebug/error_state.o gccDebug/menu_state.o gccDebug/play_state.o  $(Debug_Library_Path) $(Debug_Libraries) -Wl,-rpath,./ -o ../gccDebug/robot.exe

# Compiles file stdafx.h as the precompiled header stdafx.h.gch for the Debug configuration...
-include gccDebug/stdafx.d
gccDebug/stdafx.h.gch: stdafx.h
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c stdafx.h $(Debug_Include_Path) -o stdafx.h.gch

# Compiles file main.cpp for the Debug configuration...
-include gccDebug/main.d
gccDebug/main.o: main.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c main.cpp $(Debug_Include_Path) -o gccDebug/main.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM main.cpp $(Debug_Include_Path) > gccDebug/main.d

# Compiles file menu_play_state.cpp for the Debug configuration...
-include gccDebug/menu_play_state.d
gccDebug/menu_play_state.o: menu_play_state.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c menu_play_state.cpp $(Debug_Include_Path) -o gccDebug/menu_play_state.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM menu_play_state.cpp $(Debug_Include_Path) > gccDebug/menu_play_state.d

# Compiles file my_game.cpp for the Debug configuration...
-include gccDebug/my_game.d
gccDebug/my_game.o: my_game.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c my_game.cpp $(Debug_Include_Path) -o gccDebug/my_game.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM my_game.cpp $(Debug_Include_Path) > gccDebug/my_game.d

# Compiles file robot_program.cpp for the Debug configuration...
-include gccDebug/robot_program.d
gccDebug/robot_program.o: robot_program.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c robot_program.cpp $(Debug_Include_Path) -o gccDebug/robot_program.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM robot_program.cpp $(Debug_Include_Path) > gccDebug/robot_program.d

# Compiles file settings.cpp for the Debug configuration...
-include gccDebug/settings.d
gccDebug/settings.o: settings.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c settings.cpp $(Debug_Include_Path) -o gccDebug/settings.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM settings.cpp $(Debug_Include_Path) > gccDebug/settings.d

# Compiles file theme.cpp for the Debug configuration...
-include gccDebug/theme.d
gccDebug/theme.o: theme.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c theme.cpp $(Debug_Include_Path) -o gccDebug/theme.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM theme.cpp $(Debug_Include_Path) > gccDebug/theme.d

# Compiles file base_game_theme.cpp for the Debug configuration...
-include gccDebug/base_game_theme.d
gccDebug/base_game_theme.o: base_game_theme.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c base_game_theme.cpp $(Debug_Include_Path) -o gccDebug/base_game_theme.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM base_game_theme.cpp $(Debug_Include_Path) > gccDebug/base_game_theme.d

# Compiles file color.cpp for the Debug configuration...
-include gccDebug/color.d
gccDebug/color.o: color.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c color.cpp $(Debug_Include_Path) -o gccDebug/color.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM color.cpp $(Debug_Include_Path) > gccDebug/color.d

# Compiles file font_manager.cpp for the Debug configuration...
-include gccDebug/font_manager.d
gccDebug/font_manager.o: font_manager.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c font_manager.cpp $(Debug_Include_Path) -o gccDebug/font_manager.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM font_manager.cpp $(Debug_Include_Path) > gccDebug/font_manager.d

# Compiles file font_manager_font.cpp for the Debug configuration...
-include gccDebug/font_manager_font.d
gccDebug/font_manager_font.o: font_manager_font.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c font_manager_font.cpp $(Debug_Include_Path) -o gccDebug/font_manager_font.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM font_manager_font.cpp $(Debug_Include_Path) > gccDebug/font_manager_font.d

# Compiles file game.cpp for the Debug configuration...
-include gccDebug/game.d
gccDebug/game.o: game.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c game.cpp $(Debug_Include_Path) -o gccDebug/game.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM game.cpp $(Debug_Include_Path) > gccDebug/game.d

# Compiles file exception.cpp for the Debug configuration...
-include gccDebug/exception.d
gccDebug/exception.o: exception.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c exception.cpp $(Debug_Include_Path) -o gccDebug/exception.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM exception.cpp $(Debug_Include_Path) > gccDebug/exception.d

# Compiles file functions.cpp for the Debug configuration...
-include gccDebug/functions.d
gccDebug/functions.o: functions.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c functions.cpp $(Debug_Include_Path) -o gccDebug/functions.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM functions.cpp $(Debug_Include_Path) > gccDebug/functions.d

# Compiles file game_font.cpp for the Debug configuration...
-include gccDebug/game_font.d
gccDebug/game_font.o: game_font.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c game_font.cpp $(Debug_Include_Path) -o gccDebug/game_font.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM game_font.cpp $(Debug_Include_Path) > gccDebug/game_font.d

# Compiles file game_objects.cpp for the Debug configuration...
-include gccDebug/game_objects.d
gccDebug/game_objects.o: game_objects.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c game_objects.cpp $(Debug_Include_Path) -o gccDebug/game_objects.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM game_objects.cpp $(Debug_Include_Path) > gccDebug/game_objects.d

# Compiles file input_handler.cpp for the Debug configuration...
-include gccDebug/input_handler.d
gccDebug/input_handler.o: input_handler.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c input_handler.cpp $(Debug_Include_Path) -o gccDebug/input_handler.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM input_handler.cpp $(Debug_Include_Path) > gccDebug/input_handler.d

# Compiles file mouse_data.cpp for the Debug configuration...
-include gccDebug/mouse_data.d
gccDebug/mouse_data.o: mouse_data.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c mouse_data.cpp $(Debug_Include_Path) -o gccDebug/mouse_data.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM mouse_data.cpp $(Debug_Include_Path) > gccDebug/mouse_data.d

# Compiles file game_object.cpp for the Debug configuration...
-include gccDebug/game_object.d
gccDebug/game_object.o: game_object.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c game_object.cpp $(Debug_Include_Path) -o gccDebug/game_object.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM game_object.cpp $(Debug_Include_Path) > gccDebug/game_object.d

# Compiles file image_manager.cpp for the Debug configuration...
-include gccDebug/image_manager.d
gccDebug/image_manager.o: image_manager.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c image_manager.cpp $(Debug_Include_Path) -o gccDebug/image_manager.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM image_manager.cpp $(Debug_Include_Path) > gccDebug/image_manager.d

# Compiles file image.cpp for the Debug configuration...
-include gccDebug/image.d
gccDebug/image.o: image.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c image.cpp $(Debug_Include_Path) -o gccDebug/image.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM image.cpp $(Debug_Include_Path) > gccDebug/image.d

# Compiles file settings_base.cpp for the Debug configuration...
-include gccDebug/settings_base.d
gccDebug/settings_base.o: settings_base.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c settings_base.cpp $(Debug_Include_Path) -o gccDebug/settings_base.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM settings_base.cpp $(Debug_Include_Path) > gccDebug/settings_base.d

# Compiles file stdafx.cpp for the Debug configuration...
-include gccDebug/stdafx.d
gccDebug/stdafx.o: stdafx.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c stdafx.cpp $(Debug_Include_Path) -o gccDebug/stdafx.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM stdafx.cpp $(Debug_Include_Path) > gccDebug/stdafx.d

# Compiles file theme_object_image.cpp for the Debug configuration...
-include gccDebug/theme_object_image.d
gccDebug/theme_object_image.o: theme_object_image.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c theme_object_image.cpp $(Debug_Include_Path) -o gccDebug/theme_object_image.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM theme_object_image.cpp $(Debug_Include_Path) > gccDebug/theme_object_image.d

# Compiles file split_path.cpp for the Debug configuration...
-include gccDebug/split_path.d
gccDebug/split_path.o: split_path.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c split_path.cpp $(Debug_Include_Path) -o gccDebug/split_path.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM split_path.cpp $(Debug_Include_Path) > gccDebug/split_path.d

# Compiles file state.cpp for the Debug configuration...
-include gccDebug/state.d
gccDebug/state.o: state.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c state.cpp $(Debug_Include_Path) -o gccDebug/state.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM state.cpp $(Debug_Include_Path) > gccDebug/state.d

# Compiles file state_manager.cpp for the Debug configuration...
-include gccDebug/state_manager.d
gccDebug/state_manager.o: state_manager.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c state_manager.cpp $(Debug_Include_Path) -o gccDebug/state_manager.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM state_manager.cpp $(Debug_Include_Path) > gccDebug/state_manager.d

# Compiles file theme_object.cpp for the Debug configuration...
-include gccDebug/theme_object.d
gccDebug/theme_object.o: theme_object.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c theme_object.cpp $(Debug_Include_Path) -o gccDebug/theme_object.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM theme_object.cpp $(Debug_Include_Path) > gccDebug/theme_object.d

# Compiles file types.cpp for the Debug configuration...
-include gccDebug/types.d
gccDebug/types.o: types.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c types.cpp $(Debug_Include_Path) -o gccDebug/types.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM types.cpp $(Debug_Include_Path) > gccDebug/types.d

# Compiles file vector_2d.cpp for the Debug configuration...
-include gccDebug/vector_2d.d
gccDebug/vector_2d.o: vector_2d.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c vector_2d.cpp $(Debug_Include_Path) -o gccDebug/vector_2d.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM vector_2d.cpp $(Debug_Include_Path) > gccDebug/vector_2d.d

# Compiles file window.cpp for the Debug configuration...
-include gccDebug/window.d
gccDebug/window.o: window.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c window.cpp $(Debug_Include_Path) -o gccDebug/window.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM window.cpp $(Debug_Include_Path) > gccDebug/window.d

# Compiles file format.cc for the Debug configuration...
-include gccDebug/format.d
gccDebug/format.o: format.cc
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c format.cc $(Debug_Include_Path) -o gccDebug/format.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM format.cc $(Debug_Include_Path) > gccDebug/format.d

# Compiles file tinystr.cpp for the Debug configuration...
-include gccDebug/tinystr.d
gccDebug/tinystr.o: tinystr.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c tinystr.cpp $(Debug_Include_Path) -o gccDebug/tinystr.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM tinystr.cpp $(Debug_Include_Path) > gccDebug/tinystr.d

# Compiles file tinyxml.cpp for the Debug configuration...
-include gccDebug/tinyxml.d
gccDebug/tinyxml.o: tinyxml.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c tinyxml.cpp $(Debug_Include_Path) -o gccDebug/tinyxml.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM tinyxml.cpp $(Debug_Include_Path) > gccDebug/tinyxml.d

# Compiles file tinyxmlerror.cpp for the Debug configuration...
-include gccDebug/tinyxmlerror.d
gccDebug/tinyxmlerror.o: tinyxmlerror.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c tinyxmlerror.cpp $(Debug_Include_Path) -o gccDebug/tinyxmlerror.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM tinyxmlerror.cpp $(Debug_Include_Path) > gccDebug/tinyxmlerror.d

# Compiles file tinyxmlparser.cpp for the Debug configuration...
-include gccDebug/tinyxmlparser.d
gccDebug/tinyxmlparser.o: tinyxmlparser.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c tinyxmlparser.cpp $(Debug_Include_Path) -o gccDebug/tinyxmlparser.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM tinyxmlparser.cpp $(Debug_Include_Path) > gccDebug/tinyxmlparser.d

# Compiles file level.cpp for the Debug configuration...
-include gccDebug/level.d
gccDebug/level.o: level.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c level.cpp $(Debug_Include_Path) -o gccDebug/level.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM level.cpp $(Debug_Include_Path) > gccDebug/level.d

# Compiles file level_pack.cpp for the Debug configuration...
-include gccDebug/level_pack.d
gccDebug/level_pack.o: level_pack.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c level_pack.cpp $(Debug_Include_Path) -o gccDebug/level_pack.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM level_pack.cpp $(Debug_Include_Path) > gccDebug/level_pack.d

# Compiles file level_packs.cpp for the Debug configuration...
-include gccDebug/level_packs.d
gccDebug/level_packs.o: level_packs.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c level_packs.cpp $(Debug_Include_Path) -o gccDebug/level_packs.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM level_packs.cpp $(Debug_Include_Path) > gccDebug/level_packs.d

# Compiles file level_square.cpp for the Debug configuration...
-include gccDebug/level_square.d
gccDebug/level_square.o: level_square.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c level_square.cpp $(Debug_Include_Path) -o gccDebug/level_square.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM level_square.cpp $(Debug_Include_Path) > gccDebug/level_square.d

# Compiles file board_square.cpp for the Debug configuration...
-include gccDebug/board_square.d
gccDebug/board_square.o: board_square.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c board_square.cpp $(Debug_Include_Path) -o gccDebug/board_square.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM board_square.cpp $(Debug_Include_Path) > gccDebug/board_square.d

# Compiles file board.cpp for the Debug configuration...
-include gccDebug/board.d
gccDebug/board.o: board.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c board.cpp $(Debug_Include_Path) -o gccDebug/board.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM board.cpp $(Debug_Include_Path) > gccDebug/board.d

# Compiles file button.cpp for the Debug configuration...
-include gccDebug/button.d
gccDebug/button.o: button.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c button.cpp $(Debug_Include_Path) -o gccDebug/button.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM button.cpp $(Debug_Include_Path) > gccDebug/button.d

# Compiles file button_bar.cpp for the Debug configuration...
-include gccDebug/button_bar.d
gccDebug/button_bar.o: button_bar.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c button_bar.cpp $(Debug_Include_Path) -o gccDebug/button_bar.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM button_bar.cpp $(Debug_Include_Path) > gccDebug/button_bar.d

# Compiles file command_bar.cpp for the Debug configuration...
-include gccDebug/command_bar.d
gccDebug/command_bar.o: command_bar.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c command_bar.cpp $(Debug_Include_Path) -o gccDebug/command_bar.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM command_bar.cpp $(Debug_Include_Path) > gccDebug/command_bar.d

# Compiles file command_bar_button.cpp for the Debug configuration...
-include gccDebug/command_bar_button.d
gccDebug/command_bar_button.o: command_bar_button.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c command_bar_button.cpp $(Debug_Include_Path) -o gccDebug/command_bar_button.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM command_bar_button.cpp $(Debug_Include_Path) > gccDebug/command_bar_button.d

# Compiles file head_up_display.cpp for the Debug configuration...
-include gccDebug/head_up_display.d
gccDebug/head_up_display.o: head_up_display.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c head_up_display.cpp $(Debug_Include_Path) -o gccDebug/head_up_display.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM head_up_display.cpp $(Debug_Include_Path) > gccDebug/head_up_display.d

# Compiles file label.cpp for the Debug configuration...
-include gccDebug/label.d
gccDebug/label.o: label.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c label.cpp $(Debug_Include_Path) -o gccDebug/label.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM label.cpp $(Debug_Include_Path) > gccDebug/label.d

# Compiles file menu_item.cpp for the Debug configuration...
-include gccDebug/menu_item.d
gccDebug/menu_item.o: menu_item.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c menu_item.cpp $(Debug_Include_Path) -o gccDebug/menu_item.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM menu_item.cpp $(Debug_Include_Path) > gccDebug/menu_item.d

# Compiles file robot.cpp for the Debug configuration...
-include gccDebug/robot.d
gccDebug/robot.o: robot.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c robot.cpp $(Debug_Include_Path) -o gccDebug/robot.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM robot.cpp $(Debug_Include_Path) > gccDebug/robot.d

# Compiles file board_rotation_arrow.cpp for the Debug configuration...
-include gccDebug/board_rotation_arrow.d
gccDebug/board_rotation_arrow.o: board_rotation_arrow.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c board_rotation_arrow.cpp $(Debug_Include_Path) -o gccDebug/board_rotation_arrow.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM board_rotation_arrow.cpp $(Debug_Include_Path) > gccDebug/board_rotation_arrow.d

# Compiles file standard_background.cpp for the Debug configuration...
-include gccDebug/standard_background.d
gccDebug/standard_background.o: standard_background.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c standard_background.cpp $(Debug_Include_Path) -o gccDebug/standard_background.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM standard_background.cpp $(Debug_Include_Path) > gccDebug/standard_background.d

# Compiles file error_state.cpp for the Debug configuration...
-include gccDebug/error_state.d
gccDebug/error_state.o: error_state.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c error_state.cpp $(Debug_Include_Path) -o gccDebug/error_state.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM error_state.cpp $(Debug_Include_Path) > gccDebug/error_state.d

# Compiles file menu_state.cpp for the Debug configuration...
-include gccDebug/menu_state.d
gccDebug/menu_state.o: menu_state.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c menu_state.cpp $(Debug_Include_Path) -o gccDebug/menu_state.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM menu_state.cpp $(Debug_Include_Path) > gccDebug/menu_state.d

# Compiles file play_state.cpp for the Debug configuration...
-include gccDebug/play_state.d
gccDebug/play_state.o: play_state.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c play_state.cpp $(Debug_Include_Path) -o gccDebug/play_state.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM play_state.cpp $(Debug_Include_Path) > gccDebug/play_state.d

# Builds the Release configuration...
.PHONY: Release
Release: create_folders gccRelease/stdafx.h.gch gccRelease/main.o gccRelease/menu_play_state.o gccRelease/my_game.o gccRelease/robot_program.o gccRelease/settings.o gccRelease/theme.o gccRelease/base_game_theme.o gccRelease/color.o gccRelease/font_manager.o gccRelease/font_manager_font.o gccRelease/game.o gccRelease/exception.o gccRelease/functions.o gccRelease/game_font.o gccRelease/game_objects.o gccRelease/input_handler.o gccRelease/mouse_data.o gccRelease/game_object.o gccRelease/image_manager.o gccRelease/image.o gccRelease/settings_base.o gccRelease/stdafx.o gccRelease/theme_object_image.o gccRelease/split_path.o gccRelease/state.o gccRelease/state_manager.o gccRelease/theme_object.o gccRelease/types.o gccRelease/vector_2d.o gccRelease/window.o gccRelease/format.o gccRelease/tinystr.o gccRelease/tinyxml.o gccRelease/tinyxmlerror.o gccRelease/tinyxmlparser.o gccRelease/level.o gccRelease/level_pack.o gccRelease/level_packs.o gccRelease/level_square.o gccRelease/board_square.o gccRelease/board.o gccRelease/button.o gccRelease/button_bar.o gccRelease/command_bar.o gccRelease/command_bar_button.o gccRelease/head_up_display.o gccRelease/label.o gccRelease/menu_item.o gccRelease/robot.o gccRelease/board_rotation_arrow.o gccRelease/standard_background.o gccRelease/error_state.o gccRelease/menu_state.o gccRelease/play_state.o 
	g++ gccRelease/main.o gccRelease/menu_play_state.o gccRelease/my_game.o gccRelease/robot_program.o gccRelease/settings.o gccRelease/theme.o gccRelease/base_game_theme.o gccRelease/color.o gccRelease/font_manager.o gccRelease/font_manager_font.o gccRelease/game.o gccRelease/exception.o gccRelease/functions.o gccRelease/game_font.o gccRelease/game_objects.o gccRelease/input_handler.o gccRelease/mouse_data.o gccRelease/game_object.o gccRelease/image_manager.o gccRelease/image.o gccRelease/settings_base.o gccRelease/stdafx.o gccRelease/theme_object_image.o gccRelease/split_path.o gccRelease/state.o gccRelease/state_manager.o gccRelease/theme_object.o gccRelease/types.o gccRelease/vector_2d.o gccRelease/window.o gccRelease/format.o gccRelease/tinystr.o gccRelease/tinyxml.o gccRelease/tinyxmlerror.o gccRelease/tinyxmlparser.o gccRelease/level.o gccRelease/level_pack.o gccRelease/level_packs.o gccRelease/level_square.o gccRelease/board_square.o gccRelease/board.o gccRelease/button.o gccRelease/button_bar.o gccRelease/command_bar.o gccRelease/command_bar_button.o gccRelease/head_up_display.o gccRelease/label.o gccRelease/menu_item.o gccRelease/robot.o gccRelease/board_rotation_arrow.o gccRelease/standard_background.o gccRelease/error_state.o gccRelease/menu_state.o gccRelease/play_state.o  $(Release_Library_Path) $(Release_Libraries) -Wl,-rpath,./ -o ../gccRelease/robot.exe

# Compiles file stdafx.h as the precompiled header stdafx.h.gch for the Release configuration...
-include gccRelease/stdafx.d
gccRelease/stdafx.h.gch: stdafx.h
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c stdafx.h $(Release_Include_Path) -o stdafx.h.gch

# Compiles file main.cpp for the Release configuration...
-include gccRelease/main.d
gccRelease/main.o: main.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c main.cpp $(Release_Include_Path) -o gccRelease/main.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM main.cpp $(Release_Include_Path) > gccRelease/main.d

# Compiles file menu_play_state.cpp for the Release configuration...
-include gccRelease/menu_play_state.d
gccRelease/menu_play_state.o: menu_play_state.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c menu_play_state.cpp $(Release_Include_Path) -o gccRelease/menu_play_state.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM menu_play_state.cpp $(Release_Include_Path) > gccRelease/menu_play_state.d

# Compiles file my_game.cpp for the Release configuration...
-include gccRelease/my_game.d
gccRelease/my_game.o: my_game.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c my_game.cpp $(Release_Include_Path) -o gccRelease/my_game.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM my_game.cpp $(Release_Include_Path) > gccRelease/my_game.d

# Compiles file robot_program.cpp for the Release configuration...
-include gccRelease/robot_program.d
gccRelease/robot_program.o: robot_program.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c robot_program.cpp $(Release_Include_Path) -o gccRelease/robot_program.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM robot_program.cpp $(Release_Include_Path) > gccRelease/robot_program.d

# Compiles file settings.cpp for the Release configuration...
-include gccRelease/settings.d
gccRelease/settings.o: settings.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c settings.cpp $(Release_Include_Path) -o gccRelease/settings.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM settings.cpp $(Release_Include_Path) > gccRelease/settings.d

# Compiles file theme.cpp for the Release configuration...
-include gccRelease/theme.d
gccRelease/theme.o: theme.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c theme.cpp $(Release_Include_Path) -o gccRelease/theme.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM theme.cpp $(Release_Include_Path) > gccRelease/theme.d

# Compiles file base_game_theme.cpp for the Release configuration...
-include gccRelease/base_game_theme.d
gccRelease/base_game_theme.o: base_game_theme.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c base_game_theme.cpp $(Release_Include_Path) -o gccRelease/base_game_theme.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM base_game_theme.cpp $(Release_Include_Path) > gccRelease/base_game_theme.d

# Compiles file color.cpp for the Release configuration...
-include gccRelease/color.d
gccRelease/color.o: color.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c color.cpp $(Release_Include_Path) -o gccRelease/color.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM color.cpp $(Release_Include_Path) > gccRelease/color.d

# Compiles file font_manager.cpp for the Release configuration...
-include gccRelease/font_manager.d
gccRelease/font_manager.o: font_manager.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c font_manager.cpp $(Release_Include_Path) -o gccRelease/font_manager.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM font_manager.cpp $(Release_Include_Path) > gccRelease/font_manager.d

# Compiles file font_manager_font.cpp for the Release configuration...
-include gccRelease/font_manager_font.d
gccRelease/font_manager_font.o: font_manager_font.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c font_manager_font.cpp $(Release_Include_Path) -o gccRelease/font_manager_font.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM font_manager_font.cpp $(Release_Include_Path) > gccRelease/font_manager_font.d

# Compiles file game.cpp for the Release configuration...
-include gccRelease/game.d
gccRelease/game.o: game.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c game.cpp $(Release_Include_Path) -o gccRelease/game.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM game.cpp $(Release_Include_Path) > gccRelease/game.d

# Compiles file exception.cpp for the Release configuration...
-include gccRelease/exception.d
gccRelease/exception.o: exception.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c exception.cpp $(Release_Include_Path) -o gccRelease/exception.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM exception.cpp $(Release_Include_Path) > gccRelease/exception.d

# Compiles file functions.cpp for the Release configuration...
-include gccRelease/functions.d
gccRelease/functions.o: functions.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c functions.cpp $(Release_Include_Path) -o gccRelease/functions.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM functions.cpp $(Release_Include_Path) > gccRelease/functions.d

# Compiles file game_font.cpp for the Release configuration...
-include gccRelease/game_font.d
gccRelease/game_font.o: game_font.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c game_font.cpp $(Release_Include_Path) -o gccRelease/game_font.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM game_font.cpp $(Release_Include_Path) > gccRelease/game_font.d

# Compiles file game_objects.cpp for the Release configuration...
-include gccRelease/game_objects.d
gccRelease/game_objects.o: game_objects.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c game_objects.cpp $(Release_Include_Path) -o gccRelease/game_objects.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM game_objects.cpp $(Release_Include_Path) > gccRelease/game_objects.d

# Compiles file input_handler.cpp for the Release configuration...
-include gccRelease/input_handler.d
gccRelease/input_handler.o: input_handler.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c input_handler.cpp $(Release_Include_Path) -o gccRelease/input_handler.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM input_handler.cpp $(Release_Include_Path) > gccRelease/input_handler.d

# Compiles file mouse_data.cpp for the Release configuration...
-include gccRelease/mouse_data.d
gccRelease/mouse_data.o: mouse_data.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c mouse_data.cpp $(Release_Include_Path) -o gccRelease/mouse_data.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM mouse_data.cpp $(Release_Include_Path) > gccRelease/mouse_data.d

# Compiles file game_object.cpp for the Release configuration...
-include gccRelease/game_object.d
gccRelease/game_object.o: game_object.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c game_object.cpp $(Release_Include_Path) -o gccRelease/game_object.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM game_object.cpp $(Release_Include_Path) > gccRelease/game_object.d

# Compiles file image_manager.cpp for the Release configuration...
-include gccRelease/image_manager.d
gccRelease/image_manager.o: image_manager.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c image_manager.cpp $(Release_Include_Path) -o gccRelease/image_manager.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM image_manager.cpp $(Release_Include_Path) > gccRelease/image_manager.d

# Compiles file image.cpp for the Release configuration...
-include gccRelease/image.d
gccRelease/image.o: image.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c image.cpp $(Release_Include_Path) -o gccRelease/image.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM image.cpp $(Release_Include_Path) > gccRelease/image.d

# Compiles file settings_base.cpp for the Release configuration...
-include gccRelease/settings_base.d
gccRelease/settings_base.o: settings_base.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c settings_base.cpp $(Release_Include_Path) -o gccRelease/settings_base.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM settings_base.cpp $(Release_Include_Path) > gccRelease/settings_base.d

# Compiles file stdafx.cpp for the Release configuration...
-include gccRelease/stdafx.d
gccRelease/stdafx.o: stdafx.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c stdafx.cpp $(Release_Include_Path) -o gccRelease/stdafx.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM stdafx.cpp $(Release_Include_Path) > gccRelease/stdafx.d

# Compiles file theme_object_image.cpp for the Release configuration...
-include gccRelease/theme_object_image.d
gccRelease/theme_object_image.o: theme_object_image.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c theme_object_image.cpp $(Release_Include_Path) -o gccRelease/theme_object_image.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM theme_object_image.cpp $(Release_Include_Path) > gccRelease/theme_object_image.d

# Compiles file split_path.cpp for the Release configuration...
-include gccRelease/split_path.d
gccRelease/split_path.o: split_path.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c split_path.cpp $(Release_Include_Path) -o gccRelease/split_path.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM split_path.cpp $(Release_Include_Path) > gccRelease/split_path.d

# Compiles file state.cpp for the Release configuration...
-include gccRelease/state.d
gccRelease/state.o: state.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c state.cpp $(Release_Include_Path) -o gccRelease/state.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM state.cpp $(Release_Include_Path) > gccRelease/state.d

# Compiles file state_manager.cpp for the Release configuration...
-include gccRelease/state_manager.d
gccRelease/state_manager.o: state_manager.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c state_manager.cpp $(Release_Include_Path) -o gccRelease/state_manager.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM state_manager.cpp $(Release_Include_Path) > gccRelease/state_manager.d

# Compiles file theme_object.cpp for the Release configuration...
-include gccRelease/theme_object.d
gccRelease/theme_object.o: theme_object.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c theme_object.cpp $(Release_Include_Path) -o gccRelease/theme_object.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM theme_object.cpp $(Release_Include_Path) > gccRelease/theme_object.d

# Compiles file types.cpp for the Release configuration...
-include gccRelease/types.d
gccRelease/types.o: types.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c types.cpp $(Release_Include_Path) -o gccRelease/types.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM types.cpp $(Release_Include_Path) > gccRelease/types.d

# Compiles file vector_2d.cpp for the Release configuration...
-include gccRelease/vector_2d.d
gccRelease/vector_2d.o: vector_2d.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c vector_2d.cpp $(Release_Include_Path) -o gccRelease/vector_2d.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM vector_2d.cpp $(Release_Include_Path) > gccRelease/vector_2d.d

# Compiles file window.cpp for the Release configuration...
-include gccRelease/window.d
gccRelease/window.o: window.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c window.cpp $(Release_Include_Path) -o gccRelease/window.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM window.cpp $(Release_Include_Path) > gccRelease/window.d

# Compiles file format.cc for the Release configuration...
-include gccRelease/format.d
gccRelease/format.o: format.cc
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c format.cc $(Release_Include_Path) -o gccRelease/format.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM format.cc $(Release_Include_Path) > gccRelease/format.d

# Compiles file tinystr.cpp for the Release configuration...
-include gccRelease/tinystr.d
gccRelease/tinystr.o: tinystr.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c tinystr.cpp $(Release_Include_Path) -o gccRelease/tinystr.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM tinystr.cpp $(Release_Include_Path) > gccRelease/tinystr.d

# Compiles file tinyxml.cpp for the Release configuration...
-include gccRelease/tinyxml.d
gccRelease/tinyxml.o: tinyxml.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c tinyxml.cpp $(Release_Include_Path) -o gccRelease/tinyxml.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM tinyxml.cpp $(Release_Include_Path) > gccRelease/tinyxml.d

# Compiles file tinyxmlerror.cpp for the Release configuration...
-include gccRelease/tinyxmlerror.d
gccRelease/tinyxmlerror.o: tinyxmlerror.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c tinyxmlerror.cpp $(Release_Include_Path) -o gccRelease/tinyxmlerror.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM tinyxmlerror.cpp $(Release_Include_Path) > gccRelease/tinyxmlerror.d

# Compiles file tinyxmlparser.cpp for the Release configuration...
-include gccRelease/tinyxmlparser.d
gccRelease/tinyxmlparser.o: tinyxmlparser.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c tinyxmlparser.cpp $(Release_Include_Path) -o gccRelease/tinyxmlparser.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM tinyxmlparser.cpp $(Release_Include_Path) > gccRelease/tinyxmlparser.d

# Compiles file level.cpp for the Release configuration...
-include gccRelease/level.d
gccRelease/level.o: level.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c level.cpp $(Release_Include_Path) -o gccRelease/level.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM level.cpp $(Release_Include_Path) > gccRelease/level.d

# Compiles file level_pack.cpp for the Release configuration...
-include gccRelease/level_pack.d
gccRelease/level_pack.o: level_pack.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c level_pack.cpp $(Release_Include_Path) -o gccRelease/level_pack.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM level_pack.cpp $(Release_Include_Path) > gccRelease/level_pack.d

# Compiles file level_packs.cpp for the Release configuration...
-include gccRelease/level_packs.d
gccRelease/level_packs.o: level_packs.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c level_packs.cpp $(Release_Include_Path) -o gccRelease/level_packs.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM level_packs.cpp $(Release_Include_Path) > gccRelease/level_packs.d

# Compiles file level_square.cpp for the Release configuration...
-include gccRelease/level_square.d
gccRelease/level_square.o: level_square.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c level_square.cpp $(Release_Include_Path) -o gccRelease/level_square.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM level_square.cpp $(Release_Include_Path) > gccRelease/level_square.d

# Compiles file board_square.cpp for the Release configuration...
-include gccRelease/board_square.d
gccRelease/board_square.o: board_square.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c board_square.cpp $(Release_Include_Path) -o gccRelease/board_square.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM board_square.cpp $(Release_Include_Path) > gccRelease/board_square.d

# Compiles file board.cpp for the Release configuration...
-include gccRelease/board.d
gccRelease/board.o: board.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c board.cpp $(Release_Include_Path) -o gccRelease/board.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM board.cpp $(Release_Include_Path) > gccRelease/board.d

# Compiles file button.cpp for the Release configuration...
-include gccRelease/button.d
gccRelease/button.o: button.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c button.cpp $(Release_Include_Path) -o gccRelease/button.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM button.cpp $(Release_Include_Path) > gccRelease/button.d

# Compiles file button_bar.cpp for the Release configuration...
-include gccRelease/button_bar.d
gccRelease/button_bar.o: button_bar.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c button_bar.cpp $(Release_Include_Path) -o gccRelease/button_bar.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM button_bar.cpp $(Release_Include_Path) > gccRelease/button_bar.d

# Compiles file command_bar.cpp for the Release configuration...
-include gccRelease/command_bar.d
gccRelease/command_bar.o: command_bar.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c command_bar.cpp $(Release_Include_Path) -o gccRelease/command_bar.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM command_bar.cpp $(Release_Include_Path) > gccRelease/command_bar.d

# Compiles file command_bar_button.cpp for the Release configuration...
-include gccRelease/command_bar_button.d
gccRelease/command_bar_button.o: command_bar_button.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c command_bar_button.cpp $(Release_Include_Path) -o gccRelease/command_bar_button.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM command_bar_button.cpp $(Release_Include_Path) > gccRelease/command_bar_button.d

# Compiles file head_up_display.cpp for the Release configuration...
-include gccRelease/head_up_display.d
gccRelease/head_up_display.o: head_up_display.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c head_up_display.cpp $(Release_Include_Path) -o gccRelease/head_up_display.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM head_up_display.cpp $(Release_Include_Path) > gccRelease/head_up_display.d

# Compiles file label.cpp for the Release configuration...
-include gccRelease/label.d
gccRelease/label.o: label.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c label.cpp $(Release_Include_Path) -o gccRelease/label.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM label.cpp $(Release_Include_Path) > gccRelease/label.d

# Compiles file menu_item.cpp for the Release configuration...
-include gccRelease/menu_item.d
gccRelease/menu_item.o: menu_item.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c menu_item.cpp $(Release_Include_Path) -o gccRelease/menu_item.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM menu_item.cpp $(Release_Include_Path) > gccRelease/menu_item.d

# Compiles file robot.cpp for the Release configuration...
-include gccRelease/robot.d
gccRelease/robot.o: robot.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c robot.cpp $(Release_Include_Path) -o gccRelease/robot.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM robot.cpp $(Release_Include_Path) > gccRelease/robot.d

# Compiles file board_rotation_arrow.cpp for the Release configuration...
-include gccRelease/board_rotation_arrow.d
gccRelease/board_rotation_arrow.o: board_rotation_arrow.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c board_rotation_arrow.cpp $(Release_Include_Path) -o gccRelease/board_rotation_arrow.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM board_rotation_arrow.cpp $(Release_Include_Path) > gccRelease/board_rotation_arrow.d

# Compiles file standard_background.cpp for the Release configuration...
-include gccRelease/standard_background.d
gccRelease/standard_background.o: standard_background.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c standard_background.cpp $(Release_Include_Path) -o gccRelease/standard_background.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM standard_background.cpp $(Release_Include_Path) > gccRelease/standard_background.d

# Compiles file error_state.cpp for the Release configuration...
-include gccRelease/error_state.d
gccRelease/error_state.o: error_state.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c error_state.cpp $(Release_Include_Path) -o gccRelease/error_state.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM error_state.cpp $(Release_Include_Path) > gccRelease/error_state.d

# Compiles file menu_state.cpp for the Release configuration...
-include gccRelease/menu_state.d
gccRelease/menu_state.o: menu_state.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c menu_state.cpp $(Release_Include_Path) -o gccRelease/menu_state.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM menu_state.cpp $(Release_Include_Path) > gccRelease/menu_state.d

# Compiles file play_state.cpp for the Release configuration...
-include gccRelease/play_state.d
gccRelease/play_state.o: play_state.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c play_state.cpp $(Release_Include_Path) -o gccRelease/play_state.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM play_state.cpp $(Release_Include_Path) > gccRelease/play_state.d

# Creates the intermediate and output folders for each configuration...
.PHONY: create_folders
create_folders:
	mkdir -p gccDebug/source
	mkdir -p ../gccDebug
	mkdir -p gccRelease/source
	mkdir -p ../gccRelease

# Cleans intermediate and output files (objects, libraries, executables)...
.PHONY: clean
clean:
	rm -f gccDebug/*.o
	rm -f gccDebug/*.d
	rm -f ../gccDebug/*.a
	rm -f ../gccDebug/*.so
	rm -f ../gccDebug/*.dll
	rm -f ../gccDebug/*.exe
	rm -f gccRelease/*.o
	rm -f gccRelease/*.d
	rm -f ../gccRelease/*.a
	rm -f ../gccRelease/*.so
	rm -f ../gccRelease/*.dll
	rm -f ../gccRelease/*.exe

