// Copyright(c) 2024 Valkai-N�meth B�la-�rs

#ifndef PLAY_GROUND_H
#define PLAY_GROUND_H

#include <vector>
#include "TileEntry.hpp"
#include "AtlassedSpriteU.hpp"
#include "Vector2D.hpp"

class PlayGround
{
	std::vector<TileEntry> m_tiles;
	vo::AtlassedSpriteU m_tileSprite;
	unsigned short m_height{0};
	unsigned short m_width{0};

public:
	PlayGround(unsigned short screenWidth, unsigned short screenHeight, SDL_Renderer* pRenderer, const char* pFilePathToTileAtlas);
	void Init();
	void Draw(float deltaTime);
	unsigned short GetNrOfTiles() const;
	unsigned short GetTileId(unsigned short tileX, unsigned short tileY) const;
	TileEntry& GetTileAt(unsigned short tileId);
	TileEntry& GetTileAt(unsigned short tileX, unsigned short tileY);
	unsigned short GetNeighborIdForTileAt(const vo::Vector2D<signed short>& direction, unsigned short tileId) const;
	unsigned short GetNeighborIdsForTileAt(std::array<unsigned short, 4>& neighborIds, unsigned short tileId) const;
	unsigned short GetNeighborIdForTileAt(const vo::Vector2D<signed short>& direction, unsigned short tileX, unsigned short tileY) const;
	unsigned short GetNeighborIdsForTileAt(std::array<unsigned short, 4>& neighborIds, unsigned short tileX, unsigned short tileY) const;
};

#endif // PLAY_GROUND_H

