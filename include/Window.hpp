#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

enum class ColourMode {
    R = 0,
    G = 1,
    B = 2,
};

class Application {
private:
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::String windowTitle;
    sf::Event event;
    sf::Clock clock;
    sf::Color ZERO = sf::Color::Black;
    sf::Color backgroundColor;
    ColourMode colourMode = ColourMode::R;
    void handleKeyPressed(sf::Event::KeyEvent key);
    void update();
    static sf::String colour2String(const sf::Color &);
public:
    void init(int width, int height, const char *title = nullptr);
    void pollEvents();
    void display();
    [[nodiscard]] inline bool isOpen() const;
    void setTitle(const char *title);
    int run();
    ~Application();
    [[nodiscard]] inline sf::Time getElapsedTime() const;

};

#endif //WINDOW_HPP
