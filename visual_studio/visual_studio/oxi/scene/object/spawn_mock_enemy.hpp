#pragma once

#include "../i_spawn.hpp"
#include <vector>

namespace oxi
{
	namespace scene
	{
		namespace object
		{
			class SpawnMockEnemy :public ISpawn
			{
			private:
				int kind_;
				int frame_{0};
				bool creatable_{ true };
				std::shared_ptr<IPosition> position_;
				std::shared_ptr<std::vector<std::shared_ptr<IPosition>>> enemy_positions_;
			public:
				explicit SpawnMockEnemy(std::shared_ptr<IPosition> position, std::shared_ptr<std::vector<std::shared_ptr<IPosition>>> enemy_positions);
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				void run() override;
				int getKind() override { return kind_; }
				bool isDisposable() override { return false; }
				bool isCreatable() override { return creatable_; }
				std::shared_ptr<IObject> create() override;
			};
		}
	}
}