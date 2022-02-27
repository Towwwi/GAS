// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/ASCBase.h"
#include "ASCBase.h"

void UASCBase::ReceiveDamage(UASCBase* SourceASC, float UnmitigatedDamage, float MitigatedDamage)
{
		ReceivedDamage.Broadcast(SourceASC, UnmitigatedDamage, MitigatedDamage);
}
