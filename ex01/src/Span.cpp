#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span() : N(0)
{
    std::cout << "Empty span created" << std::endl;
}

Span::Span(unsigned int N) : N(N)
{
    std::cout << "Span of size " << N << " created" << std::endl;
}

Span::Span(const Span &other) : N(other.N), numbers(other.numbers)
{
    std::cout << "Span copy-constructed" << std::endl;
}

Span::~Span()
{
    std::cout << "Span destroyed" << std::endl;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N = other.N;
        numbers = other.numbers;
    }
    std::cout << "Span assigned" << std::endl;
    return *this;
}

void Span::addNumber(int number)
{
    if (numbers.size() >= N)
        throw std::out_of_range("Span is full");
    numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::out_of_range("Not enough numbers in span");
    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for(size_t i = 2; i < sorted.size(); i++)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::out_of_range("Not enough numbers in span");
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}