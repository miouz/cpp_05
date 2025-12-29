#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

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
	file << "                   \\\"  \\   '\\ \\___/)_          \n";
	file << "                    |   |  ` \\_      \\`  ,        \n";
	file << "                    \\   \\       (\\ .o-`-o    \n";
	file << "                    |    \\__  _______,-'\\`      \n";
	file << "                    \\      ( |  |              \n";
	file << "                     |      \\\\  |               \n";
	file << "              b    \"\" \\\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137),
shrubberyName_("_shrubbery")
{
	std::ofstream	file(shrubberyName_);

	if (!file.is_open())
		throw std::runtime_error("Fail to creat _shrubbery form");
	drawTree(file);
	file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target): AForm("ShrubberyCreationForm", 145, 127),
shrubberyName_(target + "_shrubbery")
{

	std::ofstream	file(shrubberyName_);

	if (!file.is_open())
		throw std::runtime_error("Fail to creat " + target + "_shrubbery");
	drawTree(file);
	file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{

}

ShrubberyCreationForm::ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other)
{

}
