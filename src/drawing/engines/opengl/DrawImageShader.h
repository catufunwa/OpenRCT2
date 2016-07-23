#pragma region Copyright (c) 2014-2016 OpenRCT2 Developers
/*****************************************************************************
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * OpenRCT2 is the work of many authors, a full list can be found in contributors.md
 * For more information, visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * A full copy of the GNU General Public License can be found in licence.txt
 *****************************************************************************/
#pragma endregion

#pragma once

#include "GLSLTypes.h"
#include "OpenGLShaderProgram.h"
#include <SDL_pixels.h>
#include <vector>

// Per-instance data for images
struct DrawImageInstance {
    vec4i clip;
    vec2f texCoordScale;
    int texColourSlot;
    int texMaskSlot;
    int flags;
    vec4f colour;
    vec4i bounds;
    int mask;
};

class DrawImageShader : public OpenGLShaderProgram
{
private:
    GLuint uScreenSize;
    GLuint uTexture;
    GLuint uPalette;
    GLuint uTextureCoordinates;

    GLuint vIndex;

    GLuint _vbo;
    GLuint _vboInstances;
    GLuint _vao;
    
    SDL_Color _palette[256];

public:
    DrawImageShader();
    ~DrawImageShader() override;

    void SetScreenSize(sint32 width, sint32 height);
    void SetPalette(const vec4f *glPalette);
    void SetTextureCoordinates(sint32 left, sint32 top, sint32 right, sint32 bottom);
    void DrawInstances(const std::vector<DrawImageInstance>& instances);

private:
    void GetLocations();
};
