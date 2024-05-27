// Copyright Vicente Danzmann. All rights reserved.

#pragma once

#include "EBitmasking_ElementalDamage.generated.h"

/**
 * Example enum that using bitmasks can be useful.
 */
UENUM(BlueprintType, Meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EBitmasking_ElementalDamage : uint8
{
	None      = 0 UMETA(Hidden), // 0x00
	Fire      = 1,               // 0x01 // 1 << 0
	Frost     = 2,               // 0x02 // 1 << 1
	Lightning = 4,               // 0x04 // 1 << 2
	Poison    = 8                // 0x08 // 1 << 3
};

ENUM_CLASS_FLAGS(EBitmasking_ElementalDamage)
ENUM_RANGE_BY_FIRST_AND_LAST(EBitmasking_ElementalDamage, EBitmasking_ElementalDamage::None, EBitmasking_ElementalDamage::Poison)
