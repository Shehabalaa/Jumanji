#include "collisiondetection.hpp"
#include <vector>

class line
{
public:
	glm::vec3 p1;
	glm::vec3 vec;
	glm::vec3 p2;
public:
	line()
	{};
	void load(glm::vec3 point1, glm::vec3 point2)
	{
		p1 = point1;
		vec = point2 - point1;
		p2 = point2;
	}
};
class plane
{
public:
	glm::vec3 arr_points[4];
	glm::vec3 n;
public:
	plane()
	{};
	void load(glm::vec3 point1, glm::vec3 point2, glm::vec3 point3, glm::vec3 point4)
	{
		arr_points[0] = point1;
		arr_points[1] = point2;
		arr_points[2] = point3;
		arr_points[3] = point4;
		n = glm::cross((point1 - point2), (point1 - point3));
		n = glm::normalize(n);
	}

};
bool Line_Plane_Intersect(const line &l,const plane &pl)
{
	if (glm::dot(l.vec, pl.n) == 0)
		return false;
	float tmp = glm::dot(pl.arr_points[0], pl.n);
	
	float t = (tmp - glm::dot(l.p1, pl.n)) / (glm::dot(l.vec, pl.n));
	if (t >= 0 && t <= 1) // check if point between line boundries
	{
		glm::vec3 intersection_point = l.p1 + t*l.vec;

		// check if point between plane boundries

		float area1 = 0;
		area1 += glm::length(glm::cross(pl.arr_points[0] - intersection_point, pl.arr_points[1] - intersection_point)) / 2;
		area1 += glm::length(glm::cross(pl.arr_points[1] - intersection_point, pl.arr_points[2] - intersection_point)) / 2;
		area1 += glm::length(glm::cross(pl.arr_points[2] - intersection_point, pl.arr_points[3] - intersection_point)) / 2;
		area1 += glm::length(glm::cross(pl.arr_points[3] - intersection_point, pl.arr_points[0] - intersection_point)) / 2;
			

		float area2 = glm::distance(pl.arr_points[0], pl.arr_points[1]) * glm::distance(pl.arr_points[1], pl.arr_points[2]);

		if (abs(area1 - area2) <= 0.2)
			return true;

	}
	return false;

}

bool CollisionDetection(const object & obj1, const object &obj2, BV_type BV1_type , BV_type BV2_type) // fuctions works for horizontal or vertical shapes only
{
	if (BV1_type == Cuboid && BV2_type == Cuboid)
	{
		
		glm::vec3 BV1_Vetices[8];
		glm::vec3 BV2_Vetices[8];

		for (int i = 0; i < 8; i++)
			BV1_Vetices[i] = glm::vec3(obj1.ModelMatrix * glm::vec4(obj1.obj_BV.BV_vertices[i], 1));

		for (int i = 0; i < 8; i++)
			BV2_Vetices[i] = glm::vec3(obj2.ModelMatrix * glm::vec4(obj2.obj_BV.BV_vertices[i], 1));

		//printf("%s", "obj1111111111111111111111\n");
		//for (int i = 0; i < 8; i++)
		//{
		//	printf("v %f %f %f \n", BV1_Vetices[i].x, BV1_Vetices[i].y, BV1_Vetices[i].z);
		//}

		//printf("%s", "obj22222222222222\n");
		//for (int i = 0; i < 8; i++)
		//{
		//	printf("v %f %f %f \n", BV2_Vetices[i].x, BV2_Vetices[i].y, BV2_Vetices[i].z);
		//}

		//intersect all edges of cube 1 with all faces of cube 2
		//first get edges of first cube
		line edges[12];
		//
		edges[0].load(BV1_Vetices[0], BV1_Vetices[1]);
		edges[1].load(BV1_Vetices[1], BV1_Vetices[3]);
		edges[2].load(BV1_Vetices[3], BV1_Vetices[2]);
		edges[3].load(BV1_Vetices[2], BV1_Vetices[0]);

		edges[4].load(BV1_Vetices[3], BV1_Vetices[7]);
		edges[5].load(BV1_Vetices[7], BV1_Vetices[6]);
		edges[6].load(BV1_Vetices[6], BV1_Vetices[2]);
		edges[7].load(BV1_Vetices[7], BV1_Vetices[5]);

		edges[8].load(BV1_Vetices[5], BV1_Vetices[4]);
		edges[9].load(BV1_Vetices[4], BV1_Vetices[6]);
		edges[10].load(BV1_Vetices[0], BV1_Vetices[4]);
		edges[11].load(BV1_Vetices[1], BV1_Vetices[5]);




		//second getfaces of second cube
		plane faces[6];
		faces[0].load(BV2_Vetices[0], BV2_Vetices[1], BV2_Vetices[3], BV2_Vetices[2]);
		faces[1].load(BV2_Vetices[2], BV2_Vetices[3], BV2_Vetices[7], BV2_Vetices[6]);
		faces[2].load(BV2_Vetices[6], BV2_Vetices[7], BV2_Vetices[5], BV2_Vetices[4]);
		faces[3].load(BV2_Vetices[4], BV2_Vetices[5], BV2_Vetices[1], BV2_Vetices[0]);
		faces[4].load(BV2_Vetices[2], BV2_Vetices[6], BV2_Vetices[4], BV2_Vetices[0]);
		faces[5].load(BV2_Vetices[7], BV2_Vetices[3], BV2_Vetices[1], BV2_Vetices[5]);


		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (Line_Plane_Intersect(edges[i], faces[j]))
					return true;

			}

		}

		return false;

	}


	//printf("%s", "obj1111111111111111111111\n");
	//for (int i = 0; i < 8; i++)
	//{
	//	printf("v %f %f %f \n", obj1_vertices[i].x, obj1_vertices[i].y, obj1_vertices[i].z);
	//}

	//printf("%s", "obj22222222222222\n");
	//for (int i = 0; i < 8; i++)
	//{
	//	printf("v %f %f %f \n", obj2_vertices[i].x, obj2_vertices[i].y, obj2_vertices[i].z);
	//}
	// to be continues bs mesh hnkmla isa hyea al cubes 7elwa :D

};