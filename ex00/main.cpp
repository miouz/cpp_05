#include "Bureaucrat.hpp"

int main()
{
	//test for constructor exception
	try{
	Bureaucrat	cafNpc1(-1,"Francois");

	std::cout << cafNpc1;
	}
	catch(std::exception& e) {
		std::cout << "Error: " << e.what();
	}

	//test for upgrade and degrade exeption
	try {
	Bureaucrat cafNpc2(150, "Patricia");

	std::cout << cafNpc2;
	cafNpc2.degrade();
	std::cout << cafNpc2;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what();
	}
	try {
	Bureaucrat cafNpc3(1, "Jean-Charles");

	std::cout << cafNpc3;
	cafNpc3.upgrade();
	std::cout << cafNpc3;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what();
	}
	return (0);
}
