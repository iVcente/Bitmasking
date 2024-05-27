// Copyright Vicente Danzmann. All rights reserved.

#include "FunctionLibraries/BitmaskingFunctionLibrary.h"

int32 UBitmaskingFunctionLibrary::Blueprint_AddFlags(int32 Flags, const int32 FlagsToAdd)
{
	return Flags |= FlagsToAdd;
}

int32 UBitmaskingFunctionLibrary::Blueprint_RemoveFlags(int32 Flags, const int32 FlagsToRemove)
{
	return Flags &= ~FlagsToRemove;
}

int32 UBitmaskingFunctionLibrary::Blueprint_FlipFlags(int32 Flags, const int32 FlagsToFlip)
{
	return Flags ^= FlagsToFlip;
}

bool UBitmaskingFunctionLibrary::Blueprint_HasAnyFlags(const int32 Flags, const int32 FlagsToCheck)
{
	return (Flags & FlagsToCheck) != 0;
}

bool UBitmaskingFunctionLibrary::Blueprint_HasAllFlags(const int32 Flags, const int32 FlagsToCheck)
{
	return (Flags & FlagsToCheck) == FlagsToCheck;
}
