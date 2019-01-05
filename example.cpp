#include <iostream>
#include <random>
#include <vector>

#include "system_seeder.hpp"

int main()
{	
	system_seed seeder;
	
	// The Mersenne-Twister has a 
	std::vector<uint32_t> seed_vec(std::mt19937::state_size);

	std::cout << "\nState size of the Mersenne-Twister: " << std::mt19937::state_size << "\n\n";

	// Fill our vector with random numbers from our operating system
	seeder.generate(seed_vec.begin(), seed_vec.end());

	// Create a seed_seq object and copy the values from out vector
	std::seed_seq seq(seed_vec.begin(), seed_vec.end());

	// Seed the MT generator with our 624 32-bit integers
	std::mt19937 generator(seq);

	std::cout << "Some random numbers...\n";
	for(int i = 0; i < 10; ++i)
		std::cout << generator() << "\n";

}