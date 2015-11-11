#pragma once

#include "Engine/CanvasRenderTarget2D.h"
#include "CompositeTexture.generated.h"

///@brief Class for merging multiple textures into one to reduce texture samples and simplify shaders.
///Layers can be changed at any time, however after changing them UpdateResource must be called to finalize the changes.
UCLASS(Blueprintable)
class UCompositeTexture : public UCanvasRenderTarget2D
{
	GENERATED_BODY()

		UCompositeTexture();

	UFUNCTION()
		void PerformMerge(UCanvas* Canvas, int32 Width, int32 Height);

public:

	///@brief Texture layers
	UPROPERTY(EditAnywhere, Category = "Layers")
		TArray<UTexture2D*> Layers;
	///@brief Tint applied to texture layers
	UPROPERTY(EditAnywhere, Category = "Layers")
		TArray<FColor> LayerTints;

	///@brief Creates a layered texture and updates it based on the passed in layers.
	static UCompositeTexture* Create(UObject* WorldContextObject, const TArray<UTexture2D*>& Layers);
	///@brief Creates a layered texture and updates it like the other version. Also applies tint to layers.
	static UCompositeTexture* Create(UObject* WorldContextObject, const TArray<UTexture2D*>& Layers, const TArray<FColor>& LayerTints);
};
