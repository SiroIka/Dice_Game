#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include"cocos2d.h"

class Game:public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();   //�V�[���̍쐬
       virtual bool init();                    //������
       void update( float dt );
       void myupdate( float dt );
       float ret=NULL;
    CREATE_FUNC( Game );                    //creste�֐��̎����}�N��
    //���ꏑ���Ƃ���OK
    int count = NULL;

private:
    

};



#endif // !__GAME_SCENE_H__

