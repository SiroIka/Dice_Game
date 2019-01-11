#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include"cocos2d.h"

class Game:public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();   //シーンの作成
       virtual bool init();                    //初期化
       void update( float dt );
       void myupdate( float dt );
       float ret=NULL;
    CREATE_FUNC( Game );                    //creste関数の実装マクロ
    //これ書いとけばOK
    int count = NULL;

private:
    

};



#endif // !__GAME_SCENE_H__

