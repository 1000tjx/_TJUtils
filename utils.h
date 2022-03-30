#pragma once
#ifndef TJ_UTILS_H
#define TJ_UTILS_H
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <limits> // for std::numeric_limits


namespace tjutils {

	inline bool str_contains(std::string main_str, std::string sub_str) {
		return main_str.find(sub_str) != std::string::npos;
	}

	inline double random_number(float a, float b) {
		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_real_distribution<> distr(a, b);
		return distr(eng);
	}

	inline int random_ms(float a, float b) {
		return (int)(random_number(a, b) * 10000);
	}

	inline std::string get_str_input(std::string msg) {
		std::string inp{  };
		std::cout << msg;
		std::getline(std::cin, inp);
		return inp;
	}


	inline int get_int_input(std::string msg) {
		std::string inp;
		std::cout << msg;
		std::getline(std::cin, inp);
		try {
			return std::stoi(inp);
		}
		catch (std::exception err) {
			return 0;
		}
	}


	inline std::vector<std::string> split_string(std::string s, std::string by) {
		std::vector<std::string> tokens{};
		size_t pos = 0;
		std::string token;
		while ((pos = s.find(by)) != std::string::npos) {
			token = s.substr(0, pos);
			s.erase(0, pos + by.length());
			tokens.push_back(token);
		}
		tokens.push_back(token);
		return tokens;
	}

	inline void thread_sleep(int ms) {
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	}

	inline void thread_sleep(float _from, float _to) {
		std::this_thread::sleep_for(std::chrono::milliseconds(random_ms(_from, _to)));
	}
	
	inline bool approximately_equal(double a, double b, double absEpsilon=1e-12, double relEpsilon=1e-8)
	{
	    // Check if the numbers are really close -- needed when comparing numbers near zero.
	    double diff{ std::abs(a - b) };
	    if (diff <= absEpsilon)
		return true;

	    // Otherwise fall back to Knuth's algorithm
	    return (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
	}
	
	inline void ignore_line()
	{
	    if (std::cin.fail())
	    {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	    }
	    else
	    {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	    }
	}
}

#endif
