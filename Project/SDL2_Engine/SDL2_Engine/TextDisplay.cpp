#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

#include "TextDisplay.h"
#include "Renderer.h"
#include "Texture.h"
#include "Helper.h"

using namespace std;
//#include "Vector2.h"



//CTextDisplay::CTextDisplay()
//{
//}


CTextDisplay::CTextDisplay(SVector2 _pos, string _text, CRenderer* _pRenderer)
{

	// // (m2vh)
	// // set the variables
	m_text = _text;
	//m_pRenderer = _pRenderer;

	m_position = _pos;
	m_rect.x = _pos.X;
	m_rect.y = _pos.Y;

	m_fontPath = "Fonts/roboto/Roboto-Medium.ttf";

	// let the .exe find her Assets
	// const char* path = GetAssetPath(m_fontPath, 3);
	// string path = GetAssetPath(m_fontPath, 3);
	// m_fontPath = path.c_str();
	string font = GetAssetPath(m_fontPath, 4);


	// // load font
	// // m2vh: TTF_Init(); is called in engine init
	//TTF_Init();

	m_font = TTF_OpenFont(font.c_str(), m_fontSize);

#pragma region (m2vh) make SDL_Surface
	// // (m2vh)
	// // show path to font
	//cout << font;

	// set text color
	m_textColor = { 255, 255, 255, 1 };
	m_bgColor = { 60, 0, 60, 0 };
	//render text
	// create a surface with text
	m_pSDL_Surface = TTF_RenderText_Shaded(m_font, m_text.c_str(), m_textColor, m_bgColor);

	// we need a new canvas
	m_newCanvas = true;


#pragma endregion

#pragma region (m2vh) render texture from surface
	// //
	// // we need an option to load 
	// // text directly into texture

	//m_pTexture->SetSDLTexture(
	//	SDL_CreateTextureFromSurface(_pRenderer->GetSDLRenderer(), surface)
	//);

	// // 
	// SDL_Texture* aTexture = m_pTexture->GetSDLTexture();
	// // m2vh put next func into renderer;

	m_pSDLTexture = SDL_CreateTextureFromSurface(_pRenderer->GetSDLRenderer(), m_pSDL_Surface);



#pragma endregion

#pragma region m2vh 

	// // put the size of font texture in m_rect;
	// // m_rect.h = ???
	// // m_rect.w = ???

	//SDL_QueryTexture(m_pTexture->GetSDLTexture(),
	//	nullptr, nullptr,
	//	&m_rect.w,
	//	&m_rect.h);

	// // optional

	SDL_QueryTexture(m_pSDLTexture,
		nullptr, nullptr,
		&m_rect.w,
		&m_rect.h);

#pragma endregion



#pragma region (m2vh) : 
	// // TODO: clean up;
	//if (TTF_WasInit())
	//{
	//	TTF_Quit();
	//}

#pragma endregion
}

CTextDisplay::~CTextDisplay()
{
	if (m_pSDLTexture)
	{
		delete m_pSDLTexture;
	}
}


#pragma region public override function
// update every frame
void CTextDisplay::Update()
{
	m_updateCount++;
	m_updateCount = m_updateCount % 10;

	// // set position of rect
	if (!m_updateCount)
	{
		m_position.X += 3;
		m_position.X = (int)m_position.X % 1280;

		m_rect.x = m_position.X;

		//cout << m_text;
		m_save = m_text.substr(0, m_text.length() - 1);
		m_save.insert(m_save.begin(), m_text.back());
		Print(m_save);
		//cout << m_text;

	}
	m_rect.y = m_position.Y;
	m_srcRect.x = 0;
	m_srcRect.y = 0;
	m_srcRect.w = m_rect.w;
	m_srcRect.h = m_rect.h;


	// // a new surface is needed
	m_pSDL_Surface = TTF_RenderText_Shaded(m_font, m_text.c_str(), m_textColor, m_bgColor);



}

// render every frame
void CTextDisplay::Render(CRenderer * _pRenderer)
{
	// // m2vh: origin render function
	// // render texture
	// _pRenderer->RenderTexture(m_pTexture, m_rect, m_srcRect);

	// // we must render surface into texture
	m_pSDLTexture = SDL_CreateTextureFromSurface(_pRenderer->GetSDLRenderer(), m_pSDL_Surface);

	SDL_FreeSurface(m_pSDL_Surface);
	m_pSDL_Surface = nullptr;


	// // we make use of SDL_RenderCopy
	SDL_RenderCopy(
		_pRenderer->GetSDLRenderer(),
		m_pSDLTexture,
		&m_srcRect,
		&m_rect
	);

	SDL_DestroyTexture(m_pSDLTexture);

	// // we must do some clean up
	m_pSDLTexture = nullptr;

	m_newCanvas = false;
}
#pragma endregion
#pragma region inline functions
inline void CTextDisplay::Print(string _text)
{
	m_text = _text;

	// // we need a new texture;
	// MakeTexture();
}
//inline void CTextDisplay::MakeTexture()
//{
//}
#pragma endregion
