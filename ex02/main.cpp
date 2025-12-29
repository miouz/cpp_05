#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat cafNpc(1,"Francois");
	Bureaucrat cafNpc2(150,"Patricia");
	AForm	*cerfa01;

	cerfa01 = new ShrubberyCreationForm("WC");
	cerfa01->beSigned(cafNpc);
	cerfa01->execute(cafNpc);
	
	return (0);
}

