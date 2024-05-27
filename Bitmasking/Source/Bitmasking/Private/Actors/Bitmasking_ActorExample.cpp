// Copyright Vicente Danzmann. All rights reserved.

#include "Actors/Bitmasking_ActorExample.h"

#include "Enums/EBitmasking_ElementalDamage.h"
#include "FunctionLibraries/BitmaskingFunctionLibrary.h"

void ABitmasking_ActorExample::BeginPlay()
{
	Super::BeginPlay();

	// Set actor's negative stats as fire and lightning
	UBitmaskingFunctionLibrary::AddFlags(Debuffs, EBitmasking_ElementalDamage::Fire | EBitmasking_ElementalDamage::Lightning);

	// Check if actor has lightning or poison negative stats
	bool bResult = UBitmaskingFunctionLibrary::HasAnyFlags(Debuffs, EBitmasking_ElementalDamage::Poison | EBitmasking_ElementalDamage::Lightning);
}

int32 ABitmasking_ActorExample::GetDebuffs() const
{
	return Debuffs;
}

void ABitmasking_ActorExample::SetDebuffs(const int32 NewDebuffs)
{
	Debuffs = NewDebuffs;
}
