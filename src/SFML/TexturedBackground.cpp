#include "TexturedBackground.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace Utils{namespace sfml
{

TexturedBackground::TexturedBackground():
_texture(00), _vertices(), _horizontalRepeat(1), _verticalRepeat(1)
{
    _vertices[0].color = sf::Color::White;
    _vertices[1].color = sf::Color::White;
    _vertices[2].color = sf::Color::White;
    _vertices[3].color = sf::Color::White;
    _vertices[0].position = sf::Vector2f(0, 1);
    _vertices[1].position = sf::Vector2f(1, 1);
    _vertices[2].position = sf::Vector2f(0, 0);
    _vertices[3].position = sf::Vector2f(1, 0);
}

TexturedBackground::~TexturedBackground(){}

void TexturedBackground::SetRepeat(unsigned int horizontalRepeat, unsigned int verticalRepeat)
{
    _horizontalRepeat = horizontalRepeat;
    _verticalRepeat = verticalRepeat;
    Comp();
}

void TexturedBackground::SetTexture(const sf::Texture * texture)
{
    _texture = texture;
    Comp();
}

void TexturedBackground::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    sf::View actualView = target.getView();
    target.setView(sf::View(sf::FloatRect(0, 0, 1, 1)));
    states.texture = _texture;
    target.draw(_vertices, 4, sf::PrimitiveType::TrianglesStrip, states);
    target.setView(actualView);
}

void TexturedBackground::Comp()
{
    if (_texture == nullptr)
        return;
    sf::Vector2u size = _texture->getSize();
    _vertices[0].texCoords = sf::Vector2f(0, size.y*_verticalRepeat);
    _vertices[1].texCoords = sf::Vector2f(size.x*_horizontalRepeat, size.y*_verticalRepeat);
    _vertices[2].texCoords = sf::Vector2f(0, 0);
    _vertices[3].texCoords = sf::Vector2f(size.x*_horizontalRepeat, 0);
}

}}
