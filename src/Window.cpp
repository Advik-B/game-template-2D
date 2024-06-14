#include "Window.hpp"

void Application::init(int width, int height, const char *title) {
    videoMode = sf::VideoMode(width, height);
    this->windowTitle = title;
    window = new sf::RenderWindow(videoMode, title);
    window->setVerticalSyncEnabled(true);
    clock.restart();
    backgroundColor = ZERO;
}


void Application::pollEvents() {
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                handleKeyPressed(event.key);
                break;

            default:
                break;
        }
    }
}

void Application::display() {
    window->clear(backgroundColor);
    window->display();
}

bool Application::isOpen() const {
    return window->isOpen();
}

void Application::setTitle(const char *title) {
    this->windowTitle = title;
    window->setTitle(this->windowTitle);
}

void Application::update() {
    sf::Uint64 elapsed = getElapsedTime().asMicroseconds();
    switch (colourMode) {
        case ColourMode::R:
            backgroundColor.r += (sf::Uint8) elapsed % 255;
            colourMode = ColourMode::G;
            break;
        case ColourMode::G:
            backgroundColor.g += (sf::Uint8) elapsed % 255;
            colourMode = ColourMode::B;
            break;
        case ColourMode::B:
            backgroundColor.b += (sf::Uint8) elapsed % 255;
            colourMode = ColourMode::R;
            break;
    }

    setTitle(colour2String(backgroundColor).toAnsiString().c_str());
}

sf::String Application::colour2String(const sf::Color &colour) {
    sf::String str;
    str += "Colour: (";
    str += std::to_string(colour.r) + ", ";
    str += std::to_string(colour.g) + ", ";
    str += std::to_string(colour.b);
    str += ")";
    return str;
}

int Application::run() {

    while (isOpen()) {
        pollEvents();
        update();
        display();
        clock.restart();
    }
    return 0;
}

Application::~Application() {
    delete window;
}

sf::Time Application::getElapsedTime() const {
    return clock.getElapsedTime();
}

void Application::handleKeyPressed(sf::Event::KeyEvent key) {
    if (key.code == sf::Keyboard::Escape) {
        window->close();
    }
}