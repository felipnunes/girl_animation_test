#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    
    sf::RenderWindow janela(sf::VideoMode(800,600), "Princess");
    janela.setVerticalSyncEnabled(true);
    //personagem
    sf::IntRect rect(0,0,45,79);
    sf::Texture t;
    t.loadFromFile("character_sprite.png");
    t.setSmooth(true);
    sf::Sprite player(t, rect);
    player.setPosition(400,300);
    player.scale(1.5,1.5);

    sf::Clock c;
    while(janela.isOpen()) {
        sf::Event evento;



        while(janela.pollEvent(evento)) {

        //event polling
        switch (evento.type) {
            case sf::Event::Closed:
                janela.close();
                break;
            }

        }

        //Updating

        //Render
        janela.clear(sf::Color::White); // clear the old frame

        //.......here you draw your game.......//
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(5,0);
            if(c.getElapsedTime().asSeconds() >= 0.15) {

                rect.top = 160;

                if(rect.left >= 2*45) {
                rect.left = 0;
                }
            
                else {
                    rect.left += 49;
                }
                player.setTextureRect(rect);
                c.restart();


                rect.top = 0;
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.move(-5,0);
            if(c.getElapsedTime().asSeconds() >= 0.15) {

                rect.top = 80;

                if(rect.left >= 2*45) {
                rect.left = 0;
                }
            
                else {
                    rect.left += 49;
                }
                player.setTextureRect(rect);
                c.restart();


                rect.top = 0;
            }
        }

        else if(c.getElapsedTime().asSeconds() >= 0.25) {

            if(rect.left >= 2*45) {
                rect.left = 0;
            }
            else {
                rect.left += 49;
            }
            player.setTextureRect(rect);
            c.restart();
        }
        janela.draw(player);

        janela.display(); // tell app that is done drawing

    }
    return 0;
}
