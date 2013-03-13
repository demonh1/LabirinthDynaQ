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
@detailed класс агента 
обучающегос€ с помощью 
алгоритма планировани€ и обучени€ 
јгент обучаетс€ на своем опыте 
добавл€€ результат своих действий 
в свою базу знаний*/
typedef std::vector<std::tr1::shared_ptr<QLearningValue>>::iterator IterFilter;

class QLearningAgent
{
public:


	QLearningAgent(void);
	

	~QLearningAgent(void);	
	


	/**новый шаг в эпизоде*/
	void newStep();

	/**@breif эмул€ци€ ревакции объекта на среду 
	@detailed объект с состо€ни€м и выбранным 
	действием после шага итерации получает новое состо€ние*/

	void goDo();

	/**@breif инициализаци€ Q */

	void run();

	/**@breif сброс положени€ текуйей
	оценки и перенос объекта вновь
	на стартовую позицию*/

	void newEpisode();

	std::tr1::shared_ptr<QLearningValue> getQLerningbySA(int,int);

	void setQLearningValue();

	int randomValue(int);
	void planning();
	void setModel(const int,const int,const int,const int);
	void tryToEditModel();

	/**breif рекурсивна€ функци€
	поиска максимальных значений
	измен€ет filtersiterator
	@return 1 если обход массива 
	QLearning Value окончен */

 int filterQbyS(const std::vector<std::tr1::shared_ptr<QLearningValue>>::iterator,int);


	
	/**@breif функци€ получени€ жадного действие 
	@detailed дл€ данного состо€ни€ 
	и набора оценок определить действие 
	привод€щие к максимальной оценки
	если оценки равны то возвращаетс€ 
	случайное действие
	@return randIdModel - возращает из набора 
	идентификаторов Q(s,a), тот действие 
	которого приводит к максимальному эффекту */

	int getGreadly(int);

	private:
		int mCurrentAct;
		int mState;
		int mNextState;
		int mReward;
		float mQmaxa;
/**filtersIterator зависит от getGreadly*/
		 std::vector< IterFilter>  filtersIterator;
		 std::vector<std::tr1::shared_ptr<QLearningValue>>maxQorRand;
		 std::vector<std::tr1::shared_ptr<QLearningValue>>QLerningTable;
		 std::vector<std::tr1::shared_ptr<Model>>ModelTable;
};
#endif