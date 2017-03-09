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
        TexturedBackground(const TexturedBackground & other) = default;
        ~TexturedBackground();

        TexturedBackground & operator=(const TexturedBackground & other) = default;

        void SetRepeat(unsigned int horizontalRepeat, unsigned int verticalRepeat);
        void SetTexture(const sf::Texture * texture);
        void Rotate(int rotation);//1 = 90°, trigonometric
        void FlipX();
        void FlipY();

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

    private:
        void Comp();

        const sf::Texture * _texture;
        sf::Vertex _vertices[4];
        unsigned int _horizontalRepeat, _verticalRepeat, _rotation;
        bool _flipX;
};

}}

#endif
