//#include "Dragon.h"
//
//
//void Dragon::update()
//{
//	dragon.update(1.0f/60);
//	//dragon.
//	dragonPos.x +=2;
//	dragonHead = SkeletonData_findBone (dragon.getSkeletonData(), "head");
//	headPos.x = dragonHead->x;
//	headPos.y = dragonHead->y;
//	dragon.setPosition(dragonPos);
//	
//
//	for(int i=0; i<particles.size(); i++) {
//		
//		float x = particles[i].getPosition().x;
//		
//		
//			if(x <ofGetWidth() || x>=0)
//				particles[i].update();
//			else
//			{
//				particles[i].body->GetWorld()->DestroyBody(particles[i].body);
//				particles.erase(particles.begin()+i );
//			}
//
//		
//
//		
//	}
//
//}
//
//void Dragon::createProjectile()
//{
//	
//	CustomParticle p;
//	p.setPhysics(1.0, 0.5, 0.3);
//	p.setup(box2dworld.getWorld(), 10, 500, 50);
//	p. setupTheCustomData() ;
//	particles.push_back(p);
//}
//
//void Dragon::createDragon()
//{
//	dragon.setup("assets/dragon.atlas", "assets/dragon.json", 0.3);
//	AnimationState_setAnimationByName(dragon.getState(), "fly", true);
//	dragonPos.x = -50;
//	dragonPos.y = 250;
//	dragon.setPosition(dragonPos);
//
//}
//
//
//
//void Dragon::draw()
//{
//	
//	dragon.draw();
//	for(int i=0; i<particles.size(); i++) {
//		particles[i].draw();
//	}
//	
//	
//}
