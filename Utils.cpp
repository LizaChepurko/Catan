/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include "Utils.hpp"

sf::Vector2f hexCorner(float centerX, float centerY, int size, int i) {
    float angle_deg = 60 * i + 30;
    float angle_rad = M_PI / 180 * angle_deg;
    return sf::Vector2f(centerX + size * cos(angle_rad),
                        centerY + size * sin(angle_rad));
}

void drawHex(sf::RenderWindow &window, float x, float y, int size, sf::Color color) {
    sf::ConvexShape hex;
    hex.setPointCount(6);
    for (int i = 0; i < 6; ++i) {
        sf::Vector2f corner = hexCorner(x, y, size, i);
        hex.setPoint(i, corner);
    }
    hex.setFillColor(color);
    hex.setOutlineColor(sf::Color::Black);
    hex.setOutlineThickness(2);
    window.draw(hex);
}

void drawBoard(sf::RenderWindow &window, Board &board, sf::Font &font) {
    std::map<std::string, sf::Color> colorMap = {
        {"Wood", sf::Color(1, 150, 32)},
        {"Brick", sf::Color(150, 70, 42)},
        {"Desert", sf::Color(255, 255, 0)},
        {"Ore", sf::Color(192, 192, 192)},
        {"Wheat", sf::Color(255, 200, 0)},
        {"Sheep", sf::Color(0, 255, 0)}
    };

    std::vector<sf::Vector2f> positions = {
        {300, 150}, {390, 150}, {480, 150}, {255, 225},
        {345, 225}, {435, 225}, {525, 225}, {210, 300},
        {300, 300}, {390, 300}, {480, 300}, {570, 300},
        {255, 375}, {345, 375}, {435, 375}, {525, 375},
        {300, 450}, {390, 450}, {480, 450}
    };

        for (size_t i = 0; i < board.block.size(); ++i) {
        std::string resourceType = board.block[i].ResourceType;
        sf::Color color = colorMap[resourceType];
        drawHex(window, positions[i].x, positions[i].y, TILE_RADIUS, color);

        // Draw productivity number
        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(board.block[i].productivity));
        text.setCharacterSize(24); // You can adjust the size
        text.setFillColor(sf::Color::Black);

        // Center the text on the hex
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(positions[i].x, positions[i].y);

        window.draw(text);
    }
}

void runSfmlWindow(Board &board, sf::Font &font) {
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Catan Board");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        drawBoard(window, board, font);
        window.display();
    }
}