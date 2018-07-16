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
	m_offset.X = (int)((int)m_offset.X % (int)m_windowSize.X);

	m_posCenter = m_posCenter + m_offset;
	m_posLeft = m_posLeft + m_offset;
	m_posRight = m_posRight + m_offset;
}

#pragma endregion
