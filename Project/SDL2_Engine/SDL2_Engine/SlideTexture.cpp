#pragma region project include
#include "SlideTexture.h"
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
}

/// <summary>
/// destructor
/// </summary>
CSlideTexture::~CSlideTexture()
{
	// delete the texture
	delete m_pTexture;
}

#pragma endregion

#pragma region public override function
void CSlideTexture::Update()
{
	// ToDo (m2vh) : manipulate offset
}

void CSlideTexture::Render(CRenderer * _pRenderer)
{
	// ToDo (m2vh) : render all needed textures
}

inline void CSlideTexture::SetOffset(SVector2 _pOffset)
{
	// ToDo (m2vh) : set the offset and calc all members
}

#pragma endregion
