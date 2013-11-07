#include "Item.h"

//ItemContactListener contactListener;
//vector <CustomItem>	GlobalData::items;

void Item::update()
{
for(int i=0; i<GlobalData::items.size(); i++) {
		float x = GlobalData::items[i].getPosition().x;
		float y = GlobalData::items[i].getPosition().y;
		GlobalData::items[i].setPosition(x,ofGetHeight()/2);
		b2Vec2 vel = GlobalData::items[i].body->GetLinearVelocity();
		vel.x = 5;
		GlobalData::items[i].body->SetLinearVelocity(vel);
		if(x <ofGetWidth())
			GlobalData::items[i].update(x,y);
		else
		{
			GlobalData::items[i].body->GetWorld()->DestroyBody(GlobalData::items[i].body);
			GlobalData::items.erase(GlobalData::items.begin()+i );
		}
	}
}

void Item::createItem()
{
	CustomItem p;
	p.setPhysics(1.0, 0.5, 0.3);
	p.setup(GlobalData::box2dworld.getWorld(), 10, 500, 1);
	p. setupTheCustomData();

	GlobalData::items.push_back(p);
	//GlobalData::box2dworld.getWorld()->SetContactListener(&contactListener);

	//ofAddListener(GlobalData::box2dworld.contactStartEvents, this, &Item::contactStart);
	//ofAddListener(GlobalData::box2dworld.contactEndEvents, this, &Item::contactEnd);
}



void Item::draw()
{
	for(int i=0; i<GlobalData::items.size(); i++) {
		GlobalData::items[i].draw();
	}
}

