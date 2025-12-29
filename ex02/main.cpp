#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {

	Form cerfa666("cerfa666", 1, 1);
	Bureacrat cafNpc1(2, "Patricia");

	std::cout << cerfa666;
	std::cout << cafNpc1;
	cafNpc1.signForm(cerfa666);
	std::cout << cerfa666;
	} catch (std::exception& e) {
		e.what();
	}

	try {

		Form cerfa666("cerfawtf", 1, 1);
		Bureacrat franceTravailNpc(1, "Francois");

		std::cout << cerfa666;
		std::cout << franceTravailNpc;
		franceTravailNpc.signForm(cerfa666);
		std::cout << cerfa666;
		} catch (std::exception& e) {
			e.what();
		}
	return (0);
}
