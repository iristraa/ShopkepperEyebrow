#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include "ShopkepperLayer.hpp"

using namespace geode::prelude;

// 1 2 3 4 2 3 1
class $modify(ShopkepperNotShopkeeper, CreatorLayer) {
	void onShopkepper(CCObject * sender) {
		auto shopkepperLayer = ShopkepperLayer::scene();
		auto transitionFade = CCTransitionFade::create(0.5, shopkepperLayer);
		CCDirector::sharedDirector()->pushScene(transitionFade);
	}

	void onMultiplayer(cocos2d::CCObject* sender) {
		ShopkepperNotShopkeeper::onShopkepper(sender);
	}

	void onEventLevel(cocos2d::CCObject* sender) {
		ShopkepperNotShopkeeper::onShopkepper(sender);
	}

	void onAdventureMap(cocos2d::CCObject* sender) {
		ShopkepperNotShopkeeper::onShopkepper(sender);
	}
};
