#ifndef UTILS_UNICOLOR_HPP
#define UTILS_UNICOLOR_HPP

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace Utils{namespace sfml
{

class UniColor : public sf::Drawable
{
    public:
        UniColor(const sf::Color & c = sf::Color::Black);
        virtual ~UniColor();

        sf::Color color;

        virtual void draw(sf::RenderTarget & target, sf::RenderStates) const;
};

}}

#endif
