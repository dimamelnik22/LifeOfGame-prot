// Fill out your copyright notice in the Description page of Project Settings.

#include "NavButtonsComponent.h"

// Sets default values for this component's properties
UNavButtonsComponent::UNavButtonsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
    
    Parent = GetOwner();
    //NavComp = Cast<UNavigationComponent>(Parent->GetComponentByClass(UNavigationComponent::StaticClass()));
	if (Parent!=NULL)	NavComp = Parent->FindComponentByClass<UNavigationComponent>();
}

void UNavButtonsComponent::UpdateButtons(){
	for (int i = 0; i < Buttons.Num(); ++i) Buttons[i]->Destroy();
	Buttons.Empty();
    int R = NavComp->R;
    if (NavComp->field == nullptr) return;
    for (int i=0;i<2*R+1;++i)
        for (int j=0;j<2*R+1;++j){
            if (NavComp->field[i][j].steps <= R) {
                FVector Location = this->Parent->GetActorLocation();
                Location.Y += (i-R)*100.0f;
                Location.X += (j-R)*100.0f;
				//Location.Z += 100.0f;
                FActorSpawnParameters SpawnInfo;
				FRotator rot = FRotator::ZeroRotator;
				switch (NavComp->field[i][j].direction) {
					case 0:
						//rot = FRotator::ZeroRotator;
						rot.Yaw = 0;
						break;
					case 1:
						rot.Yaw = -90;
						break;
					case 2:
						rot.Yaw = 180;
						break;
					case 3:
						rot.Yaw = 90;
						break;	
				}
				//ANavButton* tmp = GetWorld()->SpawnActor(ButtonToSpawn.Get(),Location, FRotator::ZeroRotator, SpawnInfo);
				ANavButton* tmp = (ANavButton*) GetWorld()->SpawnActor(ButtonToSpawn, &Location, &rot, SpawnInfo);
				if (tmp == NULL) return;
				tmp->x = i - R;
				tmp->y = j - R;
				tmp->steps = NavComp->field[i][j].steps;
				#if WITH_EDITOR
				tmp->SetFolderPath("SpawnedActors/NavButtons");  // �������� ����
				#endif
                Buttons.Add(tmp);
            }
        }
	//Buttons.Num();
}

//void UNavButtonsComponent::SetNavButton(ANavButton * Button)
//{
//	ButtonToSpawn = Button;
//}


// Called when the game starts
void UNavButtonsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UNavButtonsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
