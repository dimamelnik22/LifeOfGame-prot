// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
 
#include "GoLUser.h"

#include <memory>
#include <algorithm> 
#include "Engine/Texture2D.h"
#include "Object.h"
#include "DrawingCanvas.generated.h"


UCLASS(Blueprintable, BlueprintType)
class PROTOTYPE_API UDrawingCanvas : public UObject
{
    GENERATED_BODY()
 
public:
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
        UTexture2D* dynamicCanvas;
 
    UFUNCTION(BlueprintCallable, Category = DrawingTools)
        void InitializeCanvas(const int32 pixelsH, const int32 pixelsV);
    UFUNCTION(BlueprintCallable, Category = DrawingTools)
        void UpdateCanvas();
    UFUNCTION(BlueprintCallable, Category = DrawingTools)
        void ClearCanvas();
 
    UDrawingCanvas();
    ~UDrawingCanvas();
 
private:
 
    // canvas
    std::unique_ptr<uint8[]> canvasPixelData;
    int canvasWidth;
    int canvasHeight;
    int bytesPerPixel;
    int bufferPitch;
    int bufferSize;
 
    std::unique_ptr<FUpdateTextureRegion2D> echoUpdateTextureRegion;
    void setPixelColor(uint8*& pointer, uint8 red, uint8 green, uint8 blue, uint8 alpha);
    void setPixelColor(uint8*& pointer, uint8 red);
    
    UFUNCTION(BlueprintCallable, Category = DrawingTools)
    void DrawLife(AGoLUser* GoL);
};