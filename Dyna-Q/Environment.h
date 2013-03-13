#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
/**@breif пространство имен окружения 
агента для детерминированной среды
@detailed описывает статические 
параметры среды напр лабиринт*/
namespace Environment
{

	static const int cols=6;
		static const float alpha=0.1;
			static const float epsilon=0.1;
				static const float gamma=0.95;
								static const int zeroState=666;
	static const int rows=6;
	static const int states[]={0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0};
	static const int initialState=2;
	static const int terminated=35;
		static const int N=30;
	//static const char actions[]={"urdl"}; 

	/**описание типов действий 0-вверх 1-вправо 2-влево 3-вниз*/

	static const int actions[]={0,1,2,3};
	static const int actionsAmount=sizeof(actions);
}

#endif