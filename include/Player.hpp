// Copyright(c) 2024 Valkai-N�meth B�la-�rs

#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerSprite.hpp"
#include "IDrawable.hpp"
#include "BaseControl.hpp"

class Player : public vo::IDrawable
{
private:
	PlayerSprite m_sprite;
	std::shared_ptr<BaseControl> m_pCtrl;
	AnimId m_animId = AnimId::IdleBack;

public:
	Player(SDL_Renderer* pRenderer, const char* pFilePath, unsigned width, unsigned height, unsigned nrSprites);
	std::shared_ptr<BaseControl> AddControl(std::shared_ptr<BaseControl> spCtrl);
	void Update(float deltaTime);
	bool Draw(int posX, int posY, float deltaTime) final;
};

#endif // PLAYER_H

