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
    Rectangle(const std::string& name, float x, 
              float y, float vx, float vy, int r, int g, int b, float width, 
              float height)
        : m_name(name)
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
        m_rect.setSize(sf::Vector2f(width, height));
        m_rect.setFillColor(sf::Color(r, g, b));
        m_rect.setPosition(m_x, m_y);
    }
    ~Rectangle() {}

    void printName()
    {
        std::cout << m_name << std::endl;
    }

    void printPosition() const
    {
        std::cout << "x: "  << m_rect.getPosition().x 
                  << " y: " << m_rect.getPosition().y << std::endl;
    }

    void updatePosition(float dt, const sf::Vector2u& windowSize)
    {
        // reverse direction if going off screen
        int width = windowSize.x;
        int height = windowSize.y;
        {
            m_vx *= -1;
        }
        if (m_y + m_height > height || m_y < 0)
        {
            m_vy *= -1;
        }

        // update position
        m_x += m_vx*dt;
        m_y -= m_vy*dt; // screen coordinates flipped
        m_rect.setPosition(m_x, m_y);
    }

    const sf::RectangleShape& getShape() const
    {
        return m_rect;
    }

    const sf::Vector2f& getSize() const
    {
        return m_rect.getSize();
    }
};

class App
{
    unsigned int m_width = 800;
    unsigned int m_height = 600;
    std::vector<Rectangle> m_rectangles;
    std::vector<sf::CircleShape> m_circles;
    sf::RenderWindow m_window;

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
                m_rectangles.push_back(Rectangle(name, x, y, vx, vy, 
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
        for (size_t i = 0; i < m_rectangles.size(); i++)
        {
            m_rectangles[i].printName();
        }
    }

    void createWindow(const std::string& windowName)
    {
        m_window.create(sf::VideoMode(m_width, m_height), windowName);
    }

    void update(float dt)
    {
        for (auto& rectangle : m_rectangles)
        {
            rectangle.updatePosition(dt, m_window.getSize());
        }
    }

    void draw()
    {
        for (auto& rectangle : m_rectangles)
        {
            m_window.draw(rectangle.getShape());
        }
    }

    void mainLoop()
    {
        sf::Clock clock;
        while (m_window.isOpen())
        {
            sf::Event event;
            while (m_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_window.close();
            }

            float dt = clock.restart().asSeconds();
            update(dt);
            m_window.clear();
            draw();
            m_window.display();
        }
    }
};

int main()
{
    App app("config.txt");
    app.printWindowInfo();
    app.printRectangleNames();

    app.createWindow("Assignment 1");

    // sf::CircleShape shape(100.0f);
    // shape.setFillColor(sf::Color::Green);

    app.mainLoop();

    return 0;
}