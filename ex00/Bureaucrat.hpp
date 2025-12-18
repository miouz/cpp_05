#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <string>
#include <iostream>

class Bureacrat
{
	const std::string	name_;
	int					grade_	;

	public:
	Bureacrat();
	~Bureacrat();
	Bureacrat(const Bureacrat& other);
	Bureacrat& operator=(const Bureacrat& other);

	std::string getName() const;
	int			getGrade() const;
	void	increment();
	void	decrement();

};

std::ostream& operator<<(std::ostream& out, const Bureacrat& one);

#endif // !BUREAUCRAT_HPP_
