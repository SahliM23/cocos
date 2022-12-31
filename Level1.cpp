#include "Level1.h"



USING_NS_CC;

Scene* Level1::createScene()
{
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    //scene->getPhysicsWorld()->setGravity( Vec2( 0, 0 ) );

    // 'layer' is an autorelease object
    auto layer = Level1::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());

    // add layer as a child to scene
        scene->addChild(layer);

    // return the scene
    return scene;


    //return Level1::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Level1::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("images/map.png");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(background);

    /*auto background = Sprite::create("images/.jpg");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background);*/

  /* auto menu_item_1 = MenuItemFont::create("GoBack", CC_CALLBACK_1(Level1::GoBack, this));

    menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 4) * 1.95));
  

    menu_item_1->setColor(cocos2d::Color3B(255, 153, 51));
   

    auto* menu = Menu::create(menu_item_1, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu); */ 
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height*0.63 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);

    this->addChild(edgeNode);

    {
        auto sprite = Sprite::create("images/map1.png");
        sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height*0.185));

        auto spriteBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0, 1, 0));

        spriteBody->setDynamic(false);
        sprite->setPhysicsBody(spriteBody);

        this->addChild(sprite);
    }

    
        auto avatar = Sprite::create("images/map3.png");
        avatar->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        auto spriteBody = PhysicsBody::createBox(avatar->getContentSize(), PhysicsMaterial(0, 1, 0));

        avatar->setPhysicsBody(spriteBody);

        this->addChild(avatar);
    
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
        auto avatar = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 loc = event->getCurrentTarget()->getPosition();
        switch (keyCode)
        {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            static int nx;
            event->getCurrentTarget()->setPosition(loc.x -= 10, loc.y);
            nx -= 10;

            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            event->getCurrentTarget()->setPosition(loc.x += 10, loc.y);
            nx += 10;
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
            /* avatar->runAction(JumpBy::create(3.0, Point(0, loc.y - 150), 10, 1)); */

            avatar->runAction(Sequence::create(JumpBy::create(3.0, Point(0, loc.y), 10, 1), JumpTo::create(3.0, Point(loc.x + nx, loc.y), 10, 1), nullptr));

            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            avatar->runAction(JumpTo::create(3.0, Point(loc.x + nx + 15, loc.y), 10, 1));
            break;
        case EventKeyboard::KeyCode::KEY_V:
            event->getCurrentTarget()->setPosition(0, 0);
            break;
        }};

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener,  avatar);
  

    return true;
}
 
/* void Level1::GoBack(cocos2d::Ref* pSender) {
    CCLOG("GoBack");
}*/
