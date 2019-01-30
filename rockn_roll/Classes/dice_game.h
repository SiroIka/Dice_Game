#pragma once
//      マクロ定義       //

//スプライト

#ifndef __DICE_GAME_SCENE_H__
#define __DICE_GAME_SCENE_H__

#include"cocos2d.h"
#include<bitset>
#include<array>
#include<list>
#include<map>

class Dice_game :public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();   //シーンの作成
    virtual bool init();                    //初期化
    void update( float dt );
    float ret;
    int RemoveAction( int value1, int value2, int value3, int value4 ,int chenged);
    bool ResetArray( int value1, int value2, int value3, int value4 );
    int Checkscoreing( std::string value1, std::string value2, std::string value3, std::string value4,int EorN );

    CREATE_FUNC( Dice_game );               //creste関数の実装マクロ
    std::bitset<4> check_BordSetDice_flag;
    std::bitset<1> check_RePushPrevention_flag;
    std::bitset<4> check_SetDiceChange_flag;
    std::bitset<4> check_HoldDice_flag;
    std::vector<cocos2d::Sprite*> L_Dice;
    std::vector<int> four_dice_;
    const int kpos_=39;
    int count = NULL;
    
private:
    };

#endif // !__DICE_GAME_SCENE_H__