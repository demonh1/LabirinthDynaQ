#ifndef MODEL
#define MODEL

/**@breif класс описывающий модель,
которую формирует агент
@detailed модель создается для
применения алгоритма планирования
содержит описание среды накопленное
реальным и иметируемым опытом 
содержит начальное состояние действие
и следующее состояние 
как результат действия и награду
*/

class Model
{
public:
	Model(int,int,int,int);
	~Model(void);
	int getPlanningResultState() const;
	int getPlanningAction() const;
	int getPlanningState() const;
	int getPlanningRewards() const;
	void setModelResState(int);
	void setModelRewards(int);
private:
	int mPlanningState;
	int mPlanningAction;
	int mPlanningResultState;
	int mPlanningRewards;
};
#endif