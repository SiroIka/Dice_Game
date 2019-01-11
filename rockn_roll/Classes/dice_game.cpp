#include"dice_game.h"

USING_NS_CC; const float kEriasize = 29.2F;
#define CHECKPOSION(i,j,k,g) (( (touch->getLocation().x <= (fieldtile_[ i ].position_.x + kEriasize)) &&touch->getLocation().x >= (fieldtile_[ j ].position_.x - kEriasize)) &&(touch->getLocation().y <= (fieldtile_[ k ].position_.y + kEriasize)) &&(touch->getLocation().y >= (fieldtile_[ g ].position_.y - kEriasize )))
#define CHECKSUBPOSION(i,j,k,g) (( (touch->getLocation().x > (fieldtile_[ i ].position_.x + kEriasize)) &&touch->getLocation().x < (fieldtile_[ j ].position_.x - kEriasize)) &&(touch->getLocation().y > (fieldtile_[ k ].position_.y + kEriasize)) &&(touch->getLocation().y < (fieldtile_[ g ].position_.y - kEriasize )))

//シーンの作成
//ダイスの個数
const int DiceType =4;

Vec2 flo;
struct fieldtile
{
    Vec2 position_;
    int flag_;

};
fieldtile fieldtile_[ 16 ];
//x527 54 y436 54
const std::array< const char*,17> kN_F_DiceName={"",
"N_F_/blue1.png","N_F_/blue2.png","N_F_/blue3.png","N_F_/blue4.png",
"N_F_/green1.png","N_F_/green2.png","N_F_/green3.png","N_F_/green4.png",
"N_F_/red1.png","N_F_/red2.png","N_F_/red3.png","N_F_/red4.png",
"N_F_/yellow1.png","N_F_/yellow2.png","N_F_/yellow3.png","N_F_/yellow4.png"
};
const std::array< const char*,17> kF_DiceName= {"",
    "F/blue1.png","F/blue2.png","F/blue3.png","F/blue4.png",
    "F/green1.png","F/green2.png","F/green3.png","F/green4.png",
    "F/red1.png","F/red2.png","F/red3.png","F/red4.png",
    "F/yellow1.png","F/yellow2.png","F/yellow3.png","F/yellow4.png"
};
Scene* Dice_game::createScene()
{
    return Dice_game::create();
}

bool Dice_game::init()
{

    //更新処理の開始
    //scheduleUpdate();
    if( !Scene::init() )
    {
        return false;
    };

    Sprite* GameTex = Sprite::create( "ghw.png" );
    Sprite* Score   = Sprite::create( "borde.png" );
    Sprite* RollTex = Sprite::create( "roll.png" );
    for( int j = 0,k=0; j < DiceType; j++ )
    {
        for( int i = 0; i < DiceType; i++,k++ )
        {
            fieldtile_[ k ].position_ = Vec2( 121.0F + (59* i), 391.0F - (59 * j) );
        }
        check_SetDiceChange_flag.reset( j );
        check_BordSetDice_flag.reset( j );
    }
    //略の後にはアンダーバー(スコア)をつけている
    //変数名の大文字Nは　not   の略
    //変数名の大文字Fは　frame の略
    //変数名の大文字Lは　local の略

    GameTex->setPosition(  360.0F/2.0F, 640.0F/2.0F  );
    Score->setPosition(180.0F, 560.0F );
    RollTex->setPosition( 50.0F, 475.0F );
    RollTex->setScale( 0.5F );
    Score->setScale( 0.5F );
    GameTex->setScale( 0.5F );

   /* 
    position_::16.000132,504.000458
    position_::82.999825,448.000519
    position_::97.000336,415.000702
    position_::325.000366,189.000305
    position_::95.000191,416.000793
    position_::325.000366,189.000305
    position_::121.000008,390.000458
    position_::296.000336,218.000351*/


    //1、シングルタッチを取得するイベントパスを取得
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

    //イベントが発生した時に処理を行う関数を実装
    //ontouchbeganの実装
    listener->onTouchBegan = [&]( Touch* touch, Event* event )->bool{
        
        //初期化
        scheduleUpdate();
        Sprite* Roll = Sprite::create( "roll.png" );
        Roll->setPosition( 440.0F, 540.0F );
        Roll->setScale( 0.6F );


        //og( "position_::%f,%f",touch->getLocation().x, touch->getLocation().y );

        Rect spriteRect = (Rect( (Roll->getPosition().x - Roll->getContentSize().width /2.4),
            (Roll->getPosition().y - Roll->getContentSize().height / 2.4),
            ((Roll->getContentSize().width)- (Roll->getContentSize().width*0.2)),
            ((Roll->getContentSize().height) -(Roll->getContentSize().height)*0.2 )));
        //領域確保 Roll用
        if( four_dice_.empty() ){
            four_dice_.reserve( DiceType );
            for( int i = 0; i < (DiceType); i++ ){
                four_dice_.push_back( NULL );
                L_Dice.push_back( NULL );
            }
        }
        //ここまで

        //振ったダイスを生成
        if( ((touch->getLocation().x <= 83.0F&&touch->getLocation().x >= 16.0F) && (touch->getLocation().y <= 504.0F&&touch->getLocation().y >= 448.0F)) )
        {
            if( check_BordSetDice_flag.all()&&check_SetDiceChange_flag.all() )
            {
                for( int i = 0; i < DiceType; i++ ){
                    check_SetDiceChange_flag.reset(i);
                    check_BordSetDice_flag.reset(i);
                }
            }
            if( check_BordSetDice_flag.none() && check_RePushPrevention_flag.none() )
            {
                for( int i = 0; i < DiceType; i++ ){
                    four_dice_.at( i ) = random( 1, 16 );
                    L_Dice.at( i ) = Sprite::create( kN_F_DiceName.at( four_dice_.at( i ) ) );
                    L_Dice.at( i )->setScale( 1.2F, 1.2F );
                    L_Dice.at( i )->setPosition( 50.0F, (397.0F - (60 * i)) );
                    L_Dice.at( i )->setTag( four_dice_.at( i ) );
                }
            }
            
            for( int i = 0; i < DiceType; i++ ){
                if( (check_BordSetDice_flag.test( i ) == true) && (check_SetDiceChange_flag.test( i ) == false) )
                {
                    L_Dice.at( i )->setSpriteFrame( Sprite::create( kF_DiceName.at( four_dice_.at( i ) ) )->getSpriteFrame() );
                    check_SetDiceChange_flag.set( i );
                }
            }
            if( check_BordSetDice_flag.none() && check_RePushPrevention_flag.none() )
            {
                for( int i = 0; i < DiceType; i++ ){
                    check_RePushPrevention_flag.set( 0 );
                    this->addChild( L_Dice.at( i ) );
                    count++;
                }

            }
        }
        else
        {
            //枠なしのダイスをタッチした場合に持つ処理
            for( int i = 0; i < L_Dice.size(); i++ ){

                if( (L_Dice.at( i ) == NULL) == false ){

                    if( touch->getLocation().x <= (L_Dice.at( i )->getPosition().x + 25) &&
                        touch->getLocation().x >= (L_Dice.at( i )->getPosition().x - 25) ){

                        if( touch->getLocation().y <= (L_Dice.at( i )->getPosition().y + 25)
                            && touch->getLocation().y >= (L_Dice.at( i )->getPosition().y - 25) ){
                            check_HoldDice_flag.set( i );
                        }
                    }
                }

                for( int j = 0; j < ((DiceType*DiceType)); j++ ){

                    if( CHECKPOSION( j, j, j, j ) ){
                        fieldtile_[ j ].flag_ = false;
                    }
                }
            }
        }
        return true;
    };

    listener->onTouchMoved = [&]( Touch* touch, Event* event )->bool{

       // 領域確保
        L_Dice.reserve( DiceType );
        four_dice_.reserve( DiceType );
        if( L_Dice.empty() ){

            for( int i = 0; i < DiceType; i++ ){

                four_dice_.push_back( NULL );
                L_Dice.push_back( Sprite::create( "ghw.png" ) );
            }
        }
        
        //入力に追従する
        for( int i = 0; i < L_Dice.size(); i++ ){

            if( L_Dice.at( i )!=NULL ){

                if( check_HoldDice_flag.test( i ) ){
                    L_Dice.at( i )->setPosition( touch->getLocation() );
                }
            }
        }
        return true;
    };

    listener->onTouchEnded = [&]( Touch* touch, Event* event )->bool{

        //入力が終わった時に一番近い区画の位置にダイスを置く処理
        
        for( int i = 0; i < (DiceType*DiceType); i++ )
        {
            if( CHECKPOSION( i, i, i, i ))
            {
                for( int j = 0; j < L_Dice.size(); j++ )
                {
                    if( L_Dice.at( j ) != NULL )
                    {
                        if( check_HoldDice_flag.test( j ) )
                        {
                            if(fieldtile_[i].flag_==false )
                            {
                                L_Dice.at( j )->setPosition( fieldtile_[ i ].position_ );
                                fieldtile_[ i ].flag_ = true;
                                check_BordSetDice_flag.set( j );
                                check_HoldDice_flag.reset( j );
                            }
                            else
                            {
                                //埋まっている場合は初期位置へ戻る
                                for( int k = 0; k < DiceType; k++ )
                                {
                                    if( check_HoldDice_flag.test( k ) )
                                    {
                                        L_Dice.at( j )->setPosition( 50.0F, (400.0F - (60 * k)) );
                                    }
                                }
                            }
                        }
                    }
                }
            }    
        }

        for( int i = 0; i < (DiceType*DiceType); i++ )
        {
        if( CHECKSUBPOSION( i, i, i, i ) )
        {
                if( !CHECKPOSION( i, i, i, i ) )
                {
                    for( int j = 0; j < L_Dice.size(); j++ ){

                        if( L_Dice.at( j ) != NULL )
                        {
                            if( check_HoldDice_flag.test( j ) )
                            {
                                for( int k = 0; k < DiceType; k++ )
                                {
                                    if( check_HoldDice_flag.test( k ) )
                                    {
                                        L_Dice.at( j )->setPosition( 50.0F, (400.0F - (60 * k)) );
                                    }
                                }

                            }
                        }
                    }
                }
            }
        }

        return true;
    };
    Sprite* Roll2 = Sprite::create( "roll.png" );
    Roll2->setPosition( 440.0F, 540.0F );
    Roll2->setScale( 0.6F );
    Rect spriteRect = (Rect( (Roll2->getPosition().x - Roll2->getContentSize().width / 2.4),
        (Roll2->getPosition().y - Roll2->getContentSize().height / 2.4),
        ((Roll2->getContentSize().width) - (Roll2->getContentSize().width*0.2)),
        ((Roll2->getContentSize().height) - (Roll2->getContentSize().height)*0.2) ));
    
    this->addChild( GameTex );
    this->addChild( Roll2 );
    this->addChild( Score );
    this->addChild( RollTex );

    //イベントディスパッチャーに登録
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );

    return true;
}
void Dice_game::update( float dt )
{
    
    flo += Vec2( 1.0F,1.0F );
   /* ret++;
    Sprite* sprite = Sprite::create( "ghw.PNG" );
    sprite->setPosition( ret / 255, 100 );
    this->addChild( sprite );*/

};