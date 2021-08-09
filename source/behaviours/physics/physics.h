#pragma once
#include "../../types/behaviour/behaviour.h"
#include <Box2D/box2d.h>

namespace BigNgine
{
	class PhysicsBehaviour : public Behaviour
	{
	public:
		void Start();

		void Update(int deltaTime);

		void Destroy();
	
	private:
		b2BodyDef bodyDef;

		b2Body* body;

		b2PolygonShape dynamicBox;

		b2FixtureDef fixtureDef;
	};
}