#pragma once
#include"./Jumanji/lvl/lvl.h"
enum flying
{
	onground,
	goingup,
	goingdown,
	maxfly
};

class lvl1 :public lvl
{
	object *map;
	glm::vec3 max_mov_for_character_in_pos_XYZ;
	glm::vec3 max_mov_for_character_in_neg_XYZ;
	flying jmpcases;
public:
	lvl1(int);
	virtual void load(char *, char *, char *, char *,int= 1);
	virtual void Draw(int index, const glm::vec3 & lightpos);
	virtual void Draw_all(const glm::vec3 & lightpos);
	virtual void Play(const glm::vec3 & lightpos);

	~lvl1();
};

