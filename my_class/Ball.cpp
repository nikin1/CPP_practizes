#include <iostream>
#include <string>

class Ball {
    private:
        std::string m_color;
        double m_radius;

    public:
    // Конструктор по умолчанию без параметров
    Ball()
    {
		m_color = "red";
		m_radius = 20.0;
    }
 
    // Конструктор с параметром color (для radius предоставлено значение по умолчанию)
	Ball(const std::string &color)
	{
		m_color = color;
		m_radius = 20.0;
	}
 
    // Конструктор с параметром radius (для color предоставлено значение по умолчанию)
	Ball(double radius)
	{
		m_color = "red";
		m_radius = radius;
	}
 
    // Конструктор с параметрами color и radius
	Ball(const std::string &color, double radius)
	{
		m_color = color;
		m_radius = radius;
	}
 
	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}


};













int main()
{
    Ball def;
    def.print();
 
	Ball black("black");
	black.print();
	
	Ball thirty(30.0);
	thirty.print();
	
	Ball blackThirty("black", 30.0);
	blackThirty.print();
 
    return 0;
}