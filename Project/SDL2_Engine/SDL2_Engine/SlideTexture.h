#pragma once
#pragma region project include
#include "TexturedObject.h"

#pragma endregion

#pragma region forward declaration
class CTexturedObject;
#pragma endregion


/// <summary>
/// slide texture class
/// </summary>
class CSlideTexture :
	public CObject
{
public:

#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CSlideTexture() : CObject() {};

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">pos of object</param>
	CSlideTexture(SVector2 _pos) : CObject(_pos){}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_offset">offset of texture in outline rect</param>
	/// <param name="_pos">position of outline</param>
	/// <param name="_size">size of outline</param>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">relative path/to/file</param>
	CSlideTexture(
		SVector2 _offset,
		SVector2 _pos,
		SVector2 _size,
		CRenderer* _pRenderer,
		const char* _pFileName);

	/// <summary>
	/// destructor
	/// </summary>
	~CSlideTexture();
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

#pragma region public inline function
	/// <summary>
	/// get outline rect
	/// </summary>
	/// <returns>outline rect of texture</returns>
	inline SRect GetOutline() { return m_outline; }

	/// <summary>
	/// set offset of texture in outline
	/// </summary>
	/// <param name="_pOffset"></param>
	inline void SetOffset(SVector2 _pOffset);

	/// <summary>
	/// get the offset of texture
	/// </summary>
	/// <returns></returns>
	inline SVector2 GetOffset() { return m_offset; }
#pragma endregion


#pragma region protected variable

	/// <summary>
	/// offset of texture in outline
	/// </summary>
	SVector2 m_offset;

	/// <summary>
	/// size of window
	/// </summary>
	SVector2 m_windowSize;

	/// <summary>
	/// calculated position of center texture
	/// </summary>
	SVector2 m_posCenter;

	/// <summary>
	/// calculated position of left texture
	/// </summary>
	SVector2 m_posLeft;

	/// <summary>
	/// calculated position of right texture
	/// </summary>
	SVector2 m_posRight;

	/// <summary>
	/// stores the starting outline rect that will be visible.
	/// </summary>
	SRect m_outline;

	/// <summary>
	/// texture to display
	/// </summary>
	CTexture* m_pTexture = nullptr;

	/// <summary>
	/// center Object to render
	/// </summary>
	CTexturedObject* m_pTexObjectCenter;
	/// <summary>
	/// left object to render
	/// </summary>
	CTexturedObject* m_pTexObjectLeft;
	/// <summary>
	/// right object to render
	/// </summary>
	CTexturedObject* m_pTexObjectRight;
#pragma endregion


};

