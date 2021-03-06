#pragma once
#include "IRenderable.h"
#include "Transformable.h"
#include "DataFormatEnum.h"
#include "EntityTypeEnum.h"
#include "Material.h"
#include "Shader.h"

namespace Atlas
{

	class BaseEntity : public Transformable, public IRenderable
	{
	public:
		BaseEntity();
		BaseEntity(glm::vec3 pos, Shader* shader);
		BaseEntity(float x, float y, float z, Shader* shader);
		virtual ~BaseEntity();

		virtual void Update();
		virtual void Render(glm::mat4& view, glm::mat4& proj, glm::vec3& cameraPos, std::vector<Light*>& lights);
		
		virtual void InitData() {}

		virtual void Kill() { _dead = true; }

		// Getters
		bool IsDead() { return _dead; }
		EntityTypeEnum GetType() { return _entityType; }

		// Setters
		void SetTexture(unsigned int texID);

		void SetMaterial(Material& mat);

	protected:
		virtual void Initialise(DataFormatEnum dataFormat);
		virtual void ReloadData();
		virtual void Reset();

		void SetVertex(int &dataPos, float x, float y, float z, float r, float g, float b);
		void SetIndex(int &indexPos, unsigned short a, unsigned short b, unsigned short c);

		float* _data;
		unsigned short* _indices;
		int _numVertices;
		int _numIndices;
		
		EntityTypeEnum _entityType;
		DataFormatEnum _dataFormat;
		unsigned int _texRepeat;
		
		int _mode;

		float _size;

		Material _material;

		bool _dead;

	private:

		unsigned int _vbaID;
		unsigned int _vbID;

		unsigned int _ibaID;

		unsigned int _texID;

		Shader* _shader;

		bool _initialised;
	};
}