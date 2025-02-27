// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestAsyncActor.h"
#include "MyAsyncTask.h"
#include "Async/Async.h"

// Sets default values
AMyTestAsyncActor::AMyTestAsyncActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTestAsyncActor::BeginPlay()
{
	Super::BeginPlay();

	//FAutoDeleteAsyncTask<MyAsyncTask>* MyTask = new FAutoDeleteAsyncTask<MyAsyncTask>();
	//MyTask->StartBackgroundTask(); // 异步线程。线程池
	//MyTask->StartSynchronousTask(); // 当前线程

	Async(EAsyncExecution::ThreadPool, []() {
		for (int32 i = 0; i < 1000; i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("i = %d"), i);
		}
		});
	
}

// Called every frame
void AMyTestAsyncActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

