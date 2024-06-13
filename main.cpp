#include <SFML/Graphics.hpp>

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(1280, 720);
    //sf::VideoMode videoMode = *(new sf::VideoMode(800, 600)); sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "Game Window");
    //sf::RenderWindow window(sf::VideoMode(1280, 720), "Resizable Window", sf::Style::Resize);
    //sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Fullscreen Window", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(100, 100));

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Black);

        float windowCenterX = static_cast<float>(window.getSize().x) / 2.f;
        float windowCenterY = static_cast<float>(window.getSize().y) / 2.f;
        
        // Draw a square
        float sideLength = 500.f;
        sf::RectangleShape square(sf::Vector2f(sideLength, sideLength));
        square.setFillColor(sf::Color(132, 8, 8, 255));
        square.setPosition(windowCenterX - (sideLength / 2.f), windowCenterY - (sideLength / 2.f));
        window.draw(square);
        
        // Draw a circle
        float radius = 200.f;
        sf::CircleShape circle(radius);
        circle.setFillColor(sf::Color(31, 188, 14, 255));
        circle.setPosition(windowCenterX - radius, windowCenterY - radius);
        window.draw(circle);

        // Draw a triangle using sf::ConvexShape
        float halfBase = 120.f; // Half the length of the base of the triangle
        float height = 160.f; // Height of the triangle
        sf::ConvexShape triangle;
        triangle.setPointCount(3); // A triangle has 3 points
        // Set the positions of the points
        triangle.setPoint(0, sf::Vector2f(windowCenterX, windowCenterY - (height / 2.f))); // Top point
        triangle.setPoint(1, sf::Vector2f(windowCenterX - halfBase, windowCenterY + (height / 2.f))); // Bottom-left point
        triangle.setPoint(2, sf::Vector2f(windowCenterX + halfBase, windowCenterY + (height / 2.f))); // Bottom-right point
        triangle.setFillColor(sf::Color(8, 8, 143, 255));
        window.draw(triangle);

        // Draw sprite using texture asset
        sf::Texture logo_texture;
        logo_texture.loadFromFile("assets/textures/logo.png");
        sf::Sprite logo_sprite;
        logo_sprite.setTexture(logo_texture);
        float scale = 0.5f;
        float spriteWidth = 157.f;
        float spriteHeight = 119.f;
        logo_sprite.setPosition(windowCenterX - spriteWidth*scale/2.f, windowCenterY - spriteHeight*scale/2.f);
        logo_sprite.setRotation(0);
        logo_sprite.setScale(scale, scale);

        // Draw text using font asset
        sf::Font font;
        font.loadFromFile("assets/fonts/DS_DigiB.ttf");
        sf::Text title_text("MATRIX", font, 50);
        title_text.setPosition(windowCenterX - 65, 0);
        title_text.setFillColor(sf::Color::White);
        window.draw(title_text);

        window.draw(logo_sprite);
        
        // Display whatever you draw
        window.display();
    }

    return 0;
}