#include "ContactListener.h"




void MyContactListener::BeginContact(b2Contact* contact) {
          beginContactFoot(contact);
		  beginItemContact(contact);
		  beginMonsterContact(contact);
		  beginFireballContact(contact);
      }
  
void MyContactListener::EndContact(b2Contact* contact) {
        endContactFoot(contact);
		endItemContact(contact);
      }


void MyContactListener::beginContactFoot(b2Contact* contact)

{
	 void* fixtureUserData = contact->GetFixtureA()->GetUserData();
          if ( (int)fixtureUserData == 3 )
              GlobalData::numFootContacts++;
          //check if fixture B was the foot sensor
          fixtureUserData = contact->GetFixtureB()->GetUserData();
          if ( (int)fixtureUserData == 3 )
              GlobalData::numFootContacts++;
}

void MyContactListener::endContactFoot(b2Contact* contact)
{
	  //check if fixture A was the foot sensor
          void* fixtureUserData = contact->GetFixtureA()->GetUserData();
          if ( (int)fixtureUserData == 3 )
              GlobalData::numFootContacts--;
          //check if fixture B was the foot sensor
          fixtureUserData = contact->GetFixtureB()->GetUserData();
          if ( (int)fixtureUserData == 3 )
              GlobalData::numFootContacts--;
}

void MyContactListener::beginItemContact(b2Contact* contact)
{

	   for (int i =0; i <GlobalData::items.size(); i++)
	 {
		 b2Body* bodyA = contact->GetFixtureA()->GetBody();
		 b2Body* bodyB = contact->GetFixtureB()->GetBody();
		 if (bodyA == GlobalData::items[i].body && bodyB == GlobalData::playerBody)
		 {
			 GlobalData::items[i].body->GetWorld()->DestroyBody(GlobalData::items[i].body);
			 GlobalData::items.erase(GlobalData::items.begin()+i );
		 }

		 if(bodyB ==GlobalData::items[i].body && bodyA == GlobalData::playerBody)
		 {
		    GlobalData::items[i].body->GetWorld()->DestroyBody(GlobalData::items[i].body);
			GlobalData::items.erase(GlobalData::items.begin()+i );
		 }


	 }

}

void MyContactListener::beginMonsterContact(b2Contact* contact)
{
	
	   for (int i =0; i <GlobalData::m_bodies.size(); i++)
	 {
		 b2Body* bodyA = contact->GetFixtureA()->GetBody();
		 b2Body* bodyB = contact->GetFixtureB()->GetBody();
		 if (bodyA == GlobalData::m_bodies[i].body && bodyB == GlobalData::playerBody)
		 {
			 GlobalData::m_bodies[i].bHit = true;
			   GlobalData::healthPercent = GlobalData::healthPercent -0.1;
		 }

		 if(bodyB ==GlobalData::m_bodies[i].body && bodyA == GlobalData::playerBody)
		 {

				GlobalData::m_bodies[i].bHit = true;
				  GlobalData::healthPercent = GlobalData::healthPercent -0.1;
		 }


	 }
}


void MyContactListener::beginFireballContact(b2Contact* contact)
{
	
	   for (int i =0; i <GlobalData::fb_projectiles.size(); i++)
	 {
		 b2Body* bodyA = contact->GetFixtureA()->GetBody();
		 b2Body* bodyB = contact->GetFixtureB()->GetBody();
		 if (bodyA == GlobalData::fb_projectiles[i].body && bodyB == GlobalData::playerBody)
		 {
			 GlobalData::fb_projectiles[i].bHit = true;
			 GlobalData::healthPercent = GlobalData::healthPercent -0.1;
		 }

		 if(bodyB ==GlobalData::fb_projectiles[i].body && bodyA == GlobalData::playerBody)
		 {
				GlobalData::fb_projectiles[i].bHit = true;
			    GlobalData::healthPercent = GlobalData::healthPercent -0.1;
		 }


	 }
}



void MyContactListener::endItemContact(b2Contact* contact)
{

}

