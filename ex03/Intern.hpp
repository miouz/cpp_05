#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
	Intern();
	~Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);

	AForm* makeForm(const std::string& formName, const std::string& target);

	class	FormNotFoundException: public std::exception
	{
		std::string	msg_;
		public:
		FormNotFoundException(const std::string& formName);
		virtual ~FormNotFoundException() throw();
		virtual const char* what() const throw();
	};
};
#endif // !INTERN_HPP_
