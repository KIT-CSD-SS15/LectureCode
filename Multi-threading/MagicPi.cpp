//
//  MagicPi.cpp
//  Multi-threading
//
//  Created by Manuel Giffels on 04.02.15.
//  Original code by Fred Stober git clone http://ekptrac.physik.uni-karlsruhe.de/git-public/CSD F04.cpp
//

#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <thread>

void circleMC(const long long N, long long &hits, const int seed)
{
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0, 1.0);
    
    for (long long i = 0; i < N; ++i)
    {
        double x = distribution(generator);
        double y = distribution(generator);
        if (std::sqrt(x*x + y*y) <= 1)
            ++hits;
    }
}

int main(int argc, char **argv)
{
    const long long N = 1e7;
    long long hits = 0;
    
    if (argc < 2) {
        std::cerr << "You need to provide the number of threads!" << std::endl;
        return 1;
    }
    
    const unsigned num_of_threads(std::stoi(argv[1]));
    srand(0);
    
    std::vector<std::thread> threads;
    for (int i = 0; i < num_of_threads; ++i)
        threads.emplace_back(std::thread(circleMC, N / num_of_threads, std::ref(hits), i + 100));

    for (auto &thread: threads)
        if(thread.joinable())
            thread.join();
    
    long double my_PI = 4 * static_cast<long double>(hits) / N;
    std::cout << std::fixed
    << "\t" << std::setprecision(10) << my_PI
    << "\t" << "3.141592653589793" << std::endl;
    return 0;
}

