#include "TexturedBackground.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace Utils{namespace sfml
{

TexturedBackground::TexturedBackground():
_texture(nullptr), _vertices(), _horizontalRepeat(1), _verticalRepeat(1), _rotation(0), _flipX(false)
{
    _vertices[0].color = sf::Color::White;
    _vertices[1].color = sf::Color::White;
    _vertices[2].color = sf::Color::White;
    _vertices[3].color = sf::Color::White;
    _vertices[0].position = sf::Vector2f(0, 0);
    _vertices[1].position = sf::Vector2f(0, 1);
    _vertices[2].position = sf::Vector2f(1, 1);
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

void TexturedBackground::Rotate(int rotation)
{
    _rotation = (((_rotation+rotation)%4)+4)%4;
    Comp();
}

void TexturedBackground::FlipX()
{
    _flipX = !_flipX;
    Comp();
}

void TexturedBackground::FlipY()
{
    _rotation = (_rotation+2)%4;
    FlipX();
}

void TexturedBackground::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    sf::View actualView = target.getView();
    target.setView(sf::View(sf::FloatRect(0, 0, 1, 1)));
    states.texture = _texture;
    target.draw(_vertices, 4, sf::PrimitiveType::TrianglesFan, states);
    target.setView(actualView);
}

void TexturedBackground::Comp()
{
    if (_texture == nullptr)
        return;
    sf::Vector2u size = _texture->getSize();
    _vertices[(0+4-_rotation)%4].texCoords = sf::Vector2f(0, 0);
    _vertices[(1+4-_rotation)%4].texCoords = sf::Vector2f(0, size.y*_verticalRepeat);
    _vertices[(2+4-_rotation)%4].texCoords = sf::Vector2f(size.x*_horizontalRepeat, size.y*_verticalRepeat);
    _vertices[(3+4-_rotation)%4].texCoords = sf::Vector2f(size.x*_horizontalRepeat, 0);

    if (_flipX)
    {
        sf::Vector2f tmp;
        tmp = _vertices[0].texCoords;
        _vertices[0].texCoords = _vertices[3].texCoords;
        _vertices[3].texCoords = tmp;
        tmp = _vertices[2].texCoords;
        _vertices[2].texCoords = _vertices[1].texCoords;
        _vertices[1].texCoords = tmp;
    }
}

}}
