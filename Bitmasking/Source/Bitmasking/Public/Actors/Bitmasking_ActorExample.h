// Copyright Vicente Danzmann. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bitmasking_ActorExample.generated.h"

/**
 * Example actor where using bitmasks to define current negative stats could be useful.
 */
UCLASS()
class ABitmasking_ActorExample : public AActor
{
	GENERATED_BODY()

	public:
		void BeginPlay() override;
	
		UFUNCTION(BlueprintPure)
		int32 GetDebuffs() const;

		UFUNCTION(BlueprintCallable, Meta = (ToolTip = "Match the enum file path in the declaration of this function in C++ to your project!"))
		void SetDebuffs(UPARAM(Meta = (Bitmask, BitmaskEnum = "/Script/MyProject.EBitmasking_ElementalDamage")) const int32 NewDebuffs);

	private:
		int32 Debuffs = 0;
};
