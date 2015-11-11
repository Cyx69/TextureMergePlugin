// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
// 
// Copyright 2015 Heiko Fink, All Rights Reserved.
//
// This file is subject to the terms and conditions defined in
// file 'LICENSE.txt', which is part of this source code package.
// 
// Description:
// This code implements the blueprint functions that are provided by the TextureMerge Blueprint Function Library.
// 
#include "TextureMergePrivatePCH.h"
#include "TextureMergeBPLibrary.h"
#include "CompositeTexture.h"

UTextureMergeBPLibrary::UTextureMergeBPLibrary(const FObjectInitializer& ObjectInitializer) 
: Super(ObjectInitializer)
{

}

UCompositeTexture* UTextureMergeBPLibrary::Create(UObject* WorldContextObject, const TArray<UTexture2D*>& Layers)
{
	UCompositeTexture* MergedTexture = UCompositeTexture::Create(WorldContextObject, Layers);

	return MergedTexture;
}

UCompositeTexture* UTextureMergeBPLibrary::CreateWithTints(UObject* WorldContextObject, const TArray<UTexture2D*>& Layers, const TArray<FColor>& LayerTints)
{
	UCompositeTexture* MergedTexture = UCompositeTexture::Create(WorldContextObject, Layers, LayerTints);

	return MergedTexture;
}

UCompositeTexture* UTextureMergeBPLibrary::UpdateLayer(UCompositeTexture* RenderTarget, UTexture2D* Layer, const int32 Index)
{
	UCompositeTexture* MergedTexture = UCompositeTexture::UpdateLayer(RenderTarget, Layer, Index);

	return MergedTexture;
}

UCompositeTexture* UTextureMergeBPLibrary::UpdateAllLayers(UCompositeTexture* RenderTarget, TArray<UTexture2D*> Layers)
{
	UCompositeTexture* MergedTexture = UCompositeTexture::UpdateAllLayers(RenderTarget, Layers);

	return MergedTexture;
}

UCompositeTexture* UTextureMergeBPLibrary::UpdateTint(UCompositeTexture* RenderTarget, const FColor& Tint, int32 Index)
{
	UCompositeTexture* MergedTexture = UCompositeTexture::UpdateTint(RenderTarget, Tint, Index);

	return MergedTexture;
}

UCompositeTexture* UTextureMergeBPLibrary::UpdateAllTints(UCompositeTexture* RenderTarget, const TArray<FColor>& LayerTints)
{
	UCompositeTexture* MergedTexture = UCompositeTexture::UpdateAllTints(RenderTarget, LayerTints);

	return MergedTexture;
}
