#ifndef UTILS_TEXTUREDBACKGROUND_HPP
#define UTILS_TEXTUREDBACKGROUND_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Vertex.hpp>

namespace sf
{
class RenderTarget;
class Texture;
}

namespace Utils{namespace sfml
{

class TexturedBackground: public sf::Drawable
{
    public:
        TexturedBackground();
        ~TexturedBackground();

        void SetRepeat(unsigned int horizontalRepeat, unsigned int verticalRepeat);
        void SetTexture(const sf::Texture * texture);

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

    private:
        void Comp();

        const sf::Texture * _texture;
        sf::Vertex _vertices[4];
        unsigned int _horizontalRepeat, _verticalRepeat;
};

}}

#endif
