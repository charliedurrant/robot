#pragma once
#include "framework.h"

#if defined (__OPENGL_TEST__)
enum WindowDrawMode
{
  WindowDrawMode2D,
  WindowDrawMode3D,
  WindowDrawModeNone
};
#endif


class Window
{
  private:
    #if defined (__OPENGL_TEST__)
      WindowDrawMode _windowDrawMode;
    #endif
    void gluPerspective(float fovy, float aspect, float zNear, float zFar);
    SDL_Surface* Window::CreateTextSurface(const string& message, GameFont* font, Color* color, int wrapWidth);

  public:
    Window(string title,int x, int y, int w, int h,Uint32 flags,int logicalWidthDesign, int logicalHeightDesign);
    Window(string title,int x, int y, int w, int h,Uint32 flags, int rendererIndex,Uint32 rendererFlags,int logicalWidthDesign, int logicalHeightDesign);
    ~Window(void);
    void Construct(string title,int x, int y, int w, int h,Uint32 flags, int rendererIndex,Uint32 rendererFlags,int logicalWidthDesign, int logicalHeightDesign);
    void Render(void);
    void Update(void);
    void RenderText(const string& message, GameFont* font, Color* color, RECT_FRAMEWORK* rectangle, TextAlign textAlignment = TextAlignMiddleCenter, bool wrap = false);
    void RenderDebugText(const string& message, RECT_FRAMEWORK* rectangle, TextAlign textAlignment);
    Image* CreateTextImage(const string& message, GameFont* font, Color* color, int wrapWidth = 0);
    FontData* FontDataGet(GameFont* font);
    void Clear(void);
    SDL_Window* Pointer;
    SDL_Renderer* Renderer;    
    SIZE_FRAMEWORK LogicalSize;
    SIZE_FRAMEWORK LogicalSizeDesign;
    int ScaleToLogicalDesignHeight(int valueUnscaled);
    int ScaleToLogicalDesignWidth(int valueUnscaled);
    SIZE_FRAMEWORK Size();
    RECT_FRAMEWORK Rectangle();
    POINT_FRAMEWORK Position();
    void RendererTargetSet(Image* image);
    void RendererTargetClear();
    int RendererIndex(string  nameSearchMatch);
    #if defined (__OPENGL_TEST__)
    void DrawModeSet(WindowDrawMode windowDrawMode);
    #endif
};

