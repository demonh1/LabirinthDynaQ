#include "StdAfx.h"
#include "Model.h"

Model::Model(int state,int action,int res,int r)
:mPlanningState(state),
mPlanningAction(action),
mPlanningResultState(res),
mPlanningRewards(r)
{
}

Model::~Model(void)
{
}

int Model::getPlanningResultState() const
{
return this->mPlanningResultState;
}

int Model::getPlanningAction() const
{
	return this->mPlanningAction;

}

int Model::getPlanningState() const
{
	return this->mPlanningState;

}

int Model::getPlanningRewards() const
{
	return this->mPlanningRewards;

}



void Model::setModelResState( int s )
{
	this->mPlanningResultState=s;
}

void Model::setModelRewards( int r)
{
	this->mPlanningRewards=r;
}
