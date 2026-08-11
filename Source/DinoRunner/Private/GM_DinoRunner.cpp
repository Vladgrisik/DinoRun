#include "GM_DinoRunner.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "MyBaseTile.h"
#include "MyDinoCharacter.h"


void AGM_DinoRunner::BeginPlay()
{
    Super::BeginPlay();

    // 1. Get all tiles
    TArray<AActor*> FoundTiles;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyBaseTile::StaticClass(), FoundTiles);
    MyPlayer_Ref = Cast<AMyDinoCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
    if (FoundTiles.Num() > 0)
    {
        // 2. Беремо перший
        BaseTileRef = Cast<AMyBaseTile>(FoundTiles[0]);
        
    }

    // 3. Spawn tiles
    Spawn_Tiles(10);
    
}

void AGM_DinoRunner::Spawn_Tiles(int32 Amount)
{

    for (int32 i = 0; i < Amount; i++)
        {
        // 1. Transform
        FTransform SpawnTransform;
        SpawnTransform.SetLocation(NextSpawnPoint);
        SpawnTransform.SetRotation(FQuat::Identity);
        SpawnTransform.SetScale3D(FVector(1.f));
        }
} 

/*
void AGM_DinoRunner::Main_Spawner()
{
    if (!BaseTileRef) return;

    for (int32 i = 1; i <= 5; i++)
    {
        if (bCanSpawn)
            {
            // 1. Вибираємо випадковий індекс
            int32 Index = FMath::RandRange(1, 5);

            UArrowComponent* ChosenPoint = nullptr;

            switch (Index)
                {
                case 1: ChosenPoint = BaseTileRef->Spawn_Location1; break;
                case 2: ChosenPoint = BaseTileRef->Spawn_Location2; break;
                case 3: ChosenPoint = BaseTileRef->Spawn_Location3; break;
                case 4: ChosenPoint = BaseTileRef->Spawn_Location4; break;
                case 5: ChosenPoint = BaseTileRef->Spawn_Location5; break;
                default: break;
                }

            // 2. Set spawn point
            if (ChosenPoint)
                {
                    Obstacle_Spawn_Point = ChosenPoint;
                }

            // 3. Spawn obstacle
            Spawn_Obstacles();

            // 4. Toggle
            bCanSpawn = false;
        }
        else
        {
            bCanSpawn = true;
        }
    }
}

void AGM_DinoRunner::Spawn_Meats(int32 Amount, bool Already_Spawning, double Spawn_After_Location)
{
    if (Already_Spawning)
    {
        if (SomeInternalCounter == 0)
        {
            Meat_Amount_To_Spawn = UKismetMathLibrary::RandomIntegerInRange(1, 3);
        }
        else
        {
            Meat_Amount_To_Spawn = SomeInternalCounter;
        }

        Spawn_Meats(Meat_Amount_To_Spawn, true, 300.0);
    }
    else
    {
        Meat_Amount_To_Spawn = Amount;
        SomeInternalCounter = Amount;
        
        bool bShouldStartSpawning = (Amount > 0);
        
        Spawn_Meats(Meat_Amount_To_Spawn, bShouldStartSpawning, Spawn_After_Location);
    }
}

void AGM_DinoRunner::Set_Character()
{
    USaveGame* LoadedGame = UGameplayStatics::LoadGameFromSlot(TEXT("Savegame"), 0);
    SaveGameRef = Cast<UBP_DinoSaveGame>(LoadedGame);

    if (SaveGameRef)
    {
        Current_Character_Index = SaveGameRef->Character_Index_Selected;

        if (SaveGameRef->Characters_Info.IsValidIndex(Current_Character_Index))
        {
            FCharacter_Data_Sructure SelectedData = SaveGameRef->Characters_Info[Current_Character_Index];

            if (Player_Ref && Player_Ref->GetMesh())
            {
                Player_Ref->GetMesh()->SetSkeletalMeshAsset(SelectedData.Mesh);

                FVector NewScale = FVector(SelectedData.Scale);
                Player_Ref->GetMesh()->SetWorldScale3D(NewScale);
            }
        }
    }
}
*/
