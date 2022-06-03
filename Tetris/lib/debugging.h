#pragma once

#if defined(_DEBUG)

#include <iostream>
#include <SFML/Graphics.hpp>

template <typename _Ty>
std::ostream& operator<<(std::ostream& stream, const sf::Vector2<_Ty> vec)
{
	stream << vec.x << ", " << vec.y;
	return stream;
}

#endif // defined(_DEBUG)

