/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Board.hpp"

// Define the size of the hexagons
const int TILE_SIZE = 100;
const float TILE_RADIUS = TILE_SIZE / 2.0f;
//Calculates the coordinates of a hexagon corner.
sf::Vector2f hexCorner(float centerX, float centerY, int size, int i);
//Draws a hexagon on the SFML window with specified coordinates, size, and color.
void drawHex(sf::RenderWindow &window, float x, float y, int size, sf::Color color);
//Draws the board on the SFML window with the specified font.
void drawBoard(sf::RenderWindow &window, Board &board, sf::Font &font);
//Runs the SFML window with the board and font.
void runSfmlWindow(Board &board, sf::Font &font);

#endif