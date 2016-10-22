// © 2014 - 2016 Soverance Studios
// http://www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"
#include "ShadowRing.h"

#define LOCTEXT_NAMESPACE "EtherealText"

// Sets default values
AShadowRing::AShadowRing(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_ShadowRing.ArmorIcon_ShadowRing'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_ShadowRing-small.ArmorIcon_ShadowRing-small'"));

	// Set Default Objects
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;
	
	// Set Default Values
	Name = EMasterGearList::GL_ShadowRing;
	NameText = LOCTEXT("ShadowRingName", "Shadow Ring");
	Type = EMasterGearTypes::GT_Ring;
	TypeText = LOCTEXT("ShadowRingType", "Ring");
	Description = "Forged deep within the Shadow Realm, the ring ccasionally annulls all damage taken.";
	MPCost = 0;
	ATK = 5;
	DEF = 10;
	SPD = 5;
	HP = 0;
	MP = 50;
}

// Called when the game starts or when spawned
void AShadowRing::BeginPlay()
{
	Super::BeginPlay();
}

#undef LOCTEXT_NAMESPACE