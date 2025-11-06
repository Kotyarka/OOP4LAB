#ifndef FIGURES_HPP
#define FIGURES_HPP

#include <iostream>
#include <array>
#include <utility>
#include <cmath>
#include <memory>
#include <stdexcept>
#include <vector>

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual std::pair<double, double> geometricCenter() const = 0;
    virtual double area() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
    virtual void readVertices(std::istream& is) = 0;
    
    virtual bool operator==(const Figure& other) const = 0;
    virtual Figure& operator=(const Figure& other) = 0;
    
    virtual std::unique_ptr<Figure> clone() const = 0;
    
    operator double() const;
};

class Triangle : public Figure {
private:
    std::array<std::pair<double, double>, 3> vertices;
    
public:
    Triangle();
    Triangle(const std::array<std::pair<double, double>, 3>& points);
    
    std::pair<double, double> geometricCenter() const override;
    double area() const override;
    void printVertices(std::ostream& os) const override;
    void readVertices(std::istream& is) override;
    
    bool operator==(const Figure& other) const override;
    Triangle& operator=(const Figure& other) override;
    
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(Triangle&& other) noexcept;
    
    std::unique_ptr<Figure> clone() const override;
    
    const std::array<std::pair<double, double>, 3>& getVertices() const { return vertices; }
};

class Square : public Figure {
private:
    std::array<std::pair<double, double>, 4> vertices;
    
public:
    Square();
    Square(const std::array<std::pair<double, double>, 4>& points);
    
    std::pair<double, double> geometricCenter() const override;
    double area() const override;
    void printVertices(std::ostream& os) const override;
    void readVertices(std::istream& is) override;
    
    bool operator==(const Figure& other) const override;
    Square& operator=(const Figure& other) override;
    
    Square(const Square& other);
    Square& operator=(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(Square&& other) noexcept;
    
    std::unique_ptr<Figure> clone() const override;
    
    const std::array<std::pair<double, double>, 4>& getVertices() const { return vertices; }
};

class Rectangle : public Figure {
private:
    std::array<std::pair<double, double>, 4> vertices;
    
public:
    Rectangle();
    Rectangle(const std::array<std::pair<double, double>, 4>& points);
    
    std::pair<double, double> geometricCenter() const override;
    double area() const override;
    void printVertices(std::ostream& os) const override;
    void readVertices(std::istream& is) override;
    
    bool operator==(const Figure& other) const override;
    Rectangle& operator=(const Figure& other) override;
    
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;
    
    std::unique_ptr<Figure> clone() const override;
    
    const std::array<std::pair<double, double>, 4>& getVertices() const { return vertices; }
};

std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);

double calculateTotalArea(const std::vector<Figure*>& figures);
void printAllFiguresInfo(const std::vector<Figure*>& figures);
void removeFigureByIndex(std::vector<Figure*>& figures, size_t index);

#endif