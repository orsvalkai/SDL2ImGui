// Copyright(c) 2024 Valkai-N�meth B�la-�rs

#ifndef SPRITE_ANIMATOR_H
#define SPRITE_ANIMATOR_H

#include <vector>

// !! Not a full template since the header doesn't contain implementation !!
// We only offer implementation for T : unsinged char & unsigned short so only
// these will work and instantiation can be found on the bottom of the .cpp
//
// In case we wanted to offer any T we would have needed to implement the whole
// class in the header. In c++11 and newer you can declare template implementations
// as extern, so you debloat compile times.

template <typename T>
class SpriteAnimator {
private:
	std::vector<T> m_spriteIdPattern;
	std::vector<T> m_animOffset;
	float m_accTime = 0.f;
	int m_targetFPS;
	unsigned short m_curPatternId = 0;
	unsigned short m_lastAnimId = 257;

public:
	explicit SpriteAnimator(const int targetFPS);

	void SetSpriteIdPattern(std::vector<T>&& pattern);

	void AddAnimOffset(const T offset);

	int ComputeSpriteId(unsigned char animId, float deltaTime);
};

#endif // SPRITE_ANIMATOR_H

