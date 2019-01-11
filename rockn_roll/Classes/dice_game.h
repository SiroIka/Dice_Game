#pragma once
//      �}�N����`       //

//�X�v���C�g

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
    static cocos2d::Scene* createScene();   //�V�[���̍쐬
    virtual bool init();                    //������
    void update( float dt );
    float ret;
    CREATE_FUNC( Dice_game );               //creste�֐��̎����}�N��
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