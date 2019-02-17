// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter2GameModeBase.h"
#include "UserProfile.h"



void AChapter2GameModeBase::StartPlay()
{
	Super::StartPlay();

	auto* gm = Cast<AChapter2GameModeBase>(GetWorld()->GetAuthGameMode());

	if (gm)
	{
		// ConstructObject�� �������� �ʴ´�. deprecated.

		auto* newObject = NewObject<UUserProfile>();
	}
}
