#include "HelloWorldScene.h"
#include "Level1.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("images/PICO.jpg");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background);

    auto menu_item_1 = MenuItemFont::create("Play", CC_CALLBACK_1(HelloWorld::Play, this));
    auto menu_item_2 = MenuItemFont::create("Exit", CC_CALLBACK_1(HelloWorld::Exit, this));
    auto menu_item_3 = MenuItemFont::create("Settings", CC_CALLBACK_1(HelloWorld::Settings, this));

    menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 4) * 1.95) );
    menu_item_2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 4) * 1.45));
    menu_item_3->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 4) * 0.95));

    menu_item_1->setColor(cocos2d::Color3B(255, 153, 51));
    menu_item_2->setColor(cocos2d::Color3B(255, 153, 51));
    menu_item_3->setColor(cocos2d::Color3B(255, 153, 51));

    auto* menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);


    return true;
}
void HelloWorld::Play(cocos2d::Ref* pSender){
    CCLOG("Play");
    auto scene = Level1::createScene();
    Director::getInstance()->pushScene(scene);
}

void HelloWorld::Exit(cocos2d::Ref* pSender) {
    CCLOG("Highscores");
}

void HelloWorld::Settings(cocos2d::Ref* pSender) {
    CCLOG("Settings");
}

/*
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


// }
