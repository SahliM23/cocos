

#ifndef __LEVEL1_H__
#define __LEVEL1_H__

#include "cocos2d.h"

class Level1 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void GoBack(Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(Level1);
private:
    cocos2d::PhysicsWorld* sceneWorld;

    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
};

#endif // __LEVEL1_H__
