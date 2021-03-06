// Ãƒ€šÃ‚© 2014 - 2016 Soverance Studios
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
#include "LeatherCap.h"

#define LOCTEXT_NAMESPACE "EtherealText"

// Sets default values
ALeatherCap::ALeatherCap(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_LeatherCap.ArmorIcon_LeatherCap'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_LeatherCap-small.ArmorIcon_LeatherCap-small'"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> ArmorMeshObject(TEXT("SkeletalMesh'/Game/EtherealParty/Morgan/Clothes/LeatherArmor/LeatherCap/LeatherCap.LeatherCap'"));

	// Set Default Objects
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	SK_ArmorMesh = ArmorMeshObject.Object;
	ArmorMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("ArmorMesh"));
	ArmorMesh->SetSkeletalMesh(SK_ArmorMesh);
	ArmorMesh->SetupAttachment(RootComponent);
	UCommonLibrary::SetupSKComponentsWithCollision(ArmorMesh);
	
	// Set Default Values
	Name = EMasterGearList::GL_LeatherCap;
	NameText = LOCTEXT("LeatherCapName", "Leather Cap");
	Type = EMasterGearTypes::GT_Head;
	TypeText = LOCTEXT("LeatherCapType", "Head");
	Description = "Armor of Ethereal Warriors.";
	Price = 5000;
	MPCost = 0;
	ATK = 1;
	DEF = 2;
	SPD = 1;
	HP = 15;
	MP = 5;
	SpecialEffectText = LOCTEXT("LeatherCapSpecialEffect", "Cure Potency +5%.");
}

// Called when the game starts or when spawned
void ALeatherCap::BeginPlay()
{
	Super::BeginPlay();

	// Bind this function to the event dispatcher for Bind Gear
	OnBindGear.AddDynamic(this, &ALeatherCap::DoSpecialEffect);
	OnRemoveGear.AddDynamic(this, &ALeatherCap::RemoveSpecialEffect);
}

// Custom code for Special Effect
void ALeatherCap::DoSpecialEffect()
{
	OwnerReference->BoostCurePotency = 0.05f;  // Cure Potency +5%
}

// Custom code for Special Effect
void ALeatherCap::RemoveSpecialEffect()
{
	OwnerReference->BoostCurePotency = 0.0f;
}

#undef LOCTEXT_NAMESPACE
