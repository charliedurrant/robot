/*
http://stackoverflow.com/questions/6096384/how-to-fix-pch-file-missing-on-build
1.Right-click on your project in the Solution Explorer. 
2.Click Properties at the bottom of the drop-down menu.
3.At the top left of the Properties Pages, select All Configurations from the drop-down menu.
4.Open the C/C++ tree and select Precompiled Headers
5.Precompiled Header: Select Use (/Yu)
6.Fill in the Precompiled Header File field. Standard is stdafx.h

7.Click Okay


8.If you do not have stdafx.h in your Header Files put it there. Edit it to #include all the headers you want precompiled.

9.Put a file named stdafx.cpp into your project. Put #include "stdafx.h" at the top of it, and nothing else.
10.Right-click on stdafx.cpp in Solution Explorer. Select Properties and All configurations again as in step 4 ...

11.... but this time select Precompiled Header Create (/Yc). This will only bind to the one file stdafx.cpp.


12.Put #include "stdafx.h" at the very top 


*/
#undef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#undef _SCL_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS

#include <SDL.h>  
#include <SDL_image.h>
#include <SDL_ttf.h>
/*#include <SDL_opengl.h>*/


#if ! defined(_MSC_VER)
   #include <libgen.h>
#endif

#include <math.h>
#include <float.h>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream> //cout
#include <memory>
#include <map>
#include <vector>
#include <locale>
#include <limits>   
#include <functional>
#include "format.h" //3rdParty/format/

#undef TIXML_USE_STL
#define TIXML_USE_STL 

#include "tinyxml.h" //3rdParty/tinyxml/
#include "tinystr.h" //3rdParty/tinyxml/