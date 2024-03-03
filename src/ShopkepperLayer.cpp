#include <Geode/Geode.hpp>
#include "ShopkepperLayer.hpp"
#include <fmt/core.h>

using namespace geode::prelude;

bool ShopkepperLayer::init() {
    if (!CCLayer::init()) return false;

    auto backgroundSprite = CCSprite::create("game_bg_13_001.png");

    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);

    backgroundSprite->setAnchorPoint({ 0, 0 });
    backgroundSprite->setPosition({ 0, 0 });

    backgroundSprite->setZOrder(-2);
    this->addChild(backgroundSprite);

    auto backTexture = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
    auto backBtn = CCMenuItemSpriteExtra::create(
        backTexture, this,
        menu_selector(ShopkepperLayer::onBack)
    );

    auto menuBack = CCMenu::create();
    menuBack->addChild(backBtn);
    menuBack->setPosition({ 24, winSize.height - 24 });

    // here comes the awful part...

    log::info("{}", winSize.width);

    auto shopkepper = CCSprite::create("ShopkepperEyebrow.png"_spr);
    auto shopkepperMsg = CCSprite::create("ShopkeppersMsg.png"_spr);
    auto shopkepperMsgTitle = CCSprite::create("ShopkeppersMsgTitle.png"_spr);

    shopkepper->setAnchorPoint({ 0.5, 0 });
    shopkepper->setPosition({ winSize.width - 127, 0 });
    shopkepper->setScale(1.715f);

    shopkepperMsg->setPosition({ 171, 142 });
    shopkepperMsg->setScale(2.46f);

    shopkepperMsgTitle->setPosition({ 170, 237 });
    shopkepperMsgTitle->setScale(2.45f);

    this->addChild(shopkepper);
    this->addChild(shopkepperMsg);
    this->addChild(shopkepperMsgTitle);

    this->addChild(menuBack);

    // alright it's audio time

    FMODAudioEngine::sharedEngine()->stopAllMusic();
    FMODAudioEngine::sharedEngine()->playMusic("ShopkepperMusic.mp3"_spr, 1, 1, 1);

    this->setKeypadEnabled(true);

    return true;
}

void ShopkepperLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}


void ShopkepperLayer::onBack(CCObject* object) {
    FMODAudioEngine::sharedEngine()->stopAllMusic();
    FMODAudioEngine::sharedEngine()->playMusic("menuLoop.mp3", 1, 1, 1);
    keyBackClicked();
}

ShopkepperLayer* ShopkepperLayer::create() {
    auto ret = new ShopkepperLayer;
    if (ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

CCScene* ShopkepperLayer::scene() {
    auto layer = ShopkepperLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    return scene;
}