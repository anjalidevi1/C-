#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    // Member function to set the length and width
    void setData(double l, double w) {
        if (l > 0 && w > 0) {
            length = l;
            width = w;
        } else {
            std::cout << "Length and width must be positive values." << std::endl;
        }
    }

    // Member function to calculate and return the area
    double calculateArea() {
        return length * width;
    }

    // Member function to calculate and return the perimeter
    double calculatePerimeter() {
        return 2 * (length + width);
    }

    // Member function to display the details of the rectangle
    void display() {
        std::cout << "Length: " << length << std::endl;
        std::cout << "Width: " << width << std::endl;
        std::cout << "Area: " << calculateArea() << std::endl;
        std::cout << "Perimeter: " << calculatePerimeter() << std::endl;
    }
};

int main() {
    Rectangle rect;

    // Set the data for the rectangle
    rect.setData(10.5, 5.5);

    // Display the details of the rectangle
    rect.display();

    return 0;
}
