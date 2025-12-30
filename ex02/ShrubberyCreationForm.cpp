#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137),
shrubberyName_("_shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137),
shrubberyName_(target + "_shrubbery") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm("ShrubberyCreationForm", 145, 137),
shrubberyName_(other.shrubberyName_) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return *this;

	shrubberyName_ = other.shrubberyName_;
	return *this;
}

const std::string& ShrubberyCreationForm::getName() const
{
	return shrubberyName_;
}

void	ShrubberyCreationForm::setName(const std::string& name)
{
	shrubberyName_ = name;
}

void drawTree(std::ofstream& file)
{
	file << "           \\ i.     / s       /\n";
	file << "            \\  \\   /         /\n";
	file << "            .n'   |      a  |_.-._\n";
	file << "           /  /   /       .-'      `-.      --._\n";
	file << "          /  /    |     /            \\-.__'       `.\n";
	file << "         |  (     |    |     _        \\   _      .-.  \\\n";
	file << "         |   `-.-'     |  .-' '-.      | ' `-.  (   )_ |\n";
	file << "          `-._         \\ (  |    \\     /      \\  `-'  `.\n";
	file << "              `--.      \\ ) \\ \\`-'    /        | .'\n";
	file << "                  \\    .- '-.| `-._.-' \\      /  \\\n";
	file << "                  |   /      \\     .    `._.-'    |\n";
	file << "                  |  / |      |     '            /\n";
	file << "                  | (_/       |      `-._     _.'\n";
	file << "                  \\ //\\      .|           `--'\n";
	file << "                   \\\"  \\   '\\ \\___/)_\n";
	file << "                    |   |  ` \\_      \\`  ,\n";
	file << "                    \\   \\       (\\ .o-`-o\n";
	file << "                    |    \\__  _______,-'\\`\n";
	file << "                    \\      ( |  |\n";
	file << "                     |      \\\\  |\n";
	file << "              b    \"\" \\\n";
}

void	ShrubberyCreationForm::action(Bureaucrat const& executor) const
{
	std::ofstream	file;

	file.open(shrubberyName_.c_str(),std::fstream::out | std::fstream::trunc);

	if (!file.is_open())
		throw std::runtime_error("Fail to creat " + shrubberyName_);
	drawTree(file);
	file.close();
	std::cout << executor.getName() << " just executed "<< this->shrubberyName_ << ", the only work for today🥸🤔\n";
}
