// Copyright(c) 2024 Valkai-N�meth B�la-�rs

#include "AIControl.hpp"
#include <random>
#include <array>

AIControl::AIControl(PlayGround& playGround, unsigned short startTileId)
    : BaseControl(playGround, startTileId) {
}



void AIControl::Update(float deltaTime, vo::IDrawable* pDrawable) {
	static std::default_random_engine randEng;

	//std::cout << "AI update\n";
	const auto& targetTileId = GetTargetId();
	if (m_shouldPickNewTarget) {
		std::array<unsigned short, 4> neighbs;
		auto nCount = m_playGround.GetNeighborIdsForTileAt(neighbs, targetTileId);
        std::uniform_int_distribution<unsigned short> randDist(0, 6);

		for (unsigned short i = 0; i < nCount; i++) {
			if (neighbs[i] == GetCurrentId())
				continue;

			const auto& nTile = m_playGround.GetTileAt(neighbs[i]);
			if ((nTile.HasFlagAny(TileEntry::Flags::Destroyable) || !nTile.HasFlagAny(TileEntry::Flags::Occupied)) && randDist(randEng) >= 3) {
				m_prevId = neighbs[i];
				GetPotentialTargetId() = m_prevId;
				m_shouldPickNewTarget = false;

				//std::cout << "AI new target!\n";
				break;
			}
		}
	} else if (targetTileId == m_prevId) {
		m_shouldPickNewTarget = true;
	}

    BaseControl::Update(deltaTime, pDrawable);
}
