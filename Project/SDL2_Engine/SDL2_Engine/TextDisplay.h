#pragma once
#pragma region system include
#include <string>
#include <SDL_ttf.h>
#pragma endregion

#pragma region namespace
using namespace std;
#pragma endregion


#pragma region project include
#include "Object.h"
#include "Rect.h"
#include "Macro.h"
#pragma endregion

#pragma region Add to macro.h
#define FONT_SIZE 24
#define FONT_PATH "Fonts/roboto/Roboto-Medium.ttf"

#pragma endregion

#pragma region forward declaration
class CRenderer;
class CTexture;
#pragma endregion

class CTextDisplay :
	public CObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CTextDisplay() : CObject() {};

	CTextDisplay(SVector2 _pos) : CObject(_pos) 
	{
		m_position = _pos;
		m_rect.x = _pos.X;
		m_rect.y = _pos.Y;
	}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">upper left of rect</param>
	/// <param name="_text">text to display</param>
	CTextDisplay(SVector2 _pos, string _text, CRenderer* _pRenderer);
	
	/// <summary>
	/// destructor
	/// </summary>
	~CTextDisplay();

#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	virtual void Update() override;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	virtual void Render(CRenderer* _pRenderer) override;
#pragma endregion

#pragma region public inline functions

	/// <summary>
	/// Set the size of the generated text
	/// </summary>
	/// <param name="_size">width and height of rect</param>
	void SetSize(SVector2 _size) 
	{
		m_srcRect.w = _size.X;
		m_srcRect.h = _size.Y;
	}
	
	inline void Print(string _text);




#pragma endregion


#pragma region public primitive variable
	SVector2 m_position;

	TTF_Font* m_font;

	SDL_Color m_textColor, m_bgColor;

#pragma endregion

private:
#pragma region protected variable
	/// <summary>
	/// The rect of the generated text
	/// </summary>
	SRect m_srcRect;

	/// <summary>
	/// The rect on screen where text is displayed
	/// </summary>
	SRect m_rect;

	/// <summary>
	/// The size of font in pixel
	/// </summary>
	int m_fontSize = FONT_SIZE;

	/// <summary>
	/// The Path/To/Font.ttf
	/// </summary>
	const char* m_fontPath;


	/// <summary>
	/// The text to display
	/// </summary>
	string m_text = "";

	string m_save;

	bool m_newCanvas;

	/// <summary>
	/// the texture to render
	/// </summary>
	SDL_Texture* m_pSDLTexture;

	SDL_Surface* m_pSDL_Surface;

	//CRenderer* m_pRenderer = nullptr;

	int m_updateCount = 0;
#pragma endregion



};

