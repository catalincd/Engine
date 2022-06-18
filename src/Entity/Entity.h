#pragma once
#include "../basic.h"
#include "../Light/Light.h"

namespace Core
{
	struct EntityVertex
	{
		float x, y, z;
		float tx, ty;
	};

	class Entity
	{
		int ID = -1;
		bool IgnoreBuckets = false;
		
		int ApplyLightType = 0;
		float SpecularScale = 0.5f;
		float Radius;
		bool Collidable = false;

		bool Lit = false;
		Light* m_light;

		std::string m_name;

		std::string m_DiffusePath;
		std::string m_SpecularPath;
		std::string m_NormalPath;

		GLuint m_DiffuseID = 0;
		GLuint m_SpecularID = 0;
		GLuint m_NormalID = 0;

		vector2 m_position;
		vector2 m_size;
		vector2 m_scale = vector2(1.0);
		vector2 m_origin = vector2(0.5f);
		float m_angle = 0;
		Color m_color = Color();


		vector2 topLeft;
		vector2 bottomLeft;
		vector2 topRight;
		vector2 bottomRight;
		EntityVertex m_vertices[4];
		
		//CollisionBox m_collisionBox;

	public:
		Entity(const std::string& name, vector2 position, vector2 size = vector2(128.0f));

		void Load();

		void Update();

		void GenerateVertices();

		vector2 GetBucket();

		vector2 GetPosition() const;

		void SetPosition(const vector2& pos);
		void AddToPosition(const vector2& pos);

		inline EntityVertex GetVertex(int id) const { return m_vertices[id]; }

		void Draw();

		inline GLuint GetDiffuseID() const { return m_DiffuseID; }
		inline GLuint GetSpecularID() const { return m_SpecularID; }
		inline GLuint GetNormalID() const { return m_NormalID; }

		inline Color GetColor() const { return m_color; }

		inline float GetSpacularScale() const { return SpecularScale; }
		void SetSpecularScale(float scale);

		inline int GetApplyLightType() const { return ApplyLightType; }
		void SetApplyLightType(int type);

		inline bool isCollidable() const { return Collidable; }

		void SetCollisionRadius(float radius);

		inline float GetRadius() const;

		void SetOrigin(const vector2& origin);

		void SetAngle(float angle);

		bool IsColliding(const Entity& other);

		//Set Origin, Color, ...
	};
}