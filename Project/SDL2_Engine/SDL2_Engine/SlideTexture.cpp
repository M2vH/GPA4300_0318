#pragma region project include
#include "SlideTexture.h"
#include "Texture.h"
#pragma endregion



#pragma region constructor
/// <summary>
/// constructor
/// </summary>
//CSlideTexture::CSlideTexture()
//{
//}


CSlideTexture::CSlideTexture(SVector2 _offset, SVector2 _pos, SVector2 _size, CRenderer * _pRenderer, const char * _pFileName)
{
	// ToDo (m2vh) : create 3 TexturedObjects at calculated position.
	m_windowSize = SVector2();
	m_windowSize.X = 1280;
	m_offset = _offset;

	// set the outline rect
	m_outline = SRect(_pos.X, _pos.Y, _size.X, _size.Y);

	// set the pos of center texture
	m_posCenter = _pos + _offset;
	
	// the position of the left texture
	m_posLeft = _pos + m_offset;
	m_posLeft.X = m_posLeft.X + (m_windowSize.X * -1);

	// the position of the right texture
	m_posRight = _pos + m_offset;
	m_posRight.X = m_posRight.X + m_windowSize.X;


	//m_pTexture = new CTexture(_pFileName, _pRenderer);
	
	//	create the center texture at _pos + _offset
	m_pTexObjectCenter = new CTexturedObject(_pos = _pos + m_offset, _size, _pRenderer, _pFileName);

	m_pTexObjectLeft = new CTexturedObject(m_posLeft, _size, _pRenderer, _pFileName);

	m_pTexObjectRight = new CTexturedObject(m_posRight, _size, _pRenderer, _pFileName);


}

/// <summary>
/// destructor
/// </summary>
CSlideTexture::~CSlideTexture()
{
	// delete the texture
	delete m_pTexObjectCenter;
	delete m_pTexObjectLeft;
	delete m_pTexObjectRight;
}

#pragma endregion

#pragma region public override function
void CSlideTexture::Update()
{
	// ToDo (m2vh) : manipulate offset
	SVector2 move = { 1,0 };
	SetOffset(move);
	
	//set the new positions to texturedObjects
	m_pTexObjectLeft->SetPosition(m_posLeft);
	m_pTexObjectCenter->SetPosition(m_posCenter);
	m_pTexObjectRight->SetPosition(m_posRight);

	// update the textured objects
	m_pTexObjectLeft->Update();
	m_pTexObjectCenter->Update();
	m_pTexObjectRight->Update();
}

void CSlideTexture::Render(CRenderer * _pRenderer)
{
	// ToDo (m2vh) : render all needed textures
	m_pTexObjectCenter->Render(_pRenderer);
	m_pTexObjectLeft->Render(_pRenderer);
	m_pTexObjectRight->Render(_pRenderer);
}

inline void CSlideTexture::SetOffset(SVector2 _pOffset)
{
	// ToDo (m2vh) : set the offset and calc all members
	m_offset = _pOffset;
	
	// ToDo (m2vh) : delete
	// m_offset.X = (int)((int)m_offset.X % (int)m_windowSize.X);

	m_posCenter = m_posCenter + m_offset;
	// check if we moved more than width
	if (m_posCenter.X > m_outline.w)
	{
		// set pos back to start
		m_posCenter.X = m_outline.x;
	}
	
	m_posLeft = m_posLeft + m_offset;
	// check if we moved more than width
	if (m_posLeft.X > m_outline.x)
	{
		// set back pos to start
		// complete width to the left
		m_posLeft.X = m_outline.x - m_outline.w;
	}
	
	m_posRight = m_posRight + m_offset;
	// check if we moved more than width
	if (m_posRight.X > (m_outline.w + m_outline.w))
	{
		m_posRight.X = m_outline.w;
	}
}

#pragma endregion
