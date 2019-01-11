
#include"game.h"

USING_NS_CC;
//�V�[���̍쐬
Scene* Game::createScene()
{
    return Game::create();
}

bool Game::init()
{
    //�V�[���N���X�̏�����
    
    
    if( !Scene::init() )
    {
        return false;
    }
    //�F�t�����C���[���쐬
    //LayerColor* lc = LayerColor::create( Color4B::MAGENTA, 100.0F, 50.0F );
    // LayerColor::create( �F, ����float,�c��float,  );
    ////���W�̎w��
    //Vec2 vec2( 100.0F, 100.0F );
    //lc->setPosition( vec2 );
    ////���W�̓n�����ɂ͂��������@������
    // lc->setPosition( Vec2( 100.0F, 100.0F ) )
    // lc->setPosition( 100.0F, 100.0F );
    Sprite* sprite = Sprite::create( "game.png" );
    //{
    //Sprite* sprite2 = Sprite::create( "images.jpg" );
    //    /*sprite2->setScale( 1.5F, 1.5F );*/
    //    //sprite2->setScale( 1.5F, 1.5F );
    //    //sprite2->setPosition( size.x / 3.0F, size.y / 3.0F );
    Vec2 size = Director::getInstance()->getVisibleSize();
    sprite->setPosition( size.x / 2.0F, size.y / 2.0F );
    //    //
    //}
    ////�O���f�[�V�������C���[�̍쐬
    //LayerGradient::create( �F���, �F���, �O���f�[�V�����x�N�g�����WVec2�j
    //LayerGradient* lg = LayerGradient::create( Color4B::MAGENTA, Color4B::ORANGE, Vec2( 10.0F, 5.0F ) );
    //
    
    //1�A�V���O���^�b�`���擾����C�x���g�p�X���擾
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    
    //�C�x���g�������������ɏ������s���֐�������
    //ontouchbegan�̎���
    listener->onTouchBegan = [=]( Touch* touch, Event* event )->bool{
        //sprite2->setPosition( touch->getLocation() );
        return true; 
    };
    listener->onTouchMoved = [=]( Touch* touch, Event* event )->bool{
        //sprite2->setPosition( );
        Director::getInstance()->popScene();
        return true;
    };
    listener->onTouchEnded=[this]( Touch* touch, Event* event )->bool{
        count++;
        Sprite* sprite2 = Sprite::create( "spike.png" );

        sprite2->setPosition( touch->getLocation() );

       /* //�e�N�X�`���̕ύX
        Director::getInstance()->getTextureCache()->addImage( "cherry.png" );
        Texture2D* tex = Director::getInstance()->getTextureCache()->getTextureForKey( "cherry.png" );

        sprite2->setTexture( tex );

        sprite2->setTag( count );
        //�e�N�X�`���̕`��͈͂̍Đݒ�
        Vec2 size = Director::getInstance()->getVisibleSize();

        sprite2->setVertexRect( Rect( 0, 0, size.x, size.y ) );*/
        if( count >= 5 )
        {
            Sprite* sp = (Sprite*)this->getChildByTag( count - 4 );
            this->removeChild( sp );
            //sp->removeFromParent();
        }
        /*Label*lb = Label::create();
        lb->setPosition(200.0F,200.0F);
        lb->setString( "ABC" );
        this->addChild( lb );*/
        //����̍X�V�����̒�~
        //this->unschedule( schedule_selector( Game::myupdate ) );
        this->addChild( sprite2 );
        


        return true;
    };
    
    this->addChild( sprite );
    //�C�x���g�f�B�X�p�b�`���[�ɓo�^
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
    
    //�V�[���Ƀm�[�h��ǉ�
    
    //this->addChild( lc );
    //this->addChild( sprite );
    //sprite->addChild( sprite2 );
    //this->addChild( lg );
   //this->addChild( sprite2 );
   //sprite2->addChild( sprite2 ); 
    //lg->setVector( Vec2( 1.0F, 0.0F ) );

    return true;
}
void Game::update( float dt )
{
    ret++;
    Sprite* sprite = Sprite::create( "spike.png" );
    sprite->setPosition(  ret/ 255, 100 );
    this->addChild( sprite );

};

