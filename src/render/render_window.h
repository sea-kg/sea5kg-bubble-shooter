#pragma once

#include "render_object.h"

class RanderWindowLayer {
    public:
        RanderWindowLayer(const std::string &sName);
        void addObject(RenderObject *pObject);
        void removeObject(RenderObject *pObject);
        void drawObjects(const GameState& state, SDL_Renderer *pRenderer);
        void modifyObjects(const GameState& state, IRenderWindow *pWindow);
        void sortObjectsByPositionZ();

    private:
        std::string m_sName;
        std::vector<RenderObject *> m_vObjects;
};

class RenderWindow : public IRenderWindow {

    public:
        RenderWindow(const char* p_title, int p_w, int p_h);
        ~RenderWindow();
        virtual void addGameObject(RenderObject *pObject) override;
        
        bool isFullscreen();
        void toggleFullscreen();
        void removeObject(RenderObject *pObject);
        void sortObjectsByPositionZ();

        SDL_Texture* loadTexture(const std::string &sFilePath);
        void loadTextureBioplast(const std::string &sFilePath);
        void cleanUp();
        void clear();
        void clear(int a1, int a2, int a3, int a4);
        void modifyObjects(const GameState& state);
        void drawObjects(const GameState& state);
        SDL_Renderer* getRenderer();

        void getWindowSize(int* w, int* h);
        
    private:
        int createRenderWindowLayer(const std::string &sName);
        RanderWindowLayer *getLayer(int nLayer);

        bool m_bFullsreeen;
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
        SDL_DisplayMode m_displayMode;
        SDL_Texture* m_pTextureBioplast;
        std::vector<RanderWindowLayer *> m_vLayers;

        int m_nLayerGame;
};