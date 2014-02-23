#pragma once
#include "framework.h"
class Window
{
  private:
  public:
    Window(string title,int x, int y, int w, int h,Uint32 flags,int logicalWidthDesign, int logicalHeightDesign);
    Window(string title,int x, int y, int w, int h,Uint32 flags, int rendererIndex,Uint32 rendererFlags,int logicalWidthDesign, int logicalHeightDesign);
    ~Window(void);
    void Construct(string title,int x, int y, int w, int h,Uint32 flags, int rendererIndex,Uint32 rendererFlags,int logicalWidthDesign, int logicalHeightDesign);
    void Render(void);
    void Update(void);
    void RenderText(const string& message, GameFont* font, Color* color, RECT* rectangle );
    void RenderDebugText(const string& message, POINT pt);
    Image* CreateTextImage(const string& message, GameFont* font, Color* color, int boundingWidth );
    void Clear(void);
    SDL_Window* Pointer;
    SDL_Renderer* Renderer;    
    SIZE LogicalSize;
    SIZE LogicalSizeDesign;
    int ScaleToLogicalDesignHeight(int valueUnscaled);
    int ScaleToLogicalDesignWidth(int valueUnscaled);
    SIZE Size();
    RECT Rectangle();
    POINT Position();
};

