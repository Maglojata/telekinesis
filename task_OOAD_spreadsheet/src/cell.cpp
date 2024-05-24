#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../header/cell.h"

std::ostream& operator<<(std::ostream& out, const std::vector<int>& ob) 
{
	for (auto &i : ob) {
		out << i << ' ';
	}
	return out;
}

std::istream& operator>>(std::istream& in, std::vector<int>& ob) 
{
	std::string line;
	std::getline(in, line);
	std::istringstream str(line);
	int number;
	while (str >> number) {
		ob.push_back(number);
	}
	return in;
	
}

Cell::Cell()
	: m_val{}
{}

Cell::Cell(const Cell& rhv)
	: m_val{rhv.m_val}
{}

Cell::Cell(Cell&& rhv) 
{
	m_val = std::move(rhv.m_val);
}

Cell::Cell(int val)
	: m_val(std::to_string(val))
{}

Cell::Cell(double val)
	: m_val(std::to_string(val))
{}

Cell::Cell(char val)
	: m_val(std::to_string(val))
{}

Cell::Cell(bool val) {
	 m_val = (val == true) ? "true" : "false";
}
    
Cell::Cell(std::string val)
	: m_val(val)
{}


Cell::Cell(const std::vector<int>& val) 
{
	std::stringstream data;
	for (const auto& i : val) {
		data << i << ' ';
	}
	m_val = data.str();
}

const Cell& 
Cell::operator=(const Cell& rhv)
{
	if (this != &rhv) {
		m_val = rhv.m_val;
	}
	return *this;
}

const Cell& 
Cell::operator=(Cell&& rhv)
{
	if (this != &rhv){
		m_val = std::move(rhv.m_val);
	}
	return *this;
}

const Cell& 
Cell::operator=(int rhv)
{	
	m_val = std::to_string(rhv);
	return *this;
}

const Cell& 
Cell::operator=(double rhv)
{
	m_val = std::to_string(rhv);
	return *this;
}
    
const Cell& 
Cell::operator=(char rhv)
{
	m_val = std::to_string(rhv); 
	return *this; 	
}

const Cell& 
Cell::operator=(bool rhv)
{
	m_val = (rhv == true) ? "true" : "false";
	return *this;
}

const Cell& 
Cell::operator=(std::string rhv)
{
	m_val = rhv;
	return *this; 
}

const Cell& 
Cell::operator=(const std::vector<int>& rhv) 
{
	std::stringstream data;
	for (const auto& i : rhv) {
		data << i << ' ';
	}
	m_val = data.str();
	return *this;
}

Cell::operator int() const {
	return std::stoi(m_val);
}

Cell::operator double() const {
	return std::stod(m_val);
}

Cell::operator char() const {
	if (m_val.size() != 1) {
		return '\0';
	}
	return m_val[0];
}

Cell::operator bool() const {
	return (m_val == "true") ? true : false;
}  

Cell::operator std::string() const {
	return m_val;
}

Cell::operator std::vector<int>() const 
{
	std::vector<int> v;
	std::istringstream stream(m_val);
	int data; 
    while (stream >> data) {
		v.push_back(data);	
	}
	return v;
}

bool operator==(const Cell& lhv, const Cell& rhv) {
	return static_cast<std::string>(lhv) == static_cast<std::string>(rhv);
}
	
bool operator!=(const Cell& lhv, const Cell& rhv) {
	return static_cast<std::string>(lhv) != static_cast<std::string>(rhv);
}


std::ostream& operator<<(std::ostream& out, const Cell& ob)
{
	out << static_cast<std::string>(ob);
	return out;
}

std::istream& operator>>(std::istream& in, Cell& ob) {
	std::string temp;
	in >> temp;
	ob = static_cast<Cell>(temp);
	return in;
}

