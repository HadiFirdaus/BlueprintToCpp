// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameplay/CuttableTree.h"

ACuttableTree::ACuttableTree()
{
	TreeStumpComp = CreateDefaultSubobject<UStaticMeshComponent>("TreeStumpComp");
	TreeStumpComp->SetupAttachment(PFXRootSceneComp);
}
