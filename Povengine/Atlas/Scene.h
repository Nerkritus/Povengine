#pragma once
#include <vector>
#include <string>
#include <sstream>

#include "IRenderable.h"
#include "../AtlasUtil/AtlasStopwatch.h"
#include "Audio.h"
#include "Camera.h"
#include "glm.hpp"
#include "EntityTypeEnum.h"
#include "EntityFactory.h"
#include "Text.h"
#include "Subsystems.h"

namespace Atlas
{
	class Scene
	{
	public:
		Scene(std::string name, Subsystems subsystems);

		void UnloadScene();

		void Start();
		void Stop();

		void UpdateScene(double& fps);
		void DrawScene(glm::mat4 proj, glm::mat4 proj2D);

		//IRenderable* GetEntity(int index) { return _entities[index]; }
		Camera& GetCamera() { return _cam; }

		void RemoveEntity(BaseEntity* entity);

		bool AddBackgroundMusic(std::string fileName);
		void SetCamera(glm::vec3 pos, glm::vec3 target);
		void AddEntity(EntityHolder* entity);
		void AddLight(Light* light);
		void AddMesh(std::string& meshName, EntityCreateInfo& info);
		void AddText(std::string& text, int x, int y, FontStyleEnum style, TextAlignmentEnum horizontalAlignment, TextAlignmentEnum verticalAlignment);

	private:
		std::vector<EntityHolder*> _entities;	// Entities contained within holders (things that need to be updated regularly but are not rendered, game objects etc.)
		std::vector<Light*> _lights;
		std::vector<Text*> _textItems;

		Camera _cam;

		Subsystems _subsystems;

		AtlasUtil::AtlasStopwatch _sceneClock;
		AtlasUtil::AtlasStopwatch _textClock;

		bool _playMusic;
		unsigned long _bgMusicId;

		glm::mat4 _identity;

		std::string _name;
		std::string _titleText;
	};
}