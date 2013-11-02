#include "Monster.h"










void Monster::update()
{
for(int i=0; i<particles.size(); i++) {
		float x = particles[i].getPosition().x;
		float y = particles[i].getPosition().y;
		b2Vec2 vel = particles[i].body->GetLinearVelocity();
		vel.x = 5;
		particles[i].body->SetLinearVelocity(vel);
		
		if(x <ofGetWidth())
			particles[i].update(x,y);
		else
		{
			particles[i].body->GetWorld()->DestroyBody(particles[i].body);
			particles.erase(particles.begin()+i );
		}

		

		
	}





}

void Monster::createMonster()
{
	
	CustomParticle p;
	p.setPhysics(1.0, 0.5, 0.3);
	p.setup(box2dworld.getWorld(), 10, 500, 50);
	p. setupTheCustomData() ;
	particles.push_back(p);
}



void Monster::draw()
{
	

	for(int i=0; i<particles.size(); i++) {
		particles[i].draw();
	}
	


	
}
