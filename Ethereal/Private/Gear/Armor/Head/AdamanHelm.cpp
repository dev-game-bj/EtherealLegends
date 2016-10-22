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
#include "AdamanHelm.h"

#define LOCTEXT_NAMESPACE "EtherealText"

// Sets default values
AAdamanHelm::AAdamanHelm(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_AdamanHelm.ArmorIcon_AdamanHelm'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_AdamanHelm-small.ArmorIcon_AdamanHelm-small'"));

	// Set Default Objects
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;
	
	// Set Default Values
	Name = EMasterGearList::GL_AdamanHelm;
	NameText = LOCTEXT("AdamanHelmName", "Adaman Helm");
	Type = EMasterGearTypes::GT_Head;
	TypeText = LOCTEXT("AdamanHelmType", "Head");
	Description = "The Adaman Armor set was once issued as a reward to Ethereal Knights who complete their training.";
	MPCost = 0;
	ATK = 2;
	DEF = 4;
	SPD = 1;
	HP = 30;
	MP = 10;
}

// Called when the game starts or when spawned
void AAdamanHelm::BeginPlay()
{
	Super::BeginPlay();
}

#undef LOCTEXT_NAMESPACE