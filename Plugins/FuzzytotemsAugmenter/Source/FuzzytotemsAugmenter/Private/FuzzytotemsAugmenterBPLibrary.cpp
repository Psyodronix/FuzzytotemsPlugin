// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "FuzzytotemsAugmenterPrivatePCH.h"
#include "FuzzytotemsAugmenterBPLibrary.h"

UFuzzytotemsAugmenterBPLibrary::UFuzzytotemsAugmenterBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

bool UFuzzytotemsAugmenterBPLibrary::TArraySortFloat(TArray<float> input, TArray<float> &output, ESortType setting = ESortType::EST_Sort)
{
	return InternalPrimitiveSort<float>(input, output, setting);
}

bool UFuzzytotemsAugmenterBPLibrary::TArraySortInt(TArray<int32> input, TArray<int32> &output, ESortType setting = ESortType::EST_Sort)
{
	return InternalPrimitiveSort<int32>(input, output, setting);
}

bool UFuzzytotemsAugmenterBPLibrary::TArraySortString(TArray<FString> input, TArray<FString> &output, ESortType setting = ESortType::EST_Sort)
{
	return InternalPrimitiveSort<FString>(input, output, setting);
}

bool UFuzzytotemsAugmenterBPLibrary::TArraySortName(TArray<FName> input, TArray<FName> &output, ESortType setting = ESortType::EST_Sort)
{
	return InternalPrimitiveSort<FName>(input, output, setting);
}

//bool UFuzzytotemsAugmenterBPLibrary::TArraySortText(TArray<FText> input, TArray<FText> &output, ESortType setting = ESortType::EST_Sort)
//{
//	return InternalPrimitiveSort<FText>(input, output, setting);
//}

template<typename t>
bool UFuzzytotemsAugmenterBPLibrary::InternalPrimitiveSort(TArray<t> input, TArray<t> &output, ESortType setting)
{
	switch (setting)
	{
	case ESortType::EST_UnstableSort:
		input.Sort();
		break;
	case ESortType::EST_HeapSort:
		input.HeapSort();
		break;
	case ESortType::EST_Sort:
	default:
		input.StableSort();
		break;
	}

	output = input;

	return true;
}