#include "Dragon.h"
//
//

void Dragon::mousePressed(int x, int y, int button)
{
	DragonProjectile p;
	p.setPhysics(1.0, 0.5, 0.3);
	p.setup(box2dworld.getWorld(), headPos.x, headPos.y, ofRandom(20, 60));
	p.setupProjectileData();
	particles.push_back(p);

}

void Dragon::update()
{
	dragon.update(1.0f/60);
	//dragon.
	dragonPos.x +=2;
	dragonHead = SkeletonData_findBone (dragon.getSkeletonData(), "head");
	headPos.x = dragonHead->x + dragonPos.x;
	headPos.y = dragonHead->y - dragonPos.y;
	cout<< headPos.y << endl;
	//headPos.y = dragonHead->y;
	dragon.setPosition(dragonPos);
	if (dragonPos.x >= ofGetWidth())
		dragonPos.x =0;

	for(int i=0; i<particles.size(); i++) {
		
		float x = particles[i].getPosition().x;
		
		
			if(x <ofGetWidth())
				particles[i].update();
			else
			{
				particles[i].body->GetWorld()->DestroyBody(particles[i].body);
				particles.erase(particles.begin()+i );
			}

		

		
	}

}
//
void Dragon::createProjectile()
{
	
	DragonProjectile p;
	p.setPhysics(1.0, 0.5, 0.3);
	p.setup(box2dworld.getWorld(), 10, 500, 50);
	p. setupProjectileData() ;
	particles.push_back(p);
}
//
void Dragon::createDragon()
{
	dragon.setup("assets/dragon.atlas", "assets/dragon.json", 0.3);
	AnimationState_setAnimationByName(dragon.getState(), "fly", true);
	dragonPos.x = -50;
	dragonPos.y = 250;
	dragon.setPosition(dragonPos);

}
//
//
//
void Dragon::draw()
{
	ofLine(dragonPos.x,dragonPos.y, dragonPos.x, dragonPos.y);
	dragon.draw();
	for(int i=0; i<particles.size(); i++) {
		particles[i].draw();
	}
	
	
}
