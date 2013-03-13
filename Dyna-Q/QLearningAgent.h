#ifndef Q_LEARNING_AGENT_H
#define Q_LEARNING_AGENT_H
#include "Environment.h"
#include <vector>
#include <iostream>
#include "QLearningValue.h"
#include "Model.h"
#include <stdlib.h>
#include "Time.h"

/** @breif Dyna-Q Agent
@detailed ����� ������ 
������������ � ������� 
��������� ������������ � �������� 
����� ��������� �� ����� ����� 
�������� ��������� ����� �������� 
� ���� ���� ������*/
typedef std::vector<std::tr1::shared_ptr<QLearningValue>>::iterator IterFilter;

class QLearningAgent
{
public:


	QLearningAgent(void);
	

	~QLearningAgent(void);	
	


	/**����� ��� � �������*/
	void newStep();

	/**@breif �������� �������� ������� �� ����� 
	@detailed ������ � ���������� � ��������� 
	��������� ����� ���� �������� �������� ����� ���������*/

	void goDo();

	/**@breif ������������� Q */

	void run();

	/**@breif ����� ��������� �������
	������ � ������� ������� �����
	�� ��������� �������*/

	void newEpisode();

	std::tr1::shared_ptr<QLearningValue> getQLerningbySA(int,int);

	void setQLearningValue();

	int randomValue(int);
	void planning();
	void setModel(const int,const int,const int,const int);
	void tryToEditModel();

	/**breif ����������� �������
	������ ������������ ��������
	�������� filtersiterator
	@return 1 ���� ����� ������� 
	QLearning Value ������� */

 int filterQbyS(const std::vector<std::tr1::shared_ptr<QLearningValue>>::iterator,int);


	
	/**@breif ������� ��������� ������� �������� 
	@detailed ��� ������� ��������� 
	� ������ ������ ���������� �������� 
	���������� � ������������ ������
	���� ������ ����� �� ������������ 
	��������� ��������
	@return randIdModel - ��������� �� ������ 
	��������������� Q(s,a), ��� �������� 
	�������� �������� � ������������� ������� */

	int getGreadly(int);

	private:
		int mCurrentAct;
		int mState;
		int mNextState;
		int mReward;
		float mQmaxa;
/**filtersIterator ������� �� getGreadly*/
		 std::vector< IterFilter>  filtersIterator;
		 std::vector<std::tr1::shared_ptr<QLearningValue>>maxQorRand;
		 std::vector<std::tr1::shared_ptr<QLearningValue>>QLerningTable;
		 std::vector<std::tr1::shared_ptr<Model>>ModelTable;
};
#endif