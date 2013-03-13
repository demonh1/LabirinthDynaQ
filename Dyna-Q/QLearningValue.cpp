#include "StdAfx.h"
#include "QLearningValue.h"

QLearningValue::QLearningValue(int state,int act)
:mState(state),
mAction(act),
mQval(0)
{

	

}

QLearningValue::~QLearningValue(void)
{
}

int QLearningValue::getQLearnindS()const
{
	return mState;

}

int QLearningValue::getQLearningA()const
{
	return mAction;

}

float QLearningValue::getQLearningV()const
{
	return mQval;

}

void QLearningValue::setQLearningValue( int s,int a,float Q) 
{

	this->mAction=a;
	this->mQval=Q;
	this->mState=s;
}

void QLearningValue::setQLearningV(float Q)
{
	this->mQval=Q;

}




