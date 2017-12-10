#include "object.h"



object::object(char * p, char * t, char* vxshader_name, char* fragshader_name, Loading_kind lk) :obj_path(p), texrure_path(t)
{
	if (lk == Normal)
	{
		objectID = LoadShaders(vxshader_name, fragshader_name);
		glUseProgram(objectID);

		// Get a handle for our "MVP" uniform
		MVP_MatrixID = glGetUniformLocation(objectID, "MVP");
		ViewMatrixID = glGetUniformLocation(objectID, "V");
		ModelMatrixID = glGetUniformLocation(objectID, "M");


		// Get a handle for our buffers
		vertexPosition_modelspaceID = glGetAttribLocation(objectID, "vertexPosition_modelspace");
		vertexUVID = glGetAttribLocation(objectID, "vertexUV");
		vertexNormal_modelspaceID = glGetAttribLocation(objectID, "vertexNormal_modelspace");


		// Load the texture
		Texture = loadBMP_custom(t);

		// Get a handle for our "myTextureSampler" uniform
		TextureID = glGetUniformLocation(objectID, "myTextureSampler");


		loadOBJ(p, vertices, uvs, normals);

		BV_instilizasion();

		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);



		glGenBuffers(1, &uvbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
		glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

		glGenBuffers(1, &normalbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
		glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

		LightID = glGetUniformLocation(objectID, "LightPosition_worldspace");
		ModelMatrix = glm::mat4(1.0);

	}



}



void object::BV_instilizasion()
{
	this->obj_BV.min = this->vertices[0];
	this->obj_BV.max = this->vertices[0];
	for (unsigned int i = 1; i < vertices.size(); i++)
	{
		if (vertices[i].x < obj_BV.min.x)
			obj_BV.min.x = vertices[i].x;
		else if (vertices[i].x > obj_BV.max.x)
			obj_BV.max.x = vertices[i].x;

		if (vertices[i].y < obj_BV.min.y)
			obj_BV.min.y = vertices[i].y;
		else if (vertices[i].y > obj_BV.max.y)
			obj_BV.max.y = vertices[i].y;

		if (vertices[i].z < obj_BV.min.z)
			obj_BV.min.z = vertices[i].z;
		else if (vertices[i].z > obj_BV.max.z)
			obj_BV.max.z = vertices[i].z;

	}


	float temp_arr[6] = { this->obj_BV.min.x, this->obj_BV.min.y, this->obj_BV.min.z, this->obj_BV.max.x, this->obj_BV.max.y, this->obj_BV.max.z };

	int i = 0;
	for (int j = 7; j < 64; j++)
	{
		if (i > 7)
			break;
		int number = j;
		int pos[6];
		int pos_indx = 0;
		int one_pos_in_number = 0;
		while (number)
		{
			if (number & 1)
				pos[pos_indx++] = one_pos_in_number;

			number = number >> 1;
			one_pos_in_number++;
		}
		if (pos_indx == 3 && abs(pos[0] - pos[1]) != 3 && abs(pos[0] - pos[2]) != 3 && abs(pos[1] - pos[2]) != 3)
		{

			if (pos[0] == 0 || pos[0] == 3)
				this->obj_BV.BV_vertices[i].x = temp_arr[pos[0]];
			else if (pos[0] == 1 || pos[0] == 4)
				this->obj_BV.BV_vertices[i].y = temp_arr[pos[0]];
			else
				this->obj_BV.BV_vertices[i].z = temp_arr[pos[0]];

			if (pos[1] == 0 || pos[1] == 3)
				this->obj_BV.BV_vertices[i].x = temp_arr[pos[1]];
			else if (pos[1] == 1 || pos[1] == 4)
				this->obj_BV.BV_vertices[i].y = temp_arr[pos[1]];
			else
				this->obj_BV.BV_vertices[i].z = temp_arr[pos[1]];

			if (pos[2] == 0 || pos[2] == 3)
				this->obj_BV.BV_vertices[i].x = temp_arr[pos[2]];
			else if (pos[2] == 1 || pos[2] == 4)
				this->obj_BV.BV_vertices[i].y = temp_arr[pos[2]];
			else
				this->obj_BV.BV_vertices[i].z = temp_arr[pos[2]];

			i++;
		}

	}
}

void object::Translate(const glm::vec3 & v)
{
	ModelMatrix = glm::translate(glm::mat4(),v) * ModelMatrix;
}

void object::Rotate(float x_angle_in_rand, float y_angle_in_rand, float z_angle_in_rand)
{
	ModelMatrix = eulerAngleYXZ(y_angle_in_rand , x_angle_in_rand, z_angle_in_rand) * ModelMatrix;


}

void object::Scale(const glm::vec3 &v)
{

	ModelMatrix = glm::scale(glm::mat4(1.0f),v) *ModelMatrix;
}


void object::Draw(const glm::mat4 & ViewMatrix,const glm::mat4 & ProjectionMatrix,const glm::vec3 &lightPos)
{
	// Clear the screen
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Use our shader
	glUseProgram(objectID);


	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
	glUniformMatrix4fv(MVP_MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
	glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);

	glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture);
	// Set our "myTextureSampler" sampler to user Texture Unit 0
	glUniform1i(TextureID, 0);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(vertexPosition_modelspaceID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		vertexPosition_modelspaceID,  // The attribute we want to configure
		3,                            // size
		GL_FLOAT,                     // type
		GL_FALSE,                     // normalized?
		0,                            // stride
		(void*)0                      // array buffer offset
	);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(vertexUVID);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glVertexAttribPointer(
		vertexUVID,                   // The attribute we want to configure
		2,                            // size : U+V => 2
		GL_FLOAT,                     // type
		GL_FALSE,                     // normalized?
		0,                            // stride
		(void*)0                      // array buffer offset
	);

	// 3rd attribute buffer : normals
	glEnableVertexAttribArray(vertexNormal_modelspaceID);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glVertexAttribPointer(
		vertexNormal_modelspaceID,    // The attribute we want to configure
		3,                            // size
		GL_FLOAT,                     // type
		GL_FALSE,                     // normalized?
		0,                            // stride
		(void*)0                      // array buffer offset
	);

	// Draw the triangles !
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	glDisableVertexAttribArray(vertexPosition_modelspaceID);
	glDisableVertexAttribArray(vertexUVID);
	glDisableVertexAttribArray(vertexNormal_modelspaceID);


}

object::~object()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(objectID);
	glDeleteTextures(1, &Texture);
}
