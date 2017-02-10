#ifndef UTILS_SFML_COLOUREDBACKGROUND_HPP
#define UTILS_SFML_COLOUREDBACKGROUND_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Vertex.hpp>

namespace sf
{
class RenderTarget;
}

namespace Utils{namespace sfml
{

class ColouredBackground: public sf::Drawable
{
    public:
        ColouredBackground();
        ~ColouredBackground();

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

        void SetColors(const sf::Color & topLeft, const sf::Color & topRight, const sf::Color & bottomLeft, const sf::Color & bottomRight);
        sf::Color GetTopLeft() const;
        sf::Color GetTopRight() const;
        sf::Color GetBottomLeft() const;
        sf::Color GetBottomRight() const;

    private:
        sf::Vertex _vertices[6];
};

}}

#endif
