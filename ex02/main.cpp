#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat cafNpc(1,"Francois");
	Bureaucrat cafNpc2(150,"Patricia");

	//test for ShrubberyCreationForm
	AForm *cerfa01 = new ShrubberyCreationForm("WC");
	cafNpc.signForm(*cerfa01);
	cerfa01->execute(cafNpc);

	//test for RobotomyRequestForm
	AForm	*cerfa02 = new RobotomyRequestForm("aNewFreshIntern");
	cafNpc.signForm(*cerfa02);
	//test for the 50% time succeed
	cerfa02->execute(cafNpc);
	cerfa02->execute(cafNpc);
	cerfa02->execute(cafNpc);
	cerfa02->execute(cafNpc);
	cerfa02->execute(cafNpc);

	//test for PresidentialPardonForm
	AForm *cerfa03 = new PresidentialPardonForm("cafNPCPatricia");
	cafNpc.signForm(*cerfa03);
	cerfa03->execute(cafNpc);


	//test for execute
	cafNpc2.executeForm(*cerfa03);
	cafNpc.executeForm(*cerfa03);

	
	return (0);
}

