#ifndef UTILS_SFML_TILEMAPPER_HPP
#define UTILS_SFML_TILEMAPPER_HPP

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace Utils{namespace sfml
{

class TileMapper: public sf::Drawable, public sf::Transformable
{
    public:
        TileMapper();
        TileMapper(const TileMapper &) = default;
        virtual ~TileMapper();
        TileMapper & operator=(const TileMapper &) = default;

        virtual unsigned int GetLineCount() const = 0;
        virtual unsigned int GetColumnCount() const = 0;
        virtual const sf::Texture * GetTexture() const = 0;

        virtual sf::Color GetColor(int x, int y) const = 0;
        virtual sf::FloatRect GetInternalRect(int x, int y) const = 0;
        virtual sf::FloatRect GetExternalRect(int x, int y, const sf::FloatRect & internalRect) const = 0;

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

    private:
        sf::Texture * _texture;
        mutable sf::VertexArray _vertices;

        void MakeCoords(size_t x, size_t y, size_t index) const;
};

}}


#endif

