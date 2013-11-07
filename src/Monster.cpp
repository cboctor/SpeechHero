#include "Monster.h"


void Monster::update()
{
for(int i=0; i<GlobalData::m_bodies.size(); i++) {
		float x = GlobalData::m_bodies[i].getPosition().x;
		float y = GlobalData::m_bodies[i].getPosition().y;
		b2Vec2 vel = GlobalData::m_bodies[i].body->GetLinearVelocity();
		vel.x = 5;
		GlobalData::m_bodies[i].body->SetLinearVelocity(vel);
		if(x <ofGetWidth() && !GlobalData::m_bodies[i].bHit)
			GlobalData::m_bodies[i].update(x,y);
		
		else
		{
			GlobalData::m_bodies[i].body->GetWorld()->DestroyBody(GlobalData::m_bodies[i].body);
			GlobalData::m_bodies.erase(GlobalData::m_bodies.begin()+i );
		}

		
	}
}

void Monster::createMonster()
{
	MonsterBody p;
	p.setPhysics(1.0, 0.5, 0.3);
	p.setup(GlobalData::box2dworld.getWorld(), 10, 500, 50);
	p. setupTheCustomData() ;
	GlobalData::m_bodies.push_back(p);
}



void Monster::draw()
{
	for(int i=0; i<GlobalData::m_bodies.size(); i++) {
		GlobalData::m_bodies[i].draw();
	}
}
