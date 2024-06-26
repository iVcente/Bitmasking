// Copyright Vicente Danzmann. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FBitmaskingModule : public IModuleInterface
{
	public:

		// IModuleInterface implementation
		virtual void StartupModule() override;
		virtual void ShutdownModule() override;
};
