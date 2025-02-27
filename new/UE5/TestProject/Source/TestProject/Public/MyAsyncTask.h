// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Async/AsyncWork.h"

/**
 * 
 */
class TESTPROJECT_API MyAsyncTask : public FNonAbandonableTask
{

	friend class FAutoDeleteAsyncTask<MyAsyncTask>;

public:
	MyAsyncTask();
	~MyAsyncTask();

public:
	void DoWork();

	FORCENOINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(MyAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}

	FORCENOINLINE static const TCHAR* GetTaskName()
	{
		return TEXT("MyAsyncTask");
	}
};
