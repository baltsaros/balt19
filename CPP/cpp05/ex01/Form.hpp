#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signature;

	public:
		Form(void);
		Form(std::string name, int sign, int exec);
		Form(Form const &src);
		~Form(void);

		Form&				operator=(Form const &rhs);
		std::string			getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				getSignature(void) const;
		bool				beSigned(Bureaucrat const &b);

		class GradeTooHighException: public std::exception {
				const char*	what(void) const throw();
		};

		class GradeTooLowException: public std::exception {
				const char*	what(void) const throw();
		};
};
std::ostream&	operator<<(std::ostream& o, Form const & bob);

#endif
