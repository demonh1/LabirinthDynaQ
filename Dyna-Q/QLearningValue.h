#ifndef Q_LEARNING_VALUE_H
#define Q_LEARNING_VALUE_H

class QLearningValue
{
public:
	QLearningValue(int,int);
	~QLearningValue(void);
int	getQLearnindS() const;
int	getQLearningA() const;
float	getQLearningV() const;
void	setQLearningV(float);
void setQLearningValue(int,int,float);



private:
	int mState;
	int mAction;
	float mQval;
};

#endif