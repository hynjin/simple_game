#pragma once
#include "Stdafx.h"

#define CreateSpriteTexture(pDev,File,Width,Height,ColorKey,Texture) D3DXCreateTextureFromFileEx(\
	pDev  \
	,File  \
	,Width  \
	,Height         \
	,D3DX_DEFAULT       \
	,0          \
	,D3DFMT_UNKNOWN       \
	,D3DPOOL_MANAGED       \
	,D3DX_FILTER_TRIANGLE|D3DX_FILTER_MIRROR \
	,D3DX_FILTER_TRIANGLE|D3DX_FILTER_MIRROR \
	,ColorKey        \
	,NULL         \
	,NULL         \
	,&(Texture) )
