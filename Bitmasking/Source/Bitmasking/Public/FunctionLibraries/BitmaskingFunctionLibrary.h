// Copyright Vicente Danzmann. All rights reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BitmaskingFunctionLibrary.generated.h"

/**
 * Simplifies bitmasks use in C++ and Blueprints by providing generic functions to most common operations.
 */
UCLASS()
class UBitmaskingFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:
		/**
		 * Add/set flags in a bitmask variable.
		 * @param Flags Bitmask variable with current values.
		 * @param FlagsToAdd Bitflags to add/set in Flags.
		 * @return The new bitmask value with FlagsToAdd added/set on it.
		 * @note You can use Make Bitmask node and pass it as an argument to Flags. You may choose which Enum class the node represents.
		 */
		UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Add Flags"))
		static int32 Blueprint_AddFlags(int32 Flags, const int32 FlagsToAdd);
	
		/**
		 * Remove/unset flags in a bitmask variable.
		 * @param Flags Bitmask variable with current values.
		 * @param FlagsToRemove Bitflags to remove/unset in Flags.
		 * @return The new bitmask value with FlagsToRemove removed/unset on it.
		 * @note You can use Make Bitmask node and pass it as an argument to Flags. You may choose which Enum class the node represents.
		 */
		UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Remove Flags"))
		static int32 Blueprint_RemoveFlags(int32 Flags, const int32 FlagsToRemove);

		/**
		 * Flip flags in a bitmask variable.
		 * @param Flags Bitmask variable with current values.
		 * @param FlagsToFlip Bitflags to flip their values in Flags.
		 * @return The new bitmask value with FlagsToFlip flipped on it.
		 * @note You can use Make Bitmask node and pass it as an argument to Flags. You may choose which Enum class the node represents.
		 */
		UFUNCTION(BlueprintCallable, Meta = (DisplayName = "Flip Flags"))
		static int32 Blueprint_FlipFlags(int32 Flags, const int32 FlagsToFlip);

		/**
		 * Check if all required values are added/set in bitmask variable.
		 * @param Flags Bitmask variable with current values.
		 * @param FlagsToCheck Bitflags to check if all their values are added/set in Flags.
		 * @return Whether all FlagsToCheck are added/set in Flags.
		 * @note You can use Make Bitmask node and pass it as an argument to Flags. You may choose which Enum class the node represents.
		 */
		UFUNCTION(BlueprintPure, Meta = (DisplayName = "Has All Flags"))
		static bool Blueprint_HasAllFlags(const int32 Flags, const int32 FlagsToCheck);

		/**
		 * Check if any of the required values are added/set in bitmask variable.
		 * @param Flags Bitmask variable with current values.
		 * @param FlagsToCheck Bitflags to check if any of their values are added/set in Flags.
		 * @return Whether any of the FlagsToCheck are added/set in Flags.
		 * @note You can use Make Bitmask node and pass it as an argument to Flags. You may choose which Enum class the node represents.
		 */
		UFUNCTION(BlueprintPure, Meta = (DisplayName = "Has Any Flags"))
		static bool Blueprint_HasAnyFlags(const int32 Flags, const int32 FlagsToCheck);
	
		/**
		 * Add/set flags in a bitmask variable.
		 * @param Flags Bitmask variable with current values.
		 * @param FlagsToAdd Bitflags to add/set in Flags.
		 * @note To add/set more than one flag, you can call the function like this: AddFlags(Flags, EFlags::Flag1 | EFlags::Flag2);
		 */
		template <typename TEnum>
		static void AddFlags(int32& Flags, const TEnum FlagsToAdd)
		{
			static_assert(TIsEnum<TEnum>::Value, "Should only call this with Enum types.");
			Flags |= (static_cast<int32>(FlagsToAdd));
		}
			
		/**
		 * Remove/unset flags in a bitmask variable.
		 * @param Flags Bitmask variable with current values.
		 * @param FlagsToRemove Bitflags to remove/unset in Flags.
		 * @note To remove/unset more than one flag, you can call the function like this: RemoveFlags(Flags, EFlags::Flag1 | EFlags::Flag2);
		 */
		template <typename TEnum>
		static void RemoveFlags(int32& Flags, const TEnum FlagsToRemove)
		{
			static_assert(TIsEnum<TEnum>::Value, "Should only call this with Enum types.");
			Flags &= ~(static_cast<int32>(FlagsToRemove));
		}
	
		/**
		 * Flip flags in a bitmask variable.
		 * @param Flags Bitmask variable with current values.
		 * @param FlagsToFlip Bitflags to flip their values in Flags.
		 * @note To flip more than one flag, you can call the function like this: FlipFlags(Flags, EFlags::Flag1 | EFlags::Flag2);
		 */
		template <typename TEnum>
		static void FlipFlags(int32& Flags, const TEnum FlagsToFlip)
		{
			static_assert(TIsEnum<TEnum>::Value, "Should only call this with Enum types.");
			Flags ^= (static_cast<int32>(FlagsToFlip));
		}

		/**
		 * Check if all required values are added/set in bitmask variable.
		 * @param Flags Bitmask variable with current values.
		 * @param FlagsToCheck Bitflags to check if all their values are added/set in Flags.
		 * @return Whether all FlagsToCheck are added/set in Flags.
		 * @note To check if more than one flag is added/set, you can call the function like this: HasAllFlags(Flags, EFlags::Flag1 | EFlags::Flag2);
		 */
		template <typename TEnum>
		static bool HasAllFlags(int32 Flags, const TEnum FlagsToCheck)
		{
			static_assert(TIsEnum<TEnum>::Value, "Should only call this with Enum types.");
			return EnumHasAllFlags(static_cast<TEnum>(Flags), FlagsToCheck);
		}

		/**
		 * Check if any of the required values are added/set in bitmask variable.
		 * @param Flags Bitmask variable with current values.
		 * @param FlagsToCheck Bitflags to check if any of their values are added/set in Flags.
		 * @return Whether any of the FlagsToCheck are added/set in Flags.
		 * @note To check if more than one flag is added/set, you can call the function like this: HasAnyFlags(Flags, EFlags::Flag1 | EFlags::Flag2);
		 */
		template <typename TEnum>
		static bool HasAnyFlags(int32 Flags, const TEnum FlagsToCheck)
		{
			static_assert(TIsEnum<TEnum>::Value, "Should only call this with Enum types.");
			return EnumHasAnyFlags(static_cast<TEnum>(Flags), FlagsToCheck);
		}
};
