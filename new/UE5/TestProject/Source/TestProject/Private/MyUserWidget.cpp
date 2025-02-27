// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"

bool UMyUserWidget::Initialize()
{
    if (!Super::Initialize())
        return false;

    // 给按钮添加绑定事件
    ButtonStart->OnClicked.AddDynamic(this, &UMyUserWidget::Start);
    ButtonQuit->OnClicked.AddDynamic(this, &UMyUserWidget::Quit);

    return true;
}

void UMyUserWidget::UpdateHealth()
{
    if (CurrentHealth <= 0)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Death"));
    }
    else
    {
        CurrentHealth -= 10;
    }
}

void UMyUserWidget::Start()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Start is Clicked!"));
    UpdateHealth();
}

void UMyUserWidget::Quit()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Quit is Clicked!"));
}
