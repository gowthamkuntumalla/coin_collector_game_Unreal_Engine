// Fill out your copyright notice in the Description page of Project Settings.


#include "coin_man.h"

// Sets default values
Acoin_man::Acoin_man()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    GetCapsuleComponent()->InitCapsuleSize(42.0f,96.0f);
    
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;
    
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f,540.f,0.0f);
    GetCharacterMovement()->JumpZVelocity = 600.0f;
    
    CameraBoom = CreateDefaultSubobject<USpringArmComponent> (TEXT("CameraBoom"));
    CameraBoom->SetupAttachment (RootComponent);
    
    CameraBoom-> TargetArmLength = 300.0f;
    CameraBoom->bUsePawnControlRotation = true;
    
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent:: SocketName);
    FollowCamera-> bUsePawnControlRotation = false;
    
    bDead = false;
    
    

}




// Called when the game starts or when spawned
void Acoin_man::BeginPlay()
{
	Super::BeginPlay();
    
    GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this,&Acoin_man::OnBeginOverlap);
	
}

// Called every frame
void Acoin_man::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Acoin_man::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    PlayerInputComponent-> BindAxis("Turn",this,&APawn::AddControllerYawInput);
    PlayerInputComponent-> BindAxis("LookUp",this,&APawn::AddControllerPitchInput);

    PlayerInputComponent-> BindAction("Jump",IE_Pressed,this,&ACharacter::Jump);
    PlayerInputComponent-> BindAction("Jump",IE_Released,this,&ACharacter::StopJumping);
    
    PlayerInputComponent-> BindAxis("MoveForward",this,&Acoin_man::MoveForward);
    PlayerInputComponent-> BindAxis("MoveRight",this,&Acoin_man::MoveRight);
    
}


void Acoin_man::MoveForward(float Axis){
    if (!bDead){
        
        const FRotator Rotation = Controller-> GetControlRotation();
        const FRotator YawRotation(0,Rotation.Yaw,0);
        
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        
        AddMovementInput(Direction, Axis);
    }
    
}

void Acoin_man::MoveRight(float Axis){
    
    if (!bDead){
        
        const FRotator Rotation = Controller-> GetControlRotation();
        const FRotator YawRotation(0,Rotation.Yaw,0);
        
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        
        AddMovementInput(Direction, Axis);
    }
    
}

void Acoin_man::OnBeginOverlap(UPrimitiveComponent* HitComp,AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                               bool bFromSweep, const FHitResult &SweepResult){
    
    if(OtherActor->ActorHasTag("Recharge")){
        UE_LOG(LogTemp, Warning, TEXT("Collided with "));
    }
}
