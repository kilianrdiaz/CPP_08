#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        unsigned int N;
        std::vector<int> numbers;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        ~Span();

        Span &operator=(const Span &other);

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end)
        {
            std::vector<int>::size_type distance = std::distance(begin, end);
            if (numbers.size() + distance > N)
                throw std::out_of_range("Not enough space in span");
            while (begin != end)
            {
                addNumber(*begin);
                ++begin;
            }
        }
};


#endif