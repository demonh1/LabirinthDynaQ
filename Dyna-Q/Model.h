#ifndef MODEL
#define MODEL

/**@breif ����� ����������� ������,
������� ��������� �����
@detailed ������ ��������� ���
���������� ��������� ������������
�������� �������� ����� �����������
�������� � ����������� ������ 
�������� ��������� ��������� ��������
� ��������� ��������� 
��� ��������� �������� � �������
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