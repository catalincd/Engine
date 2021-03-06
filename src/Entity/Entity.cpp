#include "Entity.h"
#include "../Texture/TextureManager.h"
#include "../Renderer/Renderer.h"
#include "../World/World.h"
#include "../utils/math.h"

extern Core::Renderer G_Renderer;
extern Core::TextureManager G_TextureManager;
extern Core::World G_World;

namespace Core
{
	extern Math math;

	Entity::Entity(const std::string& name, vector2 position, vector2 size)
	{
		m_name = name;
		m_position = position;
		m_size = size;
	}

	void Entity::Load()
	{
		m_DiffusePath = "res/entities/diffuse/" + m_name + ".png";
		m_SpecularPath = "res/entities/specular/" + m_name + ".png";
		m_NormalPath = "res/entities/normal/" + m_name + ".png";

		m_DiffuseID = G_TextureManager.LoadTexture(m_DiffusePath);
		m_SpecularID = G_TextureManager.LoadTexture(m_SpecularPath);
		m_NormalID = G_TextureManager.LoadTexture(m_NormalPath);

		//std::cout << "Diffuse: " << m_DiffuseID << std::endl;
		//std::cout << "Specular: " << m_SpecularID << std::endl;
		//std::cout << "Normal: " << m_NormalID << std::endl;
	}


	void Entity::Draw()
	{
		if (isPointInRect(GetBucket(), vector2(-2, -2), G_World.GetBucketLimit()) || IgnoreBuckets)
		{
			G_Renderer.DrawEntity(*this);
		}
	}

	vector2 Entity::GetBucket()
	{
		return GetPosition() / G_World.GetBucketSize();
	}

	vector2 Entity::GetPosition() const
	{
		return m_position;
	}

	void Entity::SetPosition(const vector2& pos)
	{
		m_position = pos;
	}
	
	void Entity::AddToPosition(const vector2& pos)
	{
		SetPosition(GetPosition() + pos);
	}

	void Entity::GenerateVertices()
	{
		vector2 pivot = m_size * m_origin;
		vector2 secondPivot = m_size * (vector2(1.0f) - m_origin);


		topLeft = m_position - pivot;
		bottomRight = m_position + secondPivot;
		topRight = vector2(bottomRight.x, topLeft.y);
		bottomLeft = vector2(topLeft.x, bottomRight.y);


		float angle = math.DegreeToRadian(m_angle);

		topLeft = math.RotatePointAround(topLeft, m_position, angle);
		topRight = math.RotatePointAround(topRight, m_position, angle);
		bottomLeft = math.RotatePointAround(bottomLeft, m_position, angle);
		bottomRight = math.RotatePointAround(bottomRight, m_position, angle);

		float z = 0.0f;

		m_vertices[0] = { topLeft.x,	 topLeft.y,		z, 0.0f, 0.0f};
		m_vertices[1] = { topRight.x,	 topRight.y,	z, 1.0f, 0.0f};
		m_vertices[2] = { bottomRight.x, bottomRight.y, z, 1.0f, 1.0f};
		m_vertices[3] = { bottomLeft.x,	 bottomLeft.y,	z, 0.0f, 1.0f};
	}

	void Entity::Update()
	{
		GenerateVertices();
	}

	void Entity::SetSpecularScale(float scale)
	{
		SpecularScale = scale;
	}

	void Entity::SetApplyLightType(int type)
	{
		ApplyLightType = type;
	}

	void Entity::SetCollisionRadius(float radius)
	{
		Radius = radius;
		Collidable = true;
	}

	float Entity::GetRadius() const
	{
		return Radius;
	}

	void Entity::SetOrigin(const vector2& origin)
	{
		m_origin = origin;
	}

	bool Entity::IsColliding(const Entity& other)
	{
		return (distance(m_position, other.GetPosition()) < Radius + other.GetRadius());
	}

	void Entity::SetAngle(float angle)
	{
		m_angle = angle;
	}
}

