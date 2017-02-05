#include "ColouredBackground.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace Utils{namespace sfml
{

ColouredBackground::ColouredBackground():
_vertices()
{
    _vertices[0].color = sf::Color::White;
    _vertices[1].color = sf::Color::White;
    _vertices[2].color = sf::Color::White;
    _vertices[3].color = sf::Color::White;
    _vertices[4].color = sf::Color::White;
    _vertices[5].color = sf::Color::White;
    _vertices[0].position = sf::Vector2f(0, 0);
    _vertices[1].position = sf::Vector2f(-1, -1);
    _vertices[2].position = sf::Vector2f(1, -1);
    _vertices[3].position = sf::Vector2f(1, 1);
    _vertices[4].position = sf::Vector2f(-1, 1);
    _vertices[5].position = sf::Vector2f(-1, 1);
}

ColouredBackground::~ColouredBackground(){}

void ColouredBackground::SetColors(const sf::Color & topLeft, const sf::Color & topRight, const sf::Color & bottomLeft, const sf::Color & bottomRight)
{
    _vertices[0].color = sf::Color(
        (int(topLeft.r) + int(topRight.r) + int(bottomLeft.r) + int(bottomRight.r))/4,
        (int(topLeft.g) + int(topRight.g) + int(bottomLeft.g) + int(bottomRight.g))/4,
        (int(topLeft.b) + int(topRight.b) + int(bottomLeft.b) + int(bottomRight.b))/4,
        (int(topLeft.a) + int(topRight.a) + int(bottomLeft.a) + int(bottomRight.a))/4);
    _vertices[1].color = topLeft;
    _vertices[2].color = topRight;
    _vertices[3].color = bottomRight;
    _vertices[4].color = bottomLeft;
    _vertices[5] = _vertices[1];
}

void ColouredBackground::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    sf::View actualView = target.getView();
    target.setView(sf::View(sf::FloatRect(-1, -1, 2, 2)));
    target.draw(_vertices, 6, sf::PrimitiveType::TrianglesFan, states);
    target.setView(actualView);
}

}}
