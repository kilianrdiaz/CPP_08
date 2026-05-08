#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));

    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        int shortest = sp.shortestSpan();
        int longest = sp.longestSpan();

        std::cout << "Shortest span: " << shortest << std::endl;
        std::cout << "Longest span: " << longest << std::endl;

        sp.addNumber(42);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        Span sp3(10000);
        std::vector<int> bigVec2;
        for (int i = 0; i < 10000; i++)
            bigVec2.push_back(rand() % 20000);
        sp3.addNumbers(bigVec2.begin(), bigVec2.end());

        int shortest = sp3.shortestSpan();
        int longest = sp3.longestSpan();
        std::cout << "Shortest span: " << shortest << std::endl;
        std::cout << "Longest span: " << longest << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        Span emptySpan(5);
        int result = emptySpan.shortestSpan();
        std::cout << "Shortest span: " << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        Span singleSpan(5);
        singleSpan.addNumber(42);
        int result = singleSpan.shortestSpan();
        std::cout << "Shortest span: " << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}