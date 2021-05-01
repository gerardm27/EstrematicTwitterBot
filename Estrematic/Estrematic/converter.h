#pragma once
#include <iostream>
#include <vector>
#include <string>

constexpr auto Exc1 = "penis";
constexpr auto Exc2 = "pene";
constexpr auto Exc3 = "si";
constexpr auto Exc4 = "no";
constexpr auto Exc5 = "correcte";
constexpr auto Exc6 = "gerard";
constexpr auto Exc7 = "bernat";
constexpr auto Exc8 = "marc";
constexpr auto Exc9 = "pau";
constexpr auto Exc10 = "roc";
constexpr auto Exc11 = "jordi";
constexpr auto Exc12 = "nico";


using namespace std;
class converter
{
private:
	static bool isVowel(const char&);
	static void lowerCapitalize(string&);
public:
	static string estrematize(string&);
};

