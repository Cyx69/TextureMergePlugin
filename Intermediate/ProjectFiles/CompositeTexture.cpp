#include "Runtime/Engine/Classes/Engine/Canvas.h"
#include "CompositeTexture.h"

UCompositeTexture::UCompositeTexture()
{
	OnCanvasRenderTargetUpdate.AddDynamic(this, &UCompositeTexture::PerformMerge);
}

void UCompositeTexture::PerformMerge(UCanvas* Canvas, int32 Width, int32 Height)
{
	for (int32 i = 0; i < Layers.Num(); ++i)
	{
		UTexture* LayerTex = Layers[i];
		if (LayerTex)
		{
			FColor TintColor = FColor::White;
			if (LayerTints.Num() > i)
			{
				TintColor = LayerTints[i];
			}

			Canvas->SetDrawColor(TintColor);
			Canvas->DrawTile(LayerTex, 0, 0, Width, Height, 0, 0, Width, Height);
		}
	}
}

UCompositeTexture* UCompositeTexture::Create(UObject* WorldContextObject, const TArray<UTexture2D*>& Layers)
{
	TArray<FColor> Colors;
	return UCompositeTexture::Create(WorldContextObject, Layers, Colors);
}

UCompositeTexture* UCompositeTexture::Create(UObject* WorldContextObject, const TArray<UTexture2D*>& Layers, const TArray<FColor>& LayerTints)
{
	if (Layers.Num() <= 0)
	{
		return NULL;
	}

	UTexture2D* BaseTexture = Layers[0];

	UCompositeTexture* RenderTarget = Cast<UCompositeTexture>(UCanvasRenderTarget2D::CreateCanvasRenderTarget2D(WorldContextObject, UCompositeTexture::StaticClass(), BaseTexture->GetSizeX(), BaseTexture->GetSizeY()));

	RenderTarget->Layers.Append(Layers);
	RenderTarget->LayerTints.Append(LayerTints);

	RenderTarget->UpdateResource();
	return RenderTarget;
}
