#include "UniColor.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace Utils{namespace sfml
{

UniColor::UniColor(const sf::Color & c):color(c){}
UniColor::~UniColor(){}

void UniColor::draw(sf::RenderTarget & target, sf::RenderStates) const
{
    target.clear(color);
}

}}
