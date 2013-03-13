#include "StdAfx.h"
#include "QLearningAgent.h"
#include <algorithm>
#include <vector>

using namespace Environment;

QLearningAgent::QLearningAgent(void):mReward(0)
{


}

QLearningAgent::~QLearningAgent(void)
{
	
}

void QLearningAgent::run()
{

	srand(time(NULL));


for (int i=0;i<((Environment::cols)*(Environment::rows));i++)
for (int j=0;j<4;j++)
{
	
	std::tr1::shared_ptr<QLearningValue> QLV(new QLearningValue(i,Environment::actions[j]));
	QLerningTable.push_back(QLV);

	
}

mState=Environment::initialState;
//пока разность между оценками остается велика 
for (int count=0;count<2;count++)
{
	newEpisode();
}


std::vector<std::tr1::shared_ptr<QLearningValue>>::iterator it1=QLerningTable.begin();
std::cout<<"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ "<<std::endl;
for (;it1!=QLerningTable.end();++it1)
{
	std::cout<<"S "<<(*it1)->getQLearnindS()<<" A "<<(*it1)->getQLearningA()<<" Q "<<(*it1)->getQLearningV()<<std::endl;
}


int i;
std::cin>>i;
}

 void QLearningAgent::goDo()
 {
 switch(mCurrentAct) { 
 
 		  /* элемент в верхней строке переходящий 
 	наверх или элемент расположенный выше*/
 		case 0: 
			mNextState=((mState-(Environment::cols))<(Environment::cols) || Environment::states[mState-Environment::cols]==1)? mState : (mState-Environment::cols);
 			break; 
 		case 2:
			mNextState=(((mState)+Environment::cols) >=((Environment::rows)*(Environment::cols)) || Environment::states[mState+Environment::cols]==1)? mState : (mState+Environment::cols);
 			break; 
 		case 1:
			mNextState=(((mState+1)%(Environment::cols))==0 || Environment::states[mState+1]==1)?mState:(mState+1);
 			break;
 		case 3:
			mNextState=(((mState)%(Environment::cols))==0 || Environment::states[mState-1]==1)?mState:(mState-1);
 			break;
 			} 
 if(mNextState==Environment::terminated)
 {mReward=1;}


 
 }



void QLearningAgent::newEpisode()
{

	while (mState!=Environment::terminated)
	{
		newStep();
	}
	
	mState=Environment::initialState;
	mReward=0;


}

void QLearningAgent::newStep()
{


	//получение из типов QLearningValue значения жадного действия
	mCurrentAct= (*filtersIterator[getGreadly(mState)])->getQLearningA();

	this->goDo();//nextStep


	float Qsa=getQLerningbySA(mState,mCurrentAct)->getQLearningV();
	float alpha=(Environment::alpha);
	float g=(Environment::gamma);
	float nextsa=(*filtersIterator[getGreadly(mNextState)])->getQLearningV();

	float QRL=Qsa+alpha*(mReward+g*nextsa-Qsa);//формула расчета


	getQLerningbySA(mState,mCurrentAct)->setQLearningV(QRL);
	

	
///adding to model
	setModel(  mState, mCurrentAct, mNextState, mReward);

	this->planning();

	mState=mNextState;
	ModelTable;QLerningTable;

}



int QLearningAgent::getGreadly(int state)
{

	
	filtersIterator.clear();
	filterQbyS(QLerningTable.begin(),state);
	int randIdModel= rand() % filtersIterator.size();
	return randIdModel;
}

std::tr1::shared_ptr<QLearningValue> QLearningAgent::getQLerningbySA(int s,int a)
{

	//если не нашел то возврат первого

	std::vector<std::tr1::shared_ptr<QLearningValue>>::iterator Q;
	std::vector<std::tr1::shared_ptr<QLearningValue>>::iterator it= QLerningTable.begin();

	for( ; it != QLerningTable.end() ; ++(it) )
	{
		if ((*it)->getQLearnindS()==s && (*it)->getQLearningA()==a)Q=it;
	}
	return (*Q);

}



 void QLearningAgent::planning()
 {
 
 	for (int i=0;i<Environment::N;i++)
 	{
 	
  		int randIdModel=randomValue(ModelTable.size());//случайный элемент модели
 
		 int reward=ModelTable[randIdModel]->getPlanningRewards();
		 int state=ModelTable[randIdModel]->getPlanningState();
		 int act=ModelTable[randIdModel]->getPlanningAction();
		 int nex=ModelTable[randIdModel]->getPlanningResultState();

		 float nextsa=(*filtersIterator[getGreadly(nex)])->getQLearningV();

		 float Qsa=getQLerningbySA(state,act)->getQLearningV();


		 float QRL=Qsa+Environment::alpha*(reward+Environment::gamma*nextsa-Qsa);//формула расчета

		 getQLerningbySA(state,act)->setQLearningV(QRL);
 
 	}

 }

struct CompareName{

	CompareName(const int& otherS,const int& otherA)
		:s(otherS),a(otherA),sn(0)
	{
	}
	CompareName(const int& otherS)
		:sn(otherS),s(0),a(0)
	{
		
	}

	bool operator()(std::tr1::shared_ptr<QLearningValue> &n1)
	{
		return ( n1->getQLearnindS()==sn);
	}

	bool operator()(std::tr1::shared_ptr<Model> &n1)
	{
		return (n1->getPlanningState()==s && n1->getPlanningAction()==a);
	}
	const int s;
	const int a;
	const int sn;



};

void QLearningAgent::setModel( const int s,const int a,const int sr,const int r)
{
 

	std::vector<std::tr1::shared_ptr<Model>>::iterator it= ModelTable.begin();

	//исключительная ситуация контейнер модели-пуст


	if(ModelTable.begin()!=ModelTable.end())
	{

	
		std::vector<std::tr1::shared_ptr<Model>>::iterator findIt;
		findIt=find_if(ModelTable.begin(),ModelTable.end(), CompareName(s,a) );

		if(findIt==ModelTable.end())
		{
			std::tr1::shared_ptr<Model> planningModel(new Model(s,a,sr,r));
			ModelTable.push_back(planningModel);
		}
		else
		{
			(*findIt)->setModelResState(sr);
			(*findIt)->setModelRewards(r);
		}
	}
	else
	{
	
		std::tr1::shared_ptr<Model> planningModel(new Model(s,a,sr,r));
		ModelTable.push_back(planningModel);
	}


}


 int QLearningAgent::filterQbyS(const std::vector<std::tr1::shared_ptr<QLearningValue>>::iterator iterBegin,int s)
{

	

	std::vector<std::tr1::shared_ptr<QLearningValue>>::iterator maxQ;



	maxQ=find_if(iterBegin,QLerningTable.end(),CompareName(s));

	if(maxQ!=QLerningTable.end())
	{
		if(filtersIterator.empty())
		{
				filtersIterator.push_back(maxQ);

 		}
 		else{	
		

			if(  ((*maxQ)->getQLearningV())> (*(filtersIterator[0]))->getQLearningV())
			{

				filtersIterator.clear();
				filtersIterator.push_back(maxQ);
			}

			if( ((*maxQ)->getQLearningV())== (*(filtersIterator[0]))->getQLearningV())
			{

				filtersIterator.push_back(maxQ);
			}

		}


	}		



	return ((maxQ)==(QLerningTable.end()) )?1:(QLearningAgent::filterQbyS((maxQ+1),s));
	}

 int QLearningAgent::randomValue( int num)
 {
	 return (num==0)?0:rand() % num;
 }



