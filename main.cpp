#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>

class Frogs: public sf::Sprite
{
public:

    Frogs(float position): sf::Sprite()
    {
        position_ = position;
        setTextureRect(sf::IntRect(0, 0, 100, 100));
    }
    float position()
    {
        return position_;
    }
    void set_position(float p)
    {
        position_ = p;
    }

private:

   float position_;

};

int main() {
    // create the window
    int dimension_x = 750;
    int dimension_y = 450;
    sf::RenderWindow window(sf::VideoMode(dimension_x, dimension_y), "My window");
    //tlo
    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\aleks\\Documents\\build-Projekt-Desktop_Qt_5_12_1_MSVC2017_64bit-Debug\\debug\\rzeka.png"))
    {
        std::cout<<"Blad"<<std::endl;
    }
    sf::Sprite sprite;
    sprite.setTextureRect(sf::IntRect(10, 10, dimension_x, dimension_y));
    sprite.setPosition(sf::Vector2f(0.f, 0.f));
    sprite.setTexture(texture);
    //kamienie
    sf::Texture stone;
    if (!stone.loadFromFile("C:\\Users\\aleks\\Documents\\build-Projekt-Desktop_Qt_5_12_1_MSVC2017_64bit-Debug\\debug\\stone.png"))
    {
        std::cout<<"Blad"<<std::endl;
    }

    std::vector<sf::Sprite> stones;
    for(int i = 0; i < 7; i++)
    {

        sf::Sprite sprite_stone;
        sprite_stone.setTextureRect(sf::IntRect(10, 10, 100, 100));
        int a = 25 + 100*i;
        sprite_stone.setPosition(sf::Vector2f(a, 300.f));
        sprite_stone.setTexture(stone);
        stones.emplace_back(sprite_stone);

    }
    //zaby
    sf::Texture frog1;
    if (!frog1.loadFromFile("C:\\Users\\aleks\\Documents\\build-Projekt-Desktop_Qt_5_12_1_MSVC2017_64bit-Debug\\debug\\frog.png"))
    {
        std::cout<<"Blad"<<std::endl;
    }

    std::vector<Frogs> frogs1;

    for(int i = 0; i < 3; i++)
    {
        int a = 25 + 100*i;
        Frogs sprite_frog1(a);
        sprite_frog1.setPosition(sf::Vector2f(a, 285.f));
        sprite_frog1.setTexture(frog1);
        frogs1.emplace_back(sprite_frog1);

    }

    sf::Texture frog2;
    if (!frog2.loadFromFile("C:\\Users\\aleks\\Documents\\build-Projekt-Desktop_Qt_5_12_1_MSVC2017_64bit-Debug\\debug\\frog1.png"))
    {
        std::cout<<"Blad"<<std::endl;
    }

    sf::Texture frog3;
    if (!frog3.loadFromFile("C:\\Users\\aleks\\Documents\\build-Projekt-Desktop_Qt_5_12_1_MSVC2017_64bit-Debug\\debug\\frog2.png"))
    {
        std::cout<<"Blad"<<std::endl;
    }

    for(int i = 0; i < 3; i++)
    {
        int a = 425 + 100*i;
        Frogs sprite_frog1(a);
        sprite_frog1.setPosition(sf::Vector2f(a, 285.f));
        sprite_frog1.setTexture(frog3);
        frogs1.emplace_back(sprite_frog1);
    }


    sf::Texture frog4;
    if (!frog4.loadFromFile("C:\\Users\\aleks\\Documents\\build-Projekt-Desktop_Qt_5_12_1_MSVC2017_64bit-Debug\\debug\\frog3.png"))
    {
        std::cout<<"Blad"<<std::endl;
    }

    std::vector<bool> wybor;
    std::vector<bool> skokO2;
    std::vector<float> position;
    for (int i = 0; i < frogs1.size(); i++)
    {
        wybor.push_back(0);
        skokO2.push_back(0);
    }
    for(int i = 0; i < 3; i++)
    {
        position.push_back(100*i+25);
    }
    for(int i = 3; i <6; i++)
    {
        position.push_back(100*i+425);
    }




    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        sf::Vector2i v = sf::Mouse::getPosition(window);
        for(int i = 0; i <frogs1.size(); i++)
        {
            sf::FloatRect rect = frogs1[i].getGlobalBounds();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&(v.x>rect.left)&&(v.x<rect.left+rect.width)
                    &&(v.y>rect.top)&&(v.y<rect.top+rect.height))
            {
                wybor[i] = 1;
                skokO2[i] = 1;
                for (int j = 0; j < frogs1.size(); j++)
                {
                if ((i < 3)&&((frogs1[i].position() + 100)== frogs1[j].position()))
                {
                    wybor[i] = 0;
                    for (int k = 0; k < frogs1.size(); k++)
                    {
                        if(((frogs1[i].position() + 200)== frogs1[k].position()))
                        {
                            skokO2[i] = 0;
                        }
                    }

                }
                else if ((i > 2)&&((frogs1[i].position() - 100) == frogs1[j].position()))
                {
                    wybor[i] = 0;
                    for (int k = 0; k < frogs1.size(); k++)
                    {
                        if (((frogs1[i].position() - 200)== frogs1[k].position()))
                        {
                            skokO2[i] = 0;
                        }
                    }

                }
                }
                if(wybor[i] == 1)
                {
                    skokO2[i] = 0;
                }
        }}

            for (int i = 0; i < frogs1.size(); i++)
            {

                if (wybor[i] == 1)
                {
                    if ((i < 3)&&(position[i] < 600))
                    {
                        frogs1[i].setTexture(frog2);
                        sf::FloatRect rect = frogs1[i].getGlobalBounds();
                        if(rect.left< position[i]+50)
                        {
                            frogs1[i].move(0.5,-0.5);
                        }
                        else if ((rect.left>= position[i]+50)&&(rect.left<position[i]+100))
                        {
                            frogs1[i].move(0.5,0.5);
                        }
                        else if(rect.left>= position[i] +100)
                        {
                            wybor[i]=0;
                            position[i] = position[i] + 100;
                            frogs1[i].setTexture(frog1);
                            frogs1[i].set_position(position[i]);
                        }
                    }
                    else if ((i >= 3)&&(position[i]>100))
                    {
                        frogs1[i].setTexture(frog4);
                        sf::FloatRect rect = frogs1[i].getGlobalBounds();
                        if(rect.left> position[i]-50)
                        {
                            frogs1[i].move(-0.5,-0.5);
                        }
                        else if ((rect.left<= position[i]-50)&&(rect.left>position[i]-100))
                        {
                            frogs1[i].move(-0.5,0.5);
                        }
                        else if(rect.left<= position[i] -100)
                        {
                            frogs1[i].setTexture(frog3);
                            wybor[i]=0;
                            position[i] = position[i] - 100;
                            frogs1[i].set_position(position[i]);
                        }
                    }
                }
                if (skokO2[i] == 1)
                {
                    if ((i < 3)&&(position[i] < 500))
                    {
                        frogs1[i].setTexture(frog2);
                        sf::FloatRect rect = frogs1[i].getGlobalBounds();
                        if(rect.left< position[i]+100)
                        {
                            frogs1[i].move(1,-0.5);
                        }
                        else if ((rect.left>= position[i]+100)&&(rect.left<position[i]+200))
                        {
                            frogs1[i].move(1,0.5);
                        }
                        else if(rect.left>= position[i] +200)
                        {
                            skokO2[i]=0;
                            position[i] = position[i] + 200;
                            frogs1[i].setTexture(frog1);
                            frogs1[i].set_position(position[i]);
                        }
                    }
                    else if ((i >= 3)&&(position[i]>200))
                    {
                        frogs1[i].setTexture(frog4);
                        sf::FloatRect rect = frogs1[i].getGlobalBounds();
                        if(rect.left> position[i]-100)
                        {
                            frogs1[i].move(-1,-0.5);
                        }
                        else if ((rect.left<= position[i]-100)&&(rect.left>position[i]-200))
                        {
                            frogs1[i].move(-1,0.5);
                        }
                        else if(rect.left<= position[i] -200)
                        {
                            frogs1[i].setTexture(frog3);
                            skokO2[i]=0;
                            position[i] = position[i] - 200;
                            frogs1[i].set_position(position[i]);
                        }
                    }
                }
            }
        // draw everything here...
        window.draw(sprite);
        for(int i = 0; i < 7; i++)
        {
            window.draw(stones[i]);
        }

        for(int i = 0; i < frogs1.size(); i++)
        {
            window.draw(frogs1[i]);
        }


        // end the current frame
        window.display();
    }

    return 0;
}
