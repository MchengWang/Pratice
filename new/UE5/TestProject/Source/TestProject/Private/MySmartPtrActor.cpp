// Fill out your copyright notice in the Description page of Project Settings.


#include "MySmartPtrActor.h"

// Sets default values
AMySmartPtrActor::AMySmartPtrActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMySmartPtrActor::BeginPlay()
{
	Super::BeginPlay();
	//TestAFunction();  
	//TestBFunction();  
	TestCFunction();  
}

// Called every frame
void AMySmartPtrActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMySmartPtrActor::TestAFunction()
{
	// 通过创建C++原生指针，在转换成UE智能指针 这种方式容易混淆原生和共享指针，不推荐
	A* ptr1 = new A(1, 3.2f);
	TSharedPtr<A> Sharedptr2(ptr1); 

	// 共享指针右值初始化
	TSharedPtr<A> Sharedptr3(new A(2, 3.60f));

	// 通过拷贝构造初始化
	TSharedPtr<A> Sharedptr4(Sharedptr2);

	// UE 推荐的共享指针初始化
	TSharedPtr<A> Sharedptr5 = nullptr; // 可以为空
	Sharedptr5 = MakeShareable(new A(10284, 368.0f));

	// 线程安全的共享
	TSharedPtr<A, ESPMode::ThreadSafe> Sharedptr6(new A(10284, 360.f));
	
	// 共享指针常用的接口
	if (Sharedptr5.IsValid()) // 指针是否有效
	{
		TSharedRef<A> SharedRef1(new A(10284, 368.f));
		SharedRef1 = Sharedptr5.ToSharedRef(); // 将指针转化为引用，引用计数加1
		int32 Count1 = Sharedptr5.GetSharedReferenceCount(); // 获取引用计数
		UE_LOG(LogTemp, Warning, TEXT("Count1 is %d"), Count1);
		if (!Sharedptr5.IsUnique()) // 判断是否唯一即引用计数为1
		{
			UE_LOG(LogTemp, Warning, TEXT("sharedptr5 is not Unique"));
		}
		// 解引用就是原生指针
		UE_LOG(LogTemp, Warning, TEXT("a of the ptr is %d"), Sharedptr5.Get()->a);
		Sharedptr5.Reset(); // 将共享指针置为空
		int32 Count2 = Sharedptr5.GetSharedReferenceCount();
		UE_LOG(LogTemp, Warning, TEXT("Count2 is %d"), Count2);
	}
}

void AMySmartPtrActor::TestBFunction()
{
	// 共享引用初始化的时候必须指向一个有效的对象
	TSharedRef<A> SharedRef2(new A(10284, 368.0f));
	if (SharedRef2.IsUnique()) // 判断引用是否唯一
	{
		UE_LOG(LogTemp, Warning, TEXT("2a is %d"), SharedRef2->a);
		// 引用 -> 指针
		TSharedPtr<A> Sharedptr6;
		Sharedptr6 = SharedRef2;
		UE_LOG(LogTemp, Warning, TEXT("2a is %f"), Sharedptr6.Get()->b);
	}
}

void AMySmartPtrActor::TestCFunction()
{
	// 弱指针解决了循环引用，只对弱指针保留引用不参与引用计数
	// 不能组织对象被销毁，如果弱指针指向对象被销毁，弱指针会自动清空
	TSharedPtr<A> Sharedptr7 = MakeShareable(new A(10284, 368.0f));
	TSharedPtr<A> SharedRef3(new A(10284, 368.0f));

	// 声明弱指针并初始化
	TWeakPtr<A> WeakPtr1(Sharedptr7);
	TWeakPtr<A> WeakPtr2(SharedRef3);
	if (WeakPtr1.IsValid())
	{
		TSharedPtr<A> Sharedptr8(WeakPtr1.Pin());
		if (Sharedptr8.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("8a is %d"), Sharedptr8.Get()->a);
		}
	}
}

