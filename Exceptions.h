//
// Created by 33769 on 30/12/2021.
//

#ifndef VERSION1_EXCEPTIONS_H
#define VERSION1_EXCEPTIONS_H


#include <exception>

namespace {
    using std::exception;
}

namespace mtm {

    class Exception : public std::exception {
    };


    class NegativePoints : public mtm::Exception
    {
    public:
        const char* what() const noexcept override;
    };

class CanNotLearnSkill : public mtm::Exception
{
    const char* what() const noexcept override;
};

    class SkillAlreadyLearned : public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class DidNotLearnSkill : public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class EmployeeAlreadyHired : public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class EmployeeIsNotHired : public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class  EmployeeNotSelected : public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class ManagerIsNotHired : public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class ManagerAlreadyHired : public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class CanNotHireManager : public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class EmployeeNotAccepted : public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class CitizenAlreadyExists: public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class FacultyAlreadyExists: public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class WorkplaceAlreadyExists: public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class FacultyDoesNotExist: public mtm::Exception
    {
        const char* what() const noexcept override;
    };

    class EmployeeDoesNotExist: public mtm::Exception
    {
        const char* what() const noexcept override;
    };
    class ManagerDoesNotExist: public mtm::Exception
    {
        const char* what() const noexcept override;
    };
    class WorkplaceDoesNotExist: public mtm::Exception
    {
        const char* what() const noexcept override;
    };



}
#endif //VERSION1_EXCEPTIONS_H
