#include "TileMapper.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

namespace Utils{namespace sfml
{

TileMapper::TileMapper():_texture(nullptr),_vertices(){}
TileMapper::~TileMapper(){}

void TileMapper::MakeCoords(size_t x, size_t y, size_t index) const
{
    sf::FloatRect internalRect = GetInternalRect(x, y);
    sf::FloatRect externalRect = GetExternalRect(x, y, internalRect);

    float unitX = internalRect.width;
    float unitY = internalRect.height;
    float xmin = (externalRect.left - internalRect.left)/unitX + x;
    float xmax = (externalRect.left+externalRect.width - (internalRect.left+internalRect.width))/unitX + x + 1;
    float ymin = (externalRect.top-externalRect.height - (internalRect.top-internalRect.height))/unitY + y;
    float ymax = (externalRect.top - internalRect.top)/unitY + y + 1;

    sf::Color color = GetColor(x, y);
    _vertices[index+0].texCoords = sf::Vector2f(externalRect.left, externalRect.top-externalRect.height);
    _vertices[index+0].color = color;
    _vertices[index+0].position = sf::Vector2f(xmin, ymin);

    _vertices[index+1].texCoords = sf::Vector2f(externalRect.left+externalRect.width, externalRect.top-externalRect.height);
    _vertices[index+1].color = color;
    _vertices[index+1].position = sf::Vector2f(xmax, ymin);

    _vertices[index+2].texCoords = sf::Vector2f(externalRect.left+externalRect.width, externalRect.top);
    _vertices[index+2].color = color;
    _vertices[index+2].position = sf::Vector2f(xmax, ymax);

    _vertices[index+3] = _vertices[index+2];

    _vertices[index+4].texCoords = sf::Vector2f(externalRect.left, externalRect.top);
    _vertices[index+4].color = color;
    _vertices[index+4].position = sf::Vector2f(xmin, ymax);

    _vertices[index+5] = _vertices[index+0];
}

void TileMapper::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    size_t i = 0, j = 0;
    size_t Lines = GetLineCount();
    size_t Columns = GetColumnCount();
    size_t LinesColumns = Lines * Columns;
    //Avoid empty map and integer overflow
    if (LinesColumns == 0 || LinesColumns/Lines != Columns || (LinesColumns*6)/6 != LinesColumns)
        return;
    _vertices.resize(LinesColumns*6);
    size_t index;
    while (i < Lines)
    {
        j = 0;
        while (j < Columns)
        {
            index = i*Columns+j;
            MakeCoords(i, j, index*6);
            j++;
        }
        i++;
    }
    _vertices.setPrimitiveType(sf::Triangles);
    states.transform *= getTransform();
    states.texture = GetTexture();
    target.draw(_vertices, states);
}

}}



