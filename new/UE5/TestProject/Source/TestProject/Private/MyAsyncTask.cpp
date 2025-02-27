// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAsyncTask.h"

MyAsyncTask::MyAsyncTask()
{
}

MyAsyncTask::~MyAsyncTask()
{
	UE_LOG(LogTemp, Warning, TEXT("AsyncTask End >>>>>>>>"));
}

void MyAsyncTask::DoWork()
{
	UE_LOG(LogTemp, Warning, TEXT("AsyncTask Start >>>>>>>>"));
	for (int32 i = 0; i < 1000; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("i = %d"), i);
	}
}
