#ifndef collisiondetection_hpp
#define collisiondetection_hpp
#include"./Jumanji/object/object.h"

enum BV_type
{
	Cylinder,
	Cuboid
};

bool CollisionDetection(const object & obj1, const object &obj2, BV_type BV1_type = Cuboid, BV_type BV2_type = Cuboid); // fuctions works for horizontal or vertical shapes only

#endif