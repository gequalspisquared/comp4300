// g++ assignment1.cpp -lsfml-graphics -lsfml-window -lsfml-system && ./a.out
#include <iostream>
#include <fstream>
#include <vector>

#include <SFML/Graphics.hpp>

class Rectangle
{
    sf::RectangleShape m_rect;
    std::string m_name;
    float m_x;
    float m_y;
    float m_vx;
    float m_vy;
    int   m_r;
    int   m_g;
    int   m_b;
    float m_width;
    float m_height;

public:
    Rectangle() {}
    Rectangle(const sf::RectangleShape& rect, const std::string& name, float x, 
              float y, float vx, float vy, int r, int g, int b, float width, 
              float height)
        : m_rect(rect)
        , m_name(name)
        , m_x(x)
        , m_y(y)
        , m_vx(vx)
        , m_vy(vy)
        , m_r(r)
        , m_g(g)
        , m_b(b)
        , m_width(width)
        , m_height(height)
    {
    }
    ~Rectangle() {}

    void printName()
    {
        std::cout << m_name << std::endl;
    }
};

class App
{
    unsigned int m_width = 800;
    unsigned int m_height = 600;
    std::vector<Rectangle> rectangles;
    std::vector<sf::CircleShape> circles;

public: 
    App() {}

    ~App() {}

    void loadConfigFile(const std::string& fileName)
    {
        std::cout << "Loading...\n";
        std::ifstream fin(fileName);
        std::string parameterName;
        std::string name;
        float x;
        float y;
        float vx;
        float vy;
        int r;
        int g;
        int b;
        float width;
        float height;

        while (fin >> parameterName)
        {
            if (parameterName == "Window")
            {
                fin >> m_width >> m_height;
            }
            
            if (parameterName == "Rectangle")
            {
                fin >> name >> x >> y >> vx >> vy >> r 
                    >> g >> b >> width >> height;
                sf::RectangleShape rect;
                rectangles.push_back(Rectangle(rect, name, x, y, vx, vy, 
                                               r, g, b, width, height));
            }
        }
    }

    App(const std::string& fileName) 
    {
        loadConfigFile(fileName);
    }

    void printWindowInfo()
    {
        std::cout << "Width: " << m_width << " "
                  << "Height: " << m_height << std::endl;
    }

    void printRectangleNames()
    {
        for (size_t i = 0; i < rectangles.size(); i++)
        {
            rectangles[i].printName();
        }
    }

    void createWindow(sf::RenderWindow& window, const std::string& windowName)
    {
        window.create(sf::VideoMode(m_width, m_height), windowName);
    }
};

int main()
{
    App app("config.txt");
    app.printWindowInfo();
    app.printRectangleNames();

    sf::RenderWindow window;
    app.createWindow(window, "Assignment 1");

    sf::CircleShape shape(100.0f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}