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
#include "WarBrais.h"

#define LOCTEXT_NAMESPACE "EtherealText"

// Sets default values
AWarBrais::AWarBrais(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_WarBrais.ArmorIcon_WarBrais'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_WarBrais-small.ArmorIcon_WarBrais-small'"));

	// Set Default Objects
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;
	
	// Set Default Values
	Name = EMasterGearList::GL_WarBrais;
	NameText = LOCTEXT("WarBraisName", "War Brais");
	Type = EMasterGearTypes::GT_Legs;
	TypeText = LOCTEXT("WarBraisType", "Legs");
	Description = "Ethereal Assassins infused the War Armor with dark power, which proved an effective defense against Zhan's betrayal.";
	MPCost = 0;
	ATK = 4;
	DEF = 7;
	SPD = 4;
	HP = 60;
	MP = 30;
}

// Called when the game starts or when spawned
void AWarBrais::BeginPlay()
{
	Super::BeginPlay();
}

#undef LOCTEXT_NAMESPACE