#include "../include/figures.hpp"
#include <stdexcept>

Figure::operator double() const {
    return area();
}

Triangle::Triangle() : vertices() {}

Triangle::Triangle(const std::array<std::pair<double, double>, 3>& points) {
    vertices = points;
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Triangle::Triangle(const Triangle& other) : vertices(other.vertices) {}

Triangle::Triangle(Triangle&& other) noexcept : vertices(std::move(other.vertices)) {}

std::pair<double, double> Triangle::geometricCenter() const {
    double centerX = (vertices[0].first + vertices[1].first + vertices[2].first) / 3.0;
    double centerY = (vertices[0].second + vertices[1].second + vertices[2].second) / 3.0;
    return {centerX, centerY};
}

double Triangle::area() const {
    double x1 = vertices[0].first, y1 = vertices[0].second;
    double x2 = vertices[1].first, y2 = vertices[1].second;
    double x3 = vertices[2].first, y3 = vertices[2].second;
    
    return std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
}

void Triangle::printVertices(std::ostream& os) const {
    os << "Triangle vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Triangle::readVertices(std::istream& is) {
    for (int i = 0; i < 3; ++i) {
        double x, y;
        is >> x >> y;
        vertices[i] = {x, y};
    }
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    if (!otherTriangle) return false;
    
    return vertices == otherTriangle->vertices;
}

Triangle& Triangle::operator=(const Figure& other) {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    if (otherTriangle) {
        vertices = otherTriangle->vertices;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

std::unique_ptr<Figure> Triangle::clone() const {
    return std::make_unique<Triangle>(*this);
}

Square::Square() : vertices() {}

Square::Square(const std::array<std::pair<double, double>, 4>& points) {
    vertices = points;
}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Square::Square(const Square& other) : vertices(other.vertices) {}

Square::Square(Square&& other) noexcept : vertices(std::move(other.vertices)) {}

std::pair<double, double> Square::geometricCenter() const {
    double centerX = 0, centerY = 0;
    for (const auto& vertex : vertices) {
        centerX += vertex.first;
        centerY += vertex.second;
    }
    return {centerX / 4.0, centerY / 4.0};
}

double Square::area() const {
    double minSide = std::numeric_limits<double>::max();
    
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            double distance = std::sqrt(std::pow(vertices[i].first - vertices[j].first, 2) + 
                                       std::pow(vertices[i].second - vertices[j].second, 2));
            if (distance > 1e-9 && distance < minSide) {
                minSide = distance;
            }
        }
    }
    
    return minSide * minSide;
}

void Square::printVertices(std::ostream& os) const {
    os << "Square vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Square::readVertices(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        double x, y;
        is >> x >> y;
        vertices[i] = {x, y};
    }
}

bool Square::operator==(const Figure& other) const {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (!otherSquare) return false;
    
    return vertices == otherSquare->vertices;
}

Square& Square::operator=(const Figure& other) {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (otherSquare) {
        vertices = otherSquare->vertices;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

std::unique_ptr<Figure> Square::clone() const {
    return std::make_unique<Square>(*this);
}

Rectangle::Rectangle() : vertices() {}

Rectangle::Rectangle(const std::array<std::pair<double, double>, 4>& points) {
    vertices = points;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Rectangle::Rectangle(const Rectangle& other) : vertices(other.vertices) {}

Rectangle::Rectangle(Rectangle&& other) noexcept : vertices(std::move(other.vertices)) {}

std::pair<double, double> Rectangle::geometricCenter() const {
    double centerX = 0, centerY = 0;
    for (const auto& vertex : vertices) {
        centerX += vertex.first;
        centerY += vertex.second;
    }
    return {centerX / 4.0, centerY / 4.0};
}

double Rectangle::area() const {
    double area = 0;
    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        area += vertices[i].first * vertices[j].second - 
                vertices[j].first * vertices[i].second;
    }
    return std::abs(area) / 2.0;
}

void Rectangle::printVertices(std::ostream& os) const {
    os << "Rectangle vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Rectangle::readVertices(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        double x, y;
        is >> x >> y;
        vertices[i] = {x, y};
    }
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (!otherRect) return false;
    
    return vertices == otherRect->vertices;
}

Rectangle& Rectangle::operator=(const Figure& other) {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (otherRect) {
        vertices = otherRect->vertices;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

std::unique_ptr<Figure> Rectangle::clone() const {
    return std::make_unique<Rectangle>(*this);
}

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    figure.printVertices(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.readVertices(is);
    return is;
}

double calculateTotalArea(const std::vector<Figure*>& figures) {
    double total = 0;
    for (const auto& figure : figures) {
        total += figure->area();
    }
    return total;
}

void printAllFiguresInfo(const std::vector<Figure*>& figures) {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i + 1 << ":\n";
        std::cout << "  " << *figures[i] << "\n";
        auto center = figures[i]->geometricCenter();
        std::cout << "  Geometric center: (" << center.first << ", " << center.second << ")\n";
        std::cout << "  Area: " << figures[i]->area() << "\n\n";
    }
}

void removeFigureByIndex(std::vector<Figure*>& figures, size_t index) {
    if (index < figures.size()) {
        delete figures[index];
        figures.erase(figures.begin() + index);
    }
}