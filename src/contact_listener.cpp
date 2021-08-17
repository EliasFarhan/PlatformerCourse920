#include "contact_listener.h"
#include <box2d/box2d.h>
#include <iostream>


#include "game.h"
#include "user_data.h"

MyContactListener::MyContactListener(Game& game) : game_(game)
{

}

void MyContactListener::BeginContact(b2Contact* contact)
{
    std::cout << "Contact Begin!\n";
    UserData* dataA = reinterpret_cast<UserData*>(contact->GetFixtureA()->GetUserData().pointer);
    UserData* dataB = reinterpret_cast<UserData*>(contact->GetFixtureB()->GetUserData().pointer);
    game_.BeginContact(dataA->userData, dataB->userData);
}

void MyContactListener::EndContact(b2Contact* contact)
{
    UserData* dataA = reinterpret_cast<UserData*>(contact->GetFixtureA()->GetUserData().pointer);
    UserData* dataB = reinterpret_cast<UserData*>(contact->GetFixtureB()->GetUserData().pointer);
    game_.EndContact(dataA->userData, dataB->userData);
    std::cout << "Contact End!\n";
}
